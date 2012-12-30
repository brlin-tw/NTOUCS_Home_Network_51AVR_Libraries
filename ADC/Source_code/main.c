/* 
main.c
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
	/* Standard io library definition? */
		#include <stdio.h>

	/* Common definitions */
		#include "Project_configurations/Common_definitions.h"

	/* Hardware_configurations */
		#include "Hardware_configurations/NTOUCS_Home_Network_51AVR.h"
		
	/* Test target */
		#include "ADC/ADC.h"
	
	/* for LED control procedures*/
		#include "LED/LED.h"
	
	/* for Flow_of_control procedures */
		#include "Flow_of_control/Delay.h"
		#include "Flow_of_control/Hang.h"
		
	/* for TMR_CTR* */
		#include "Timer_or_counter/Timer_or_counter.h"
	
	/* for button switch access procedures */
		#include "Button_switch/Button_switch.h"
	
	/* 為了７段顯示器的定義 */
		#include "Seven_segment_display/Seven_segment_display.h"
		
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 測試子程式 */
		void testAdcGetValue(void);
		
/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	disableAllUnit();
	
	/* main loop */
	while(TRUE){
		testAdcGetValue();
		
		ledDisplayValue(LED_ALL);
		delaySecond(TMR_CTR0, 1);
		ledDisplayValue(LED_NONE);
		delaySecond(TMR_CTR0, 1);		
		ledDisplayValue(LED_ALL);
		hangForever();
	}
	
	return;
}

void testAdcGetValue(void){
	unsigned char recieved;
	
	while(FALSE == button_swIsPressed(BTN_SW4)){
		unsigned int i;
		
		adcEnable();
		recieved = adcGetValue();
		adcDisable();
		for(i = 0; i < 200; ++i){ 
			seven_segmentDisplayDecimal(recieved);
		}
		seven_segmentDisable();
		delaySecond(TMR_CTR0, 1);
	}
	return;
}