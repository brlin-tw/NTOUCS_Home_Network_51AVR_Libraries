/* 
main.c
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
	/* Standard io library definition? */
		#include <stdio.h>

	/* Common definitions */
		#include "Project_configurations/Common_definitions.h"

	/* for signals definitions used by initialize() */
		#include "Project_configurations/Configuration_NTOUCS_HN_Winbond_W78E58B.h"
		
	/* Test target */
		#include "ADC/ADC.h"
	
	/* for LED control procedures*/
		#include "LED/LED.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 初始化硬體（關掉所有元件）的函式 */
		void initializeSystem();

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	initializeSystem();
	
	/* main loop */
	while(TRUE){
		ledDisplayValue(adcGetValue());
		
	}
	
	return;
}

void initializeSystem(){
	/* 清空 LED 輸出 */
		LED = 0xFF;
	/* 停用 ADC 的輸出 */
		adc_chip_select_bar_read_bar = LOGIC_HIGH;
	/* 停用 DIP 的輸出 */
		dip_sw_chip_enable_bar = LOGIC_HIGH;
	/* 停用 LCD */
		lcd_enable = LOGIC_LOW;
	/* 停用 LCD 的暫存器輸入 */
		lcd_read_write_bar = LOGIC_HIGH;
	/* 停用 7 段顯示器的輸入 */
		SEVEN_SEG = 0x00;
		seven_seg_latch_position_enable = LOGIC_HIGH;
		seven_seg_latch_position_enable = LOGIC_LOW;
	return;
}
