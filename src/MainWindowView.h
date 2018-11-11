#ifndef MAIN_WINDOW_View_H_
#define MAIN_WINDOW_View_H_

#include <gtkmm.h>

using namespace std;
using namespace Gtk;
using namespace Glib;

class MainWindowView : public Window
{
	public:
		MainWindowView();
		virtual ~MainWindowView();
};

#endif // MAIN_WINDOW_H_
