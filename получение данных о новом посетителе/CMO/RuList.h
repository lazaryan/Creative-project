#pragma once
#include "Structs.h"//структуры
#include "Visits.h"
#include "PrivateMethodsForVisitor.h"//служебные методы (для корректной работы класса)

using namespace System;
using namespace System::Collections;

ref class RuList : Visits
{
public:
	RuList();
	void SetSub(String^);
	bool InputFile();
private:
	ArrayList ^ ls;
};

