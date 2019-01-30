#include "MainWindow.h"

const std::string voba::MainWindow::CLASS_NAME = "MainWindowView";

// constructors
voba::MainWindow::MainWindow()
	: Logable(voba::MainWindow::CLASS_NAME)
	, login_page(*this)
	, app_page(*this)
{
	this->init();
}

voba::MainWindow::~MainWindow()
{
}

void voba::MainWindow::login_callback(const voba::User user)
{
	std::cout << user.id << std::endl;
	std::cout << user.account << std::endl;
	std::cout << user.pwd << std::endl;
	std::cout << static_cast<int>(user.role) << std::endl;
	this->user = user;
	if (static_cast<int>(user.role) < 16)
	{
		this->login_page.hide();
		this->app_page.show();
	}
}

// protected
// private
void voba::MainWindow::init()
{
	add(this->box_all);
		this->box_all.pack_start(this->login_page);
		this->box_all.pack_start(this->app_page);
	
	show_all_children();
	this->app_page.hide();
	resize(voba::MainWindow::LoginPage::WINDOW_WIDTH, voba::MainWindow::LoginPage::WINDOW_HEIGHT);
}
