#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <chrono>
#include <gtkmm.h>
#include <thread>

#include "../models/Team.h"
#include "../tools/Logger.h"
#include "../tools/MySQLConnector.h"
#include "../auth.h" 

namespace voba
{
	enum View
	{
		LOGIN,
		APP
	};
	
	class MainWindow : public Gtk::Window, Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			MainWindow();
			virtual ~MainWindow();
			
			void login_callback(const User user);
		
		protected:
			const static std::string WINDOW_TITLE;
			const static int CONTAINER_BORDER_SIZE = 20;
			const static int SPACING_BORDER_SIZE = 10;
			const static int BUTTON_SPACING_SIZE = 5;
			
		private:
			User user;
			
			Gtk::Box box_all;
			class LoginView : public Gtk::Box
			{
				public:
					const static std::string CLASS_NAME;
					const static int WINDOW_WIDTH = 250;
					const static int WINDOW_HEIGHT = 100;
					const static View TYPE = View::LOGIN;
					
					LoginView(MainWindow& parent);
					virtual ~LoginView();
					
				protected:
					Gtk::Box vbox_center;
						Gtk::Box hbox_login_msg;
							Gtk::Label label_login_msg;
						Gtk::Box hbox_username_input;
							Gtk::Label label_username;
							Gtk::Entry entry_username;
						Gtk::Box hbox_password_input;
							Gtk::Label label_password;
							Gtk::Entry entry_password;
						Gtk::Box hbox_btngroup;
							Gtk::ButtonBox btnbox_login;
								Gtk::Button btn_login;
					
					void init();
					void set_position();
					void set_attribute();
					void set_signal_handler();
					
				private:
					MainWindow& parent;
					
					void on_btn_login_clicked();
			}; 
			LoginView login_view;
			
			class AppView : public Gtk::Box
			{
				public:
					const static std::string CLASS_NAME;
					const static int WINDOW_WIDTH = 1000;
					const static int WINDOW_HEIGHT = 650;
					const static View TYPE = View::APP;
					
					AppView(MainWindow& parent);
					virtual ~AppView();
					
				protected:
					Gtk::Box vbox_center;
						Gtk::Box vbox_sidebar;
							Gtk::StackSidebar sidebar;
							Gtk::Separator separator;
							Gtk::Stack stack;
					
					void init();
					void set_position();
					void set_attribute();
					void set_signal_handler();
					
				private:
					MainWindow& parent;
					
					void init_stack_contents();
					void init_register_user_page();
					void init_team_list_page();
					void init_modify_team_page();
					void init_schedule_page();
			};
			AppView app_view;
			
			void init();
	};
}

#endif // MAIN_WINDOW_H_
