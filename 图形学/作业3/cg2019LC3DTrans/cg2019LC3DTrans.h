
// cg2019LC3DTrans.h : cg2019LC3DTrans Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Ccg2019LC3DTransApp:
// �йش����ʵ�֣������ cg2019LC3DTrans.cpp
//

class Ccg2019LC3DTransApp : public CWinAppEx
{
public:
	Ccg2019LC3DTransApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ccg2019LC3DTransApp theApp;
