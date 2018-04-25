#pragma once
#include "Structs.h"//структуры
#include "Enums.h"//перечисления
#include "PrivateMethods.h"//служебные методы (для корректной работы класса)

using namespace System;
using namespace System::IO;
using namespace System::Collections;

/*
**Класс пришедшего посетителя
**для получения :
**1)имени
**2)Времени прихода
**3)Списка заказов
**и для внесения этих данных в файл
*/
ref class Visits : PrivateMethods
{
public:
	Visits();

	/*получение данных о посетителе*/
	void SetVisitor(String^ data);		//строка в виде: Имя; время начала(формат чч:мм:сс); список заказов через запятую
	void SetVisitor(String^ name, String^ date, String^ orders);
	void SetVisitor(String^ name, Date^ date, ArrayList^ orders);

	/*получение данных по отдельности*/
	bool SetName(String^ name);		//получение имени

	void SetDate(String^ date);		//получение времени начала
	void SetDate(Date^ date);
	void SetDateSystem();			//получение системного времени

	bool SetListOrders(String^ orders);	//получение списка заказов
	bool SetListOrders(ArrayList^ orders);

	/*возвращение данных о посетителе*/
	String^    GetName();
	Date^      GetDate();
	ArrayList^ GetOrders();

	Date^ ResidenceTime(Date^ finish);	//сколько посетитель провел времени в кафе

	/*внесение посетителя в файл*/
	bool RecordVisits();//имя;время
	bool RecordVisits(int number_table);//номер стола;имя;время
private:
	String	 ^ Name;			//имя посетителя
	Date     ^ TimeStart;			//время начала
	ArrayList^ Orders;			//список заказов

	StreamWriter^ File_w;
	bool OpenFile(String^ path_in_file);	//открыть файл
	void CloseFile();			//закрыть файл
};


