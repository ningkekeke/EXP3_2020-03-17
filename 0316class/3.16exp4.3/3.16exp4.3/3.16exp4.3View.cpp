
// 3.16exp4.3View.cpp : CMy316exp43View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy316exp43View 构造/析构

CMy316exp43View::CMy316exp43View()
{
	// TODO: 在此处添加构造代码

}

CMy316exp43View::~CMy316exp43View()
{
}

BOOL CMy316exp43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy316exp43View 绘制

void CMy316exp43View::OnDraw(CDC* pDC)
{
	CMy316exp43Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy316exp43View 打印

BOOL CMy316exp43View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy316exp43View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy316exp43View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy316exp43View 诊断

#ifdef _DEBUG
void CMy316exp43View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316exp43View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316exp43Doc* CMy316exp43View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316exp43Doc)));
	return (CMy316exp43Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316exp43View 消息处理程序


void CMy316exp43View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	CView::OnLButtonDown(nFlags, point);
}


void CMy316exp43View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void CMy316exp43View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	char str[50];
	CClientDC dc(this);
	CString s, S;
	s.Format(_T("WM_MOUSEMOVE"));
	S.Format(_T("X: %d    Y:%d    "), point.x, point.y);
	dc.TextOutW(20, 20,s);
	dc.TextOutW(200, 20, S);
	CView::OnMouseMove(nFlags, point);
}
