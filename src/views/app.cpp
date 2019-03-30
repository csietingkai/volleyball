#include "MainWindow.h"

const std::string voba::MainWindow::AppView::CLASS_NAME = "AppView";

// constructors
voba::MainWindow::AppView::AppView(MainWindow& parent)
	: parent(parent)
{
	this->init();
}

voba::MainWindow::AppView::~AppView()
{
}

// protected
void voba::MainWindow::AppView::init()
{
	show_all_children();
	this->init_stack_contents();
	this->set_position();
	this->set_attribute();
	this->set_signal_handler();
}

void voba::MainWindow::AppView::set_position()
{
	pack_start(this->vbox_center);
		this->vbox_center.pack_start(this->vbox_sidebar);
			this->vbox_sidebar.pack_start(this->sidebar, Gtk::PACK_SHRINK);
			this->vbox_sidebar.pack_start(this->separator, Gtk::PACK_SHRINK);
			this->vbox_sidebar.pack_start(this->stack, Gtk::PACK_EXPAND_WIDGET);
}

void voba::MainWindow::AppView::set_attribute()
{
	this->vbox_center.set_orientation(Gtk::ORIENTATION_VERTICAL);
	
	this->sidebar.set_stack(this->stack);
	
	this->separator.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
	
	this->stack.set_transition_type(Gtk::STACK_TRANSITION_TYPE_SLIDE_UP_DOWN);
}

void voba::MainWindow::AppView::set_signal_handler()
{
	
}

// private
void voba::MainWindow::AppView::init_stack_contents()
{
	this->init_register_user_page("Create New User");
	this->init_team_list_page("Team List");
	this->init_schedule_page("Schedule");
}

void voba::MainWindow::AppView::init_register_user_page(const std::string page_name)
{
	Gtk::Box* hbox_all = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
	hbox_all->set_border_width(100);
	Gtk::Button *btn = new Gtk::Button("haha");
	hbox_all->pack_start(*btn);
	
	this->stack.add(*hbox_all, page_name, page_name);
}

void voba::MainWindow::AppView::init_team_list_page(const std::string page_name)
{
	
}

void voba::MainWindow::AppView::init_schedule_page(const std::string page_name)
{
	
}
