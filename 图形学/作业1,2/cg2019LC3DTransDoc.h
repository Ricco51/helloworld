
// cg2019LC3DTransDoc.h : Ccg2019LC3DTransDoc ��Ľӿ�
//


#pragma once


class Ccg2019LC3DTransDoc : public CDocument
{
protected: // �������л�����
	Ccg2019LC3DTransDoc();
	DECLARE_DYNCREATE(Ccg2019LC3DTransDoc)

// ����
public:
	float m_translateVector[3];               // Scene Translation parameters.
	float m_xAngle, m_yAngle, m_zAngle;      // Scene Rotation parameters.

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Ccg2019LC3DTransDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
