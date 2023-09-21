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
