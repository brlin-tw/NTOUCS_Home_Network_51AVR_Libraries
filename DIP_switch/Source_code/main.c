/* 
主程式
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/* Standard io library definition? */
	#include <stdio.h>

/* Definitions of 8051 register constants
   　如果您要直接存取而非透過 Project_configurations/Ports_and_control_signals_* 來存取硬體的話需引入此檔案
	#include <REG51.h> */

/* Common definitions */
	#include "Project_configurations/Common_definitions.h"

/* Ports and control signals definitions */
	#include "Hardware_configurations/NTOUCS_Home_Network_51AVR.h"

/* Testing object */
	#include "DIP_switch/DIP_switch.h"
	
/* LED */
	#include "LED/LED.h"

/* FLOW */
	#include "Flow_of_control/Flow_of_control.h"
	
/* Timer_or_counter */
	#include "Timer_or_counter/Timer_or_counter.h"
	
/* 按鈕開關 */
	#include "Button_switch/Button_switch.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	void testDIP_SWgetValue(void);
	void testDIP_SWisOn(void);
	
/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	initializeSystem();
	
	/* main loop */
	while(TRUE){
		testDIP_SWgetValue();
		
		ledDisplayValue(LED_ALL);
		delaySecond(TMR_CTR0, 1);
		ledDisplayValue(LED_NONE);
		
		testDIP_SWisOn();
		
		ledDisplayValue(LED_ALL);
		hangForever();
	}
	
	return;
}

void testDIP_SWgetValue(void){
	while(button_swIsPressed(BTN_SW6) == FALSE){
		dip_swEnable();
		ledDisplayValue(dip_swGetValue());
		dip_swDisable();
	}
	return;
}

void testDIP_SWisOn(void){
	while(button_swIsPressed(BTN_SW6) == FALSE){
		dip_swEnable();
		switch ((unsigned char)dip_swIsOn(DIP_SW8)){
		case TRUE:
			ledDisplayValue(D8);
			break;
		case FALSE:
			ledDisplayValue(LED_NONE);
			break;
		}
		dip_swDisable();
	}
	return;
}