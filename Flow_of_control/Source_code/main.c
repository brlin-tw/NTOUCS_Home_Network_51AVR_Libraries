/* 
main.c
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
	/* Standard io library definition?
		#include <stdio.h> */

	/* Common definitions */
		#include "Project_configurations/Common_definitions.h"

	/* Configuration of target hardware */
		#include "Project_configurations/Configuration_NTOUCS_HN_Winbond_W78E58B.h"

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
	/* 初始化8051硬體的函式 */
		void initialize8051();

	/* 功能測試 */
		void testDelaySecond(bit timer);
		void testDelayDoing(void);
		
/*||||| 全域變數 | Global Variables |||||*/
	
/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	initialize8051();
	
	/* main loop */
	while(TRUE){
		testDelaySecond(TMR_CTR0);
		testDelaySecond(TMR_CTR1);
		testDelayDoing();
		hangForever();
		
	}
	
	return;
}

void initialize8051(){
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
	/* 停用計時器(timer)／計數器(counter) */
		tmr_ctr1_run = LOGIC_LOW;
		tmr_ctr0_run = LOGIC_LOW;
	return;
}

void testDelaySecond(bit timer){
	unsigned char i = 0;
	
	while(switch4 == LOGIC_HIGH){
		delaySecond(timer, 1);
		ledDisplayValue(i);
		++i;
	}
	delay(65535);
	ledDisable();
	return;
}

void testDelayDoing(void){
	while(switch4 == LOGIC_HIGH){	
		delayDoing(65535, seven_segmentDisplayDecimal, 1234);
	}
	seven_segmentDisable();
	return;
}