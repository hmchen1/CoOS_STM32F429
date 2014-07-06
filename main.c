#include "main.h"

OS_STK taskA_stk[STACK_SIZE_TASK];
OS_STK taskB_stk[STACK_SIZE_TASK];

void taskA(void* pdata);
void taskB(void* pdata);

int main(void){
	SystemInit();
	UB_Led_Init();
	CoInitOS();
	CoCreateTask(taskA, 0, 0, &taskA_stk[STACK_SIZE_TASK-1], STACK_SIZE_TASK);
	CoCreateTask(taskB, 0, 1, &taskB_stk[STACK_SIZE_TASK-1], STACK_SIZE_TASK);
	CoStartOS();
	while(1){
	}
}

void taskA(void* pdata){
	unsigned int a = 0;
	for(;;){

		if (a & 1){
			UB_Led_On(LED_GREEN);
        }
		else{
			UB_Led_Off( LED_GREEN);
        }
		a++;
		CoTickDelay(100);
    }
}
void taskB(void* pdata){
	unsigned int b = 0;
	for(;;){
    	if (b & 1){
    		UB_Led_On(LED_RED);
        }
    	else{
    		UB_Led_Off(LED_RED);
        }
    	b++;
    	CoTickDelay(100);
    }
}
