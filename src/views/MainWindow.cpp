#include "MainWindow.h"

const std::string voba::MainWindow::CLASS_NAME = "MainWindowView";

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

// protected
// private
void voba::MainWindow::init()
{
	add(this->login_page);
	resize(voba::MainWindow::LoginPage::WINDOW_WIDTH, voba::MainWindow::LoginPage::WINDOW_HEIGHT);
}
