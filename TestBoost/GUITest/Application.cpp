#include <wx/frame.h>
#include "Application.h"

IMPLEMENT_APP(mxApplication)

bool mxApplication::OnInit() {
	wxFrame *frm = new wxFrame(NULL,wxID_ANY,"Example window");
	frm->Show();
	return true;
}


