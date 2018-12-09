#ifndef MAIN_WINDOW_View_H_
#define MAIN_WINDOW_View_H_

#include <gtkmm.h>
#include <unistd.h>
#include <vector>

#include "../models/Team.h"
#include "../tools/Logger.h"

namespace voba
{
	class MainWindowView : public Gtk::Window
	{
		public:
			const static std::string CLASS_NAME;
			
			MainWindowView();
			virtual ~MainWindowView();
		
		protected:
			//Tree model columns:
			class ModelColumns : public Gtk::TreeModel::ColumnRecord
			{
				public:
					Gtk::TreeModelColumn<Glib::ustring> id;
					Gtk::TreeModelColumn<Glib::ustring> name;
					
					ModelColumns() { add(id); add(name); }
			};
			Gtk::Box hbox_all;
				Gtk::Box vbox_tree_view_teams;
					Gtk::ScrolledWindow scrolled_tree_view;
						Gtk::TreeView tv_team_list;
						Glib::RefPtr<Gtk::TreeStore> ref_team_list_model;
						ModelColumns model_columns;
				Gtk::Box vbox_schedule;
					// Custom widegt calander
					Gtk::Box hbox_btngroup;
						Gtk::ButtonBox btnbox_btngroup;
							Gtk::Button btn_start;
							Gtk::Button btn_close;
			
			void init();
			void set_position();
			void set_attribute();
			void set_signal_handler();
			
		private:
			std::vector<Team> team_list;
			
			Logger logger;
			
			const static std::string WINDOW_TITLE;
			const static int WINDOW_WIDTH = 700;
			const static int WINDOW_HEIGHT = 500;
			const static int CONTAINER_BORDER_SIZE = 20;
			const static int SPACING_BORDER_SIZE = 10;
			const static int BUTTON_SPACING_SIZE = 5;
			
			void on_btn_start_click();
			void on_btn_close_click();
			
			void fetch_team_data();
	};

}

#endif // MAIN_WINDOW_H_
