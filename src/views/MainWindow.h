#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <gtkmm.h>

#include "../tools/Logger.h"
#include "../auth.h" 
#include "page_enum.h"

namespace voba
{
	class MainWindow : public Gtk::Window, Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			MainWindow();
			virtual ~MainWindow();
			
			friend void switch_page();
		
		protected:
			const static std::string WINDOW_TITLE;
			const static int CONTAINER_BORDER_SIZE = 20;
			const static int SPACING_BORDER_SIZE = 10;
			const static int BUTTON_SPACING_SIZE = 5;
			
		private:
			User user;
			
			class LoginPage : public Gtk::Box
			{
				public:
					const static std::string CLASS_NAME;
					const static int WINDOW_WIDTH = 250;
					const static int WINDOW_HEIGHT = 100;
					const static Page type = Page::LOGIN_PAGE;
					
					LoginPage();
					virtual ~LoginPage();
					
				protected:
					Gtk::Box vbox_center;
						Gtk::Box hbox_username_input;
							Gtk::Label label_username;
							Gtk::Entry entry_username;
						Gtk::Box hbox_password_input;
							Gtk::Label label_password;
							Gtk::Entry entry_password;
						Gtk::Box hbox_btngroup;
							Gtk::ButtonBox btnbox_login;
								Gtk::Button btn_login;
					
					void set_position();
					void set_attribute();
					void set_signal_handler();
					
				private:
					
					void on_btn_login_clicked();
			}; 
			LoginPage login_page;
			class AppPage : public Gtk::Box
			{
				public:
					const static std::string CLASS_NAME;
					const static int WINDOW_WIDTH = 250;
					const static int WINDOW_HEIGHT = 100;
					
					AppPage();
					virtual ~AppPage();
					
				protected:
					void set_position();
					void set_attribute();
					void set_signal_handler();
					
				private:
			};
			AppPage app_page;
			
			void init();
	};
}

#endif // MAIN_WINDOW_H_
