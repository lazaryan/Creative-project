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
	/*работа с числами*/
	String ^ GetStringInCount(int count);//преобразование числа в строку
	long Power(int number, int deg);//возведение числа number в степень deg(только положительная)
	double PowerNegative(int number, int deg);//возведение в степень(не зависит от знака)

	/*работа со строками*/
	int GetNumber(String^);//преобразование строки в число
	int PosSumbol(String^ s, char symboll);//поиск номера символа в строке

	String^ GetString(String^, int pos_left, int pos_right);//получение подстроки
	String^ GetReverseString(String^ str);//получение обратной строки

	ArrayList^ SortingListString(ArrayList^ list);//сортировка списка строк(пузырьковая)

	/*работа со временем*/
	int GetMinutes(Date^ time);//получение общего числа минут

	/*проверки*/
	bool CheckNumber(String^ count);//проверка, можем ли мы преобразовать строку в число
	bool CheckIncludedString(String^ in, String^ out);//проверка, входит ли строка out в строку in

	/*парсинг*/
	Date^ ParsingDate(String^);//парсинг даты (( получение структуры даты) чч:мм:сс)
	ArrayList^ ParsingOrders(String^);//получение списка всех заказов(заказ1, заказ2, заказ3 ...)
private:
	int GemMaxLength(ArrayList^ list);
};

