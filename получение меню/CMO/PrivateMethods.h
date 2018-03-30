#pragma once
#include "Structs.h"//структуры

using namespace System;
using namespace System::Collections;

/*
**все основные методы
**для нормальной работы классов
*/
ref class PrivateMethods
{
public:
	PrivateMethods();
protected:
	Date^ ParsingDate(String^);//парсинг даты (( получение структуры даты) чч:мм:сс)
	ArrayList^ ParsingOrders(String^);//получение списка всех заказов(заказ1, заказ2, заказ3 ...)

	int GetNumber(String^);//преобразование строки в число
	int PosSumbol(String^ s, char symboll);//поиск номера символа в строке

	String^ GetStringInCount(int count);//преобразование числа в строку
	String^ GetString(String^, int pos_left, int pos_right);//получение подстроки
	String^ GetReverseString(String^ str);//получение обратной строки

	bool CheckNumber(String^ count);//проверка, можем ли мы преобразовать строку в число
	bool CheckIncludedString(String^ in, String^ out);//проверка, входит ли строка out в строку in
};

