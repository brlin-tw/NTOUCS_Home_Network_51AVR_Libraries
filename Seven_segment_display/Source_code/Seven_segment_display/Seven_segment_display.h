/* Seven_segment_display.h
程式名稱 | Program name
	7 段顯示器控制函式庫
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	7 段顯示器控制函式庫 is part of NTOUCS_Home_Network_W78E58B_board_libraries
	NTOUCS_Home_Network_W78E58B_board_libraries is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	NTOUCS_Home_Network_W78E58B_board_libraries is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with NTOUCS_Home_Network_W78E58B_board_libraries.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef SEVEN_SEGMENT_DISPLAY_H_INCLUDED
	#define SEVEN_SEGMENT_DISPLAY_H_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/

	/*||||| 常數與巨集 | Constants & Macros |||||*/
		/* used in seven_segmentWritePosition() */
			#define SEVEN_SEGMENT_POSITION_ALL 0x0f
			#define SEVEN_SEGMENT_POSITION_NONE 0x00
		
		/* position fonts */
			#define SEVEN_SEGMENT_FONT_ALL 0xFF
			/* (decimal) point
			   　1000_0000b */
				#define SEVEN_SEGMENT_FONT_POINT 0x80
			
	/* 數位掃描電路延遲時間
	   　數位的掃描電路切換會有延遲，造成下一個數位的字型發光在前一個數位的殘影
		 　所以 seven_segmentWritePosition() 呼叫完要等一下
		 　估計時間
		 　　delay(100~400) */
		#define SEVEN_SEGMENT_SCAN_DELAY 400
	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/
		void seven_segmentDisable(
			/* 關閉 7 段顯示器的顯示 */
			void
		);
			
		void seven_segmentWritePositionFont(
			unsigned char font
		);
		
		void seven_segmentWritePosition(
			unsigned char position
				/* current max 4 bit defined, from 0x01 to 0x08 */
		);
					
		void seven_segmentDisplayDecimal(
			unsigned int value
				/* 顯示的數值(0 ~ power(10, SEVEN_SEG_DIGIT_NO) - 1
    			 不過目前的實作只支持到 4 位元 */
		);

		void seven_segmentDisplayOctal(
			unsigned int value
				/* 顯示的數值(0 ~ power(16, SEVEN_SEG_DIGIT_NO) - 1
				   不過目前的實作只支持到 4 位元 */
		);
		
	/*||||| 全域變數 | Global Variables |||||*/
		/* 數字字型 */
			extern code const unsigned char seven_segment_font_digits[16];
		/* 掃描位置 */
			extern code const unsigned char seven_segment_scan_position[4];
	#ifdef __cplusplus
		}
	#endif
#endif /* SEVEN_SEGMENT_DISPLAY_H_INCLUDED */
