// CMO.cpp: главный файл проекта.

#include "stdafx.h"

using namespace System;
using namespace System::Collections;

float SetMjy(ArrayList^ diap, ArrayList^ count );

int PosSumbol(String^, char);//+
int GetNumber(String^);//+
String^ GetString(String^, int, int);//+
bool ScheckNumber(String^);//+

int main(array<System::String ^> ^args)
{
	ArrayList ^ a = gcnew ArrayList();
	ArrayList ^ b = gcnew ArrayList();

	a->Add("0-5");   b->Add(12);
	a->Add("5-10");  b->Add(15);
	a->Add("10-15"); b->Add(20);
	a->Add("15-20"); b->Add(14);
	a->Add("20-25"); b->Add(4);
	a->Add("25-30"); b->Add(2);

	float Mja = SetMjy(a, b);

    return 0;
}


/*сама функция*/
float SetMjy(ArrayList^ diap, ArrayList^ count) {//формат массива diap "5-10", count- список чисел
	int length = diap->Count;
	String^ s;
	int poz, 
		count1,
		count2;
	float sum_obh = 0;
	int   sum_loc = 0;


	for (int i = 0; i < length; i++) {
		s = (String^)diap[i];//получаем строку-пределов
		poz = PosSumbol(s, '-');//получаем позицию тере
		count1 = GetNumber(GetString(s, 0, poz));//получаем наши числа
		count2 = GetNumber(GetString(s, poz + 1, s->Length));
		float sr_znach = (count1 + count2) / 2;//среднее число в промежутке времени
		sum_obh += sr_znach * (int)count[i];
		sum_loc += (int)count[i];
	}

	float time_sr = sum_obh / sum_loc;//среднее время

	return (1 / time_sr) * 60;//возвращаем интенсивность обслуживания (если передавалось в минутах, то возвращаем в часах)
}

/*служебные*/
int PosSumbol(String^ text, char sumbol) {//получение позиции символа
	int length = text->Length;

	for (int i = 0; i < length; i++) {
		if (text[i] == sumbol)
			return i;
	}

	return -1;
}

int GetNumber(String^ s) {//перевод строки в число
	if (!(ScheckNumber(s)))//проверяем, все ли символы в строке-цифры
		return -1;

	int length = s->Length,
		number = 0;

	for (int i = 0; i < length; i++) {
		number = number * 10 + ((int)s[i] - (int)'0');
	}

	return number;
}

String^ GetString(String^ text, int pos1, int pos2) {//получение подстрок
	if (pos1 < 0 || pos2 > text->Length)
		return "";

	String^ new_str;
	for (int i = pos1; i < pos2; i++) {
		new_str += text[i];
	}

	return new_str;
}

bool ScheckNumber(String^ s) {//проверка строки но возможность преобразования в число
	int length = s->Length;

	for (int i = 0; i < length; i++) {
		if (!(s[i] >= '0' && s[i] <= '9'))
			return false;
	}

	return true;
}