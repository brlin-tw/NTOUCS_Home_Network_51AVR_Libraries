/* 
Button_switch.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	/* Project 設定 */
		#include "../Project_configurations/Common_definitions.h"

	/* Hardware_configurations */
		#include "../Hardware_configurations/NTOUCS_Home_Network_51AVR.h"
		
	/* itself definitions */
		#include "Button_switch.h"
		
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	bit button_swIsPressed(
		/* 如果有被按下回傳 TRUE */
		bit button_sw
			/* BTN_SW* */){
		if(button_sw == BTN_SW_PRESSED){
			return TRUE;
		}else{
			return FALSE;
		}
	}