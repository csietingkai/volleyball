#ifndef MAIN_WINDOW_View_H_
#define MAIN_WINDOW_View_H_

#include <gtkmm.h>

#include "common.h"
#include "Datee.h"
#include "DateTime.h"
#include "MySQLConnector.h"
#include "Person.h"
#include "Team.h"
#include "Time.h"
#include "Logger.h" 

using namespace std;
using namespace Gtk;
using namespace Glib;

class MainWindowView : public Window
{
	public:
		MainWindowView();
		virtual ~MainWindowView();
	
	protected:
		Box hbox_all;
			Box vbox_tree_view_teams;
				// TreeView team_list
			Box vbox_schedule;
				// Custom widegt calander
				Box hbox_btngroup;
					ButtonBox btnbox_btngroup;
						Button btn_start;
						Button btn_close;
		
		void init();
		void set_position();
		void set_attribute();
		void set_signal_handler();
		
	private:
		Logger logger;
		
		const static string CLASS_NAME;
		
		const static string WINDOW_TITLE;
		const static int WINDOW_WIDTH = 700;
		const static int WINDOW_HEIGHT = 500;
		const static int CONTAINER_BORDER_SIZE = 20;
		const static int SPACING_BORDER_SIZE = 10;
		const static int BUTTON_SPACING_SIZE = 5;
};

#endif // MAIN_WINDOW_H_
