#include "MainWindowView.h"

// constructors
MainWindowView::MainWindowView()
	: logger(MainWindowView::CLASS_NAME)
{
	init();
	show_all_children();
}

MainWindowView::~MainWindowView()
{
}

// protected functions
void MainWindowView::init()
{
	set_title(WINDOW_TITLE);
	set_size_request(WINDOW_WIDTH, WINDOW_HEIGHT); 
	set_border_width(CONTAINER_BORDER_SIZE);
	set_position();
	set_attribute();
	set_signal_handler();
}

void MainWindowView::set_position()
{
	add(hbox_all);
	hbox_all.pack_start(vbox_tree_view_teams);
		vbox_tree_view_teams.pack_start(scrolled_tree_view);
			scrolled_tree_view.add(tv_team_list);
	hbox_all.pack_start(hbox_btngroup);
		hbox_btngroup.pack_start(btnbox_btngroup);
			btnbox_btngroup.pack_start(btn_start, Gtk::PACK_SHRINK);
			btnbox_btngroup.pack_start(btn_close, Gtk::PACK_SHRINK);
}

void MainWindowView::set_attribute()
{
	hbox_all.set_orientation(ORIENTATION_HORIZONTAL);
	
	vbox_tree_view_teams.set_orientation(ORIENTATION_VERTICAL);
	
	// only show the scrollbars when they are necessary
	scrolled_tree_view.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
	
	vbox_schedule.set_orientation(ORIENTATION_VERTICAL);
	
	hbox_btngroup.set_orientation(ORIENTATION_HORIZONTAL);
	
	btnbox_btngroup.set_spacing(BUTTON_SPACING_SIZE);
	btnbox_btngroup.set_layout(Gtk::BUTTONBOX_END);	// right align
	
	btn_start.set_label("start");
	btn_close.set_label("close");
	
	// create the Tree model:
	ref_team_list_model = TreeStore::create(model_columns);
	tv_team_list.set_model(ref_team_list_model);
	
	// fetch datas in DB
	fetch_team_data();
	
	// set tree view's columns
	tv_team_list.append_column("ID", model_columns.id);
	tv_team_list.append_column("Name", model_columns.name);
}

void MainWindowView::set_signal_handler()
{
	btn_start.signal_clicked().connect([&]()
	{
		on_btn_start_click();
	});
	
	btn_close.signal_clicked().connect([&]()
	{
		on_btn_close_click();
	});
}

// private functions
const string MainWindowView::CLASS_NAME = "MainWindowView";
const string MainWindowView::WINDOW_TITLE = "WINDOW_TITLE";

void MainWindowView::on_btn_start_click()
{
}

void MainWindowView::on_btn_close_click()
{
	close();
}

void MainWindowView::fetch_team_data()
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
