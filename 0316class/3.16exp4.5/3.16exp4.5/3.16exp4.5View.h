
// 3.16exp4.5View.h : CMy316exp45View ��Ľӿ�
//

#pragma once


class CMy316exp45View : public CView
{
protected: // �������л�����
	CMy316exp45View();
	DECLARE_DYNCREATE(CMy316exp45View)

// ����
public:
	CMy316exp45Doc* GetDocument() const;

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
	virtual ~CMy316exp45View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // 3.16exp4.5View.cpp �еĵ��԰汾
inline CMy316exp45Doc* CMy316exp45View::GetDocument() const
   { return reinterpret_cast<CMy316exp45Doc*>(m_pDocument); }
#endif

