
// 3.16exp4.6View.cpp : CMy316exp46View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.16exp4.6.h"
#endif

#include "3.16exp4.6Doc.h"
#include "3.16exp4.6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy316exp46View

IMPLEMENT_DYNCREATE(CMy316exp46View, CView)

BEGIN_MESSAGE_MAP(CMy316exp46View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
END_MESSAGE_MAP()

// CMy316exp46View ����/����

CMy316exp46View::CMy316exp46View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy316exp46View::~CMy316exp46View()
{
}

BOOL CMy316exp46View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy316exp46View ����

void CMy316exp46View::OnDraw(CDC* pDC)
{
	CMy316exp46Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOut(20, 20, pDoc->m_pStr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy316exp46View ��ӡ

BOOL CMy316exp46View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy316exp46View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy316exp46View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy316exp46View ���

#ifdef _DEBUG
void CMy316exp46View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316exp46View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316exp46Doc* CMy316exp46View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316exp46Doc)));
	return (CMy316exp46Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316exp46View ��Ϣ�������


void CMy316exp46View::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);
	CMy316exp46Doc* pDoc = GetDocument();
	pDoc->m_pStr = "��������뽹��.";
	InvalidateRect(NULL, TRUE);
	// TODO: �ڴ˴������Ϣ����������
}


void CMy316exp46View::OnKillFocus(CWnd* pNewWnd)
{
	CView::OnKillFocus(pNewWnd);
	CMy316exp46Doc* pDoc = GetDocument();
	pDoc->m_pStr = "ʧȥ�����뽹��.";
	InvalidateRect(NULL, TRUE);
	// TODO: �ڴ˴������Ϣ����������
}
