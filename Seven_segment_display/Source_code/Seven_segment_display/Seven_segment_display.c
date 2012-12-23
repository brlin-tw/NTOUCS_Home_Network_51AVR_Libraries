/* 
Seven_segment_display.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	/* ports definitions */
		#include "../Project_configurations/Configuration_NTOUCS_HN_Winbond_W78E58B.h"
	
	/* for logic signals */
		#include "../Project_configurations/Common_definitions.h"
		
	/* for function definitions */
		#include "Seven_segment_display.h"
		
	/* for delay procedures */
		#include "../Flow_of_control/Delay.h"
		
/*||||| 常數與巨集 | Constants & Macros |||||*/
	/* 數位掃描電路延遲時間
	   　數位的掃描電路切換會有延遲，造成下一個數位的字型發光在前一個數位的殘影
		 　所以 seven_segmentWritePosition() 呼叫完要等一下
		 　估計時間
		 　　delay(100~400) */
		#define SEVEN_SEGMENT_SCAN_DELAY 400
/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/
	extern code const unsigned char seven_segment_font_digits[10]
		/* ７段顯示器的數字字型（1 代表亮） */ = {
		0x3F
			/* 0: 0011_1111b */, 
		0x06
			/* 1: 0000_0110b */, 
		0x5B
			/* 2: 0101_1011b */, 
		0x4F
			/* 3: 0100_1111b */, 
		0x66
			/* 4: 0110_0110b */, 
		0x6D
			/* 5: 0110_1101b */, 
		0x7D
			/* 6: 0111_1101b */, 
		0x07
			/* 7: 0000_0111b */, 
		0x7F
			/* 8: 0111_1111b */, 
		0x6F
			/* 9: 0110_1111b */
	};
		
	extern code const unsigned char 
		seven_segment_scan_position[4] = {
			/* 數位的對應是由高位到低位... */
			0x08/* 1000b */, 
			0x04/* 0100b */, 
			0x02/* 0010b */, 
			0x01/* 0001b */
	};
	
/*||||| 主要程式碼 | Main Code |||||*/
	void seven_segmentDisable(
		/* 關閉 7 段顯示器的顯示 */
		void){
		SEVEN_SEG = 0x00;
		/* 關閉數位顯示開關 */
			seven_seg_latch_position_enable = LOGIC_HIGH;
			seven_seg_latch_position_enable = LOGIC_LOW;
			delay(400);
		/* 清空數位字型內容 */
			seven_seg_latch_font_enable = LOGIC_HIGH;
			seven_seg_latch_font_enable = LOGIC_LOW;
		return;
	}
	
	void seven_segmentWritePositionFont(
		unsigned char font){
		SEVEN_SEG = ~font;
		seven_seg_latch_font_enable = LOGIC_HIGH;
		seven_seg_latch_font_enable = LOGIC_LOW;
		return;
	}
	
	void seven_segmentWritePosition(
		unsigned char position
			/* current max 4 bit defined, from 0x01 to 0x08 */){
		SEVEN_SEG = position;
		seven_seg_latch_position_enable = LOGIC_HIGH;
		seven_seg_latch_position_enable = LOGIC_LOW;
		return;
	}
	
	void seven_segmentDisplayValue4digit(
		unsigned int value
			/* 顯示的數值(0000~9999) */){
		unsigned char i;
		unsigned char digit;
			
		/* 每個數位掃描一遍 */
			for(i = 0; i < 4; ++i){
				digit = value % 10;
				
				seven_segmentWritePositionFont(seven_segment_font_digits[digit]);
				seven_segmentWritePosition(seven_segment_scan_position[i]);
				/* 等數位掃描電路切換 */
					delay(SEVEN_SEGMENT_SCAN_DELAY);
				
				value /= 10;
			}
			
		return;
	}
		