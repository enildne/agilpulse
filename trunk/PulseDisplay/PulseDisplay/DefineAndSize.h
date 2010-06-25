#pragma once
/* 제어용 정의 */
//#define USE_ASRL_DEVICE						// ASRL Device Listing 여부
//#define		USE_GPIB_DEVICE
//#define		LOGIN_DLG							// Login Dlg 를 보일지 말지 결정(개발중에는 안보이도록)
//#define		SCREEN_MAX							// 화면 크기에 무조건 맞도록 수정.
//#define		USE_SAMPLE_FILE

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

#define		VERTICAL_GRID_COUNT			10
#define		HORIZONTAL_GRID_COUNT		8
#define		USE_8_GRID									// 실제 Data 는 10개중 8개까지의 그래프만 나온다

#define		CONFIG_EXT					TEXT(".set")

#define		MAX_GRAPH_VALUE				230.8
#define		MIN_GRAPH_VALUE				27.6
#define		VERTICAL_1_GRID_VALUE		25.4			// 180 - 53 / 5

#define		LOGIN_FILE_NAME				"ACCOUNT"


/* 사용되는 스트링 */

#define		MAIN_WINDOW_NAME			"PULSE DISPLAY"
#define		LOGIN_DLG_NAME				"Login"

#define		TAB1_DSP_NAME				"RT"
#define		TAB2_DSP_NAME				"주파수"
#define		TAB3_DSP_NAME				"Reserved"
#define		TAB4_DSP_NAME				"Reserved"

#define		TAB1_BTN1_NAME				"장비설정"
#define		TAB1_BTN2_NAME				"모델선택"
#define		TAB1_BTN3_NAME				"시작"
#define		TAB1_BTN4_NAME				"반복"
#define		TAB1_ST_DEVICE_NAME			"No device"

#define		STR_DEVICE_LIST				"장비 리스트"
#define		STR_SETTING_LIST			"설정파일 리스트"

#define		NOTSELECT_CFG				"설정 파일이 선택되지 않았습니다."
#define		STR_NO_SETTING_FILE			"설정 파일이 없습니다."

#define		NOTSELECT_DEVICE			"장비가 선택되지 않았습니다."
#define		DEVICE_CON_ERROE			"장비 연결이 실패했습니다."
#define		DEVICE_SET_SUCCESS			"장비 설정이 적용되었습니다."
#define		DEVICE_SET_FAILED			"장비 설정이 실패했습니다."

#define		LOGIN_STRING_NAME			"이름"
#define		LOGIN_STRING_PWD			"비밀번호"
#define		LOGIN_BTN					"로그인"
#define		INVALID_USER				"로그인 후 사용이 가능합니다."
#define		LOGIN_RD_USER				"사용자"
#define		LOGIN_RD_ADMIN				"관리자"
#define		NO_USER_ACCOUNT				"해당 유저정보가 없습니다."
#define		NO_USER_ACCOUNT_FILE		"유저정보 파일이 없습니다."
