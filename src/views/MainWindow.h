#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <gtkmm.h>

#include "../tools/Logger.h"
#include "pages/app.h"
#include "pages/login.h"

namespace voba
{
	Page current_page;
	void callback();
	void switch_page();
	
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
			
			LoginPage login_page;
			AppPage app_page;
			
			void init();
	};
}

#endif // MAIN_WINDOW_H_
