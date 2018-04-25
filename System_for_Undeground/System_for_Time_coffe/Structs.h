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

//посетитель
ref struct Visitor {
	Visitor();
	Visitor(String^ name);
	Visitor(Date^ date);
	Visitor(String^ name, Date^ date);

	String^ Name;
	Date^ TimeStart;
};

#endif
