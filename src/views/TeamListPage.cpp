#include "MainWindow.h"

const std::string voba::MainWindow::AppView::TeamListPage::CLASS_NAME = "TeamListPage";
const std::string voba::MainWindow::AppView::TeamListPage::PAGE_NAME = "Team List";

voba::MainWindow::AppView::TeamListPage::TeamListPage(AppView& parent)
	: parent(parent)
{
	this->init();
	show_all_children();
}

voba::MainWindow::AppView::TeamListPage::~TeamListPage()
{
}

// protected
void voba::MainWindow::AppView::TeamListPage::init()
{
	this->new_member_variable();
	this->set_position();
	this->set_attribute();
	this->set_signal_handler();
}

void voba::MainWindow::AppView::TeamListPage::new_member_variable()
{
	this->hbox_center = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
		this->vbox_team_list = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		this->vbox_team_detail = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		this->vbox_person_detail = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
}

void voba::MainWindow::AppView::TeamListPage::set_position()
{
	pack_start(*this->hbox_center);
		this->hbox_center->pack_start(*this->vbox_team_list);
		this->hbox_center->pack_start(*this->vbox_team_detail);
		this->hbox_center->pack_start(*this->vbox_person_detail);
}

void voba::MainWindow::AppView::TeamListPage::set_attribute()
{
	
}

void voba::MainWindow::AppView::TeamListPage::set_signal_handler()
{
	
}

// private
