
// 3.16exp4.3.h : 3.16exp4.3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy316exp43App:
// �йش����ʵ�֣������ 3.16exp4.3.cpp
//

class CMy316exp43App : public CWinApp
{
public:
	CMy316exp43App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy316exp43App theApp;
