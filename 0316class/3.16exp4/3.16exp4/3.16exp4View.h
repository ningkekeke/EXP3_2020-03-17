
// 3.16exp4View.h : CMy316exp4View ��Ľӿ�
//

#pragma once


class CMy316exp4View : public CView
{
protected: // �������л�����
	CMy316exp4View();
	DECLARE_DYNCREATE(CMy316exp4View)

// ����
public:
	CMy316exp4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy316exp4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 3.16exp4View.cpp �еĵ��԰汾
inline CMy316exp4Doc* CMy316exp4View::GetDocument() const
   { return reinterpret_cast<CMy316exp4Doc*>(m_pDocument); }
#endif

