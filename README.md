# 0x19. C - Stacks, Queues - LIFO, FIFO

0. push, pall
	- Implement the `push` and `pall` opcodes.
	- ___The push opcode___
	- The opcode `push` pushes an element to the stack.
		- Usage: `push <int>`
			- where `<int>` is an integer
		- if `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`
			- where is the line number in the file
		- You won’t have to deal with overflows. Use the `atoi` function
	- ___The pall opcode___
	- The opcode `pall` prints all the values on the stack, starting from the top of the stack. 
		- Usage `pall`
		- Format: see example
		- If the stack is empty, don’t print anything
	```
	julien@ubuntu:~/monty$ cat -e bytecodes/00.m
	push 1$
	push 2$
	push 3$
	pall$
	julien@ubuntu:~/monty$ ./monty bytecodes/00.m
	3
	2
	1
	julien@ubuntu:~/monty$
	```

1. pint
	- Implement the `pint` opcode.
	- ___The pint opcode___
	- The opcode `pint` prints the value at the top of the stack, followed by a new line.	
		- Usage: `pint`
		- If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`
	```
	julien@ubuntu:~/monty$ cat bytecodes/06.m 
	push 1
	pint
	push 2
	pint
	push 3
	pint
	julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
	1
	2
	3
	julien@ubuntu:~/monty$ 
	```

2. pop
	- Implement the `pop` opcode.
	- ___The pop opcode___
	- The opcode `pop` removes the top element of the stack.
		- Usage: `pop`
		- If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`
	```
	julien@ubuntu:~/monty$ cat bytecodes/07.m 
	push 1
	push 2
	push 3
	pall
	pop
	pall
	pop
	pall
	pop
	pall
	julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
	3
	2
	1
	2
	1
	1
	julien@ubuntu:~/monty$ 
	```

3. swap
	- Implement the `swap` opcode.
	- ___The swap opcode___
	- The opcode `swap` swaps the top two elements of the stack.
		- Usage: `swap`
		- If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
	```
	julien@ubuntu:~/monty$ cat bytecodes/09.m 
	push 1
	push 2
	push 3
	pall
	swap
	pall
	julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
	3
	2
	1
	2
	3
	1
	julien@ubuntu:~/monty$ 
	```

4. add
	- Implement the `add` opcode.
	- ___The add opcode___
	- The opcode `add` adds the top two elements of the stack.
		- Usage: `add`
		- If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
		- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
			- The top element of the stack contains the result
			- The stack is one element shorter
	```
	julien@ubuntu:~/monty$ cat bytecodes/12.m 
	push 1
	push 2
	push 3
	pall
	add
	pall

	julien@ubuntu:~/monty$ ./monty bytecodes/12.m 
	3
	2
	1
	5
	1
	julien@ubuntu:~/monty$
	```

5. nop
	- Implement the `nop` opcode.
	- ___The nop opcode___
	- The opcode `nop` doesn’t do anything.
		- Usage: `nop`

6. sub
	- Implement the `sub` opcode.
	- ___The sub opcode___
	- The opcode `sub` subtracts the top element of the stack from the second top element of the stack.
		- Usage: `sub`
		- If the stack contains less than two elements, print the error message `L<line_number>: can't sub, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
		- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
			- The top element of the stack contains the result
			- The stack is one element shorter
	```
	julien@ubuntu:~/monty$ cat bytecodes/19.m 
	push 1
	push 2
	push 10
	push 3
	sub
	pall
	julien@ubuntu:~/monty$ ./monty bytecodes/19.m 
	7
	2
	1
	julien@ubuntu:~/monty$
	```

7. div
	- Implement the `div` opcode.
	- ___The div opcode___
	- The opcode `div` divides the second top element of the stack by the top element of the stack.
		- Usage: `div`
		- If the stack contains less than two elements, print the error message `L<line_number>: can't div, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
		- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
			- The top element of the stack contains the result
			- The stack is one element shorter
		- If the top element of the stack is `0`, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

8. mul
	- Implement the `mul` opcode.
	- ___The mul opcode___
	- The opcode `mul` multiplies the second top element of the stack with the top element of the stack.
		- Usage: `mul`
		- If the stack contains less than two elements, print the error message `L<line_number>: can't mul, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
		- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
			- The top element of the stack contains the result
			- The stack is one element shorter

9. mod
	- Implement the `mod` opcode.
	- ___The mod opcode___
	- The opcode `mod` computes the rest of the division of the second top element of the stack by the top element of the stack.
		- Usage: `mod
		- If the stack contains less than two elements, print the error message `L<line_number>: can't mod, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
		- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
			- The top element of the stack contains the result
			- The stack is one element shorter
		- If the top element of the stack is `0`, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

11. pchar
	- Implement the `pchar` opcode.
	- ___The pchar opcode___
	- The opcode `pchar` prints the char at the top of the stack, followed by a new line.
		- Usage: `pchar`
		- The integer stored at the top of the stack is treated as the ascii value of the character to be printed
		- If the value is not in the ascii table (man ascii) print the error message `L<line_number>: can't pchar, value out of range`, followed by a new line, and exit with the status `EXIT_FAILURE`
		- If the stack is empty, print the error message `L<line_number>: can't pchar, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`
	```
	julien@ubuntu:~/monty$ cat bytecodes/28.m 
	push 72
	pchar
	julien@ubuntu:~/monty$ ./monty bytecodes/28.m 
	H
	julien@ubuntu:~/monty$
	```

12. pstr
	- Implement the `pstr` opcode.
	- ___The pstr opcode___
	- The opcode `pstr` prints the string starting at the top of the stack, followed by a new line.
		- Usage: `pstr`
		- The integer stored in each element of the stack is treated as the ascii value of the character to be printed
		- The string stops when either:
			- the stack is over
			- the value of the element is 0
			- the value of the element is not in the ascii table
		- If the stack is empty, print only a new line
	```
	julien@ubuntu:~/monty$ cat bytecodes/31.m 
	push 1
	push 2
	push 3
	push 4
	push 0
	push 110
	push 0
	push 108
	push 111
	push 111
	push 104
	push 99
	push 83
	pstr
	julien@ubuntu:~/monty$ ./monty bytecodes/31.m 
	School
	julien@ubuntu:~/monty$ 
	```

13. rotl
	- Implement the `rotl` opcode.
	- ___The rotl opcode___
	- The opcode `rotl` rotates the stack to the top.
		- Usage: `rotl`
		- The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
		- `rotl` never fails
	```
	julien@ubuntu:~/monty$ cat bytecodes/35.m 
	push 1
	push 2
	push 3
	push 4
	push 5
	push 6
	push 7
	push 8
	push 9
	push 0
	pall
	rotl
	pall
	julien@ubuntu:~/monty$ ./monty bytecodes/35.m 
	0
	9
	8
	7
	6
	5
	4
	3
	2
	1
	9
	8
	7
	6
	5
	4
	3
	2
	1
	0
	julien@ubuntu:~/monty$ 
	```

14. rotr
	- Implement the `rotr` opcode.
	- ___The rotr opcode___
	- The opcode `rotr` rotates the stack to the bottom.
		- Usage: `rotr`
		- The last element of the stack becomes the top element of the stack
		- `rotr` never fails
