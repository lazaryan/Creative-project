#pragma once
#include "Structs.h"//структуры

using namespace System;
using namespace System::Collections;

ref class PrivateMethods
{
public:
	PrivateMethods();
protected:
	Date^ ParsingDate(String^);//парсинг даты (( получение структуры даты) чч:мм:сс)
	ArrayList^ ParsingOrders(String^);//получение списка всех заказов(заказ1, заказ2, заказ3 ...)

	int GetNumber(String^);//преобразование строки в число
	bool CheckNumber(String^ count);//проверка, можем ли мы преобразовать строку в число
	int PosSumbol(String^ s, char symboll);//поиск номера символа в строке
	String^ GetString(String^, int pos_left, int pos_right);//получение подстроки
};

