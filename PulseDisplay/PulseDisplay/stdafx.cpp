// stdafx.cpp : ǥ�� ���� ������ �����ϴ� �ҽ� �����Դϴ�.
// PulseDisplay.pch�� �̸� �����ϵ� ����� �˴ϴ�.
// stdafx.obj�� �̸� �����ϵ� ���� ������ �����մϴ�.

#include "stdafx.h"
#include "strsafe.h"

void RTrace(TCHAR* szFormat, ...)
{
	TCHAR szTempBuf[2048] ;
	va_list vlMarker ;

	va_start(vlMarker,szFormat) ;
	StringCchVPrintf(szTempBuf, 2048, szFormat, vlMarker) ;
	va_end(vlMarker) ;

	OutputDebugString(szTempBuf) ;
}
