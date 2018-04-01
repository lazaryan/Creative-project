#include "stdafx.h"
#include "Visits.h"


Visits::Visits()
{
	Orders = gcnew ArrayList();
	TimeStart = gcnew Date();
}

/*
//////////////////////////////////////////////////////////////////

			ВНЕСЕНИЕ ДАННЫХ (ВСЕ СРАЗУ)

//////////////////////////////////////////////////////////////////
*/

void Visits::SetVisitor(String^ s) {
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

/*
///////////////////////////////////////////////////////////////////////

			ПОЛУЧЕНИЕ ДАННЫХ ПО ОТДЕЛЬНОСТИ

///////////////////////////////////////////////////////////////////////
*/

/*
	имени
*/

bool Visits::SetName(String^ name) {
	if (name == nullptr || name->Length == 0)
		return false;

	Name = name;
	return true;
}

/*
	времени
*/

void Visits::SetDate(String^ date) {
	TimeStart = ParsingDate(date);
}

void Visits::SetDate(Date^ date) {
	TimeStart = date;
}

void Visits::SetDateSystem() {
	DateTime system_time = DateTime::Now;

	TimeStart->house   = system_time.Hour;
	TimeStart->minutes = system_time.Minute;
	TimeStart->seconds = system_time.Second;
}

/*
	списка заказов
*/

bool Visits::SetListOrders(String^ orders) {
	if (orders == nullptr || orders->Length == 0)
		return false;

	Orders = ParsingOrders(orders);
	return true;
}

bool Visits::SetListOrders(ArrayList^ orders) {
	if (orders->Count == 0)
		return false;

	Orders = orders;
	return true;
}

/*
///////////////////////////////////////////////////////////////////////

			ВОЗВРАЩЕНИЕ ВСЕХ ДАННЫХ

///////////////////////////////////////////////////////////////////////
*/
String^ Visits::GetName() {
	return Name;
}

Date^ Visits::GetDate() {
	return TimeStart;
}

ArrayList^ Visits::GetOrders() {
	return Orders;
}