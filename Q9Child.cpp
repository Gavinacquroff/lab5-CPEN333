//////////////////////////////////////////////////////////////////////////////////
//	The Consumer Process
//////////////////////////////////////////////////////////////////////////////////

#include 	<stdio.h>
#include	"..\..\rt.h"			

struct		mydatapooldata {			
	int x ;						
} ;

struct		mydatapooldata 		*TheDataPointer ;		

int main()
{
	CSemaphore		ps1("PS1", 0, 1) ;    
	CSemaphore		cs1("CS1", 1, 1) ;    


	CDataPool dp1("MyDataPoolName", sizeof(struct mydatapooldata)) ;
	TheDataPointer = (struct mydatapooldata *)(dp1.LinkDataPool()) ;

	//-------------------------------------------------------
	//part D, a
	//comment out following code to run part D, b

	printf("Consumer Process 1 Running.....\n") ;
	for(int i = 0; i < 10; i++) {	// consume 10 lots of data
		printf("Hit RETURN to Consume Data.....\n") ;
		getchar() ;
		ps1.Wait() ;		// wait for producer process to signal producer semaphore
		printf("Consumed: %d\n", TheDataPointer->x ) ;
		cs1.Signal() ;		// signal the consumer semaphore to wake up the producer
	}
	//-------------------------------------------------------

	//-------------------------------------------------------
	//part D, b
	//comment out following code to run part D, a

	/*printf("Producer Process 1 Running.....\n");
	for (int i = 0; i < 10; i++) {	
		printf("Hit RETURN to produce Data.....\n");
		getchar();
		cs1.Wait();
		TheDataPointer->x = i;
		printf("Produced: %d\n", TheDataPointer->x);
		ps1.Signal();		
	}*/
	//-------------------------------------------------------


	return 0 ;
}
