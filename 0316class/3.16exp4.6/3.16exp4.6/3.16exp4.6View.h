
// 3.16exp4.6View.h : CMy316exp46View ��Ľӿ�
//

#pragma once


class CMy316exp46View : public CView
{
protected: // �������л�����
	CMy316exp46View();
	DECLARE_DYNCREATE(CMy316exp46View)

// ����
public:
	CMy316exp46Doc* GetDocument() const;

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
	virtual ~CMy316exp46View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
};

#ifndef _DEBUG  // 3.16exp4.6View.cpp �еĵ��԰汾
inline CMy316exp46Doc* CMy316exp46View::GetDocument() const
   { return reinterpret_cast<CMy316exp46Doc*>(m_pDocument); }
#endif

