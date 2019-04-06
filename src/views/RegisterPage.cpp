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
	this->new_member_variable();
	this->set_position();
	this->set_attribute();
	this->set_signal_handler();
}

void voba::MainWindow::AppView::RegisterPage::new_member_variable()
{
	this->vbox_center = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
		this->hbox_create_msg = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
			this->label_create_msg = new Gtk::Label("");
		this->hbox_username_input = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
			this->label_username = new Gtk::Label("username: ", Gtk::Align::ALIGN_START);
			this->entry_username = new Gtk::Entry();
		this->hbox_password_input = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
			this->label_password = new Gtk::Label("password: ", Gtk::Align::ALIGN_START);
			this->entry_password = new Gtk::Entry();
		this->hbox_password_again_input = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
			this->label_password_again = new Gtk::Label("password again:", Gtk::Align::ALIGN_START);
			this->entry_password_again = new Gtk::Entry();
		this->hbox_roles = new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
			this->label_roles = new Gtk::Label("role: ", Gtk::Align::ALIGN_START);
			this->vbox_role_options = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
				this->rbtn_admin = new Gtk::RadioButton("Admin");
				this->rbtn_leader = new Gtk::RadioButton("Team Leader");
				this->rbtn_user = new Gtk::RadioButton("Team Member");
		this->hbox_btngroup = new Gtk::Box(Gtk::ORIENTATION_VERTICAL);
			this->btnbox_create = new Gtk::ButtonBox();
				this->btn_create = new Gtk::Button("create");
}

void voba::MainWindow::AppView::RegisterPage::set_position()
{
	pack_start(*this->vbox_center);
		this->vbox_center->pack_start(*this->hbox_create_msg);
		this->hbox_create_msg->pack_start(*this->label_create_msg);
		this->vbox_center->pack_start(*this->hbox_username_input);
			this->hbox_username_input->pack_start(*this->label_username);
			this->hbox_username_input->pack_start(*this->entry_username);
		this->vbox_center->pack_start(*this->hbox_password_input);
			this->hbox_password_input->pack_start(*this->label_password);
			this->hbox_password_input->pack_start(*this->entry_password);
		this->vbox_center->pack_start(*this->hbox_password_again_input);
			this->hbox_password_again_input->pack_start(*this->label_password_again);
			this->hbox_password_again_input->pack_start(*this->entry_password_again);
		this->vbox_center->pack_start(*this->hbox_roles);
			this->hbox_roles->pack_start(*this->label_roles);
			this->hbox_roles->pack_start(*this->vbox_role_options);
				this->vbox_role_options->pack_start(*this->rbtn_admin);
				this->vbox_role_options->pack_start(*this->rbtn_leader);
				this->vbox_role_options->pack_start(*this->rbtn_user);
		this->vbox_center->pack_start(*this->hbox_btngroup);
			this->hbox_btngroup->pack_start(*this->btnbox_create);
				this->btnbox_create->pack_start(*this->btn_create);
}

void voba::MainWindow::AppView::RegisterPage::set_attribute()
{
	this->vbox_center->set_border_width(250);
	
	this->label_create_msg->set_justify(Gtk::JUSTIFY_CENTER);
	this->label_create_msg->set_text("");
	
	this->entry_username->set_width_chars(10);
	
	this->entry_password->set_width_chars(10);
	this->entry_password->set_visibility(false);		// can not see password value
	
	this->entry_password_again->set_width_chars(10);
	this->entry_password_again->set_visibility(false);		// can not see password value
	
	this->rbtn_leader->join_group(*this->rbtn_admin);
	this->rbtn_user->join_group(*this->rbtn_admin);
	
	this->btnbox_create->set_spacing(5);
	this->btnbox_create->set_layout(Gtk::BUTTONBOX_END);// align right
}

void voba::MainWindow::AppView::RegisterPage::set_signal_handler()
{
	this->btn_create->signal_clicked().connect([&]()
	{
		this->on_btn_create_clicked();
	});
}

// private
void voba::MainWindow::AppView::RegisterPage::on_btn_create_clicked()
{
	User new_user;
	new_user.account = this->entry_username->get_text();
	new_user.pwd = this->entry_password->get_text();
	new_user.role = voba::Role::NONE;
	if (this->rbtn_admin->get_active())
	{
		new_user.role = voba::Role::ADMIN;
	}
	else if (this->rbtn_leader->get_active())
	{
		new_user.role = voba::Role::LEADER;
	}
	else if (this->rbtn_user->get_active())
	{
		new_user.role = voba::Role::USER;
	}
	
	if (!this->is_all_field_fill())
	{
		this->hbox_create_msg->override_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
		this->label_create_msg->set_text("Not All Fields Filled!!");
	}
	else if (!this->is_password_repeat())
	{
		this->hbox_create_msg->override_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
		this->label_create_msg->set_text("Password Is Not The Same!!");
	}
	else
	{
		voba::AuthState create_user_state = voba::create_auth(this->parent.parent.user, new_user);
		
		switch (create_user_state)
		{
			case voba::AuthState::SUCCESS:
				this->hbox_create_msg->override_color(Gdk::RGBA("green"), Gtk::STATE_FLAG_NORMAL);
				this->label_create_msg->set_text("Create User Successfully!!");
				break;
			
			case voba::AuthState::DUPLICATE_ACCOUNT_NAME:
				this->hbox_create_msg->override_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
				this->label_create_msg->set_text("Username Has Been Used!!");
				break;
			
			case voba::AuthState::AUTH_NOT_ENOUGH:
				this->hbox_create_msg->override_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
				this->label_create_msg->set_text("You Can't Create This User!!");
				break;
			
			case voba::AuthState::FAIL:
				this->hbox_create_msg->override_color(Gdk::RGBA("red"), Gtk::STATE_FLAG_NORMAL);
				this->label_create_msg->set_text("Create New User Failed!!");
				break;
		}
	}
}


const bool voba::MainWindow::AppView::RegisterPage::is_all_field_fill()
{
	bool re = true;
	re = re && (this->entry_username->get_text().compare("") != 0);
	re = re && (this->entry_password->get_text().compare("") != 0);
	re = re && (this->entry_password_again->get_text().compare("") != 0);
	return re;
}

const bool voba::MainWindow::AppView::RegisterPage::is_password_repeat()
{
	return this->entry_password->get_text().compare(this->entry_password_again->get_text()) == 0;
}
