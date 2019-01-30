#include "MainWindow.h"

const std::string voba::MainWindow::LoginPage::CLASS_NAME = "LoginPage";

// constructors
voba::MainWindow::LoginPage::LoginPage()
{
	this->set_position();
	this->set_attribute();
	this->set_signal_handler();
}

voba::MainWindow::LoginPage::~LoginPage()
{
}

// protected
void voba::MainWindow::LoginPage::set_position()
{
	pack_start(this->vbox_center);
		this->vbox_center.pack_start(this->hbox_username_input);
			this->hbox_username_input.pack_start(this->label_username);
			this->hbox_username_input.pack_start(this->entry_username);
		this->vbox_center.pack_start(this->hbox_password_input);
			this->hbox_password_input.pack_start(this->label_password);
			this->hbox_password_input.pack_start(this->entry_password);
		this->vbox_center.pack_start(this->hbox_btngroup);
			this->hbox_btngroup.pack_start(this->btnbox_login);
				this->btnbox_login.pack_start(this->btn_login);
}

void voba::MainWindow::LoginPage::set_attribute()
{
	this->vbox_center.set_orientation(Gtk::ORIENTATION_VERTICAL);
	this->vbox_center.set_border_width(150);
	
	this->label_username.set_justify(Gtk::JUSTIFY_RIGHT);
	this->label_username.set_text("username: ");
	
	this->label_password.set_justify(Gtk::JUSTIFY_RIGHT);
	this->label_password.set_text("password: ");

	this->btnbox_login.set_spacing(5);
	this->btnbox_login.set_layout(Gtk::BUTTONBOX_END);	// right align
	
	this->btn_login.set_label("login");
}

void voba::MainWindow::LoginPage::set_signal_handler()
{
	this->btn_login.signal_clicked().connect([&]()
	{
		this->on_btn_login_clicked();
	});
}

// private
void voba::MainWindow::LoginPage::on_btn_login_clicked()
{
	std::cout << "login" << std::endl;
}
