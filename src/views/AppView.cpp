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
