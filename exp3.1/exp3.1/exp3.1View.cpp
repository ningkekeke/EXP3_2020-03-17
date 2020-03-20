
// exp3.1View.cpp : Cexp31View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "exp3.1.h"
#endif

#include "exp3.1Doc.h"
#include "exp3.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp31View

IMPLEMENT_DYNCREATE(Cexp31View, CView)

BEGIN_MESSAGE_MAP(Cexp31View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cexp31View ����/����

Cexp31View::Cexp31View()
{
	// TODO: �ڴ˴���ӹ������

}

Cexp31View::~Cexp31View()
{
}

BOOL Cexp31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cexp31View ����

void Cexp31View::OnDraw(CDC* /*pDC*/)
{
	Cexp31Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cexp31View ��ӡ

BOOL Cexp31View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cexp31View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cexp31View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cexp31View ���

#ifdef _DEBUG
void Cexp31View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp31View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp31Doc* Cexp31View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp31Doc)));
	return (Cexp31Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp31View ��Ϣ�������


void Cexp31View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 1;
	x = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void Cexp31View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	int f = 0;
	f += (point.x - x) / count;
	CString s, S;
	s.Format(_T("MouseMove:%d"), count);
	S.Format(_T("ƽ��ÿ�κ����ƶ�������:%d"), f);
	dc.TextOutW(200, 200, s);
	dc.TextOutW(200, 300, S);
	CView::OnLButtonUp(nFlags, point);
}


void Cexp31View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag)
		count++;
	CView::OnMouseMove(nFlags, point);
}
