
// 3.16exp4.1View.h : CMy316exp41View 类的接口
//

#pragma once


class CMy316exp41View : public CView
{
protected: // 仅从序列化创建
	CMy316exp41View();
	DECLARE_DYNCREATE(CMy316exp41View)

// 特性
public:
	CMy316exp41Doc* GetDocument() const;

// 操作
public:

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
	virtual ~CMy316exp41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3.16exp4.1View.cpp 中的调试版本
inline CMy316exp41Doc* CMy316exp41View::GetDocument() const
   { return reinterpret_cast<CMy316exp41Doc*>(m_pDocument); }
#endif

