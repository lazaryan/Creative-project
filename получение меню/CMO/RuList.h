#pragma once
#include "Structs.h"//структуры
#include "Visits.h"

using namespace System;
using namespace System::Collections;

/*
**Общий класс
**для ведения отчетности
**подсчетов
*/
ref class RuList : Visits
{
public:
	RuList();
	/*внесение нового посетителя*/
	void SetSub(String^);
	void SetSub(String^ name, String^ date, String^ orders);
	void SetSub(String^ name, Date^ date, ArrayList^ orders);
	/*запись посетителя в файл*/
	bool OutputFile();
	/*поиск посетителя по имени*/
	ArrayList^ SearchVisits(String^ name);
private:
	ArrayList ^ ls;//список посетителей
};

