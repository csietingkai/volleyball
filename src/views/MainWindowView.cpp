#include "MainWindowView.h"

const std::string voba::MainWindowView::CLASS_NAME = "MainWindowView";

// constructors
voba::MainWindowView::MainWindowView()
	: logger(voba::MainWindowView::CLASS_NAME)
{
	this->init();
	show_all_children();
}

voba::MainWindowView::~MainWindowView()
{
}

// protected functions
void voba::MainWindowView::init()
{
	set_title(WINDOW_TITLE);
	set_size_request(WINDOW_WIDTH, WINDOW_HEIGHT); 
	set_border_width(CONTAINER_BORDER_SIZE);
	this->set_position();
	this->set_attribute();
	this->set_signal_handler();
}

void voba::MainWindowView::set_position()
{
	add(hbox_all);
	this->hbox_all.pack_start(this->vbox_tree_view_teams);
		this->vbox_tree_view_teams.pack_start(this->scrolled_tree_view);
			this->scrolled_tree_view.add(this->tv_team_list);
	this->hbox_all.pack_start(this->hbox_btngroup);
		this->hbox_btngroup.pack_start(this->btnbox_btngroup);
			this->btnbox_btngroup.pack_start(this->btn_start, Gtk::PACK_SHRINK);
			this->btnbox_btngroup.pack_start(this->btn_close, Gtk::PACK_SHRINK);
}

void voba::MainWindowView::set_attribute()
{
	this->hbox_all.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
	
	this->vbox_tree_view_teams.set_orientation(Gtk::ORIENTATION_VERTICAL);
	
	// only show the scrollbars when they are necessary
	this->scrolled_tree_view.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	
	this->vbox_schedule.set_orientation(Gtk::ORIENTATION_VERTICAL);
	
	this->hbox_btngroup.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
	
	this->btnbox_btngroup.set_spacing(voba::MainWindowView::BUTTON_SPACING_SIZE);
	this->btnbox_btngroup.set_layout(Gtk::BUTTONBOX_END);	// right align
	
	this->btn_start.set_label("start");
	this->btn_close.set_label("close");
	
	// create the Tree model:
	this->ref_team_list_model = Gtk::TreeStore::create(model_columns);
	this->tv_team_list.set_model(ref_team_list_model);
	
	// fetch datas in DB
	this->fetch_team_data();
	
	// set tree view's columns
	this->tv_team_list.append_column("ID", model_columns.id);
	this->tv_team_list.append_column("Name", model_columns.name);
}

void voba::MainWindowView::set_signal_handler()
{
	this->btn_start.signal_clicked().connect([&]()
	{
		this->on_btn_start_click();
	});
	
	this->btn_close.signal_clicked().connect([&]()
	{
		this->on_btn_close_click();
	});
}

// private functions
const std::string voba::MainWindowView::WINDOW_TITLE = "WINDOW_TITLE";

void voba::MainWindowView::on_btn_start_click()
{
}

void voba::MainWindowView::on_btn_close_click()
{
	close();
}

void voba::MainWindowView::fetch_team_data()
{
	/*Team t1("test_team");
	team_list.push_back(t1);
	for (Team team : team_list)
	{
		cout << "haha" <<endl;
	}*/
	//Fill the TreeView's model
	Gtk::TreeModel::Row row = *(ref_team_list_model->append());
	row[model_columns.id] = "1";
	row[model_columns.name] = "Billy Bob";

	Gtk::TreeModel::Row childrow = *(ref_team_list_model->append(row.children()));
	childrow[model_columns.id] = "11";
	childrow[model_columns.name] = "Billy Bob Junior";

	childrow = *(ref_team_list_model->append(row.children()));
	childrow[model_columns.id] = "12";
	childrow[model_columns.name] = "Sue Bob";

	row = *(ref_team_list_model->append());
	row[model_columns.id] = "2";
	row[model_columns.name] = "Joey Jojo";


	row = *(ref_team_list_model->append());
	row[model_columns.id] = "3";
	row[model_columns.name] = "Rob McRoberts";

	childrow = *(ref_team_list_model->append(row.children()));
	childrow[model_columns.id] = "31";
	childrow[model_columns.name] = "Xavier McRoberts";
}
