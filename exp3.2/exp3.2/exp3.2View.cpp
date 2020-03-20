
// exp3.2View.cpp : Cexp32View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Cexp32View 构造/析构

Cexp32View::Cexp32View()
{
	// TODO: 在此处添加构造代码

}

Cexp32View::~Cexp32View()
{
}

BOOL Cexp32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp32View 绘制

void Cexp32View::OnDraw(CDC* pDC)
{
	Cexp32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->c);
	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp32View 打印

BOOL Cexp32View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp32View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp32View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp32View 诊断

#ifdef _DEBUG
void Cexp32View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp32Doc* Cexp32View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp32Doc)));
	return (Cexp32Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp32View 消息处理程序


void Cexp32View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
