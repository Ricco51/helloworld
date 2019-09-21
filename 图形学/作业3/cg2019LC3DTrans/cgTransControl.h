#pragma once



// cgTransControl 窗体视图

class cgTransControl : public CFormView
{
	DECLARE_DYNCREATE(cgTransControl)

protected:
	cgTransControl();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedTransmode();
	afx_msg void OnClickedXleft();
	afx_msg void OnClickedXright();
	afx_msg void OnClickedYdown();
	afx_msg void OnClickedYup();
	afx_msg void OnClickedZback();
	afx_msg void OnClickedZfront();
};


