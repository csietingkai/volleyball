#ifndef VIEW_H_
#define VIEW_H_

#include <gtkmm.h>

using namespace std;
using namespace Gtk;
using namespace Glib;

class View : public Window
{
	public:
		View();
		virtual ~View();
};

#endif // VIEW_H_
