#pragma once

/*формы*/
#include "Setting.h"
#include "AddVisits.h"
#include "ResultPrise.h"

/*классы*/
#include "PrivateMethods.h"
#include "PriseList.h"
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

			ListVisits	= gcnew RuList();
			MyMethods	= gcnew PrivateMethods();
			ListProducts	= gcnew PriseList();
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

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: RuList		^ ListVisits;
	private: PrivateMethods ^ MyMethods;
	private: PriseList	^ ListProducts;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label18;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			this->button1->Location = System::Drawing::Point(12, 12);
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
			this->button2->Location = System::Drawing::Point(138, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 50);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Убрать";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(106)), static_cast<System::Int32>(static_cast<System::Byte>(111)),
				static_cast<System::Int32>(static_cast<System::Byte>(138)));
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(66)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)), static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::SystemColors::Window;
			this->button3->Location = System::Drawing::Point(652, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 50);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Настройки";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->dataGridView1->Location = System::Drawing::Point(528, 127);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(244, 374);
			this->dataGridView1->TabIndex = 5;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Наименование";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Цена";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(532, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Список товаров";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(8, 530);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 37);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Время прихода:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(155, 530);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 37);
			this->label3->TabIndex = 8;
			this->label3->Text = L"00:00:00";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(532, 529);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(127, 37);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Цена 1 минуты:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(652, 530);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(62, 37);
			this->label5->TabIndex = 10;
			this->label5->Text = L"0";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(720, 530);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 29);
			this->label6->TabIndex = 11;
			this->label6->Text = L"₽";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 74);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Стол№1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 110);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 13;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(119, 110);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 14;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(116, 94);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(42, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"СТАРТ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 94);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(43, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Клиент";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(11, 166);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(43, 13);
			this->label10->TabIndex = 21;
			this->label10->Text = L"Клиент";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(115, 166);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(42, 13);
			this->label11->TabIndex = 20;
			this->label11->Text = L"СТАРТ";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(11, 182);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 19;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(119, 182);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 18;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(11, 146);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(48, 13);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Стол№2";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(10, 312);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(43, 13);
			this->label13->TabIndex = 31;
			this->label13->Text = L"Клиент";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(114, 312);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(42, 13);
			this->label14->TabIndex = 30;
			this->label14->Text = L"СТАРТ";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(11, 256);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 29;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(117, 256);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 28;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(10, 292);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(48, 13);
			this->label15->TabIndex = 27;
			this->label15->Text = L"Стол№4";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(11, 240);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(43, 13);
			this->label16->TabIndex = 26;
			this->label16->Text = L"Клиент";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(115, 240);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(42, 13);
			this->label17->TabIndex = 25;
			this->label17->Text = L"СТАРТ";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(11, 331);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 24;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(117, 331);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 23;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(11, 220);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(48, 13);
			this->label18->TabIndex = 22;
			this->label18->Text = L"Стол№3";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 594);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		ListVisits->CreateDirectory();							//создаем все папки
		ListVisits->CreateNewFile();							//создаем новый буферный файл
		ListVisits->CreateReport();							//создаем дневной отчет

		ListVisits->DeleteOldFile();							//удаляем старый буферный файл

		FillList();									//загружаем в список всех посетителей
		ListVisits->SetPrisePerMinute();						//загружаем в программу цену 1 минуты
		FillListProduct();								//загружаем список товаров и их цены
		this->textBox1->Text = L"Свободно!";
		this->textBox2->Text = "00:00:00";
		this->textBox3->Text = L"Свободно!";
		this->textBox4->Text = "00:00:00";
		this->textBox5->Text = L"Свободно!";
		this->textBox6->Text = "00:00:00";
		this->textBox7->Text = L"Свободно!";
		this->textBox8->Text = "00:00:00";
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		AddVisits^ new_vis = gcnew AddVisits();

		new_vis->ShowDialog();

		this->label3->Text = "00:00:00";
		FillList();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	

		int count;
		/*if (s != "") {
			int poz = MyMethods->PosSumbol(s, ')');
			count = MyMethods->GetNumber(MyMethods->GetString(s, 0, poz)) - 1;

			String^ prise = ListVisits->GetResultPrise(count);			//сколько должен заплатить за время

			ListVisits->OutputFile(count);						//вносим посетителя в отчет

			ResultPrise^ result = gcnew ResultPrise(prise);				//создаем экземляр с данным числом
			result->ShowDialog();							//выводим сумму

			ListVisits->RemoveVisit(count);						//удаляем посетителя
		}*/


		FillList();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		Setting^ set = gcnew Setting();

		set->ShowDialog();

		ListVisits->SetPrisePerMinute();

		this->dataGridView1->Rows->Clear();
		FillListProduct();
	}

	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		//String^ s = this->listBox1->Text;

	//	int poz = MyMethods->PosSumbol(s, ')');
	//	int count = MyMethods->GetNumber(MyMethods->GetString(s, 0, poz)) - 1;

		//Date^ time = ListVisits->GetTimeVisitor(count);

		//this->label3->Text = time->house + ":" + time->minutes + ":" + time->seconds;
	}

	private: void FillList() {
		/*ListVisits->SetLIstInFile();
		ArrayList^ names = ListVisits->GetNamesVisits();

		int count = 0;

		for each(String^ name in names) {
			count++;
			String^ s = count + ") " + name;
			this->listBox1->Items->Add(s);
		}*/
	}

	private: void FillListProduct() {
		ListProducts->SetListPrises();
		Dictionary<String^, int>^ list = ListProducts->GetPrise();
		Dictionary<String^, int>::KeyCollection ^ names =
			gcnew Dictionary<String^, int>::KeyCollection(list);

		for each(String^ name in names)
			this->dataGridView1->Rows->Add(name, list[name]);

		if (!ListVisits->GetPrisePerMinute())
			ListVisits->SetPrisePerMinute();

		int prise_min = ListVisits->GetPrisePerMinute();

		this->label5->Text = prise_min + "";

	}
};
}
