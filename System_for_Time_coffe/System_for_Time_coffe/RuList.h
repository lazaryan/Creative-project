#pragma once
#include "Structs.h"//структуры
#include "Enums.h"
#include "Visits.h"
#include "PrivateMethods.h"
#include "MyConst.h"

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

	bool SetLIstInFile();						//Получение списка посетителей из файла

	/*возвращение*/
	ArrayList ^ GetNamesVisits();					//возващает все имена посетителей
	String^ GetResultPrise(String^ name);				//сколько должны заплатить за время
	String^ GetResultPrise(int number);

	/*работа с файлами*/
	bool OutputFile();						//внесение посетителя в отчет
	bool RemoveVisit(String^ name);					//убрать посетителя из файла
	bool RemoveVisit(int count);
	bool SetPrisePerMinute();					//получаем, сколько стоит одна минута
	bool DeleteOldFile();						//удаление старого буферного файла
	bool CreateNewFile();						//создание нового буферного файла рабочего дня

	/*поиск посетителя по имени*/
	ArrayList^ SearchVisits(String^ name);
private:
	ArrayList ^ ls;							//список посетителей (Возможно исчезнет)

	ArrayList^ ListVisitors;					//массив структур Visitor (посетитель (имя и время прихода))
	int PriseMinutes;						//сколько стоит минута

	StreamReader^ File_r;						//откуда считываем
	StreamWriter^ File_w;						//для обновления списка

	bool OpenFile(String^ path_in_file, TypeFile type);		//открыть файл
	bool Re_CreateFile(String^ path_in_file);			//пересоздать файл и открыть его
	void CloseFile(TypeFile type);					//закрытие файла

	int GetTotalTime(String^ name);					//сколько минут человек провел в кафе
	int GetTotalTime(int number);
	void ThrowInFile();						//заливка в файл содержимого массива list_pos
};
