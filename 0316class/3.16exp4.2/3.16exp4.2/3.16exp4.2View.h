
// 3.16exp4.2View.h : CMy316exp42View 类的接口
//

#pragma once


class CMy316exp42View : public CView
{
protected: // 仅从序列化创建
	CMy316exp42View();
	DECLARE_DYNCREATE(CMy316exp42View)

// 特性
public:
	CMy316exp42Doc* GetDocument() const;

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
	virtual ~CMy316exp42View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 3.16exp4.2View.cpp 中的调试版本
inline CMy316exp42Doc* CMy316exp42View::GetDocument() const
   { return reinterpret_cast<CMy316exp42Doc*>(m_pDocument); }
#endif

