
// 3.16exp4.1View.cpp : CMy316exp41View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.16exp4.1.h"
#endif

#include "3.16exp4.1Doc.h"
#include "3.16exp4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy316exp41View

IMPLEMENT_DYNCREATE(CMy316exp41View, CView)

BEGIN_MESSAGE_MAP(CMy316exp41View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy316exp41View ����/����

CMy316exp41View::CMy316exp41View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy316exp41View::~CMy316exp41View()
{
}

BOOL CMy316exp41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy316exp41View ����

void CMy316exp41View::OnDraw(CDC* pDC)
{
	CMy316exp41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPoint point(30, 30);//�̶���
	pDC->MoveTo(point);
	pDC->LineTo(pDoc->m_point);
}


// CMy316exp41View ��ӡ

BOOL CMy316exp41View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy316exp41View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy316exp41View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy316exp41View ���

#ifdef _DEBUG
void CMy316exp41View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316exp41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316exp41Doc* CMy316exp41View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316exp41Doc)));
	return (CMy316exp41Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316exp41View ��Ϣ�������


void CMy316exp41View::OnMouseMove(UINT nFlags, CPoint point)
{
	CMy316exp41Doc* pDoc = GetDocument();
	pDoc->m_point = point; //��귢���ĵ� �����ĵ�������ĵ�
	InvalidateRect(NULL, FALSE);
	CView::OnMouseMove(nFlags, point);
}
