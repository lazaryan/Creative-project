#pragma once
#include "Structs.h"//���������
#include "Visits.h"
#include "PrivateMethodsForVisitor.h"//��������� ������ (��� ���������� ������ ������)

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

