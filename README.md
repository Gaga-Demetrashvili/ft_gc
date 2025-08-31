# ft_gc
Garbage Collector simulation for C programs

Basically what I did is just to create for malloc a wrapper function, which allocates memory with malloc for the pointer requested,
saves that pointer in a newly allocated linked list node and returns that pointer back to user. New allocattions are added to the 
node list in front so that in case of array and it's members at first members are freed and then array itself.

Usage:
Before starting using "gc_malloc" function, call "init_gc(malloc(sizeof(t_gc)))" so t_gc struct was created. It is needed for 
function internally to work.

When you call "gc_malloc" just pass size of the memory you want to allocate (e.g. if you want to create an array of five integers 
"int *arr = gc_malloc(5 * sizeof(int))").

At the end of the program you can call "gc_free_all" and all the memory allocated with "gc_malloc" will be freed.

There is an option to free specific pointer allocated with "gc_malloc". If you will need that case use "gc_free" and
pass the pointer you want to free.

Threre is also commented main function in the repo in case you want to test your cases.
