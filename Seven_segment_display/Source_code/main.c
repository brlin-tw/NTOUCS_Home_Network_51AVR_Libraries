/* 
主程式
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
/* Standard io library definition? */
	#include <stdio.h>

/* Definitions of 8051 register constants
   　如果您要直接存取而非透過 Project_configurations/Ports_and_control_signals_* 來存取硬體的話需引入此檔案
	#include <REG51.h> */

/* Common definitions */
	#include "Project_configurations/Common_definitions.h"

/* Ports and control signals definitions */
	#include "Hardware_configurations/NTOUCS_Home_Network_51AVR.h"
		
/* 7 segment display procedures */
	#include "Seven_segment_display/Seven_segment_display.h"
	
/* flow of control libraries */
	#include "Flow_of_control/Delay.h"
	#include "Flow_of_control/Hang.h"
	
/*||||| 常數與巨集 | Constants & Macros |||||*/
	/* scan interval of 7 segment display  */
		#define DISPLAY_INTERVAL 1
		
/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* unit test procedures */
		void testSevenSegmentDisplayDecimal(void);
		void testSevenSegmentDisplayPoint(void);
		void testSevenSegmentDisplayOctal(void);
		
/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
/* 程式進入點 | Program entry point
   　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
void main(void){
	disableAllUnit();
	
	/* main loop */
	while(TRUE){
		testSevenSegmentDisplayDecimal();
		testSevenSegmentDisplayPoint();
		testSevenSegmentDisplayOctal();
		hangForever();
	}
	
	return;
}

void testSevenSegmentDisplayDecimal(void){
	unsigned int count = 0;
	unsigned int i;
	while(BTN_SW4 == LOGIC_HIGH){
		seven_segmentDisplayDecimal(count); 
	}
	seven_segmentDisable();
	delay(65535);
	for(; count <= 9999; ++count){
		if(BTN_SW4 == LOGIC_LOW){
			break;
		}
		for(i = 0; i < DISPLAY_INTERVAL; ++i){
			seven_segmentDisplayDecimal(count);
		}
	}
	seven_segmentDisable();
	
	return;
}

void testSevenSegmentDisplayPoint(void){
	unsigned char scan;
	delay(65535);
	while(BTN_SW4 == LOGIC_HIGH){
		for(scan = 0; scan < SEVEN_SEG_DIGIT_NO; ++scan){
			seven_segmentWritePositionFont(SEVEN_SEGMENT_FONT_POINT);			
			seven_segmentWritePosition(seven_segment_scan_position[scan]);
			delay(SEVEN_SEGMENT_SCAN_DELAY);
		}
	}
	seven_segmentDisable();
	return;
}

void testSevenSegmentDisplayOctal(void){
	unsigned int count = 0;
	unsigned int i;
	while(BTN_SW4 == LOGIC_HIGH){
		seven_segmentDisplayOctal(count); 
	}
	seven_segmentDisable();
	delay(65535);
	for(; count <= 65535; ++count){
		if(BTN_SW4 == LOGIC_LOW){
			break;
		}
		for(i = 0; i < DISPLAY_INTERVAL; ++i){
			seven_segmentDisplayOctal(count);
		}
	}
	seven_segmentDisable();	
	return;
}
