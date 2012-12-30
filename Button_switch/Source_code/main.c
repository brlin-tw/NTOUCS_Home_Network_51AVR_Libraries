/* 
主程式
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/* Standard io library definition? */
	#include <stdio.h>

/* Definitions of 8052 register constants
   　如果您要直接存取而非透過 Project_configurations/Ports_and_control_signals_* 來存取硬體的話需引入此檔案
	#include <REG52.h> */

/* Project_configurations */
	#include "Project_configurations/Common_definitions.h"

/* Hardware_configurations */
	#include "Hardware_configurations/NTOUCS_Home_Network_51AVR.h"
	
/* Flow_of_control procedures definitions */
	#include "Flow_of_control/Delay.h"
	#include "Flow_of_control/Hang.h"
	
/* LED definitions */
	#include "LED/LED.h"

/* timer definitions */
	#include "Timer_or_counter/Timer_or_counter.h"

/* for ADC definitions */
	#include "ADC/ADC.h"
	
/* test target */
	#include "Button_switch/Button_switch.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 測試函式 */
		void testButtonIsPressed(void);
		void testButton3andADC(void);
		
/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	disableAllUnit();
	
	/* main loop */
	while(TRUE){
		testButtonIsPressed();
		testButton3andADC();
		ledDisplayValue(LED_ALL);
		hangForever();
	}
	
	return;
}

void testButtonIsPressed(void){
	while(
		(button_swIsPressed(BTN_SW4) &&
		button_swIsPressed(BTN_SW5) && 
		button_swIsPressed(BTN_SW6)) == FALSE){
		if(button_swIsPressed(BTN_SW4)){
			ledDisplayValue(D4);
			ledDisable();
		}
		
		if(button_swIsPressed(BTN_SW5)){
			ledDisplayValue(D5);
			ledDisable();
		}
		
		if(button_swIsPressed(BTN_SW6)){
			ledDisplayValue(D6);
			ledDisable();
		}
		
		if(button_swIsPressed(BTN_SW3)){
			ledDisplayValue(D3);
			ledDisable();
		}
	}
	return;
}

void testButton3andADC(void){
	
	
	return;
}