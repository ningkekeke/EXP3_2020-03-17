
// 3.16exp4.6View.cpp : CMy316exp46View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
END_MESSAGE_MAP()

// CMy316exp46View 构造/析构

CMy316exp46View::CMy316exp46View()
{
	// TODO: 在此处添加构造代码

}

CMy316exp46View::~CMy316exp46View()
{
}

BOOL CMy316exp46View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy316exp46View 绘制

void CMy316exp46View::OnDraw(CDC* pDC)
{
	CMy316exp46Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOut(20, 20, pDoc->m_pStr);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy316exp46View 打印

BOOL CMy316exp46View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy316exp46View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy316exp46View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy316exp46View 诊断

#ifdef _DEBUG
void CMy316exp46View::AssertValid() const
{
	CView::AssertValid();
}

void CMy316exp46View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy316exp46Doc* CMy316exp46View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy316exp46Doc)));
	return (CMy316exp46Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy316exp46View 消息处理程序


void CMy316exp46View::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);
	CMy316exp46Doc* pDoc = GetDocument();
	pDoc->m_pStr = "获得了输入焦点.";
	InvalidateRect(NULL, TRUE);
	// TODO: 在此处添加消息处理程序代码
}


void CMy316exp46View::OnKillFocus(CWnd* pNewWnd)
{
	CView::OnKillFocus(pNewWnd);
	CMy316exp46Doc* pDoc = GetDocument();
	pDoc->m_pStr = "失去了输入焦点.";
	InvalidateRect(NULL, TRUE);
	// TODO: 在此处添加消息处理程序代码
}
