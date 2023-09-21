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
