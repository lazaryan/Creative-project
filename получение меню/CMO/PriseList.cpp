#include "stdafx.h"
#include "PriseList.h"

//путь к файлу, где лежит прайс лист
#define SOURCE_FILE_PRISE_LIST "Data/prise.txt"

PriseList::PriseList()
{
	Prise = gcnew Dictionary<String^, int>();
}

/*
//////////////////////////////////////////////////////////////////////////////////////////

				ПОЛУЧЕНИЕ И ВНЕСЕНИЕ ДАННЫХ

/////////////////////////////////////////////////////////////////////////////////////////
*/

bool PriseList::SetListPrises() {
	OpenFile(SOURCE_FILE_PRISE_LIST, Reader);

	String^ product;
	int poz;

	while (!File_r->EndOfStream) {
		String^ name_product;
		int prise_product;

		product = File_r->ReadLine();

		poz = PosSumbol(product, ';');
		name_product = GetString(product, 0, poz);
		prise_product = GetNumber(GetString(product, poz + 1, product->Length));

		Prise->Add(name_product, prise_product);
	}

	CloseFile(Reader);
	return true;
}

bool PriseList::SetPrise(String^ name, int prise) {
	if(!OpenFile(SOURCE_FILE_PRISE_LIST, Writer))
		return false;

	String^ s = name + ";" + GetStringInCount(prise);

	File_w->WriteLine(s);
	Prise->Add(name, prise);

	CloseFile(Writer);
	return true;
}

/*
////////////////////////////////////////////////////////////////////////////////////////////////

				ВОЗВРАЩЕНИЕ ЗНАЧЕНИЙ

////////////////////////////////////////////////////////////////////////////////////////////////
*/

Dictionary<String^, int>^ PriseList::GetPrise() {
	return Prise;
}

Dictionary<String^, int>^ PriseList::SearchProduct(String^ name) {
	Dictionary<String^, int>^ search_list = gcnew Dictionary<String^, int>();
	Dictionary<String^, int>::KeyCollection ^ names_products = gcnew Dictionary<String^, int>::KeyCollection(Prise);

	for each(String^ s in names_products) {
		if (CheckIncludedString(s, name))
			search_list->Add(s, Prise[s]);
	}	

	return search_list;
}

/*
/////////////////////////////////////////////////////////////////////////////////////////////////

				ОТКРЫТИЕ ФАЙЛА

/////////////////////////////////////////////////////////////////////////////////////////////////
*/

bool PriseList::OpenFile(String^ path_in_file, TypeFile type) {
	try {
		if (type == Writer)
			File_w = gcnew StreamWriter(path_in_file, true);
		else
			File_r = gcnew StreamReader(path_in_file);
	}
	catch (...) {
		return false;
	}

	return true;
}

/*
//////////////////////////////////////////////////////////////////////////////////////////////

				ЗАКРЫТИЕ ФАЙЛОВ

//////////////////////////////////////////////////////////////////////////////////////////////
*/

void PriseList::CloseFile(TypeFile type) {
	if(type == Writer)
		File_w->Close();
	else
		File_r->Close();
}
