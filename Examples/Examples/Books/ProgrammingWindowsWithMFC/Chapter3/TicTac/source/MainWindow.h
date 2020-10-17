#pragma once

class CMainWindow : public CWnd
{
public:
	CMainWindow();

protected:
	int GetRectID(CPoint point);
	void DrawBoard(CDC* pDC);
	void DrawX(CDC* pDC, int nPos);
	void DrawO(CDC* pDC, int nPos);
	void ResetGame();
	void CheckForGameOver();
	int IsWinner();
	BOOL IsDraw();

	virtual void PostNcDestroy();

	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP()

protected:
	static const CRect m_rcSquares[9]; // Grid coordinates
	int m_nGameGrid[9]; // Grid contents
	int m_nNextChar; // Next character (EX or OH)
};

