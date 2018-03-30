#pragma once
#include "Structs.h"//структуры
#include "Visits.h"

using namespace System;
using namespace System::Collections;

/*
**Общий класс
**для ведения отчетности
**подсчетов
**(возможно обновление меню)
*/
ref class RuList : Visits
{
public:
	RuList();
	void SetSub(String^);
	bool InputFile();
private:
	ArrayList ^ ls;
};

