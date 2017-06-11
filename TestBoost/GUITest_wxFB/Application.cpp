#include "Application.h"
#include "MyMainWindow.h"
#include <wx/image.h>

IMPLEMENT_APP(mxApplication)

bool mxApplication::OnInit() {
	
	wxInitAllImageHandlers(); // required to properly show custom images/icons
	
	MyMainWindow *v = new MyMainWindow(NULL); // create (load in memory) the main window
	v->Show(); // make the main window visible
	
	return true; // initialization finished ok
	
}

