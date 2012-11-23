/* 
main.c
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/* Standard io library definition? */
	#include <stdio.h>

/* Definitions of 8051 register constants */
	#include <REG51.h>

/* Common definitions */
	#include "Project_configurations/Common_definitions.h"

/* Testing target */
	#include "Flow_of_control/Delay.h"
	#include "Flow_of_control/Hang.h"
/* led functions */
	#include "LED/LED.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 初始化8051硬體的函式 */
	void initialize8051();

/*||||| 全域變數 | Global Variables |||||*/
	unsigned char led_position;
		/* 不知道為什麼放在 main() 裏面會建構失敗orz
			 0000_0001 */
	
/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	initialize8051();
	
	/* main loop */
	while(TRUE){
		ledRotateOneWay(LED_LOWEST, LED_ROTATE_UP, delay, 10000);
		hangForever();
		ledDisplayValue(0xff);
	}
	
	return;
}

void initialize8051(){
	
	return;
}
