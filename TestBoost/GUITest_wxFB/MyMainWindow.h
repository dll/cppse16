#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H
#include "wxfbWindows.h"

class MyMainWindow:public FBMainWindow {
public:
	MyMainWindow(wxWindow *parent=NULL);
	void OnButtonClose(wxCommandEvent &evt);
};

#endif
