/* 
LED.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	#include "LED.h"
		/* led constant definition */
	#include "../Project_configurations/Common_definitions.h"
		/* for C true */
	#include "../Delay/Delay.h"
		/* for delay procedure */
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
void ledDisplayValue(unsigned char value){
	/* 實際上 LED 將邏輯 LOW 訊號視為發光，所以將反向之後再填進去 */
	LED = ~value;
	return;
}


void ledRotateOneWay(
	/* 讓 LED 從一邊亮到另外一邊 */
	unsigned char initial_position, 
		/* 初始位置 */
	bit direction
		/* 輪動方向 */){
	/* set initial position : use initial_position as led_position to save memory */
		#define led_position initial_position

	/* rotate to last bit */
		while(TRUE){
			/* leave when overflow/underflow to 0 */
				if(led_position == 0x0){
					return;
				}
			
			ledDisplayValue(led_position);
			delay(20000);
				
			/* shift 1 bit */
				if(direction == LED_ROTATE_UP){
					led_position <<= 1;
				}else{
					led_position >>= 1;
				}
		}
}

void ledRotateTwoWay(
	/* 讓 LED 從一邊亮到另外一邊...再亮回來 */
	bit initial_direction
		/* 第一次輪轉的轉動方向 */){
	ledRotateOneWay(
		(initial_direction == LED_ROTATE_UP) ? 
			LED_LOWEST : LED_HIGHEST, 
		initial_direction);
	ledRotateOneWay(
		(initial_direction == LED_ROTATE_UP) ?
			LED_HIGHEST / 2 : LED_LOWEST * 2, 
		~initial_direction);
	return;
}