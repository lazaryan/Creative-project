#include "stdafx.h"
#include "PriseList.h"
//путь к файлу, где лежит прайс лист
#define SOURCE_FILE_PRISE_LIST "Data/prise.txt"

PriseList::PriseList()
{
	Prise = gcnew Dictionary<String^, int>();
}

bool PriseList::SetListPrises() {
	OpenFileRead(SOURCE_FILE_PRISE_LIST);

	String^ product;
	int poz;

	while (!File->EndOfStream) {
		String^ name_product;
		int prise_product;

		product = File->ReadLine();

		poz = PosSumbol(product, ';');
		name_product = GetString(product, 0, poz);
		prise_product = GetNumber(GetString(product, poz + 1, product->Length));

		Prise->Add(name_product, prise_product);
	}

	CloseFileRead();
	return true;
}

bool PriseList::OpenFileRead(String^ path_in_file) {
	try {
		File = gcnew StreamReader(path_in_file);
	}
	catch (...) {
		return false;
	}

	return true;
}

void PriseList::CloseFileRead() {
	File->Close();
}

Dictionary<String^, int>^ PriseList::GetPrise() {
	return Prise;
}

bool PriseList::SetPrise(String^ name, int prise) {
	if (!OpenFileWrite(SOURCE_FILE_PRISE_LIST))
		return false;

	String^ s = name + ";" + GetStringInCount(prise);

	File_w->WriteLine(s);
	Prise->Add(name, prise);

	CloseFileWriter();
	return true;
}

bool PriseList::OpenFileWrite(String^ path_in_file) {
	try {
		File_w = gcnew StreamWriter(path_in_file, true);
	}
	catch (...) {
		return false;
	}

	return true;
}

void PriseList::CloseFileWriter() {
	File_w->Close();
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

