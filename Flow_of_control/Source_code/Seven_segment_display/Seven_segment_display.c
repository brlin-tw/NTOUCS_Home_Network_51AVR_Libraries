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

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/
	extern code const unsigned char seven_segment_font_digits[16]
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
			/* 9: 0110_1111b */, 
		0x77
			/* A: 0111_0111b */, 
		0x7C
			/* b: 0111_1100b */, 
		0x39
			/* C: 0011_1001b */, 
		0x5E
			/* d: 0101_1110b */, 
		0x79
			/* E: 0111_1001b */, 
		0x71
			/* F: 0111_0001b */		
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
		seven_seg = 0x00;
		/* 關閉數位顯示開關 */
			seven_seg_latch_position_enable = LOGIC_HIGH;
			seven_seg_latch_position_enable = LOGIC_LOW;
			delay(SEVEN_SEGMENT_SCAN_DELAY);
		/* 清空數位字型內容 */
			seven_seg_latch_font_enable = LOGIC_HIGH;
			seven_seg_latch_font_enable = LOGIC_LOW;
		return;
	}
	
	void seven_segmentWritePositionFont(
		unsigned char font){
		seven_seg = ~font;
		seven_seg_latch_font_enable = LOGIC_HIGH;
		seven_seg_latch_font_enable = LOGIC_LOW;
		return;
	}
	
	void seven_segmentWritePosition(
		unsigned char position
			/* current max 4 bit defined, from 0x01 to 0x08 */){
		seven_seg = position;
		seven_seg_latch_position_enable = LOGIC_HIGH;
		seven_seg_latch_position_enable = LOGIC_LOW;
		return;
	}
	
	void seven_segmentDisplayDecimal(
		unsigned int value
			/* 顯示的數值(0 ~ power(10, SEVEN_SEG_DIGIT_NO) - 1 */){
		unsigned char i;
		unsigned char digit;
			
		/* 每個數位掃描一遍 */
			for(i = 0; i < SEVEN_SEG_DIGIT_NO; ++i){
				digit = value % 10;
				
				seven_segmentWritePositionFont(seven_segment_font_digits[digit]);
				seven_segmentWritePosition(seven_segment_scan_position[i]);
				/* 等數位掃描電路切換 */
					delay(SEVEN_SEGMENT_SCAN_DELAY);
				
				value /= 10;
			}
			
		return;
	}
	
	void seven_segmentDisplayOctal(
		unsigned int value
			/* 顯示的數值(0 ~ power(16, SEVEN_SEG_DIGIT_NO) - 1 */){
		unsigned char i;
		unsigned char digit;
			
		/* 每個數位掃描一遍 */
			for(i = 0; i < SEVEN_SEG_DIGIT_NO; ++i){
				digit = value % 16;
				
				seven_segmentWritePositionFont(seven_segment_font_digits[digit]);
				seven_segmentWritePosition(seven_segment_scan_position[i]);
				/* 等數位掃描電路切換 */
					delay(SEVEN_SEGMENT_SCAN_DELAY);
				
				value /= 16;
			}
			
		return;
	}