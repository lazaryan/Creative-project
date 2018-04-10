﻿#pragma once
#include "ResultPrise.h"
#include "RuList.h"

namespace SystemforTimecoffe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RemoveVisits
	/// </summary>
	public ref class RemoveVisits : public System::Windows::Forms::Form
	{
	public:
		RemoveVisits(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~RemoveVisits()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(57, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(226, 30);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Выберите посетителя";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 63);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(310, 26);
			this->comboBox1->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(106)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(136)),
				static_cast<System::Int32>(static_cast<System::Byte>(106)), static_cast<System::Int32>(static_cast<System::Byte>(126)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Tw Cen MT Condensed", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::Window;
			this->button1->Location = System::Drawing::Point(113, 176);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 50);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Убрать";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &RemoveVisits::button1_Click);
			// 
			// RemoveVisits
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(334, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Name = L"RemoveVisits";
			this->Text = L"RemoveVisits";
			this->Load += gcnew System::EventHandler(this, &RemoveVisits::RemoveVisits_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		RuList^ remove_pos = gcnew RuList();
		String^ name = this->comboBox1->Text;			//получаем имя уходящего посетителя

		remove_pos->SetLIstInFile();				//получаем список всех посетителей
		remove_pos->SetPrisePerMinute();			//получаем, сколько стоит одна минута

		String^ prise = remove_pos->GetResultPrise(name);	//получаем, сколько данный человек должен заплотить
		ResultPrise^ result = gcnew ResultPrise(prise);		//создаем экземляр с данным числом
		result->ShowDialog();					//выводим сумму

		remove_pos->RemoveVisit(name);				//удаляем посетителя

		Close();						//закрываем форму
	}
	private: System::Void RemoveVisits_Load(System::Object^  sender, System::EventArgs^  e) {
		ArrayList^ names    = gcnew ArrayList();
		RuList^ names_pos   = gcnew RuList();

		names_pos->SetLIstInFile();				//получаем всех посетителей
		names = names_pos->GetNamesVisits();			//получаем имена всех посетителей

		this->comboBox1->Text = (String^)names[0];		//для начала записываем первое имя в список
		for each(String^ name in names)				//добавляем все имена в выподающий список
			this->comboBox1->Items->Add(name);
	}
	};
}
