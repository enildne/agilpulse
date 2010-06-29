// stdafx.cpp : 표준 포함 파일을 포함하는 소스 파일입니다.
// PulseDisplay.pch는 미리 컴파일된 헤더가 됩니다.
// stdafx.obj는 미리 컴파일된 형식 정보를 포함합니다.

#include "stdafx.h"
#include "DefineAndSize.h"

void RTrace(TCHAR* szFormat, ...)
{
#ifdef LOG_DEBUG
	char szTempBuf[2048] ;
	va_list vlMarker ;

	va_start(vlMarker,szFormat) ;
	vsprintf(szTempBuf,szFormat,vlMarker) ;
	va_end(vlMarker) ;

	OutputDebugString(szTempBuf) ;
#endif
}
