#include "stdafx.h"
#include "PriseList.h"


PriseList::PriseList()
{
	Prise = gcnew Dictionary<String^, int>();
}

bool PriseList::SetListPrises() {
	OpenFileRead("Data/prise.txt");

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

