#pragma once
#include "Structs.h"//структуры
#include "Enums.h"
#include "Visits.h"
#include "PrivateMethods.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

/*
**Общий класс
**для ведения отчетности
**подсчетов
*/
ref class RuList : PrivateMethods
{
public:
	RuList();
	/*внесение нового посетителя*/
	void SetSub(String^);
	void SetSub(String^ name, String^ date, String^ orders);
	void SetSub(String^ name, Date^ date, ArrayList^ orders);
	/*запись посетителя в файл*/
	bool OutputFile();						//внесение посетителя в отчет
	/*убрать посетителя из файла*/
	bool RemoveVisit(String^ name);
	/*поиск посетителя по имени*/
	ArrayList^ SearchVisits(String^ name);
	/*Получение списка посетителей из файла*/
	bool SetLIstInFile();
	/*возвращение*/
	ArrayList ^ GetNamesVisits();
private:
	ArrayList ^ ls;//список посетителей

	Dictionary<String^, Date^>^ list_pos;

	StreamReader^ File_r;						//откуда считываем
	StreamWriter^ File_w;						//для обновления списка

	bool OpenFile(String^ path_in_file, TypeFile type);		//открыть файл
	bool Re_CreateFile(String^ path_in_file);			//пересоздать файл и открыть его
	void CloseFile(TypeFile type);					//закрытие файла
	void ThrowInFile();						//заливка в файл содержимого массива Prise
};
