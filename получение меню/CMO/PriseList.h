#pragma once
#include "PrivateMethods.h"
#include "Enums.h"

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
	Dictionary<String^, int>^ SearchProduct(String^ name);//поиск продукта по имени
private:
	Dictionary<String^, int>^ Prise;//список цен(хранится в формате (наименование, цена))
	StreamReader^ File_r;//откуда считываем
	StreamWriter^ File_w;//для обновления списка

	bool OpenFile(String^ path_in_file , TypeFile type);
	void CloseFile(TypeFile type);//закрытие файла
};

