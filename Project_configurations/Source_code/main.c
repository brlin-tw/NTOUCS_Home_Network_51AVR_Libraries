/* 
「檔案名稱 | File name」
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/* Standard io library definition? */
#include <stdio.h>

/* Test object */
#include "Project_configurations/Common_definitions.h"

/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 初始化 W78E58B 硬體的函式 */
	void initializeW78E58B();

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	initializeW78E58B();
	
	/* main loop */
	while(TRUE){
		
		
	}
	
	return;
}

void initializeW78E58B(){
	
	return;
}
