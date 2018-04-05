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


Date^ Visits::ResidenceTime(Date^ finish) 
{
	Date^ difference;
	int hour, min;
	int kolmin;
	kolmin = ((finish->house * 60) + finish->minutes) - ((TimeStart->house * 60) + TimeStart->minutes);
	hour = kolmin / 60;
	min = kolmin % 60;
	difference->house = hour;
	difference->minutes = min;
	difference->seconds = 0;
	return difference;
}