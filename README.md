# fibon
For calculating Fibonacci numbers.

Simple program written in C to calculate Fibonacci numbers

Has multiple flags for formatting output:
`-l` or `--list`: Seperate each number by a newline rather than a space.
`-c` or `--comma`: Use commas to separate every 3 digits.
`-n` or `--numbered`: Will number each entry in output.

Can be supplied a number as an argument to calculate that amount of Fibonnachi numbers.
Will only eat the first number and disregard any further numbers supplied.

Example:
`./fibon 10 -lnc`

Output:
`1: 0  
2: 1  
3: 1  
4: 2  
5: 3  
6: 5  
7: 8  
8: 13  
9: 21  
10: 34`


