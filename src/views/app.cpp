#include "MainWindow.h"

const std::string voba::MainWindow::AppPage::CLASS_NAME = "AppPage";

// constructors
voba::MainWindow::AppPage::AppPage(MainWindow& parent)
	: parent(parent)
{
	this->init();
}

voba::MainWindow::AppPage::~AppPage()
{
}

// protected
void voba::MainWindow::AppPage::init()
{
	show_all_children();
	this->init_stack_contents();
	this->set_position();
	this->set_attribute();
	this->set_signal_handler();
}

void voba::MainWindow::AppPage::set_position()
{
	pack_start(this->vbox_center);
		this->vbox_center.pack_start(this->vbox_sidebar);
			this->vbox_sidebar.pack_start(this->sidebar, Gtk::PACK_SHRINK);
			this->vbox_sidebar.pack_start(this->separator, Gtk::PACK_SHRINK);
			this->vbox_sidebar.pack_start(this->stack, Gtk::PACK_EXPAND_WIDGET);
}

void voba::MainWindow::AppPage::set_attribute()
{
	this->vbox_center.set_orientation(Gtk::ORIENTATION_VERTICAL);
	
	this->sidebar.set_stack(this->stack);
	
	this->separator.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
	
	this->stack.set_transition_type(Gtk::STACK_TRANSITION_TYPE_SLIDE_UP_DOWN);
}

void voba::MainWindow::AppPage::set_signal_handler()
{
	
}

// private
void voba::MainWindow::AppPage::init_stack_contents()
{
	this->init_register_user_page();
	this->init_team_list_page();
	this->init_modify_team_page();
	this->init_schedule_page();
}

void voba::MainWindow::AppPage::init_register_user_page()
{
	Gtk::Image* image = Gtk::manage(new Gtk::Image());
	image->set_from_icon_name("help-about", Gtk::ICON_SIZE_MENU);
	image->set_pixel_size(256);
	this->stack.add(*image, "image", "image");
}

void voba::MainWindow::AppPage::init_team_list_page()
{
	
}

void voba::MainWindow::AppPage::init_modify_team_page()
{
	
}

void voba::MainWindow::AppPage::init_schedule_page()
{
	
}
