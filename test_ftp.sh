#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "USAGE: $0 host port"
    exit 0
fi

USERNAME="Anonymous"
PASS=""

HOST=$1
PORT=$2
MKFIFO=`which mkfifo`
PIPE=fifo
OUT=outfile
TAIL=`which tail`
NC="`which nc` -C"
TIMEOUT=0.1 #max time before reading server response

RETURN_VALUE=0

getcode()
{
  sleep $TIMEOUT
  local code=$1
  echo "Waiting for $code reply-code"
  local data=`$TAIL -n 1 $OUT |cat -e |grep "^$code.*[$]$" |wc -l`
  return $data
}

print_failed()
{
    echo -e "\e[91m$1 test failed\e[0m"
    echo -e "Expected reply-code: \e[91m$2\e[0m"
    echo -e "Received : [\e[93m"`$TAIL -n 1 $OUT| cat -e`"\e[0m]"
    echo -e "\e[91mKO\e[0m"
    RETURN_VALUE=1
}

print_succeeded()
{
  if [[ ! $? -eq 1 ]]; then
    kill_client
    return
  fi
  echo -e "\e[92m$1 test succeeded\e[0m"
  echo -e "\e[92mOK\e[0m"
  kill_client 2>&1 >/dev/null
}

launch_client()
{
  local host=$1
  local port=$2

  $MKFIFO $PIPE
  ($TAIL -f $PIPE 2>/dev/null | $NC $host $port &> $OUT &) >/dev/null 2>/dev/null

  echo -e "\e[96m--------------------------------------------------\e[0m"
  echo "Connecting to $host : $port"
  sleep $TIMEOUT
  getcode 220
  if [[ $? -eq 1 ]]; then
    echo -e "Reply-code OK"
    return 1
  else
    echo "Connection to $host:$port failed"
    echo "Expected reply-code: 220"
    echo "Received : ["`tail -n 1 $OUT |cat -e`"]"
    return 0
  fi
}

launch_test()
{
  local test_name=$1
  local cmd=$2
  local code=$3

  echo "Sending [$cmd^M$]"
  echo "$cmd" >$PIPE
  getcode $code
  if [[ ! $? -eq 1 ]]; then
    print_failed "$test_name" "$code"
    kill_client
    clean
    return
  fi
  echo -e "\e[92mReply-code OK\e[0m"
}

kill_client()
{
  local nc=`which nc`

  if [ `pidof $TAIL | wc -l` -ne 0 ]
  then
    killall $TAIL &>/dev/null
  fi
  if [ `pidof $nc | wc -l` -ne 0 ]
  then
    killall $nc &>/dev/null
  fi  
  rm -f $PIPE $OUT &> /dev/null
}

clean()
{
  rm -f $PIPE $OUT log &>/dev/null
}

# Simple authentication with USER + PASS command
test00()
{
  local test_name="Authentication"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230

  print_succeeded "$test_name"
  return
}

test01()
{
  local test_name="PASS"

  local cmd2="PASS $PASS"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd2" 503

  print_succeeded "$test_name"
  return
}

test02()
{
  local test_name="Exec Command without loggin"

  local cmd1="PWD"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 530

  print_succeeded "$test_name"
  return
}

# Simple authentication 2 time with USER + PASS command
test03()
{
  local test_name="USER -> PASS -> PASS!"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="PASS $PASS"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 503

  print_succeeded "$test_name"
  return
}

# Simple authentication 2 time with USER + PASS command
test04()
{
  local test_name="USER -> PASS -> USER!"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="USER $USERNAME"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 503

  print_succeeded "$test_name"
  return
}

# Simple authentication 2 time with USER + PASS command
test05()
{
  local test_name="QUIT"

  local cmd1="QUIT"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 221

  print_succeeded "$test_name"
  return
}

test06()
{
  local test_name="HELP NOT LOGGED"

  local cmd1="HELP"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 530

  print_succeeded "$test_name"
  return
}

test07()
{
  local test_name="HELP WITHOUT ARG"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="HELP"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 214

  print_succeeded "$test_name"
  return
}

test08()
{
  local test_name="HELP WITH ARG"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="HELP USER"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 214

  print_succeeded "$test_name"
  return
}

test09()
{
  local test_name="HELP WITH INVALID ARG"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="HELP AZFDFEG"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 501

  print_succeeded "$test_name"
  return
}

test10()
{
  local test_name="NOOP"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="NOOP"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 200

  print_succeeded "$test_name"
  return
}

test11()
{
  local test_name="BAD USER NAME"

  local cmd1="USER aisjfisjfisdf"
  local cmd2="PASS $PASS"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 530

  print_succeeded "$test_name"
  return
}

test12()
{
  local test_name="PWD"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="PWD"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 257

  print_succeeded "$test_name"
  return
}

test13()
{
  local test_name="CWD"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="CWD .."

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 250

  print_succeeded "$test_name"
  return
}

test14()
{
  local test_name="CWD"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="CWD zelfsdfsfd"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 550

  print_succeeded "$test_name"
  return
}

test15()
{
  local test_name="CDUP"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="CDUP"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 200

  print_succeeded "$test_name"
  return
}

test16()
{
  local test_name="PORT"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="PORT 127,0,0,1,22,88"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 200

  print_succeeded "$test_name"
  return
}

test17()
{
  local test_name="PASV"

  local cmd1="USER $USERNAME"
  local cmd2="PASS $PASS"
  local cmd3="PASV"

  launch_client $HOST $PORT
  if [[ ! $? -eq 1 ]]; then
    echo "KO"
    kill_client
    return
  fi
  echo ""

  launch_test "$test_name" "$cmd1" 331
  launch_test "$test_name" "$cmd2" 230
  launch_test "$test_name" "$cmd3" 227

  print_succeeded "$test_name"
  return
}

test00
test01 # bad sequence PASS
test02 # command without login
test03 # bad sequence USER PASS PASS
test04 # bad sequence USER PASS USER
test05 # QUIT
test06 # HELP not login
test07 # HELP without arg
test08 # valide HELP arg
test09 # invalide HELP arg
test10 # NOOP
test11 # wrong authentification (bad user name)
test12 # PWD
test13 # CWD
test14 # CWD invalide file
test15 # CDUP
test16 # PORT
test17 # PASV

clean

exit $RETURN_VALUE
