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
	this->set_position();
	this->set_attribute();
	this->set_signal_handler();
}

void voba::MainWindow::AppPage::set_position()
{
	pack_start(this->vbox_center);
}

void voba::MainWindow::AppPage::set_attribute()
{
	
}

void voba::MainWindow::AppPage::set_signal_handler()
{
	
}

// private
