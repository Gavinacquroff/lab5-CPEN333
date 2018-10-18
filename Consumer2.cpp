//////////////////////////////////////////////////////////////////////////////////
//	The Consumer Process
//////////////////////////////////////////////////////////////////////////////////

#include 	<stdio.h>
#include	"..\..\rt.h"			

struct		mydatapooldata {			
	int x ;						
} ;

struct		mydatapooldata 		*TheDataPointer ;		
struct		mydatapooldata 		*TheDataPointer2;		

int main()
{
	CSemaphore		ps2("PS2", 0, 1) ;    
	CSemaphore		cs2("CS2", 1, 1) ;    

	//-------------------------------------------------------
	//part D, a
	//comment out following code to run part D, b

	CDataPool dp1("MyDataPoolName", sizeof(struct mydatapooldata)) ;
	TheDataPointer = (struct mydatapooldata *)(dp1.LinkDataPool()) ; 

	printf("Consumer Process 2 Running.....\n");
	for (int i = 0; i < 10; i++) {	// consume 10 lots of data
		printf("Hit RETURN to Consume Data.....\n");
		getchar();
		ps2.Wait();		// wait for producer process to signal producer semaphore
		printf("Consumed: %d\n", TheDataPointer->x);
		cs2.Signal();		// signal the consumer semaphore to wake up the producer
	}
	//-------------------------------------------------------

	//-------------------------------------------------------
	//part D,b
	//comment out following code to run part D, a

	/*CDataPool dp2("MyDataPoolName2", sizeof(struct mydatapooldata));
	TheDataPointer2 = (struct mydatapooldata *)(dp2.LinkDataPool()); 

	printf("Producer Process 2 Running.....\n") ;
	for(int i = 0; i < 10; i++) {	
		printf("Hit RETURN to Produce Data.....\n") ;
		getchar() ;
		cs2.Wait() ;
		TheDataPointer2->x = i;
		printf("Produced: %d\n", TheDataPointer2->x ) ;
		ps2.Signal() ;		
	}*/
	//-------------------------------------------------------

	getchar() ;
	return 0 ;
}
