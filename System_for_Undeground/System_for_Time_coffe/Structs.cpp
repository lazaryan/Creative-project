#include "Structs.h"

/*
/////////////////////////////////////////////////////////

		СТРУКТУРА DATE

////////////////////////////////////////////////////////
*/

Date::Date() {

}

Date::Date(int h) {
	house = h;
	minutes = 0;
	seconds = 0;
}

Date::Date(int h, int m) {
	house = h;
	minutes = m;
	seconds = 0;
}

Date::Date(int h, int m, int s) {
	house = h;
	minutes = m;
	seconds = s;
}

/*
/////////////////////////////////////////////////////////

		СТРУКТУРА VISITOR

////////////////////////////////////////////////////////
*/

Visitor::Visitor() {
	TimeStart = gcnew Date();
}

Visitor::Visitor(String^ name) {
	Name      = name;
}

Visitor::Visitor(Date^ date) {
	TimeStart = date;
}

Visitor::Visitor(String^ name, Date^ date) {
	Name      = name;
	TimeStart = date;
}
