#include "stm32f4xx.h"                  // Device header
#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
/*-----------------------------------------
------------start main()-------------------*/
void Thread1(void const *arg){
	RCC->AHB1ENR=RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER=1<<24|1<<26|1<<28|1<<30;
	GPIOD->ODR=1<<12|1<<13|1<<14|1<<15;
}

void Thread2(void const *arg){
	GPIOD->ODR=0<<12|0<<13|0<<14|0<<15;
}

osThreadId main_id ,Thread_1,Thread_2;
osThreadDef(Thread1,osPriorityNormal,1,0);
osThreadDef(Thread2,osPriorityNormal,1,0);
int main(){
	while(1){
		osThreadCreate(osThread(Thread1),NULL);
		osDelay(1000);
		osThreadCreate(osThread(Thread2),NULL);
		osDelay(1000);
	}
}
