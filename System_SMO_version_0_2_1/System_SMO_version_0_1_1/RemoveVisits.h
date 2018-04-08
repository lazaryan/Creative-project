#pragma once
#include "RuList.h"

namespace SystemSMOversion011 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� RemoveVisits
	/// </summary>
	public ref class RemoveVisits : public System::Windows::Forms::Form
	{
	public:
		RemoveVisits(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~RemoveVisits()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  comboBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  ������;


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->������ = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(23, 72);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(257, 21);
			this->comboBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(20, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(182, 30);
			this->label1->TabIndex = 1;
			this->label1->Text = L"�������� ����������";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// ������
			// 
			this->������->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(106)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->������->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->������->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->������->ForeColor = System::Drawing::SystemColors::Window;
			this->������->Location = System::Drawing::Point(90, 163);
			this->������->Name = L"������";
			this->������->Size = System::Drawing::Size(120, 50);
			this->������->TabIndex = 2;
			this->������->Text = L"������";
			this->������->UseVisualStyleBackColor = false;
			this->������->Click += gcnew System::EventHandler(this, &RemoveVisits::������_Click);
			// 
			// RemoveVisits
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 261);
			this->Controls->Add(this->������);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Name = L"RemoveVisits";
			this->Text = L"RemoveVisits";
			this->Load += gcnew System::EventHandler(this, &RemoveVisits::RemoveVisits_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void RemoveVisits_Load(System::Object^  sender, System::EventArgs^  e) {
		ArrayList^ names   = gcnew ArrayList();
		RuList^ names_pos = gcnew RuList();

		names_pos->SetLIstInFile();
		names = names_pos->GetNamesVisits();
		this->comboBox1->Text = (String^)names[0];
		for each(String^ name in names)
			this->comboBox1->Items->Add(name);
	}
	private: System::Void ������_Click(System::Object^  sender, System::EventArgs^  e) {
		RuList^ remove_pos = gcnew RuList();
		String^ name = this->comboBox1->Text;

		remove_pos->SetLIstInFile();
		remove_pos->RemoveVisit(name);

		Close();
	}
};
}
