#!/bin/bash


RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m'
NL='\n'

echo -e $GREEN"TEST START"$NC
echo -n "making...."

make bonus > /dev/null

echo -e $GREEN"SUCCESS"$NC

echo -e "my${NL}name${NL}is${NL}seonggki" > test_input

check_diff() {
	RESULT=$(diff test_correct_output test_my_output)
	echo ------------------------------
	echo -e ${CYAN}CORRECT RESULT${NC}
	cat test_correct_output
	echo -e ${CYAN}MY RESULT${NC}
	cat test_my_output
	if [ -z "$RESULT" ]; then
		echo -e $GREEN"case $1 SUCCESS"$NC
	else
		echo -e $RED"case $1 FAILED"$NC
	fi
}

#test_input에는 mynameisseonggki의 정보가 저장되어 있고 cat명령을 사용해 파일정보를 출력하고
#리다이렉션을 사용하여 새로운 test_output 파일을 만들어서 저장
< test_input cat | cat > test_correct_output
./pipex test_input cat cat test_my_output
check_diff "1"

< test_input ls -l | wc -l > test_correct_output
./pipex test_input "ls -l" "wc -l" test_my_output
check_diff "2"

< test_input grep a1 | wc -w > test_correct_output
./pipex test_input "grep a1" "wc -w" test_my_output
check_diff "3"

< test_input cat 123 | cat > test_correct_output
./pipex test_input "cat 123" cat test_my_output
check_diff "4"

< test_input cat | ls -l | wc > test_correct_output
./pipex test_input cat "ls -l" "wc" test_my_output
check_diff "5"

< test_input cat | ls | wc > test_correct_output
./pipex test_input cat 'ls' 'wc' test_my_output
check_diff "6"

< test_input cat | ls -l | wc | cat > test_correct_output
./pipex test_input cat "ls -l" "wc" cat test_my_output
check_diff "7"

rm test_input test_correct_output test_my_output