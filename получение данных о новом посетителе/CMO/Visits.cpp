#include "stdafx.h"
#include "Visits.h"


Visits::Visits()
{
	Orders = gcnew ArrayList();
	TimeStart = gcnew Date();
}

void Visits::SetVisitor(String^ s) {//внесение данных о посетителе
	int poz = PosSumbol(s, ';');
	Name = GetString(s, 0, poz);
	
	s = GetString(s, poz + 1, s->Length);
	poz = PosSumbol(s, ';');
	TimeStart = ParsingDate(GetString(s, 0, poz));

	s = GetString(s, poz + 1, s->Length);
	Orders = ParsingOrders(s);
}

void Visits::SetVisitor(String^ name, String^ date, String^ orders) {
	Name = name;
	TimeStart = ParsingDate(date);
	Orders = ParsingOrders(orders);
}

void Visits::SetVisitor(String^ name, Date^ date, ArrayList^ orders) {
	Name = name;
	TimeStart = date;
	Orders = orders;
}

String^ Visits::GetName() {
	return Name;
}

Date^ Visits::GetDate() {
	return TimeStart;
}

ArrayList^ Visits::GetOrders() {
	return Orders;
}