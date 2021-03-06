// MemorySegmentationExemplarC++.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "stdlib.h"					//Library containing malloc, free, etc.

/*In this version of Jon Erickson's memory segmentation exeplar program, the height of the memory addresses for different variables mostly seem to line up with what he says they are: the initialised vars
have the lowest addresses, then it's the non-initialised statics relatively close after. However, we then get the stack variables a bit higher up and then the manually allocated heap variable a *lot*
higher up after that. I'm not really sure why this is, Erickson's model would have the stack addresses starting high and then growing lower. While they still do seem to grow lower when I run this program,
it seems like they start from a much lower memory address than the address that the heap_var is allocated to. At this point I think memory allocation now might just be a lot more complex than it was when
the book was written, or that the book just significantly oversimplifies it, e.g. I've not yet seen ASLR mentioned.*/

int global_var;
int global_initialised_var = 5;

void function()
{
	int stack_var;
	printf("the function's stack_var is at address 0x%08x\n", &stack_var);
}

int main()
{
	int stack_var;
	static int static_initialised_var = 5;
	static int static_var;
	int *heap_var_ptr;

	heap_var_ptr = (int*)malloc(4);

	//These variables are in the data segment.
	printf("global_initialised_var is at address 0x%08x\n", &global_initialised_var);
	printf("static_initialised_var is at address 0x%08x\n\n", &static_initialised_var);

	//These variables are in the bss segment.
	printf("static_var is at address 0x%08x\n", &static_var);
	printf("global_var is at address 0x%08x\n\n", &global_var);

	//This variable is in the heap segment.
	printf("heap_var is at address 0x%08x\n\n", heap_var_ptr);

	//These variables are in the stack segment.
	printf("stack_var is at address 0x%08x\n", &stack_var);
	function();

    return 0;
}

