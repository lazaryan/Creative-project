#include "RuList.h"
#include "Structs.h"

using namespace System;
using namespace System::Collections;
using namespace System::IO;

RuList::RuList()
{
	ls           = gcnew ArrayList();
	ListVisitors = gcnew ArrayList();
}

/*
//////////////////////////////////////////////////////////////////////

		ВНЕСЕНИЕ ДАННЫХ

//////////////////////////////////////////////////////////////////////
*/

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

	for each(Visitor^ pos in ListVisitors)
		list->Add(pos->Name);

	return list;
}

String^ RuList::GetResultPrise(String^ name) {
	int time = GetTotalTime(name);
	int prise = time * PriseMinutes;

	return GetStringInCount(prise);
}

String^ RuList::GetResultPrise(int number) {
	int time = GetTotalTime(number);
	int prise = time * PriseMinutes;

	return GetStringInCount(prise);
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

	ListVisitors->Clear();

	OpenFile(SOURCE_FILE_VISITS_LIST, Reader);

	while (!File_r->EndOfStream) {
		String^ s = File_r->ReadLine();

		poz = PosSumbol(s, ';');

		String  ^ name = GetString(s, 0, poz),
			^ date = GetString(s, poz + 1, s->Length);

		Visitor^ pos = gcnew Visitor(name, ParsingDate(date));
		ListVisitors->Add(pos);
	}

	CloseFile(Reader);
	return true;
}

bool  RuList::RemoveVisit(String^ name) {

	int number = -1;
	for each(Visitor^ pos in ListVisitors) {
		number++;
		if (name == pos->Name)
			break;
	}
	ListVisitors->Remove(ListVisitors[number]);

	ThrowInFile();

	return true;
}

bool RuList::RemoveVisit(int count) {
	ListVisitors->Remove(ListVisitors[count]);

	ThrowInFile();

	return true;
}

bool RuList::SetPrisePerMinute() {
	OpenFile(SOURCE_FILE_PRISE_ONE_MINUTE, Reader);

	String^ prise = File_r->ReadLine();
	PriseMinutes = GetNumber(prise);

	CloseFile(Reader);

	return true;
}

bool RuList::DeleteOldFile() {
	int	day  = DateTime::Now.DayOfYear,
		year = DateTime::Now.Year;

	String^ name_file = "vis_" + (day - 1) + "_" + year + ".txt";

	File::Delete("Data/" + name_file);
	return true;
}

bool RuList::CreateNewFile() {
	OpenFile(SOURCE_FILE_VISITS_LIST, Writer);
	CloseFile(Writer);

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
	Re_CreateFile(SOURCE_FILE_VISITS_LIST);

	for each (Visitor^ pos in ListVisitors)
		File_w->WriteLine("{0};{1}", pos->Name, GetStringInDate(pos->TimeStart));

	CloseFile(Writer);
}

int RuList::GetTotalTime(String^ name) {
	DateTime time_system = DateTime::Now;

	Date ^time_now = gcnew Date(time_system.Hour, time_system.Minute, time_system.Second);
	Date ^time_start;

	for each(Visitor^ pos in ListVisitors)
		if (name == pos->Name)
			time_start = pos->TimeStart;

	return (GetMinutes(time_now) - GetMinutes(time_start));
}

int RuList::GetTotalTime(int number) {
	DateTime time_system = DateTime::Now;
	Date ^time_now       = gcnew Date(time_system.Hour, time_system.Minute, time_system.Second);

	Visitor^ pos = (Visitor^)ListVisitors[number];
	Date ^time_start = pos->TimeStart;

	return (GetMinutes(time_now) - GetMinutes(time_start));
}