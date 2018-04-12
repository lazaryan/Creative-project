#pragma once
#include "PriseList.h"

namespace SystemforTimecoffe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RemoveProduct
	/// </summary>
	public ref class RemoveProduct : public System::Windows::Forms::Form
	{
	public:
		RemoveProduct(void)
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
		~RemoveProduct()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(12, 77);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(316, 21);
			this->comboBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(168, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Выберите товар: ";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(17, 175);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(243, 60);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Удалить продукт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RemoveProduct::button1_Click);
			// 
			// RemoveProduct
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 247);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"RemoveProduct";
			this->Text = L"RemoveProduct";
			this->Load += gcnew System::EventHandler(this, &RemoveProduct::RemoveProduct_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RemoveProduct_Load(System::Object^  sender, System::EventArgs^  e) {
		PriseList^ list = gcnew PriseList();

		list->SetListPrises();
		ArrayList^ names = list->GetNamesProducts();

		for each(String^ name in names)
			this->comboBox1->Items->Add(name);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		PriseList^ list = gcnew PriseList();
		String^ name_prod = this->comboBox1->Text;

		list->SetListPrises();
		list->RemoveProduct(name_prod);

		Close();
	}
	};
}
