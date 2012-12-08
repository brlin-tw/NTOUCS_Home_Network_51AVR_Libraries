/* 
DIP_switch.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	#include "../Project_configurations/Ports_and_control_signals_NTOUCS_HN_Winbond_W78E58B.h"
	#include "../Project_configurations/Common_definitions.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	unsigned char dip_swGetValue(
		/* 取得 DIP 封裝開關的數值 */){
		unsigned char recieved;
			
		dip_sw_chip_enable_bar = LOGIC_LOW;
		recieved = ~DIP_SW;
			/* OFF 時讀到 HIGH，ON 時讀到 LOW，把數值反向回來 */
		dip_sw_chip_enable_bar = LOGIC_HIGH;
			
		return recieved;
	}