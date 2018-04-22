﻿#pragma once
#include "PriseList.h"
#include "PrivateMethods.h"

namespace SystemforTimecoffe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для ChangePrisePerMinute
	/// </summary>
	public ref class ChangePrisePerMinute : public System::Windows::Forms::Form
	{
	public:
		ChangePrisePerMinute(void)
		{
			InitializeComponent();

			MyMethods = gcnew PrivateMethods();
			change_per_m = gcnew PriseList();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ChangePrisePerMinute()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: PrivateMethods ^ MyMethods;
	private: PriseList ^ change_per_m;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChangePrisePerMinute::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(59, 123);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 30);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Новая цена:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(72)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(259, 123);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(96, 31);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ChangePrisePerMinute::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(382, 122);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"₽";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(72)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)),
				static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::Window;
			this->button1->Location = System::Drawing::Point(140, 185);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(188, 47);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Внести изменения";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ChangePrisePerMinute::button1_Click);
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(59, 45);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(155, 30);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Старая цена:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(382, 44);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 29);
			this->label4->TabIndex = 5;
			this->label4->Text = L"₽";
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(72)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(255, 45);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 30);
			this->label5->TabIndex = 6;
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ChangePrisePerMinute
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(72)), static_cast<System::Int32>(static_cast<System::Byte>(72)),
				static_cast<System::Int32>(static_cast<System::Byte>(189)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(489, 257);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ChangePrisePerMinute";
			this->Text = L"ChangePrisePerMinute";
			this->Load += gcnew System::EventHandler(this, &ChangePrisePerMinute::ChangePrisePerMinute_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ price = textBox1->Text;
		change_per_m->ChangePriceMin(price);
		Close();
	}
	private: System::Void ChangePrisePerMinute_Load(System::Object^  sender, System::EventArgs^  e) {
		this->button1->Enabled = false;
		this->label5->Text = change_per_m->GetPrisePerMinute();
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		int length;
		String^ s = this->textBox1->Text;
		if(s == nullptr || 
			(length = s->Length) == 0 ||
			length > 4 || !MyMethods->CheckNumber(s))
			this->button1->Enabled = false;
		else
			this->button1->Enabled = true;
	}
};
}
