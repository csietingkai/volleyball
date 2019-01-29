#ifndef APP_H_
#define APP_H_

#include <functional>
#include <gtkmm.h>

#include "../../auth.h"

namespace voba
{
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

}

#endif // APP_H_
