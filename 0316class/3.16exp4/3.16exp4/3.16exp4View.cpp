
// 3.16exp4View.cpp : CMy316exp4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy316exp4View 构造/析构

CMy316exp4View::CMy316exp4View()
{
	// TODO: 在此处添加构造代码

}

CMy316exp4View::~CMy316exp4View()
{
}

BOOL CMy316exp4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy316exp4View 绘制

void CMy316exp4View::OnDraw(CDC* pDC)
{
	CMy316exp4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return; 
	pDC->Rectangle(pDoc->m_tagRec);
}


// CMy316exp4View 打印

BOOL CMy316exp4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy316exp4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy316exp4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy316exp4View 诊断

#ifdef _DEBUG
void CMy316exp4View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316exp4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316exp4Doc* CMy316exp4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316exp4Doc)));
	return (CMy316exp4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316exp4View 消息处理程序


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
