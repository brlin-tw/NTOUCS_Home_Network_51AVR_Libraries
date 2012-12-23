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
	#include "Project_configurations/Configuration_NTOUCS_HN_Winbond_W78E58B.h"

/* 7 segment display procedures */
	#include "Seven_segment_display/Seven_segment_display.h"
	
/* flow of control libraries */
	#include "Flow_of_control/Delay.h"
	#include "Flow_of_control/Hang.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/
	/* scan interval of 7 segment display  */
		#define DISPLAY_INTERVAL 1
/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 初始化硬體（關掉所有元件）的函式 */
		void initializeSystem();

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	unsigned int count;
	unsigned int i;
	
	initializeSystem();
	
	/* main loop */
	while(TRUE){
		for(count = 9500; count <= 9999; ++count){
			for(i = 0; i < DISPLAY_INTERVAL; ++i){
				seven_segmentDisplayValue4digit(count);
			}
		}
		seven_segmentDisable();
		hangForever();
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
	/* 停用 7 段顯示器 */
		SEVEN_SEG = 0x00;
		/* 關閉數位顯示開關 */
			seven_seg_latch_position_enable = LOGIC_HIGH;
			seven_seg_latch_position_enable = LOGIC_LOW;
			delay(400);
		/* 清空數位字型內容 */
			seven_seg_latch_font_enable = LOGIC_HIGH;
			seven_seg_latch_font_enable = LOGIC_LOW;
	return;
}
