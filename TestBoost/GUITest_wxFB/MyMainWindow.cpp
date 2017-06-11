#include "MyMainWindow.h"

MyMainWindow::MyMainWindow(wxWindow *parent) : FBMainWindow(parent) {
  
}

void MyMainWindow::OnButtonClose( wxCommandEvent& event ) { 
	Close();
}
