#pragma once
#include "Structs.h"//структуры
#include "Visits.h"
#include "PrivateMethodsForVisitor.h"//служебные методы (для корректной работы класса)

using namespace System;
using namespace System::Collections;

ref class RuList 
{
public:
	RuList();
	void SetSub(String^ data);
	void SetSub(String^ name, String^ date, String^ orders);
	void SetSub(String^ name, Date^ date, ArrayList^ orders);
	bool OutputFile();
	ArrayList^ SearchVisits(String^ name);
private:
	ArrayList ^ ls;
	bool Equality(String^ out, String^ in);
};

