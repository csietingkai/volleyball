#include "MainWindow.h"

const std::string voba::MainWindow::AppView::RegisterPage::CLASS_NAME = "RegisterPage";
const std::string voba::MainWindow::AppView::RegisterPage::PAGE_NAME = "Create New User";

voba::MainWindow::AppView::RegisterPage::RegisterPage(AppView& parent)
	: parent(parent)
{
	this->init();
	show_all_children();
}

voba::MainWindow::AppView::RegisterPage::~RegisterPage()
{
}

// protected
void voba::MainWindow::AppView::RegisterPage::init()
{
	this->btn = new Gtk::Button("haha");
	pack_start(*this->btn);
}
