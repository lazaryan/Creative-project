#pragma once
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
	/// Сводка для ChangePriseProduct
	/// </summary>
	public ref class ChangePriseProduct : public System::Windows::Forms::Form
	{
	public:
		ChangePriseProduct(void)
		{
			InitializeComponent();
			list		= gcnew PriseList();
			MyMethods	= gcnew PrivateMethods();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ChangePriseProduct()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: PriseList ^ list;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Выберите продукт: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(321, 192);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(192, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Введите новую цену: ";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(481, 243);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(48, 29);
			this->label3->TabIndex = 4;
			this->label3->Text = L"₽";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(325, 243);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 29);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &ChangePriseProduct::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(325, 318);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(204, 49);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Изменить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ChangePriseProduct::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(16, 77);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(292, 290);
			this->listBox1->TabIndex = 6;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ChangePriseProduct::listBox1_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(321, 77);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(126, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Старая цена: ";
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(481, 120);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 29);
			this->label5->TabIndex = 8;
			this->label5->Text = L"₽";
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(321, 127);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(126, 20);
			this->label6->TabIndex = 9;
			this->label6->Text = L"0";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ChangePriseProduct
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(545, 382);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ChangePriseProduct";
			this->Text = L"ChangePriseProduct";
			this->Load += gcnew System::EventHandler(this, &ChangePriseProduct::ChangePriseProduct_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ChangePriseProduct_Load(System::Object^  sender, System::EventArgs^  e) {
		list->SetListPrises();
		ArrayList^ names = list->GetNamesProducts();

		this->button1->Enabled = false;
		this->label6->Text = "0";

		for each(String^ name in names)
			this->listBox1->Items->Add(name);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ name = this->listBox1->Text;
		String^ new_prise = this->textBox1->Text;

		list->ChangePrise(name, new_prise);

		Close();
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->listBox1->Text != nullptr && this->listBox1->Text != "" 
			&& this->textBox1->Text != nullptr && this->textBox1->Text->Length != 0 && MyMethods->CheckNumber(this->textBox1->Text)) {
			this->button1->Enabled = true;
			this->label6->Text = MyMethods->GetStringInCount(list->PriseProduct(this->listBox1->Text));
		}
		else if(this->listBox1->Text != nullptr && this->listBox1->Text != ""){
			this->label6->Text = MyMethods->GetStringInCount(list->PriseProduct(this->listBox1->Text));
		}
		else {
			this->button1->Enabled = false;
			this->label6->Text = "0";
		}

	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		int length;
		String^ s = this->textBox1->Text;
		if (s == nullptr ||
			(length = s->Length) == 0 ||
			length > 4 || !MyMethods->CheckNumber(s))
			this->button1->Enabled = false;
		else
			this->button1->Enabled = true;
	}
};
}
