#include "stdafx.h"
#include "PrivateMethodsForVisitor.h"


PrivateMethodsForVisitor::PrivateMethodsForVisitor()
{
}

int PrivateMethodsForVisitor::PosSumbol(String^ text, char sumbol) {
	int length = text->Length;

	for (int i = 0; i < length; i++) {
		if (text[i] == sumbol)
			return i;
	}

	return -1;
}

String^ PrivateMethodsForVisitor::GetString(String^ text, int pos1, int pos2) {
	if (text == nullptr || pos1 < 0 || pos2 > text->Length)//nullptr - это означает, что строка пустая
		return "";

	String^ new_str;
	for (int i = pos1; i < pos2; i++) {
		new_str += text[i];
	}

	return new_str;
}

int PrivateMethodsForVisitor::GetNumber(String^ s) {
	if (!CheckNumber(s))
		return -1;

	int length = s->Length,
		count = 0;

	for (int i = 0; i < length; i++)
		count = count * 10 + (int)s[i] - (int)'0';

	return count;
}

bool PrivateMethodsForVisitor::CheckNumber(String^ s) {
	int length;
	if(s == nullptr || (length = s->Length == 0))
		return false;

	for (int i = 0; i < length; i++) {
		if (!(s[i] >= '0' && s[i] <= '9'))
			return false;
	}

	return true;
}

Date^ PrivateMethodsForVisitor::ParsingDate(String^ s) {
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

ArrayList^ PrivateMethodsForVisitor::ParsingOrders(String^ s) {
	ArrayList^ a = gcnew ArrayList();
	int poz;

	while (poz != -1) {
		String^ ordr;

		poz = PosSumbol(s, ',');
		if(poz != -1)
			ordr = GetString(s, 0, poz);
		else//если это последний заказ
			ordr = GetString(s, 0, s->Length);

		a->Add(ordr);
		s = GetString(s, poz + 2, s->Length);
	}

	return a;
}

