/* halt.c

   Simple program to test whether running a user program works.

   Just invokes a system call that shuts down the OS. */

#include <syscall.h>

int
main (void)
{
	create_simple_thread("nume1", 6);
	user_alloc(5);
	user_free(user_alloc(4));

  /* not reached */
}
