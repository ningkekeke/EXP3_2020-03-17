
// 3.16exp4.2View.cpp : CMy316exp42View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "3.16exp4.2.h"
#endif

#include "3.16exp4.2Doc.h"
#include "3.16exp4.2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy316exp42View

IMPLEMENT_DYNCREATE(CMy316exp42View, CView)

BEGIN_MESSAGE_MAP(CMy316exp42View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy316exp42View ����/����

CMy316exp42View::CMy316exp42View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy316exp42View::~CMy316exp42View()
{
}

BOOL CMy316exp42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy316exp42View ����

void CMy316exp42View::OnDraw(CDC* pDC)
{
	CMy316exp42Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy316exp42View ��ӡ

BOOL CMy316exp42View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy316exp42View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy316exp42View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy316exp42View ���

#ifdef _DEBUG
void CMy316exp42View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316exp42View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316exp42Doc* CMy316exp42View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316exp42Doc)));
	return (CMy316exp42Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316exp42View ��Ϣ�������
