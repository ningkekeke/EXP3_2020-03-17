
// 3.16exp4.3View.cpp : CMy316exp43View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.16exp4.3.h"
#endif

#include "3.16exp4.3Doc.h"
#include "3.16exp4.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy316exp43View

IMPLEMENT_DYNCREATE(CMy316exp43View, CView)

BEGIN_MESSAGE_MAP(CMy316exp43View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy316exp43View ����/����

CMy316exp43View::CMy316exp43View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy316exp43View::~CMy316exp43View()
{
}

BOOL CMy316exp43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy316exp43View ����

void CMy316exp43View::OnDraw(CDC* pDC)
{
	CMy316exp43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy316exp43View ��ӡ

BOOL CMy316exp43View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy316exp43View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy316exp43View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy316exp43View ���

#ifdef _DEBUG
void CMy316exp43View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316exp43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316exp43Doc* CMy316exp43View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316exp43Doc)));
	return (CMy316exp43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316exp43View ��Ϣ�������


void CMy316exp43View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void CMy316exp43View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void CMy316exp43View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	char str[50];
	CClientDC dc(this);
	CString s, S;
	s.Format(_T("WM_MOUSEMOVE"));
	S.Format(_T("X: %d    Y:%d    "), point.x, point.y);
	dc.TextOutW(20, 20,s);
	dc.TextOutW(200, 20, S);
	CView::OnMouseMove(nFlags, point);
}
