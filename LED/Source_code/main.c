/* 
main.c
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/* Standard io library definition? */
	#include <stdio.h>

/* Common definitions */
	#include "Project_configurations/Common_definitions.h"

/* for LED operations */
	#include "LED/LED.h"

/* for delay procedure */
	#include "Flow_of_control/Delay.h"
	
/* hang procedure */
	#include "Flow_of_control/Hang.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 初始化硬體（關掉所有設備信號）的函式 */
	void initialize();

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	initialize();
	
	/* main loop */
	while(TRUE){

		ledDisplayValue(LED_NONE);
		delay(20000);		
		ledDisplayValue(LED_ALL);
		delay(20000);
		ledDisplayValue(LED_NONE);
		delay(20000);		
		ledDisplayValue(LED_ALL);
		delay(20000);
		
#if FALSE
		ledRotateOneWay(LED_LOWEST, LED_ROTATE_UP, delay, 10000);
		ledDisplayValue(0xFF);
		delay(20000);
		
		ledRotateOneWay(LED_HIGHEST, LED_ROTATE_DOWN, delay, 10000);
		ledDisplayValue(0xFF);
		delay(20000);
		
		ledRotateTwoWay(LED_ROTATE_UP, delay, 10000);
		ledDisplayValue(0xFF);
		delay(20000);
		
		ledRotateTwoWay(LED_ROTATE_DOWN, delay, 10000);
		ledDisplayValue(0xFF);
		delay(20000);

		/* test led_position[] */{
			unsigned char i;
			
			for(i = 0; i <= 7; ++i){
				ledDisplayValue(led_position[i]);
				delay(20000);
			}
		}
#endif
		
		while(TRUE){
			ledDisplayValue(LED_HALF_UP);
			delay(20000);
			ledDisplayValue(LED_HALF_DOWN);
			delay(20000);
		}
		hangForever();
	}
	
	return;
}

void initialize(){
	/* 停用 ADC 的輸出 */
		adc_read_bar_cs_bar = LOGIC_HIGH;
	/* 停用 DIP 的輸出 */
		dip_ground = LOGIC_HIGH;
	/* 停用 LCD */
		lcd_enable = LOGIC_LOW;
	/* disable LCD register write */
		lcd_read_write_bar = LOGIC_HIGH;
	return;
}