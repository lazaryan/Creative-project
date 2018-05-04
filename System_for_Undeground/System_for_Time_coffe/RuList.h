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
	Date^ GetTimeVisitor(int number);				//получить время прихода посетителя
	int GetPrisePerMinute();					//возвращает цену 1 минуты

	/*работа с файлами*/
	bool OutputFile(int number);					//внесение посетителя в отчет

	bool RemoveVisit(String^ name);					//убрать посетителя из файла
	bool RemoveVisit(int count);
	String^ GetNameInTable(int nimber);				//Получить имя поетителя за столом
	int GetTimeInTable(int number);					//Получить, сколько человек будет сидеть

	bool SetPrisePerMinute();					//получаем, сколько стоит одна минута

	bool DeleteOldFile();						//удаление старого буферного файла

	void CreateDirectory();						//создание необходимых папок и по нужде файлов
	bool CreateNewFile();						//создание нового буферного файла рабочего дня
	bool CreateReport();						//создать сегодняшний отчет
private:
	ArrayList^ ListVisitors;					//массив структур Visitor (посетитель (имя и время прихода))
	int PriseMinutes;						//сколько стоит минута
	int Count;							//сколько посетителей обслужили

	StreamReader^ File_r;						//откуда считываем
	StreamWriter^ File_w;						//для обновления списка

	bool OpenFile(String^ path_in_file, TypeFile type);		//открыть файл
	bool Re_CreateFile(String^ path_in_file);			//пересоздать файл и открыть его
	void CloseFile(TypeFile type);					//закрытие файла

	int GetTotalTime(String^ name);					//сколько минут человек провел в кафе
	int GetTotalTime(int number);
	void ThrowInFile();						//заливка в файл содержимого массива list_pos
};
