
// cg2019LC3DTransDoc.h : Ccg2019LC3DTransDoc 类的接口
//


#pragma once


class Ccg2019LC3DTransDoc : public CDocument
{
protected: // 仅从序列化创建
	Ccg2019LC3DTransDoc();
	DECLARE_DYNCREATE(Ccg2019LC3DTransDoc)

// 特性
public:
	float m_translateVector[3];               // Scene Translation parameters.
	float m_xAngle, m_yAngle, m_zAngle;      // Scene Rotation parameters.

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~Ccg2019LC3DTransDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
