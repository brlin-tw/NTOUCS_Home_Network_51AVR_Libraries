/* 
Delay.c
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
	/* Standard io library definition?
		#include <stdio.h> */

	/* Common definitions */
		#include "../Project_configurations/Common_definitions.h"

	/* for timer procedures and definitions */
		#include "../Timer_or_counter/Timer_or_counter.h"
		
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
void delay(unsigned int time){
	while(time > 0){
		time = time - 1;
	}
	return;
}

void delaySecond(
	/* 延遲（單位：秒） */
	bit timer, 
		/* 用來計時的 timer */
	unsigned int time
		/* 延遲時距（單位：秒） */){
	unsigned char period_count;
			
	/* 先停用可能開啟的 timer */
		tmr_ctrDisable(timer);
	
	tmr_ctrSetMode(timer, TMR_CTR_MODE1);
	timerSetPeriod16bit(timer, TMR_16B_11_0592_MHZ_1S_PERIOD);			
	tmr_ctrEnable(timer);
			
	while(time != 0){
		if(tmr_ctrIsOverflow(timer) == TRUE){
			tmr_ctrClearOverflow(timer);
			timerSetPeriod16bit(timer, TMR_16B_11_0592_MHZ_1S_PERIOD);
			period_count++;
		}
		if(period_count == TMR_16B_11_0592_MHZ_1S_COUNT){
			period_count = 0;
			time--;
			
		}
	}
	tmr_ctrDisable(timer);
	return;		
}