//Lab5_PartB_Main 

#include <stdio.h>
#include "..\..\rt.h"

UINT __stdcall Thread2(void* args) {

	CMutex M("Mutex1");

	//HANDLE child_handle;
	//child_handle = M.GetHandle();

	//child_handle = *(HANDLE *)args;


	//printf("Child mutex handle is %X\n", (unsigned int)child_handle);

	for (int i = 0; i < 1000; i++) {

		//M.Wait();

		MOVE_CURSOR(20, 20);             // move cursor to cords [x,y] = 10,10
		printf("Hello from Thread 2\n");
		fflush(stdout);		      	// force output to be written to screen

		//M.Signal();
	}

	return 0;

}

int main()
{
	CMutex M("Mutex1");

	//HANDLE parent_handle;
	//parent_handle = M.GetHandle();
	//printf("Parent mutex handle is %X\n", (unsigned int)parent_handle);

	CThread t1(Thread2, ACTIVE, NULL);

	for (int i = 0; i < 1000; i++) {

		//M.Wait();

		MOVE_CURSOR(10, 10);             // move cursor to cords [x,y] = 10,10
		printf("Hello from Thread 1\n");
		fflush(stdout);		      	// force output to be written to screen

		//M.Signal();
	}

	t1.WaitForThread();

	return 0;
}
