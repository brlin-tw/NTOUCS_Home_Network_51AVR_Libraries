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
	/* 初始化硬體（關掉所有元件）的函式 */
		void initializeSystem();

	/* 測試子程式 */
		void testAdcGetValue(void);
		
/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	initializeSystem();
	
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

void initializeSystem(){
	/* 清空 LED 輸出 */
		led = 0xFF;
	/* 停用 ADC 的輸出 */
		adc_chip_select_bar_read_bar = LOGIC_HIGH;
	/* 停用 DIP 的輸出 */
		dip_sw_chip_enable_bar = LOGIC_HIGH;
	/* 停用 LCD */
		lcd_enable = LOGIC_LOW;
	/* 停用 LCD 的暫存器輸入 */
		lcd_read_write_bar = LOGIC_HIGH;
	/* 停用 7 段顯示器 */
		seven_seg = 0x00;
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