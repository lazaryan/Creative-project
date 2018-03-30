#pragma once
#include "PrivateMethods.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
/*
**Данный класс для получения 
**меню и всех цен из файла
*/
ref class PriseList : PrivateMethods
{
public:
	PriseList();
	/*получение*/
	bool SetListPrises();//получение списка продуктов
	bool OpenFileRead(String^ path_in_file);//открыть файл для чтения
	void CloseFileRead();//закрыть файл для чтения
	/*внесение*/
private:
	Dictionary<String^, int>^ Prise;//список цен(хранится в формате (наименование, цена))
	StreamReader^ File;//откуда считываем
	StreamWriter^ File_w;//для обновления списка
};

