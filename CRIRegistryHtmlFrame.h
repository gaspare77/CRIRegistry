#ifndef __CRIRegistryHtmlFrame__
#define __CRIRegistryHtmlFrame__

#include "CRIRegistryGUIs.h"

//// end generated include

/** Implementing HtmlFrame */
class CRIRegistryHtmlFrame : public HtmlFrame
{
protected:
   	// Virtual event handlers, overide them in your derived class
	void OnIconize( wxIconizeEvent& event );

public:
	/** Constructor */
	CRIRegistryHtmlFrame( wxWindow* parent );
    bool Show( const wxString& url ); 
};

#endif // __CRIRegistryHtmlFrame__
