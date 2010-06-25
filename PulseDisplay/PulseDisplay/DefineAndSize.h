#pragma once
#include "Strings.h"

/* 제어용 정의 */
//#define USE_ASRL_DEVICE						// ASRL Device Listing 여부
//#define		USE_GPIB_DEVICE
//#define		LOGIN_DLG							// Login Dlg 를 보일지 말지 결정(개발중에는 안보이도록)
//#define		SCREEN_MAX							// 화면 크기에 무조건 맞도록 수정.
//#define		USE_SAMPLE_FILE
#define		MAKE_SAMPLE_FILE

/* 창 및 버튼, 다이얼로그 사이즈 및 각각의 간격 */
#define		MAIN_DLG_WIDTH				800				// MAIN WINDOW 크기
#define		MAIN_DLG_HEIGHT				600

#define		INTAB_BTN_START_X			10				// 버튼 시작위치
#define		INTAB_BTN_START_Y			40

#define		BUTTON_WIDTH				80				// 버튼 사이즈
#define		BUTTON_HEIGHT				60

#define		BUTTON_GAP					10				// 버튼 간격

#define		DEVNAME_HEIGHT				24				// 장비 이름창 높이

#define		DEVICE_LIST_WIDTH			400				// 장비 선택창 크기
#define		DEVICE_LIST_HEIGHT			300

#define		SETTING_LIST_WIDTH			400				// Setting 선택창 크기
#define		SETTING_LIST_HEIGHT			300

#define		VALUE_COUNT					2500			// 한번의 트랜잭션에 나오는 Data의 양

#define		DRAW_TOP_PAD				5				// Grpah 화면의 상단 Padding
#define		DRAW_BOTTOM_PAD				5
#define		DRAW_LEFT_PAD				5
#define		DRAW_RIGHT_PAD				5

#define		VERTICAL_GRID_COUNT			8
#define		HORIZONTAL_GRID_COUNT		8
//#define		USE_8_GRID									// 실제 Data 는 10개중 8개까지의 그래프만 나온다

#define		CONFIG_EXT					TEXT(".set")

#define		MAX_GRAPH_VALUE				228
#define		MIN_GRAPH_VALUE				28
#define		VERTICAL_1_GRID_VALUE		25				// 180 - 53 / 5

#define		LOGIN_FILE_NAME				"ACCOUNT"
