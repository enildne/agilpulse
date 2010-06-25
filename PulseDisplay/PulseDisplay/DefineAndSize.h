#pragma once
#include "Strings.h"

/* 제어용 정의 */
//#define USE_ASRL_DEVICE						// ASRL Device Listing 여부
//#define		USE_GPIB_DEVICE
//#define		LOGIN_DLG							// Login Dlg 를 보일지 말지 결정(개발중에는 안보이도록)
#define		LIMIT_SCREEN_SIZE					// 화면 크기에 무조건 맞도록 수정.
//#define		USE_SAMPLE_FILE
//#define		MAKE_SAMPLE_FILE

/* 창 및 버튼, 다이얼로그 사이즈 및 각각의 간격 */
#define		MAIN_DLG_WIDTH				1024			// MAIN WINDOW 크기
#define		MAIN_DLG_HEIGHT				768

#define		TAB_WND_RATIO				0.7				// MAIN WINDOW 대비 TAB Window 의 비율

#define		INTAB_BTN_START_X			10				// 버튼 시작위치
#define		INTAB_BTN_START_Y			40

#define		BUTTON_WIDTH				200				// 버튼 사이즈
#define		BUTTON_HEIGHT				60

#define		BUTTON_GAP					10				// 버튼 간격

#define		DEVNAME_HEIGHT				24				// 장비 이름창 높이
#define		DEVICE_LIST_WIDTH			400				// 장비 선택창 크기
#define		DEVICE_LIST_HEIGHT			300

#define		SETTING_LIST_WIDTH			400				// Setting 선택창 크기
#define		SETTING_LIST_HEIGHT			300

#define		VALUE_COUNT					2500			// 한번의 트랜잭션에 나오는 Data의 양
#define		MAX_INPUT_VALUE				200				// 그래프 화면 높이(228 - 28)
#define		MINUS_1_LEVEL				28

#define		DRAW_TOP_PAD				5
#define		DRAW_BOTTOM_PAD				5
#define		DRAW_LEFT_PAD				5
#define		DRAW_RIGHT_PAD				5

#define		VERTICAL_GRID_COUNT			10
#define		HORIZONTAL_GRID_COUNT		8

#define		CONFIG_EXT					TEXT(".set")
#define		LOGIN_FILE_NAME				"ACCOUNT"

#define		GRAPH_PEN_WIDTH				3				// GRAPH 를 그리는 PEN 의 두께

#define		START_VOLTAGE_1				320				// 1 Volt 찾기 시작하는 Data 위치 2500 중
#define		RINGDOWN_START				320				// 
#define		RINGDOWN_END				1000			// 

#define		MAX_REPEAT_PER_TEST			5
#define		RT_TEST_FAIL_LOW			128
#define		RT_TEST_FAIL_HIGH			203
#define		RT_TEST_LOW_POSITION		1250
#define		RT_TEST_HIGH_POSITION		250