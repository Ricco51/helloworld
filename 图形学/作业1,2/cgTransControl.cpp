// cgTransControl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "cg2019LC3DTrans.h"
#include "cgTransControl.h"


// cgTransControl

IMPLEMENT_DYNCREATE(cgTransControl, CFormView)

cgTransControl::cgTransControl()
	: CFormView(IDD_TRANSCONTROL)
{

}

cgTransControl::~cgTransControl()
{
}

void cgTransControl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(cgTransControl, CFormView)
END_MESSAGE_MAP()


// cgTransControl ���

#ifdef _DEBUG
void cgTransControl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void cgTransControl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// cgTransControl ��Ϣ�������
