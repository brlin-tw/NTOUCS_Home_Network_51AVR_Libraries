/* 
LED.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	#include "LED.h"
		/* led constant definition */
	#include "../Project_configurations/Common_definitions.h"
		/* for C true */
	/* Target device configurations */
		#include "../Project_configurations/Configuration_NTOUCS_HN_Winbond_W78E58B.h"

/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/
	code unsigned char led_position[8] = {
		LED0, LED1, LED2, LED3, LED4, LED5, LED6, LED7
	};

/*||||| 主要程式碼 | Main Code |||||*/
void ledDisplayValue(unsigned char value){
	if(LED_LIT == LOGIC_HIGH){
		led = value;
	}else{
		/* 目標電路的 LED 於邏輯 LOW 時發光，所以將值反向之後再填進去 */
		led = ~value;
	}
	return;
}

void ledRotateOneWay(
	/* 讓 LED 從一邊亮到另外一邊 */
	unsigned char current_position, 
		/* 目前 LED 位置 */
	bit direction
		/* 輪動方向 */, 
	void (*delay)(unsigned)
		/* 用來當作輪動周期的時間延遲函式 */, 
	unsigned interval
		/* 輪動週期（從一個 LED 跳到下一個 LED 的 tick 數）*/ ){
	
	/* rotate to last bit */
		while(TRUE){
			/* leave when overflow/underflow to 0 */
				if(current_position == 0x0){
					return;
				}
			
			ledDisplayValue(current_position);
			delay(interval);
				
			/* shift 1 bit */
				if(direction == LED_ROTATE_UP){
					current_position <<= 1;
				}else{
					current_position >>= 1;
				}
		}
}

void ledRotateTwoWay(
	/* 讓 LED 從一邊亮到另外一邊...再亮回來 */
	bit initial_direction
		/* 第一次輪轉的轉動方向 */, 
	void (*delay)(unsigned)
		/* 用來當作輪動周期的時間延遲函式 */, 
	unsigned interval
		/* 輪動週期（從一個 LED 跳到下一個 LED 的時間） */){
	ledRotateOneWay(
		(initial_direction == LED_ROTATE_UP) ? 
			LED_LOWEST : LED_HIGHEST, 
		initial_direction, 
		delay, 
		interval);
	ledRotateOneWay(
		(initial_direction == LED_ROTATE_UP) ?
			LED_HIGHEST / 2 : LED_LOWEST * 2, 
		~initial_direction, 
		delay, 
		interval);
	return;
}

void ledDisable(
	/* 關閉 LED 顯示 */
	void){
	ledDisplayValue(LED_NONE);
	return;
}