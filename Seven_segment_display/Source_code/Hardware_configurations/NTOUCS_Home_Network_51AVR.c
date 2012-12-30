/* 
NTOUCS_Home_Network_51AVR.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	/* self header */
		#include "NTOUCS_Home_Network_51AVR.h"
		
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	void disableAllUnit(
		/* 停用所有元件輸出的函式 */
			void){
		/* 關閉 LED 顯示 */
			led = 0xFF;
		/* 停用 ADC 對匯流排的輸出 */
			adc_chip_select_bar_read_bar = LOGIC_HIGH;
		/* 停用 DIP 對匯流排的輸出 */
			dip_sw_chip_enable_bar = LOGIC_HIGH;
		/* 停用 LCD */
			lcd_enable = LOGIC_LOW;
		/* 停用 LCD 的暫存器輸入 */
			lcd_read_write_bar = LOGIC_HIGH;
		/* 停用 7 段顯示器 */
			/* 關閉數位顯示開關 */
				seven_seg_latch_position_enable = LOGIC_HIGH;
				seven_seg = 0x00;
				seven_seg_latch_position_enable = LOGIC_LOW;
				/* delay(400); */{
					unsigned char i;
					
					for(i = 0; i < 200; ++i){
						;
					}
					for(i = 0; i < 200; ++i){
						;
					}
				}
			/* 清空數位字型內容 */
				seven_seg_latch_font_enable = LOGIC_HIGH;
				seven_seg = 0x00;
				seven_seg_latch_font_enable = LOGIC_LOW;
		/* 停用計時器(timer)／計數器(counter) */
			tmr_ctr1_run = LOGIC_LOW;
			tmr_ctr0_run = LOGIC_LOW;
		return;
	}
