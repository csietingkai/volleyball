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
	hbox_all.pack_start(hbox_btngroup);
		hbox_btngroup.pack_start(btnbox_btngroup);
		btnbox_btngroup.pack_start(btn_start, Gtk::PACK_SHRINK);
		btnbox_btngroup.pack_start(btn_close, Gtk::PACK_SHRINK);
}

void MainWindowView::set_attribute()
{
	hbox_all.set_orientation(ORIENTATION_VERTICAL);
	
	btnbox_btngroup.set_spacing(BUTTON_SPACING_SIZE);
	btnbox_btngroup.set_layout(Gtk::BUTTONBOX_END);	// right align
	
	btn_start.set_label("start");
	btn_close.set_label("close");
}

void MainWindowView::set_signal_handler()
{
	/*btn_select_file.signal_clicked().connect([&]()
	{
		on_btn_select_click();
	});
	
	btn_start.signal_clicked().connect([&]()
	{
		on_btn_start_click();
	});
	
	btn_close.signal_clicked().connect([&]()
	{
		on_btn_close_click();
	});
	
	this->signal_key_press_event().connect(sigc::mem_fun
	( 
		*this, &View::on_key_press 
	));*/
}

// private functions
const string MainWindowView::CLASS_NAME = "MainWindowView";
const string MainWindowView::WINDOW_TITLE = "WINDOW_TITLE";

void MainWindowView::on_btn_close_click()
{
	close();
}
