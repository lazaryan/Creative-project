#ifndef _Structs_
#define _Structs_


using namespace System;

/*время*/
ref struct Date {
	/*конструкторы*/
	Date();
	Date(int house);
	Date(int house, int minutes);
	Date(int house, int minutes, int seconds);

	int house;
	int minutes;
	int seconds;
};

#endif
