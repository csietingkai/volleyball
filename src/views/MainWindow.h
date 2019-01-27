#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <gtkmm.h>
#include <unistd.h>
#include <vector>

#include "../tools/Logger.h"
#include "pages/login.h"

namespace voba
{
	class MainWindow : public Gtk::Window, Logable
	{
		public:
			const static std::string CLASS_NAME;
			
			MainWindow();
			virtual ~MainWindow();
		
		protected:
			
			
		private:
			const static std::string WINDOW_TITLE;
			const static int CONTAINER_BORDER_SIZE = 20;
			const static int SPACING_BORDER_SIZE = 10;
			const static int BUTTON_SPACING_SIZE = 5;
			
			LoginPage login_page;
			
			void init();
			void setting_login_page();
	};
}

#endif // MAIN_WINDOW_H_
