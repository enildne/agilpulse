#pragma once
/* 제어용 정의 */
//#define USE_ASRL_DEVICE						// ASRL Device Listing 여부
#define USE_GPIB_DEVICE

/* 창 및 버튼, 다이얼로그 사이즈 및 각각의 간격 */
#define MAIN_DLG_WIDTH			800				// MAIN WINDOW 크기
#define MAIN_DLG_HEIGHT			600

#define INTAB_BTN_START_X		10				// 버튼 시작위치
#define INTAB_BTN_START_Y		40

#define BUTTON_WIDTH			80				// 버튼 사이즈
#define BUTTON_HEIGHT			30

#define BUTTON_GAP				10				// 버튼 간격

#define DEVNAME_HEIGHT			24				// 장비 이름창 높이

#define DEVICE_LIST_WIDTH		400				// 장비 선택창 크기
#define DEVICE_LIST_HEIGHT		300

#define CONFIG_EXT				TEXT(".set")

/* 사용되는 스트링 */

#define		TAB1_DSP_NAME		"RT"
#define		TAB2_DSP_NAME		"주파수"
#define		TAB3_DSP_NAME		"Reserved"
#define		TAB4_DSP_NAME		"Reserved"

#define		TAB1_BTN1_NAME		"장비설정"
#define		TAB1_BTN2_NAME		"모델선택"
#define		TAB1_BTN3_NAME		"시작"
#define		TAB1_BTN4_NAME		"반복"
#define		TAB1_ST_DEVICE_NAME	"None"

#define		STR_DEVICE_LIST		"장비 리스트"
#define		NOTSELECT_CFG		"설정 파일이 선택되지 않았습니다."
#define		NOTSELECT_DEVICE	"장비가 선택되지 않았습니다."