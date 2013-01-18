/* 
DIP_switch.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	#include "../Project_configurations/Common_definitions.h"
	#include "../Hardware_configurations/NTOUCS_Home_Network_51AVR.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	void dip_swEnable(
		/* 啟用 DIP 封裝開關對匯流排的輸出 */
		void){
		dip_sw_chip_enable_bar = LOGIC_LOW;
		return;
	}
		
	void dip_swDisable(
		/* 停用 DIP 封裝開關對匯流排的輸出 */
		void){
		dip_sw_chip_enable_bar = LOGIC_HIGH;
		return;
	}
		
	unsigned char dip_swGetValue(
		/* 取得 DIP 封裝開關的數值 */){
		unsigned char recieved;
		
		if(DIP_SW_ON == LOGIC_HIGH){
			recieved = DIP_SW;
		}else{
			/* OFF 時讀到 HIGH，ON 時讀到 LOW，把數值反向回來 */
				recieved = ~DIP_SW;
		}
			
		return recieved;
	}
	
	bit dip_swIsOn(
		/* 判斷特定開關是否為開 */
		bit which){
		if(which == DIP_SW_ON){
			return TRUE;
		}else{
			return FALSE;
		}
	}