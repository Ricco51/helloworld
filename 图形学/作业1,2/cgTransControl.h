#pragma once



// cgTransControl ������ͼ

class cgTransControl : public CFormView
{
	DECLARE_DYNCREATE(cgTransControl)

protected:
	cgTransControl();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~cgTransControl();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRANSCONTROL };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};


