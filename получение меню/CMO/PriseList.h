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
	/*внесение*/
	bool SetPrise(String^ name_product, int prise_product);
	/*возвращение*/
	Dictionary<String^, int>^ GetPrise();//вернуть прайс-лист
	/*поиск*/
	//требует отладки
	Dictionary<String^, int>^ SearchProduct(String^ name);//поиск продукта по имени
private:
	Dictionary<String^, int>^ Prise;//список цен(хранится в формате (наименование, цена))
	StreamReader^ File;//откуда считываем
	StreamWriter^ File_w;//для обновления списка

	bool OpenFileRead(String^ path_in_file);//открыть файл для чтения
	bool OpenFileWrite(String^ path_in_file);//открыть файл для записи
	void CloseFileRead();//закрыть файл для чтения
	void CloseFileWriter();//закрыть файл для записи
};

