#pragma once
/* ����� ���� */
//#define USE_ASRL_DEVICE						// ASRL Device Listing ����
#define		USE_GPIB_DEVICE

/* â �� ��ư, ���̾�α� ������ �� ������ ���� */
#define		MAIN_DLG_WIDTH				640				// MAIN WINDOW ũ��
#define		MAIN_DLG_HEIGHT				480

#define		INTAB_BTN_START_X			10				// ��ư ������ġ
#define		INTAB_BTN_START_Y			40

#define		BUTTON_WIDTH				80				// ��ư ������
#define		BUTTON_HEIGHT				30

#define		BUTTON_GAP					10				// ��ư ����

#define		DEVNAME_HEIGHT				24				// ��� �̸�â ����

#define		DEVICE_LIST_WIDTH			400				// ��� ����â ũ��
#define		DEVICE_LIST_HEIGHT			300

#define		VALUE_COUNT					2500			// �ѹ��� Ʈ����ǿ� ������ Data�� ��

#define		CONFIG_EXT					TEXT(".set")

/* ���Ǵ� ��Ʈ�� */

#define		MAIN_WINDOW_NAME			"PULSE DISPLAY"
#define		LOGIN_DLG_NAME				"Login"

#define		TAB1_DSP_NAME				"RT"
#define		TAB2_DSP_NAME				"���ļ�"
#define		TAB3_DSP_NAME				"Reserved"
#define		TAB4_DSP_NAME				"Reserved"

#define		TAB1_BTN1_NAME				"�����"
#define		TAB1_BTN2_NAME				"�𵨼���"
#define		TAB1_BTN3_NAME				"����"
#define		TAB1_BTN4_NAME				"�ݺ�"
#define		TAB1_ST_DEVICE_NAME			"No device"

#define		STR_DEVICE_LIST				"��� ����Ʈ"
#define		NOTSELECT_CFG				"���� ������ ���õ��� �ʾҽ��ϴ�."
#define		NOTSELECT_DEVICE			"��� ���õ��� �ʾҽ��ϴ�."
#define		DEVICE_CON_ERROE			"��� ������ �����߽��ϴ�."

#define		LOGIN_STRING_NAME			"�̸�"
#define		LOGIN_STRING_PWD			"��й�ȣ"
#define		LOGIN_BTN					"�α���"
#define		INVALID_USER				"�α��� �� ����� �����մϴ�."
#define		LOGIN_RD_USER				"�����"
#define		LOGIN_RD_ADMIN				"������"