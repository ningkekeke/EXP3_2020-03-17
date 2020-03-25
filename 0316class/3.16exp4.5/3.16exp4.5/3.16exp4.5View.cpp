
// 3.16exp4.5View.cpp : CMy316exp45View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.16exp4.5.h"
#endif

#include "3.16exp4.5Doc.h"
#include "3.16exp4.5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy316exp45View

IMPLEMENT_DYNCREATE(CMy316exp45View, CView)

BEGIN_MESSAGE_MAP(CMy316exp45View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMy316exp45View ����/����

CMy316exp45View::CMy316exp45View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy316exp45View::~CMy316exp45View()
{
}

BOOL CMy316exp45View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy316exp45View ����

void CMy316exp45View::OnDraw(CDC* pDC)
{
	CMy316exp45Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(pDoc->m_crlRect);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy316exp45View ��ӡ

BOOL CMy316exp45View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy316exp45View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy316exp45View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy316exp45View ���

#ifdef _DEBUG
void CMy316exp45View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316exp45View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316exp45Doc* CMy316exp45View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316exp45Doc)));
	return (CMy316exp45Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316exp45View ��Ϣ�������


void CMy316exp45View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMy316exp45Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(&clientRec);
	switch(nChar)
	{
	case 'L':
		if (pDoc->m_crlRect.left > 0)
		{
			pDoc->m_crlRect.left -= 5;
			pDoc->m_crlRect.right -= 5;
		}
		break;
	case 'R':
		if (pDoc->m_crlRect.right <= (clientRec.right - clientRec.left))
		{
			pDoc->m_crlRect.left += 50;
			pDoc->m_crlRect.right += 50;
		}
		break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
