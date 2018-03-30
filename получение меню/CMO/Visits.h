#pragma once
#include "Structs.h"//структуры
#include "PrivateMethods.h"//служебные методы (для корректной работы класса)

using namespace System;
using namespace System::Collections;

/*
**Класс пришедшего посетителя
**для получения :
**1)имени
**2)Времени прихода
**3)Списка заказов
*/
ref class Visits : PrivateMethods
{
public:
	Visits();
	/*получение данных о посетителе*/
	void SetVisitor(String^ data);//строка в виде: Имя; время начала(формат чч:мм:сс); список заказов через запятую
	void SetVisitor(String^ name, String^ date, String^ orders);
	void SetVisitor(String^ name, Date^ date, ArrayList^ orders);
	/*возвращение данных о посетителе*/
	String^ GetName();
	Date^ GetDate();
	ArrayList^ GetOrders();
private:
	String ^ Name;//имя посетителя
	Date^ TimeStart;//время начала
	ArrayList^ Orders;//список заказов
};

