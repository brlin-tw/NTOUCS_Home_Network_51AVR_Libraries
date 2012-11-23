/* 
Delay.c
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/* Standard io library definition?
#include <stdio.h> */

/* Definitions of 8051 register constants
#include <REG51.h> */

/* Common definitions */
#include "../Project_configurations/Common_definitions.h"

/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
void delay(unsigned int time){
	while(time > 0){
		time = time - 1;
	}
	return;
}
