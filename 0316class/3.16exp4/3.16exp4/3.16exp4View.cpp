
// 3.16exp4View.cpp : CMy316exp4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.16exp4.h"
#endif

#include "3.16exp4Doc.h"
#include "3.16exp4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy316exp4View

IMPLEMENT_DYNCREATE(CMy316exp4View, CView)

BEGIN_MESSAGE_MAP(CMy316exp4View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy316exp4View ����/����

CMy316exp4View::CMy316exp4View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy316exp4View::~CMy316exp4View()
{
}

BOOL CMy316exp4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy316exp4View ����

void CMy316exp4View::OnDraw(CDC* pDC)
{
	CMy316exp4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return; 
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMy316exp4View ��ӡ

BOOL CMy316exp4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy316exp4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy316exp4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy316exp4View ���

#ifdef _DEBUG
void CMy316exp4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316exp4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316exp4Doc* CMy316exp4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316exp4Doc)));
	return (CMy316exp4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316exp4View ��Ϣ�������


void CMy316exp4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMy316exp4Doc* pDoc = GetDocument();
	if (nFlags&MK_SHIFT)
	{
		pDoc->m_tagRec.left = 30;
		pDoc->m_tagRec.top =30 ;
		pDoc->m_tagRec.right =350 ;
		pDoc->m_tagRec.bottom = 300;
	}
	else
	{
		pDoc->m_tagRec.left = point.x;
		pDoc->m_tagRec. top=point.y ;
		pDoc->m_tagRec.right =point.x+320 ;
		pDoc->m_tagRec.bottom =point.y+270 ;

	}
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
