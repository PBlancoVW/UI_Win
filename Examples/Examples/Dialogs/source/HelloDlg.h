#pragma once


// CHelloDlg dialog

class CHelloDlg : public CDialog
{
	DECLARE_DYNAMIC(CHelloDlg)

public:
	CHelloDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CHelloDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HELLO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
