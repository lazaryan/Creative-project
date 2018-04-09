#include "RuList.h"
#include "MyConst.h"

using namespace System;
using namespace System::Collections;
using namespace System::IO;

RuList::RuList()
{
	ls       = gcnew ArrayList();
	list_pos = gcnew Dictionary<String^, Date^>();
}

/*
//////////////////////////////////////////////////////////////////////

		ВНЕСЕНИЕ ДАННЫХ

//////////////////////////////////////////////////////////////////////
*/

void RuList::SetSub(String^s) {
	Visits^vis = gcnew Visits();
	vis->SetVisitor(s);
	ls->Add(vis);
}

void RuList::SetSub(String^ name, String^ date, String^ orders) {
	Visits^vis = gcnew Visits();
	vis->SetVisitor(name, date, orders);
	ls->Add(vis);
}

void RuList::SetSub(String^ name, Date^ date, ArrayList^ orders) {
	Visits^vis = gcnew Visits();
	vis->SetVisitor(name, date, orders);
	ls->Add(vis);
}

ArrayList^ RuList::SearchVisits(String ^ name)
{
	ArrayList^ search = gcnew ArrayList();
	int i = 0;
	for each(Visits ^ s in ls)
	{
		if (s->GetName() == name) { search->Add(ls[i]); }
		i++;
	}
	return search;
}

/*
/////////////////////////////////////////////////////////////////////////////////////

		ВОЗВРАЩЕНИЕ ДАННЫХ

/////////////////////////////////////////////////////////////////////////////////////
*/

ArrayList ^ RuList::GetNamesVisits() {
	ArrayList^ list = gcnew ArrayList();
	Dictionary<String^, Date^>::KeyCollection ^ names =
		gcnew Dictionary<String^, Date^>::KeyCollection(list_pos);

	for each(String^ name in names)
		list->Add(name);

	return list;
}


/*
/////////////////////////////////////////////////////////////////////////////////////

		РАБОТА С ФАЙЛАМИ

////////////////////////////////////////////////////////////////////////////////////
*/

bool RuList::OutputFile()
{
	OpenFile(SOURCE_FILE_REPORT, Writer);

	for each(Visits ^ s in ls){
		Date^ date     = s->GetDate();
		ArrayList^ buy = s->GetOrders();

		File_w->Write("{0};", s->GetName());
		File_w->Write("{0}:{1}:{2};", date->house, 
						date->minutes, 
						date->seconds);

		int k = buy->Count;
		for (int i = 0; i < k; i++){
			File_w->Write("{0}", buy[i]);
			if (i != k - 1) { File_w->Write(", "); }
		}

		File_w->WriteLine();
		}

	CloseFile(Writer);

	return true;
}

bool RuList::SetLIstInFile() {
	int poz;

	OpenFile(SOURCE_FILE_VISITS_LIST, Reader);

	while (!File_r->EndOfStream) {
		String^ s = File_r->ReadLine();

		poz = PosSumbol(s, ';');

		String  ^ name = GetString(s, 0, poz),
			^ date = GetString(s, poz + 1, s->Length);

		list_pos->Add(name, ParsingDate(date));
	}

	CloseFile(Reader);
	return true;
}

bool  RuList::RemoveVisit(String^ name) {
	list_pos->Remove(name);

	ThrowInFile();

	return true;
}


/*
/////////////////////////////////////////////////////////////////////////////////////////////////

		ОТКРЫТИЕ ФАЙЛА

/////////////////////////////////////////////////////////////////////////////////////////////////
*/

bool RuList::OpenFile(String^ path_in_file, TypeFile type) {
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

bool RuList::Re_CreateFile(String^ path_in_file) {
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

void RuList::CloseFile(TypeFile type) {
	if (type == Writer)
		File_w->Close();
	else
		File_r->Close();
}

/*
//////////////////////////////////////////////////////////////////////////////////////////////

		СЛУЖЕБНЫЕ МЕТОДЫ

//////////////////////////////////////////////////////////////////////////////////////////////
*/

void RuList::ThrowInFile() {
	Dictionary<String^, Date^>::KeyCollection ^ names =
		gcnew Dictionary<String^, Date^>::KeyCollection(list_pos);

	Re_CreateFile(SOURCE_FILE_VISITS_LIST);

	for each(String^ name in names) {
		File_w->WriteLine("{0};{1}", name, GetStringInDate(list_pos[name]));
	}

	CloseFile(Writer);
}
