#!/bin/bash
# ./push_swap `shuf -i 1-100 -n 7 | tr '\n' ' '`
# ./push_swap 25 20 83 71 65 16 48
# ./push_swap 79 61 77 62 49 92 50 #fail
# ./push_swap 74 31 48 6

#with this in mind, can you handle all this just for fun? 😁 

# error_input
# echo "------------checker linux----------------"
# ./checker_linux ""                    # 1 empty arg
# ./checker_linux "     "               # 1 empty arg
# ./checker_linux 2 "" 4 3              # has empty arg
# ./checker_linux 2 "     " 4 3         # has empty arg
# ./checker_linux 2 4 3a                # has non-number
# ./checker_linux 4+2 5 1               # has non-number
# ./checker_linux 4,2 5 1               # has non-number
# ./checker_linux 2 4 ++3               # has non-number
# ./checker_linux 2 4 +-0               # has non-number
# ./checker_linux 2147483648 12 1 5     # has overflow integer
# ./checker_linux -2147483649 12 1 5    # has overflow integer
# ./checker_linux 42 000042 5 1         # has duplicate number
# ./checker_linux -5 2 -00005 7         # has duplicate number

# echo "------------Push SWAP----------------"
# ./push_swap ""                    # 1 empty arg
# ./push_swap "     "               # 1 empty arg
# ./push_swap 2 "" 4 3              # has empty arg
# ./push_swap 2 "     " 4 3         # has empty arg
# ./push_swap 2 4 3a                # has non-number
# ./push_swap 4+2 5 1               # has non-number
# ./push_swap 4,2 5 1               # has non-number
# ./push_swap 2 4 ++3               # has non-number
# ./push_swap 2 4 +-0               # has non-number
# ./push_swap 2147483648 12 1 5     # has overflow integer
# ./push_swap -2147483649 12 1 5    # has overflow integer
# ./push_swap 42 000042 5 1         # has duplicate number
# ./push_swap -5 2 -00005 7         # has duplicate number



# with this in mind, can you handle all this just for fun? 😁 

# ok_input

# ./push_swap 4 +2 5 1 | wc -l 
# ./push_swap "4" +2 5 "1" | wc -l
# ./push_swap "  4  " " +2 " "5    1" | wc -l 
# ./push_swap 42 "1 7" 9 "  25   10 " | wc -l
# # ./push_swap 00000 +0002 -2222 "+0000009     -000009"

# ./push_swap 00000000000000000000000001 +002 -002

# // ok_input
# ./checker_Mac 4 +2 5 1
# ./checker_Mac "4" +2 5 "1"
# ./checker_Mac "  4  " " +2 " "5    1"
# ./checker_Mac 42 "1 7" 9 "  25   10 "
# ./checker_Mac 00000 +0002 -2222 "+0000009     -000009"
 ./push_swap 2147483647 "-2147483648 00000000000000000000000001 +002 -002"

