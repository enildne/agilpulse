// stdafx.cpp : ǥ�� ���� ������ �����ϴ� �ҽ� �����Դϴ�.
// PulseDisplay.pch�� �̸� �����ϵ� ����� �˴ϴ�.
// stdafx.obj�� �̸� �����ϵ� ���� ������ �����մϴ�.

#include "stdafx.h"

void RTrace(TCHAR* szFormat, ...)
{
	char szTempBuf[2048] ;
	va_list vlMarker ;

	va_start(vlMarker,szFormat) ;
	vsprintf(szTempBuf,szFormat,vlMarker) ;
	va_end(vlMarker) ;

	OutputDebugString(szTempBuf) ;
}
