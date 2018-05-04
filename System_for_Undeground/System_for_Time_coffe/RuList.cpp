#include "RuList.h"
#include "Structs.h"

using namespace System;
using namespace System::Collections;
using namespace System::IO;

RuList::RuList()
{
	ListVisitors = gcnew ArrayList();
	Count = 0;
}

/*
//////////////////////////////////////////////////////////////////////

		ВНЕСЕНИЕ ДАННЫХ

//////////////////////////////////////////////////////////////////////
*/

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

bool RuList::SetPrisePerMinute() {
	if (OpenFile(SOURCE_FILE_PRISE_ONE_MINUTE, Reader)) {
		String^ prise = File_r->ReadLine();
		PriseMinutes = GetNumber(prise);

		CloseFile(Reader);
	}
	else {
		OpenFile(SOURCE_FILE_PRISE_ONE_MINUTE, Writer);

		File_w->WriteLine(DEFAULT_PRISE);
		PriseMinutes = DEFAULT_PRISE;

		CloseFile(Writer);
	}
	return true;
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

Date^ RuList::GetTimeVisitor(int number) {
	if (!(number < 0)) {
		Visitor^ vis = (Visitor^)ListVisitors[number];

		return vis->TimeStart;
	}
	Date^ date = gcnew Date(00, 00, 00);
	return date;
}

int RuList::GetPrisePerMinute() {
	return PriseMinutes;
}

String^ RuList::GetNameInTable(int number) {
	String^ s;
	OpenFile(SOURCE_FILE_VISITS_LIST, Reader);

	while (!File_r->EndOfStream) {
		s = File_r->ReadLine();
		int n = PosSumbol(s, ';');
		if (number == GetNumber(GetString(s, 0, n))) {
			s = GetString(s, n + 1, s->Length);
			n = PosSumbol(s, ';');
			s = GetString(s, 0, n);
			break;
		}
	}


	CloseFile(Reader);
	return s;
}

int RuList::GetTimeInTable(int number) {
	String^ s;
	OpenFile(SOURCE_FILE_VISITS_LIST, Reader);

	while (!File_r->EndOfStream) {
		s = File_r->ReadLine();
		int n = PosSumbol(s, ';');

		if (number == GetNumber(GetString(s, 0, n))) {
			n = PosFinishSumbol(s, ';');
			s = GetString(s, n + 1, s->Length);
			break;
		}
	}

	CloseFile(Reader);
	return GetNumber(s);
}

/*
/////////////////////////////////////////////////////////////////////////////////////

		РАБОТА С ФАЙЛАМИ

////////////////////////////////////////////////////////////////////////////////////
*/

bool RuList::OutputFile(int n) {
	OpenFile(SOURCE_FILE_REPORT, Writer);
	Count++;

	Visitor^ vis = (Visitor^)ListVisitors[n];
	String^ name = vis->Name;
	Date^	date = vis->TimeStart;
	int	min  = GetTotalTime(n);
	String^ sum  = GetResultPrise(n);

	File_w->WriteLine("{0};{1};{2};{3};{4}", Count, name, GetStringInDate(date), min, sum);

	CloseFile(Writer);

	return true;
}

bool RuList::CreateReport() {
	int	day = DateTime::Now.Day,
		month = DateTime::Now.Month,
		year = DateTime::Now.Year;

	if (!File::Exists(SOURCE_FILE_REPORT)) {
		OpenFile(SOURCE_FILE_REPORT, Writer);

		File_w->WriteLine("Отчет на {0}\\{1}\\{2}", day, month, year);
		File_w->WriteLine();
		File_w->WriteLine("№;Имя посетителя:;Время прихода:;Проведенное время(мин):;Сумма:");

		CloseFile(Writer);
	}


	return true;
}

void RuList::CreateDirectory() {
	Directory::CreateDirectory(FOLDER_SYSTEM);
	Directory::CreateDirectory(FOLDER_REPORT);
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

bool RuList::DeleteOldFile() {
	 int	day = DateTime::Now.Day,
		month = DateTime::Now.Month,
		year = DateTime::Now.Year;

	String^ name_file = "vis_" + (day - 1) + "_" + month + "_" + year + ".txt";

	File::Delete(FOLDER_SYSTEM + name_file);
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