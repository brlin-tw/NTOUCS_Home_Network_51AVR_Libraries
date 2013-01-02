/* 
main.c
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
	/* Standard io library definition?
		#include <stdio.h> */

	/* Common definitions */
		#include "Project_configurations/Common_definitions.h"

	/* Hardware_configurations */
		#include "Hardware_configurations/NTOUCS_Home_Network_51AVR.h"
		
	/* Testing target */
		#include "Flow_of_control/Delay.h"
		#include "Flow_of_control/Hang.h"
		
	/* led functions */
		#include "LED/LED.h"

	/* for seven segment display procedure definition */
		#include "Seven_segment_display/Seven_segment_display.h"

	/* Timer_or_counter constants definitions */
		#include "Timer_or_counter/Timer_or_counter.h"
		
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 功能測試 */
		void testDelaySecond(bit timer);
		void testDelayDoing(void);
		void testDelaySecondDoing(void);
		
/*||||| 全域變數 | Global Variables |||||*/
	
/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	disableAllUnit();

	/* main loop */
	while(TRUE){
#if 0
		ledDisplayValue(LED_ALL);
		delaySecond(TMR_CTR0, 1);
		ledDisplayValue(LED_NONE);
		
		testDelaySecond(TMR_CTR0);
#endif
#if 0		
		ledDisplayValue(LED_ALL);
		delaySecond(TMR_CTR0, 1);
		ledDisplayValue(LED_NONE);
		
		testDelaySecond(TMR_CTR1);
#endif
#if 1		
		ledDisplayValue(LED_ALL);
		delaySecond(TMR_CTR0, 1);
		ledDisplayValue(LED_NONE);
		
		testDelayDoing();	
#endif	
#if 0	
		ledDisplayValue(LED_ALL);
		delaySecond(TMR_CTR0, 1);
		ledDisplayValue(LED_NONE);
		
		testDelaySecondDoing();
#endif	
		/* test ended */
		ledDisplayValue(LED_ALL);
		hangForever();
		
	}
	
	return;
}

void testDelaySecond(bit timer){
	unsigned char i = 0;
	
	while(BTN_SW4 == LOGIC_HIGH){
		delaySecond(timer, 1);
		ledDisplayValue(i);
		++i;
	}
	ledDisable();
	return;
}

void testDelayDoing(void){
	while(BTN_SW4 == LOGIC_HIGH){	
		/* delayDoing(10000, ledDisplayValue, LED_HALF_UP);
		delayDoing(10000, ledDisplayValue, LED_HALF_DOWN); */
		delayDoing(10000, seven_segmentDisplayOctal, 1234);
		delayDoing(10000, seven_segmentDisplayOctal, 4321);
	}
	seven_segmentDisable();
	return;
}

void testDelaySecondDoing(void){
	while(BTN_SW4 == LOGIC_HIGH){	
		delaySecondDoing(TMR_CTR1, 2, ledDisplayValue, LED_ODD);
		delaySecondDoing(TMR_CTR1, 2, ledDisplayValue, LED_EVEN);
		/* delaySecondDoing(TMR_CTR1, 3, seven_segmentDisplayDecimal, 5678);
		delaySecondDoing(TMR_CTR1, 3, seven_segmentDisplayDecimal, 8765); */
	}
	seven_segmentDisable();
	return;
}