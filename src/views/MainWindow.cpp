#include "MainWindow.h"

const std::string voba::MainWindow::CLASS_NAME = "MainWindowView";

// constructors
voba::MainWindow::MainWindow()
	: Logable(voba::MainWindow::CLASS_NAME)
	, login_view(*this)
	, app_view(*this)
{
	this->init();
}

voba::MainWindow::~MainWindow()
{
}

void voba::MainWindow::login_callback(const voba::User user)
{
	this->user = user;
	this->login_view.hide();
	this->app_view.show();
	resize(voba::MainWindow::AppView::WINDOW_WIDTH, voba::MainWindow::AppView::WINDOW_HEIGHT);
}

// protected
// private
void voba::MainWindow::init()
{
	add(this->box_all);
		this->box_all.pack_start(this->login_view);
		this->box_all.pack_start(this->app_view);
	
	show_all_children();
	this->app_view.hide();
	resize(voba::MainWindow::LoginView::WINDOW_WIDTH, voba::MainWindow::LoginView::WINDOW_HEIGHT);
}
