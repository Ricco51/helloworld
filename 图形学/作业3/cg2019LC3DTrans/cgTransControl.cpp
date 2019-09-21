// cgTransControl.cpp : 实现文件
//

#include "stdafx.h"
#include "cg2019LC3DTrans.h"
#include "cgTransControl.h"

#include"cg2019LC3DTransDoc.h"


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
	ON_BN_CLICKED(IDC_TRANSMODE, &cgTransControl::OnClickedTransmode)
	ON_BN_CLICKED(IDC_XLEFT, &cgTransControl::OnClickedXleft)
	ON_BN_CLICKED(IDC_XRIGHT, &cgTransControl::OnClickedXright)
	ON_BN_CLICKED(IDC_YDOWN, &cgTransControl::OnClickedYdown)
	ON_BN_CLICKED(IDC_YUP, &cgTransControl::OnClickedYup)
	ON_BN_CLICKED(IDC_ZBACK, &cgTransControl::OnClickedZback)
	ON_BN_CLICKED(IDC_ZFRONT, &cgTransControl::OnClickedZfront)
END_MESSAGE_MAP()


// cgTransControl 诊断

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


// cgTransControl 消息处理程序
void cgTransControl::OnClickedXright()
{
	// TODO: 在此添加控件通知处理程序代码
	Ccg2019LC3DTransDoc* pDoc = (Ccg2019LC3DTransDoc*)GetDocument();

	if (pDoc->m_transMode == 0)
		pDoc->m_translateVector[0] += 0.1f;
	else
		pDoc->m_xAngle += 5.0f;

	pDoc->UpdateAllViews(this);
}


void cgTransControl::OnClickedXleft()
{
	// TODO: 在此添加控件通知处理程序代码
	Ccg2019LC3DTransDoc* pDoc = (Ccg2019LC3DTransDoc*)GetDocument();

	if (pDoc->m_transMode == 0)
		pDoc->m_translateVector[0] -= 0.1f;
	else
		pDoc->m_xAngle -= 5.0f;

	pDoc->UpdateAllViews(this);
}


void cgTransControl::OnClickedYup()
{
	// TODO: 在此添加控件通知处理程序代码
	Ccg2019LC3DTransDoc* pDoc = (Ccg2019LC3DTransDoc*)GetDocument();

	if (pDoc->m_transMode == 0)
		pDoc->m_translateVector[1] += 0.1f;
	else
		pDoc->m_yAngle += 5.0f;

	pDoc->UpdateAllViews(this);
}


void cgTransControl::OnClickedYdown()
{
	// TODO: 在此添加控件通知处理程序代码
	Ccg2019LC3DTransDoc* pDoc = (Ccg2019LC3DTransDoc*)GetDocument();

	if (pDoc->m_transMode == 0)
		pDoc->m_translateVector[1] -= 0.1f;
	else
		pDoc->m_yAngle -= 5.0f;

	pDoc->UpdateAllViews(this);
}


void cgTransControl::OnClickedZfront()
{
	// TODO: 在此添加控件通知处理程序代码
	Ccg2019LC3DTransDoc* pDoc = (Ccg2019LC3DTransDoc*)GetDocument();

	if (pDoc->m_transMode == 0)
		pDoc->m_translateVector[2] += 0.1f;
	else
		pDoc->m_zAngle += 5.0f;

	pDoc->UpdateAllViews(this);
}


void cgTransControl::OnClickedZback()
{
	// TODO: 在此添加控件通知处理程序代码
	Ccg2019LC3DTransDoc* pDoc = (Ccg2019LC3DTransDoc*)GetDocument();

	if (pDoc->m_transMode == 0)
		pDoc->m_translateVector[2] -= 0.1f;
	else
		pDoc->m_zAngle -= 5.0f;

	pDoc->UpdateAllViews(this);
}


void cgTransControl::OnClickedTransmode()
{
	CButton *pButton = (CButton *)GetDlgItem(IDC_TRANSMODE);
	Ccg2019LC3DTransDoc* pDoc = (Ccg2019LC3DTransDoc*)GetDocument();

	pDoc->m_transMode++;
	if (pDoc->m_transMode > 1) pDoc->m_transMode = 0;

	if (pDoc->m_transMode == 0)  pButton->SetWindowText(_T("Translate"));
	else                                        pButton->SetWindowText(_T("Rotate"));
}
