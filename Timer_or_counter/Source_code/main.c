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
	#include "Project_configurations/Ports_and_control_signals_NTOUCS_HN_Winbond_W78E58B.h"

/* Flow_of_control procedures definitions */
	#include "Flow_of_control/Delay.h"
	#include "Flow_of_control/Hang.h"
	
/* Timer_or_counter library definitions */
	#include "Timer_or_counter/Timer_or_counter.h"
	
/* LED library definitions */
	#include "LED/LED.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 初始化硬體（關掉所有元件）的函式 */
		void initializeSystem();

	/* 功能測試函式 */
		void testTimerMode1(bit timer);
		
/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	initializeSystem();

	/* main loop */
		while(TRUE){
			testTimerMode1(TMR_CTR1);
			
			/* end */
			ledDisplayValue(0xff);
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
	/* 停用計時器(timer)／計數器(counter) */
		tmr_ctr1_run = LOGIC_LOW;
		tmr_ctr0_run = LOGIC_LOW;
	return;
}

void testTimerMode1(bit timer){
	tmr_ctrSetMode(timer, TMR_CTR_MODE1);
	timerSetPeriod16bit(timer, TMR_16B_11_0592_MHZ_1S_PERIOD);
	tmr_ctrEnable(timer);

	/* 1s */{
		unsigned char period_count = 0;
		unsigned char led_pattern = LED_ODD;
			
		while(switch4 != LOGIC_LOW){
			if(tmr_ctrIsOverflow(timer) == TRUE){
				period_count++;
				timerSetPeriod16bit(timer, 61440);
				tmr_ctrClearOverflow(timer);
			}
			if(period_count == TMR_16B_11_0592_MHZ_1S_COUNT){
				led_pattern = ~led_pattern;
				ledDisplayValue(led_pattern);
				period_count = 0;
			}
		}
	}
	return;
}