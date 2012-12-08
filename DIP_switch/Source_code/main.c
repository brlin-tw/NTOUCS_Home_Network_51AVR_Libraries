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
	#include "Project_configurations/Ports_and_control_signals_NTOUCS_HN_Winbond_W78E58B.h"

/* Testing object */
	#include "DIP_switch/DIP_switch.h"
	
/* LED */
	#include "LED/LED.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 初始化硬體（關掉所有設備信號）的函式 */
		void initializeSystem();

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	initializeSystem();
	
	/* main loop */
	while(TRUE){
		ledDisplayValue(dip_swGetValue());
		
	}
	
	return;
}

void initializeSystem(){
	/* 啟用／停用 ADC 的輸入 */
		adc_read_bar_chip_select_bar = LOGIC_HIGH;
	/* 啟用／停用 DIP 的輸入 */
		dip_sw_chip_enable_bar = LOGIC_HIGH;
	/* 啟用／停用 LCD */
		lcd_enable = LOGIC_LOW;
	/* disable LCD register write */
		lcd_read_write_bar = LOGIC_HIGH;
	return;
}