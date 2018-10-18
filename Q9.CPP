/*
**	Win32 code program to solve the graphical problem illustrated previously. The single Producer
**	Single Consumer arrangement. Let's assume this is both the Producer and the Parent program
*/

#include 	<stdio.h>
#include	"..\rt.h"			

struct		mydatapooldata {		
	int 	x ;						
} ;

struct		mydatapooldata 	*TheDataPointer ;		
struct		mydatapooldata 	*TheDataPointer2;		

int 	main()
{
	CSemaphore		ps1("PS1", 0, 1);
	CSemaphore		cs1("CS1", 1, 1);

	CSemaphore		cs2("CS2", 1, 1);	
	CSemaphore		ps2("PS2", 0, 1);	


	CDataPool dp1("MyDataPoolName", sizeof(struct mydatapooldata));
	TheDataPointer = (struct mydatapooldata *)dp1.LinkDataPool();

	CDataPool dp2("MyDataPoolName2", sizeof(struct mydatapooldata)); 
	TheDataPointer2 = (struct mydatapooldata *)dp2.LinkDataPool();


	CProcess p1("C:\\RTExamples\\Q9 - ProducerConsumerProblem\\Release\\Q9Child.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,					// process has its own window
		ACTIVE							// process is active immediately
	);

	CProcess p2("C:\\RTExamples\\Q9 - ProducerConsumerProblem\\Release\\Consumer2.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,					// process has its own window
		ACTIVE							// process is active immediately
	);
	
	//-------------------------------------------------------
	//part D, a
	//comment out following code to run part D,b

	printf("Producer Process Running.....\n");

	for (int i = 0; i < 10; i++) {
		cs1.Wait();
		cs2.Wait();	//part D,a
		TheDataPointer->x = i;
		ps1.Signal();
		ps2.Signal();
		printf("Produced %d.....\n", i);
	}
	//-------------------------------------------------------

	//-------------------------------------------------------
	//part D, b - parent process is consumer from two datapools
	//comment out following code to run part D,a

	//printf("Consumer Process Running.....\n");
	////while processes are still active
	//while ((WaitForSingleObject(p1.GetProcessHandle(),1) == 0x00000102) || 
	//		(WaitForSingleObject(p2.GetProcessHandle(), 1) == 0x00000102)) {

	//	if (ps1.Read() > 0) {
	//		ps1.Wait();
	//		printf("Consumed: %d\n", TheDataPointer->x);
	//		cs1.Signal();
	//	}

	//	if (ps2.Read() > 0) {
	//			ps2.Wait();
	//			printf("Consumed: %d\n", TheDataPointer2->x);
	//			cs2.Signal();
	//	}
	//}
	//-------------------------------------------------------
	
	return 0;
}
