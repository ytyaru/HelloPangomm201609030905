#include "MyArea.h"
//#include <gtkmm/application.h> // gtkmm3�̏ꍇ
//#include <gtkmm/window.h> // gtkmm3�̏ꍇ
#include <gtkmm.h>
#include <glibmm.h>
#include <string>
#include <pangomm.h>
#include <pangomm/fontdescription.h>

MyArea::MyArea(void)
{
}
MyArea::~MyArea(void)
{
}
bool MyArea::on_expose_event( GdkEventExpose* event )
//bool MyArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) // gtkmm3�ł�on_draw����cairo::context���擾�ł���
{
	//Gtk::Allocation allocation = get_allocation(); // gtkmm3�̏ꍇ
	//const int width = allocation.get_width();
	//const int height = allocation.get_height();
	const int width = this->get_width();
	const int height = this->get_height();

	// gtkmm2�ł͕K�v�Ȃ̂Œǉ�����
	Cairo::RefPtr< Cairo::Context > cr = get_window()->create_cairo_context();
	
	cr->set_source_rgb(0.0, 0.0, 0.0);
	draw_rectangle(cr, width, height);

	cr->set_source_rgb(1.0, 1.0, 1.0);
	draw_text(cr, width, height);

	return true;
}
void MyArea::draw_rectangle(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height)
{
	cr->rectangle(0, 0, width, height);
	cr->fill();
}
void MyArea::draw_text(const Cairo::RefPtr<Cairo::Context>& cr, int rectangle_width, int rectangle_height)
{
	Pango::FontDescription font;
	
	font.set_family("MS gothic");
	font.set_weight(Pango::WEIGHT_NORMAL);
	font.set_size(24);

	Glib::ustring text = Glib::locale_to_utf8("Pango�œ��{��I");
	auto layout = create_pango_layout(text);
	layout->set_font_description(font);
	int text_width;
	int text_height;
	layout->get_pixel_size(text_width, text_height);
	
	cr->move_to((rectangle_width-text_width)/2, (rectangle_height-text_height)/2);

	layout->show_in_cairo_context(cr);
}