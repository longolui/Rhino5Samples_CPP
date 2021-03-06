/////////////////////////////////////////////////////////////////////////////
// BlockWalkDialog.h

#pragma once

#include "Resource.h"

/////////////////////////////////////////////////////////////////////////////
// CBlockWalkDialog
// See BlockWalkDialog.cpp for the implementation of this class

class CBlockWalkDialog : public CRhinoDialog
{
	DECLARE_DYNAMIC( CBlockWalkDialog )

public:
	CBlockWalkDialog( CWnd* pParent, CRhinoDoc& doc );
	virtual ~CBlockWalkDialog();

// Dialog Data
	enum { IDD = IDD_BLOCKWALK_DIALOG };
  CTreeCtrl m_tree;
  CRhinoUiBlockPreview m_preview;
  CComboBox m_view_combo;
  CComboBox m_display_combo;

public:
  virtual BOOL OnInitDialog();
  afx_msg void OnSelChangeBlockTree(NMHDR *pNMHDR, LRESULT* pResult);
  afx_msg void OnSelChangeComboView();
  afx_msg void OnSelChangeComboDisplay();

protected:
	virtual void DoDataExchange( CDataExchange* pDX );
	DECLARE_MESSAGE_MAP()

private:
  void AddInstanceDefinitionToTreeCtrl( const CRhinoInstanceDefinition* idef, HTREEITEM hParent, HTREEITEM hInsertAfter, bool bAddDef );

private:
  CRhinoDoc& m_doc;
  const CRhinoInstanceDefinition* m_idef;
};
