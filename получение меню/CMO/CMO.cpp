// CMO.cpp: главный файл проекта.

#include "stdafx.h"
#include "Visits.h"
#include "RuList.h"
#include "PriseList.h"

using namespace System;
using namespace System::Collections;

int main(array<System::String ^> ^args)
{
	Visits^ order = gcnew Visits();
	order->SetVisitor("asd;5:25:59;asd1, asd2, asd3, a");//получаем данные о посетителе
	RuList^ vis = gcnew RuList();
	vis->SetSub("asd;5:25:59;asd1, asd2, asd3, a");
	vis->InputFile();

	PriseList^ pr = gcnew PriseList();//получение всех цен
	pr->SetListPrises();

    return 0;
}
