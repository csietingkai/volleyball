#include "MainWindow.h"

const std::string voba::MainWindow::CLASS_NAME = "MainWindowView";

void voba::callback()
{
	std::cout << "callback" << std::endl;
}

// constructors
voba::MainWindow::MainWindow()
	: Logable(voba::MainWindow::CLASS_NAME)
{
	this->init();
	show_all_children();
}

voba::MainWindow::~MainWindow()
{
}

void voba::switch_page()
{
	std::cout << "switch_page" << std::endl;
}

// protected
// private
void voba::MainWindow::init()
{
	add(this->login_page);
	this->login_page.set_callback(&voba::callback);
	resize(voba::LoginPage::WINDOW_WIDTH, voba::LoginPage::WINDOW_HEIGHT);
}
