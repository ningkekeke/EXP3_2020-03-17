
// exp3.1View.h : Cexp31View 类的接口
//

#pragma once


class Cexp31View : public CView
{
protected: // 仅从序列化创建
	Cexp31View();
	DECLARE_DYNCREATE(Cexp31View)

// 特性
public:
	Cexp31Doc* GetDocument() const;

// 操作
public:
	int count = 0, x, flag = 0;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cexp31View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // exp3.1View.cpp 中的调试版本
inline Cexp31Doc* Cexp31View::GetDocument() const
   { return reinterpret_cast<Cexp31Doc*>(m_pDocument); }
#endif

