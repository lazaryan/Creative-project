// CMO.cpp: главный файл проекта.

#include "stdafx.h"
#include "Visits.h"
#include "RuList.h"
#include "PriseList.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;


int main(array<System::String ^> ^args)
{
	Visits^ order = gcnew Visits();
	order->SetDateSystem();
	Date^ time = gcnew Date(23, 23, 23);
	Date^ time1 = gcnew Date();
	time1 = order->ResidenceTime(time);
	//order->SetVisitor("asd;5:25:59;asd1, asd2, asd3, a");//получаем данные о посетителе
	//RuList^ vis = gcnew RuList();
	//vis->SetSub("asd;5:25:59;asd1, asd2, asd3, a");
	//vis->InputFile();

	PriseList^ pr = gcnew PriseList();//получение всех цен
	pr->SetListPrises();//получить список товаров
	//pr->SetPrise("Цезарь", 250);
	//pr->SortingPriseList();
	//pr->SetPrise("чай", 50);
	//pr->ChangePrise("чай", 60);
	//pr->RemoveProduct("чай");
	//int b = pr->PriseProduct("чай");
	//Dictionary<String^, int>^ a = gcnew Dictionary<String^, int>();
	//a= pr->SearchProduct(L"Кофе");//поиск всех продуктов, начинающихся на передоваемое слово

	/*Visits^ order = gcnew Visits();
	order->SetVisitor("asd;5:25:59;asd1, asd2, asd3, a");
	order->RecordVisits();
	order->SetVisitor("add;5:15:50;asd1, asd2, asd3, a");
	order->RecordVisits();*/
    return 0;
}
