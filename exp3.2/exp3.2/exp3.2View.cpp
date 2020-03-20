
// exp3.2View.cpp : Cexp32View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp3.2.h"
#endif

#include "exp3.2Doc.h"
#include "exp3.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp32View

IMPLEMENT_DYNCREATE(Cexp32View, CView)

BEGIN_MESSAGE_MAP(Cexp32View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Cexp32View ����/����

Cexp32View::Cexp32View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp32View::~Cexp32View()
{
}

BOOL Cexp32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp32View ����

void Cexp32View::OnDraw(CDC* pDC)
{
	Cexp32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->c);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp32View ��ӡ

BOOL Cexp32View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp32View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp32View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp32View ���

#ifdef _DEBUG
void Cexp32View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp32Doc* Cexp32View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp32Doc)));
	return (Cexp32Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp32View ��Ϣ�������


void Cexp32View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Cexp32Doc* pDoc = GetDocument();
	CRect clientRec;
	GetClientRect(clientRec);
	switch (nChar)
	{
	case VK_LEFT:
		if (pDoc->c.left > 0)
		{
			pDoc->c.left -= 5;
			pDoc->c.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->c.right <= (clientRec.right - clientRec.left))
		{
			pDoc->c.left += 5;
			pDoc->c.right += 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->c.bottom <= clientRec.Height())
		{
			pDoc->c.top += 5;
			pDoc->c.bottom += 5;
		}
		break;
	case VK_UP:
		if (pDoc->c.top>0)
		{
			pDoc->c.top -= 5;
			pDoc->c.bottom -= 5;
		}
		break;
	case VK_HOME:
	{
		pDoc->c.left = 600; pDoc->c.top = 200;
		pDoc->c.right = 800; pDoc->c.bottom = 400;
	}
	break;
	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
