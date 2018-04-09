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
