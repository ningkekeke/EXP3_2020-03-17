
// 3.16exp4.1.h : 3.16exp4.1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy316exp41App:
// �йش����ʵ�֣������ 3.16exp4.1.cpp
//

class CMy316exp41App : public CWinApp
{
public:
	CMy316exp41App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy316exp41App theApp;
