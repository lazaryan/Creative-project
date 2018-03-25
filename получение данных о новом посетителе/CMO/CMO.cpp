// CMO.cpp: главный файл проекта.

#include "stdafx.h"
#include "Visits.h"

using namespace System;
using namespace System::Collections;

int main(array<System::String ^> ^args)
{
	Visits^ order = gcnew Visits();
	order->SetVisitor("asd;5:25:59;asd1, asd2, asd3, a");//получаем данные о посетителе

    return 0;
}
