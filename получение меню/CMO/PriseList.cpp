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

				РАБОТА С ДАННЫМИ

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
		name_product  = GetString(product, 0, poz);
		prise_product = GetNumber(GetString(product, poz + 1, product->Length));

		Prise->Add(name_product, prise_product);
	}

	CloseFile(Reader);
	return true;
}

bool PriseList::SetPrise(String^ name, int prise) {
	Prise->Add(name, prise);
	SortingPriseList();

	ThrowInFile();

	return true;
}

bool PriseList::ChangePrise(String^ name_product, int new_prise) {
	Prise[name_product] = new_prise;

	ThrowInFile();

	return true;
}

bool PriseList::RemoveProduct(String^ name_product) {
	Prise->Remove(name_product);

	ThrowInFile();

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
	Dictionary<String^, int>^ search_list = 
		gcnew Dictionary<String^, int>();
	Dictionary<String^, int>::KeyCollection ^ names_products = 
		gcnew Dictionary<String^, int>::KeyCollection(Prise);

	for each(String^ s in names_products) {
		if (CheckIncludedString(s, name))
			search_list->Add(s, Prise[s]);
	}	

	return search_list;
}

int PriseList::PriseProduct(String^ name_product) {
	return Prise[name_product];
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

bool PriseList::Re_CreateFile(String^ path_in_file) {
	try {
		File_w = gcnew StreamWriter(path_in_file);
	}
	catch (...) {
		return false;
	}
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

/*
//////////////////////////////////////////////////////////////////////////////////////////////

				СЛУЖЕБНЫЕ МЕТОДЫ

//////////////////////////////////////////////////////////////////////////////////////////////
*/

void PriseList::ThrowInFile() {
	Dictionary<String^, int>::KeyCollection ^ names = 
		gcnew Dictionary<String^, int>::KeyCollection(Prise);

	Re_CreateFile(SOURCE_FILE_PRISE_LIST);

	for each(String^ name in names) {
		File_w->WriteLine("{0};{1}", name, GetStringInCount(Prise[name]));
	}

	CloseFile(Writer);
}

void PriseList::SortingPriseList() {
	ArrayList^ list_name = gcnew ArrayList();
	Dictionary<String^, int>::KeyCollection ^ names =
		gcnew Dictionary<String^, int>::KeyCollection(Prise);

	for each(String^ name in names)
		list_name->Add(name);

	list_name = SortingListString(list_name);
	Prise     = GetSortingPrise(list_name);
}

Dictionary<String^, int>^ PriseList::GetSortingPrise(ArrayList^ list_names) {
	Dictionary<String^, int>^ prise_new = 
		gcnew Dictionary<String^, int>();

	for each(String^ name in list_names)
		prise_new->Add(name, Prise[name]);

	return prise_new;
}