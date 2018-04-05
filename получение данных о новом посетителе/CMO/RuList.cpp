#include "stdafx.h"
#include "RuList.h"
#include "Structs.h"//структуры
#include "Visits.h"
#include "PrivateMethodsForVisitor.h"//служебные методы (для корректной работы класса)

using namespace System;
using namespace System::Collections;
using namespace System::IO;

RuList::RuList()
{
	ls = gcnew ArrayList();
}

void RuList::SetSub(String^ data) {
	Visits^vis = gcnew Visits();
	vis->SetVisitor(data);
	ls->Add(vis);
}

void RuList::SetSub(String^ name, String^ date, String^ orders) {
	Visits^vis = gcnew Visits();
	vis->SetVisitor(name, date, orders);
	ls->Add(vis);
}

void RuList::SetSub(String^ name, Date^ date, ArrayList^ orders) {
	Visits^vis = gcnew Visits();
	vis->SetVisitor(name, date, orders);
	ls->Add(vis);
}

bool RuList::OutputFile()
{
	bool chek = true;
	StreamWriter^ fil;
	try
	{
		fil = gcnew StreamWriter("Text.txt");
	}
	catch (...)
	{
		chek = false;
	}
	if (chek)
	{
		for each(Visits ^ s in ls)
		{
			fil->Write("{0};", s->GetName());
			Date^ date = s->GetDate();
			fil->Write("{0}:{1}:{2};",date->house,date->minutes,date->seconds);
			ArrayList^ buy = s->GetOrders();
			int k = buy->Count;
			for (int i = 0; i < k;i++) 
			{
				fil->Write("{0}", buy[i]);
				if(i!=k-1){ fil->Write(", "); }
			}
			fil->WriteLine();
		}
	}
	fil->Close();
	return chek;
}

ArrayList^ RuList::SearchVisits(String ^ name) 
{
	ArrayList^ search = gcnew ArrayList();
	int i = 0;
	for each(Visits ^ s in ls) 
	{
		if (Equality(s->GetName(), name)) { search->Add(ls[i]); }
		i++;
	}
	return search;
}

bool RuList::Equality(String^ out, String^ in) {
	int in_length = in->Length;
	int out_length = out->Length;
	if (in_length != out_length) { return false; }
	for (int i = 0; i < in_length; i++)
		if (out[i] != in[i])
			return false;

	return true;
}