#pragma once
#include "Setting.h"
#include "AddVisits.h"
//#include "RemoveVisits.h"
#include "ResultPrise.h"

#include "PrivateMethods.h"
#include "RuList.h"

namespace SystemforTimecoffe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();

			ListVisits = gcnew RuList();
			MyMethods  = gcnew PrivateMethods();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button3;
	private: RuList		^ ListVisits;
	private: PrivateMethods ^ MyMethods;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(106)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::SystemColors::Window;
			this->button1->Location = System::Drawing::Point(50, 50);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 50);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(106)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::SystemColors::Window;
			this->button2->Location = System::Drawing::Point(206, 50);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 50);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Убрать";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(50, 177);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(276, 355);
			this->listBox1->TabIndex = 3;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(106)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::SystemColors::Window;
			this->button3->Location = System::Drawing::Point(638, 50);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 50);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Настройки";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		ListVisits->CreateDirectory();							//создаем все папки
		ListVisits->CreateNewFile();							//создаем новый буферный файл
		ListVisits->CreateReport();							//создаем дневной отчет

		ListVisits->DeleteOldFile();							//удаляем старый буферный файл

		FillList();									//загружаем в список всех посетителей
		ListVisits->SetPrisePerMinute();						//загружаем в программу цену 1 минуты
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		AddVisits^ new_vis = gcnew AddVisits();

		new_vis->ShowDialog();

		this->listBox1->Items->Clear();

		FillList();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ s = this->listBox1->Text;

		int count;
		if (s != "") {
			int poz = MyMethods->PosSumbol(s, ')');
			count = MyMethods->GetNumber(MyMethods->GetString(s, 0, poz)) - 1;

			String^ prise = ListVisits->GetResultPrise(count);			//сколько должен заплатить за время

			ListVisits->OutputFile(count);						//вносим посетителя в отчет

			ResultPrise^ result = gcnew ResultPrise(prise);				//создаем экземляр с данным числом
			result->ShowDialog();							//выводим сумму

			ListVisits->RemoveVisit(count);						//удаляем посетителя
		}

		this->listBox1->Items->Clear();

		FillList();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		Setting^ set = gcnew Setting();

		set->ShowDialog();
	}

	private: void FillList() {
		ListVisits->SetLIstInFile();
		ArrayList^ names = ListVisits->GetNamesVisits();

		int count = 0;

		for each(String^ name in names) {
			count++;
			String^ s = count + ") " + name;
			this->listBox1->Items->Add(s);
		}
	}
};
}
