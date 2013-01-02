/* 
ADC.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	#include "../Project_configurations/Common_definitions.h"
		/* for LOGIC signal definitions */
	
	#include "../Hardware_configurations/NTOUCS_Home_Network_51AVR.h"
		/* for port and signal definitions */
		
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/
	
/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	void adcStartConvert(
		/* 讓 ADC 開始進行轉換的子程式
			 　ADC 於 free running 模式需要有一段 
					 chip_select_bar HIGH->LOW 
					 write_bar HIGH->LOW->HIGH
					 chip_select_bar LOW->HIGH
				 才會開始轉換（資料文件 P.18） */ 
		void){
		adc_read_bar = adc_chip_select_bar = LOGIC_LOW;
		adc_write_bar = LOGIC_HIGH;
		adc_write_bar = LOGIC_LOW;
		adc_write_bar = LOGIC_HIGH;
		adc_read_bar = adc_chip_select_bar = LOGIC_HIGH;
		return;
	}
	
	unsigned char adcGetValue(
		/* 獲取 ADC 的數值 */
		void){
		unsigned char recieve;
			
		/* Issue #8 一定要先洗匯流排，原因不明 */
		ADC = 0xFF;
			
		adc_read_bar = adc_chip_select_bar = LOGIC_LOW;
		recieve = ADC;
		adc_read_bar = adc_chip_select_bar = LOGIC_HIGH;
		return recieve;
	}