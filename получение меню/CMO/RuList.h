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
	void SetSub(String^);//получить данные посетителя
	bool InputFile();//внести данные в файл
private:
	ArrayList ^ ls;
};

