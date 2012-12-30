/* 
Interrupt_callbacks.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	/* 計時器／計數器相關定義
		#include "Timer_or_counter/Timer_or_counter.h" */
	
	/* 序列式 UART 介面相關定義
		#include "Serial_UART/Serial_UART.h" */
	
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	/* 外部中斷 callback 函式 */
		void cbExtInt0(void) interrupt 0{
			return;
		}
		
		void cbExtInt1(void) interrupt 2{
			return;
		}
		
	/* 計時器／計數器中斷 callback 函式 */
		void cbTimer0(void) interrupt 1{
			return;
		}
		
		void cbTimer1(void) interrupt 3{
			return;
		}
		
	/* 序列式 UART 介面中斷 callback 函式 */
		void cbSerialUART(void) interrupt 4{
			return;
		}
		