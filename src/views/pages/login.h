#ifndef LOGIN_H_
#define LOGIN_H_

#include <gtkmm.h>
#include <map>
#include <unistd.h>
#include <vector>

#include "../../tools/Logger.h"

namespace voba
{
	class LoginPage : public Gtk::Box
	{
		public:
			const static std::string CLASS_NAME;
			const static int WINDOW_WIDTH = 250;
			const static int WINDOW_HEIGHT = 100;
			
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

}

#endif // LOGIN_H_
