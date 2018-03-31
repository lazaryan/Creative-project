#include "stdafx.h"
#include "RuList.h"

using namespace System;
using namespace System::Collections;
using namespace System::IO;

RuList::RuList()
{
	ls = gcnew ArrayList();
}

void RuList::SetSub(String^s) {
	Visits^vis = gcnew Visits();
	vis->SetVisitor(s);
	ls->Add(vis);
}

bool RuList::InputFile()
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
			for (int i = 0; i < k;i++) {
				fil->Write("{0}", buy[i]);
				if(i!=k-1){ fil->Write(", "); }
			}
			fil->WriteLine();
		}
	}
	fil->Close();
	return chek;
}
