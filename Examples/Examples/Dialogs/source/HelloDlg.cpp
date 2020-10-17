// HelloDlg.cpp : implementation file
//

#include "pch.h"
#include "HelloDlg.h"
#include "afxdialogex.h"
#include "resource.h"


// CHelloDlg dialog

IMPLEMENT_DYNAMIC(CHelloDlg, CDialog)

CHelloDlg::CHelloDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_HELLO, pParent)
{

}

CHelloDlg::~CHelloDlg()
{
}

void CHelloDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHelloDlg, CDialog)
END_MESSAGE_MAP()


// CHelloDlg message handlers
