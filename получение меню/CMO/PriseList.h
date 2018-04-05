#pragma once
#include "PrivateMethods.h"
#include "Enums.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

/*
**Данный класс для получения 
**меню и всех цен из файла
**а так же для изменения и обновления его
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
	int PriseProduct(String^ name_product);//вернуть цену продукта
	/*поиск*/
	Dictionary<String^, int>^ SearchProduct(String^ name);//поиск продукта по имени
	/*изменить цену продукта*/
	bool ChangePrise(String^ name_product, int new_prise);//изменить цену данного продукта
	/*удалить продукт*/
	bool RemoveProduct(String^ name_product);//удалить тавар
private:
	Dictionary<String^, int>^ Prise;//список цен(хранится в формате (наименование, цена))
	StreamReader^ File_r;//откуда считываем
	StreamWriter^ File_w;//для обновления списка

	bool OpenFile(String^ path_in_file , TypeFile type);
	bool Re_CreateFile(String^ path_in_file);//пересоздать файл и открыть его
	void CloseFile(TypeFile type);//закрытие файла
	void ThrowInFile();//заливка в файл содержимого массива Prise
	void SortingPriseList();//сортировка по наименованиям

	Dictionary<String^, int>^ GetSortingPrise(ArrayList^ list_names);//вернуть отсортированный список
};

