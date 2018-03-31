#include "MyForm.h"
#include "MyForm2add.h"

	
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WinForm4::MyForm form; 
	Application::Run(%form);

}

