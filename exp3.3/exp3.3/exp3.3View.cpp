
// exp3.3View.cpp : Cexp33View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp3.3.h"
#endif

#include "exp3.3Doc.h"
#include "exp3.3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cexp33View

IMPLEMENT_DYNCREATE(Cexp33View, CView)

BEGIN_MESSAGE_MAP(Cexp33View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cexp33View 构造/析构

Cexp33View::Cexp33View()
{
	// TODO: 在此处添加构造代码
	set = true;
	N = 5;
	for (int i = 0; i < N; i++) {
		int t = (i + 1) * 100;
		CRect rect(t, 0, t + 20, 20);
		cr.Add(rect);
	}
}

Cexp33View::~Cexp33View()
{
}

BOOL Cexp33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp33View 绘制

void Cexp33View::OnDraw(CDC* pDC)
{
	Cexp33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CRect rect;
	GetClientRect(rect);
	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL);
			set = false;
		}
		
	}
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);//给Ellipse一个矩形,就会在矩形里面画圆
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp33View 打印

BOOL Cexp33View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cexp33View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Cexp33View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Cexp33View 诊断

#ifdef _DEBUG
void Cexp33View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp33Doc* Cexp33View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp33Doc)));
	return (Cexp33Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp33View 消息处理程序


void Cexp33View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int i = nIDEvent;
	CRect c;
	GetClientRect(&c);
	if(flag==0&&cr[i].bottom<(c.Height())){
		if (cr[i].bottom + 10 > c.Height()) {
			cr[i].top += c.Height()- cr[i].bottom;
			cr[i].bottom = c.Height();
		}
		else {
			cr[i].top += 100;
			cr[i].bottom += 100;
		}	
	}
	else flag++;
	if(cr[i].top>0&&flag>=1){
		cr[i].top -= 50;
		cr[i].bottom -= 50;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}
