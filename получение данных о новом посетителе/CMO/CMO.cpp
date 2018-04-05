// CMO.cpp: главный файл проекта.

#include "stdafx.h"
#include "Visits.h"
#include "RuList.h"

using namespace System;
using namespace System::Collections;

int main(array<System::String ^> ^args)
{
	Visits^ order = gcnew Visits();
	order->SetVisitor("asd;5:25:59;asd1, asd2, asd3, a");//получаем данные о посетителе
	RuList^ vis = gcnew RuList();
	vis->SetSub("as;5:25:59;asd1, asd2, asd3, a");
	vis->SetSub("aswed;5:25:59;asd1, asd2, asd3, a");
	vis->SetSub("aswqd;5:25:59;asd1, asd2, asd3, a");
	vis->SetSub("aswd;5:25:59;asd1, asd2, asd3, a");
	vis->SetSub("ased;5:25:59;asd1, asd2, asd3, a");
	vis->SetSub("ased;5:25:59;asd1, asd2, asd3, a");
	ArrayList^ ret=vis->SearchVisits("as");
	vis->OutputFile();
    return 0;
}
