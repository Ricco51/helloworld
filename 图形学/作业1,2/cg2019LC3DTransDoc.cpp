
// cg2019LC3DTransDoc.cpp : Ccg2019LC3DTransDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "cg2019LC3DTrans.h"
#endif

#include "cg2019LC3DTransDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Ccg2019LC3DTransDoc

IMPLEMENT_DYNCREATE(Ccg2019LC3DTransDoc, CDocument)

BEGIN_MESSAGE_MAP(Ccg2019LC3DTransDoc, CDocument)
END_MESSAGE_MAP()


// Ccg2019LC3DTransDoc ����/����

Ccg2019LC3DTransDoc::Ccg2019LC3DTransDoc()
{
	// TODO: �ڴ����һ���Թ������
	// Scene Translate and Rotate parameters.
	m_xAngle = 10.0f;
	m_yAngle = -40.0f;
	m_zAngle = 0.0f;
	m_translateVector[0] = -0.0f;
	m_translateVector[1] = -0.3f;
	m_translateVector[2] = -5.0f;

}

Ccg2019LC3DTransDoc::~Ccg2019LC3DTransDoc()
{
}

BOOL Ccg2019LC3DTransDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// Ccg2019LC3DTransDoc ���л�

void Ccg2019LC3DTransDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void Ccg2019LC3DTransDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void Ccg2019LC3DTransDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void Ccg2019LC3DTransDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Ccg2019LC3DTransDoc ���

#ifdef _DEBUG
void Ccg2019LC3DTransDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Ccg2019LC3DTransDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Ccg2019LC3DTransDoc ����
