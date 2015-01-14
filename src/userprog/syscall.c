#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{

  printf ("system call!\n");
   int syscall_no = ((int *)f->esp)[0];
   switch(syscall_no) {
   case SYS_CRSPTH:
   	   f->eax = (uint32_t) create_simple_thread(((char *) f->esp)[1], ((int *) f->esp)[2]);
   	   break;
   case SYS_USRALLOC:
	   f->eax =
	   break;
   case SYS_USRFREE:
	   break;

   }

  thread_exit ();
}

int
create_simple_thread(const char *name, int priority)
{
	printf("create_simple_thread\n");
	return 0;//thread_create(name,priority,(thread_func *)thread_function,NULL);
}

void*
user_alloc(int size)
{
	return thread_create();
}

void
user_free(void *buffer)
{
	thread_create();
}

