#include "stdafx.h"
#include "PrivateMethods.h"


PrivateMethods::PrivateMethods()
{
}

/*
////////////////////////////////////////////////////////////////////////////////////

				РАБОТА С ЧИСЛАМИ

////////////////////////////////////////////////////////////////////////////////////
*/

String^ PrivateMethods::GetStringInCount(int count) {
	String^ buf;

	while (count) {
		buf += (char)(count % 10);
		count /= 10;
	}

	return GetReverseString(buf);
}

long PrivateMethods::Power(int number, int deg) {
	long result = 1;

	while (deg) {
		if (deg % 2 == 0) {
			deg /= 2;
			number *= number;
		}
		else {
			deg--;
			result *= number;
		}
	}

	return result;
}

double PrivateMethods::PowerNegative(int number, int deg) {
	double result = 1;
	bool negative = false;
	
	if(deg < 0){
		deg = -deg;
		negative = true;
	}

	result = Power(number, deg);

	if (negative)
		return  (1 / result);
	else
		result;
}

/*
//////////////////////////////////////////////////////////////////////////////////////

				РАБОТА СО СТРОКАМИ

//////////////////////////////////////////////////////////////////////////////////////
*/

int PrivateMethods::PosSumbol(String^ text, char sumbol) {
	int length = text->Length;

	for (int i = 0; i < length; i++) {
		if (text[i] == sumbol)
			return i;
	}

	return -1;
}

String^ PrivateMethods::GetString(String^ text, int pos1, int pos2) {
	if (text == nullptr || pos1 < 0 || pos2 > text->Length)//nullptr - это означает, что строка пустая
		return "";

	String^ new_str;
	for (int i = pos1; i < pos2; i++) {
		new_str += text[i];
	}

	return new_str;
}

int PrivateMethods::GetNumber(String^ s) {
	if (!CheckNumber(s))
		return -1;

	int length = s->Length,
		count = 0;

	for (int i = 0; i < length; i++)
		count = count * 10 + (int)s[i] - (int)'0';

	return count;
}

String^ PrivateMethods::GetReverseString(String^ str) {
	String^ reverse_text;
	int length = str->Length;

	for (int i = length - 1; i >= 0; i--) {
		reverse_text += str[i];
	}

	return reverse_text;
}

/*
///////////////////////////////////////////////////////////////////////////////////

					ПРОВЕРКИ

///////////////////////////////////////////////////////////////////////////////////
*/

bool PrivateMethods::CheckNumber(String^ s) {
	int length;
	if (s == nullptr || (length = s->Length == 0))
		return false;

	for (int i = 0; i < length; i++) {
		if (!(s[i] >= '0' && s[i] <= '9'))
			return false;
	}

	return true;
}

bool PrivateMethods::CheckIncludedString(String^ in, String^ out) {
	int length = out->Length;

	in = in->ToUpper();
	out = out->ToUpper();

	for (int i = 0; i < length; i++)
		if (!(in[i] == out[i]))
			return false;

	return true;
}

/*
/////////////////////////////////////////////////////////////////////////////////

				ПАРСИНГ

////////////////////////////////////////////////////////////////////////////////
*/
Date^ PrivateMethods::ParsingDate(String^ s) {
	Date^ dt = gcnew Date();

	int poz = PosSumbol(s, ':');
	dt->house = GetNumber(GetString(s, 0, poz));//получаем час 

	s = GetString(s, poz + 1, s->Length);
	poz = PosSumbol(s, ':');
	dt->minutes = GetNumber(GetString(s, 0, poz));//получаем минуты

	s = GetString(s, poz + 1, s->Length);
	dt->seconds = GetNumber(GetString(s, 0, s->Length));//получаем секунды

	return dt;
}

ArrayList^ PrivateMethods::ParsingOrders(String^ s) {
	ArrayList^ a = gcnew ArrayList();
	int poz;

	while (poz != -1) {
		String^ ordr;

		poz = PosSumbol(s, ',');
		if (poz != -1)
			ordr = GetString(s, 0, poz);
		else//если это последний заказ
			ordr = GetString(s, 0, s->Length);

		a->Add(ordr);
		s = GetString(s, poz + 2, s->Length);
	}

	return a;
}