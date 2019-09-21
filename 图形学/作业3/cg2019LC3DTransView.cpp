
// cg2019LC3DTransView.cpp : Ccg2019LC3DTransView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "cg2019LC3DTrans.h"
#endif

#include "gl\gl.h"
#include "gl\glu.h"

#include "cg2019LC3DTransDoc.h"
#include "cg2019LC3DTransView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ccg2019LC3DTransView

IMPLEMENT_DYNCREATE(Ccg2019LC3DTransView, CView)

BEGIN_MESSAGE_MAP(Ccg2019LC3DTransView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// Ccg2019LC3DTransView ����/����

Ccg2019LC3DTransView::Ccg2019LC3DTransView()
{
	// TODO: �ڴ˴���ӹ������

}

Ccg2019LC3DTransView::~Ccg2019LC3DTransView()
{
}

BOOL Ccg2019LC3DTransView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ccg2019LC3DTransView ����

void Ccg2019LC3DTransView::OnDraw(CDC* /*pDC*/)
{
	Ccg2019LC3DTransDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	DrawScene();
}


// Ccg2019LC3DTransView ��ӡ

BOOL Ccg2019LC3DTransView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Ccg2019LC3DTransView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Ccg2019LC3DTransView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Ccg2019LC3DTransView ���

#ifdef _DEBUG
void Ccg2019LC3DTransView::AssertValid() const
{
	CView::AssertValid();
}

void Ccg2019LC3DTransView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ccg2019LC3DTransDoc* Ccg2019LC3DTransView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ccg2019LC3DTransDoc)));
	return (Ccg2019LC3DTransDoc*)m_pDocument;
}
#endif //_DEBUG


// Ccg2019LC3DTransView ��Ϣ�������
BOOL Ccg2019LC3DTransView::bSetupPixelFormat()
{
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
		1,                              // version number
		PFD_DRAW_TO_WINDOW |            // support window
		PFD_SUPPORT_OPENGL |            // support OpenGL
		PFD_DOUBLEBUFFER,               // double buffered
		PFD_TYPE_RGBA,                  // RGBA type
		24,                             // 24-bit color depth
		0, 0, 0, 0, 0, 0,               // color bits ignored
		0,                              // no alpha buffer
		0,                              // shift bit ignored
		0,                              // no accumulation buffer
		0, 0, 0, 0,                     // accum bits ignored
		32,                             // 32-bit z-buffer
		0,                              // no stencil buffer
		0,                              // no auxiliary buffer
		PFD_MAIN_PLANE,                 // main layer
		0,                              // reserved
		0, 0, 0                         // layer masks ignored
	};
	int pixelformat;

	if ((pixelformat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0) {
		MessageBox(_T("ChoosePixelFormat failed"));
		return FALSE;
	}

	if (SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd) == FALSE) {
		MessageBox(_T("SetPixelFormat failed"));
		return FALSE;
	}

	return TRUE;
}



int Ccg2019LC3DTransView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	PIXELFORMATDESCRIPTOR pfd;
	int         n;
	HGLRC       hrc;
	GLfloat      fAspect;

	m_pDC = new CClientDC(this);

	ASSERT(m_pDC != NULL);

	if (!bSetupPixelFormat()) return 0;

	n = ::GetPixelFormat(m_pDC->GetSafeHdc());
	::DescribePixelFormat(m_pDC->GetSafeHdc(), n, sizeof(pfd), &pfd);

	//	CreateRGBPalette();

	hrc = wglCreateContext(m_pDC->GetSafeHdc());
	wglMakeCurrent(m_pDC->GetSafeHdc(), hrc);

	glClearDepth(100.0f);
	glShadeModel(GL_FLAT);
	glEnable(GL_NORMALIZE);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_AUTO_NORMAL);
	GetClientRect(&m_viewRect);

	if (!m_viewRect.bottom)	fAspect = 1.0f;
	else                    fAspect = (GLfloat)m_viewRect.right / m_viewRect.bottom;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, fAspect, 3.0f, 7.0f);
	glMatrixMode(GL_MODELVIEW);

	return 0;
}

void Ccg2019LC3DTransView::DrawScene()
{
	static BOOL bBusy = FALSE;
	Ccg2019LC3DTransDoc* pDoc = (Ccg2019LC3DTransDoc*)GetDocument();

	if (bBusy)	return;

	bBusy = TRUE;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(pDoc->m_translateVector[0],
		pDoc->m_translateVector[1],
		pDoc->m_translateVector[2]);
	glRotatef(pDoc->m_xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(pDoc->m_yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(pDoc->m_zAngle, 0.0f, 0.0f, 1.0f);
	glScalef(0.3f, 0.3f, 0.3f);   /* Make Scene Smaller Enough to Look */

	// Draw Space Axis
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);                  // X Axis 
	glVertex3f(6.0f, 0.0f, 0.0f);
	glVertex3f(-6.0f, 0.0f, 0.0f);
	glEnd();
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);                  // Y Axis 
	glVertex3f(0.0f, 6.0f, 0.0f);
	glVertex3f(0.0f, -6.0f, 0.0f);
	glEnd();
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);                  // Z Axis 
	glVertex3f(0.0f, 0.0f, 6.0f);
	glVertex3f(0.0f, 0.0f, -24.0f);
	glEnd();

	// Display BALL
	Object_p ballObject = &(pDoc->m_spaceObjects[BALL]);
	for (int i = 0; i < ballObject->polyCount; i++) {
		glColor3f(1.0f, 0.0f, 0.0f);
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < ballObject->objectSpace[i].polyCount; j++)
			glVertex3f(ballObject->objectSpace[i].polyObject[j].x,
				ballObject->objectSpace[i].polyObject[j].y,
				ballObject->objectSpace[i].polyObject[j].z);
		glEnd();
	}

	// Display CUBE
	Object_p cubeObject = &(pDoc->m_spaceObjects[CUBE]);
	for (int i = 0; i < cubeObject->polyCount; i++) {
		glColor3f(1.0f, 0.0f, 1.0f);
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < cubeObject->objectSpace[i].polyCount; j++)
			glVertex3f(cubeObject->objectSpace[i].polyObject[j].x,
				cubeObject->objectSpace[i].polyObject[j].y,
				cubeObject->objectSpace[i].polyObject[j].z);
		glEnd();
	}

	glPopMatrix();

	glFinish();
	SwapBuffers(wglGetCurrentDC());

	bBusy = FALSE;

	// Notify CCgTransControl can process the Project Result to PictureBox 'PROJECTPANE'
	//	pDoc->UpdateAllViews(this);
}


void Ccg2019LC3DTransView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	if ((m_viewRect.right != cx) || (m_viewRect.bottom != cy)) {
		
		glViewport(0, 0, cx, cy);

		//RedrawWindow();

		m_viewRect.right = cx;
		m_viewRect.bottom = cy;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLdouble)cx / cy, 3.0f, 7.0f);
		glMatrixMode(GL_MODELVIEW);
	}
}

