
// 3.16exp4.5View.h : CMy316exp45View 类的接口
//

#pragma once


class CMy316exp45View : public CView
{
protected: // 仅从序列化创建
	CMy316exp45View();
	DECLARE_DYNCREATE(CMy316exp45View)

// 特性
public:
	CMy316exp45Doc* GetDocument() const;

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
	virtual ~CMy316exp45View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 3.16exp4.5View.cpp 中的调试版本
inline CMy316exp45Doc* CMy316exp45View::GetDocument() const
   { return reinterpret_cast<CMy316exp45Doc*>(m_pDocument); }
#endif

