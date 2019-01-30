#include "MainWindow.h"

const std::string voba::MainWindow::AppPage::CLASS_NAME = "AppPage";

// constructors
voba::MainWindow::AppPage::AppPage(MainWindow& parent)
	: parent(parent)
{
	this->set_position();
	this->set_attribute();
	this->set_signal_handler();
	show_all_children();
}

voba::MainWindow::AppPage::~AppPage()
{
}

// protected
void voba::MainWindow::AppPage::set_position()
{
	pack_start(this->btn_a);
}

void voba::MainWindow::AppPage::set_attribute()
{
	this->btn_a.set_label("a");
}

void voba::MainWindow::AppPage::set_signal_handler()
{
	
}

// private
