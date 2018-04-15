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
	/// Сводка для AddProductInMenu
	/// </summary>
	public ref class AddProductInMenu : public System::Windows::Forms::Form
	{
	public:
		AddProductInMenu(void)
		{
			InitializeComponent();
			MyMethods = gcnew PrivateMethods();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AddProductInMenu()
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
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(324, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введине наименование продукта: ";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(341, 49);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(259, 26);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &AddProductInMenu::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(466, 101);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 29);
			this->label2->TabIndex = 5;
			this->label2->Text = L"₽";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(341, 101);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 29);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &AddProductInMenu::textBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(264, 30);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Введите стоимость :";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(16, 174);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(225, 49);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddProductInMenu::button1_Click);
			// 
			// AddProductInMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(633, 249);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"AddProductInMenu";
			this->Text = L"AddProductInMenu";
			this->Load += gcnew System::EventHandler(this, &AddProductInMenu::AddProductInMenu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		PriseList^ add_prise = gcnew PriseList();

		String^ name_prod = this->textBox1->Text;
		String^ prise_prod = this->textBox2->Text;

		add_prise->SetListPrises();
		add_prise->SetPrise(name_prod, prise_prod);

		Close();
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		int length;

		if (this->textBox1->Text == nullptr ||
			(length = this->textBox1->Text->Length) == 0 ||
			length > 30 || 
			this->textBox2->Text == nullptr || this->textBox2->Text == "" || !MyMethods->CheckNumber(this->textBox2->Text))
			this->button1->Enabled = false;
		else
			this->button1->Enabled = true;
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		int length;
		String^ s = this->textBox2->Text;
		if (s == nullptr ||
			(length = s->Length) == 0 ||
			length > 4 || !MyMethods->CheckNumber(s) ||
			this->textBox1->Text == nullptr || this->textBox1->Text == "")
			this->button1->Enabled = false;
		else
			this->button1->Enabled = true;
	}
	private: System::Void AddProductInMenu_Load(System::Object^  sender, System::EventArgs^  e) {
		this->button1->Enabled = false;
		this->textBox1->Clear();
		this->textBox2->Clear();
	}
};
}
