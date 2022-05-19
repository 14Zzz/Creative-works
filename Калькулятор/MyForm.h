#pragma once

namespace Kalkulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ Texta;
	private: System::Windows::Forms::TextBox^ Textb;
	private: System::Windows::Forms::TextBox^ Textc;
	protected:



	protected:



	protected:






	private: System::Windows::Forms::Button^ Enter;
	private: System::Windows::Forms::Label^ Yrawnenie;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ Textx1;
	private: System::Windows::Forms::TextBox^ Textx2;
	private: System::Windows::Forms::TextBox^ TextD;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ BClear;
	private: System::Windows::Forms::TextBox^ VasheY;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ менюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ теорияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::Button^ graphik;




	private: System::ComponentModel::IContainer^ components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Texta = (gcnew System::Windows::Forms::TextBox());
			this->Textb = (gcnew System::Windows::Forms::TextBox());
			this->Textc = (gcnew System::Windows::Forms::TextBox());
			this->Enter = (gcnew System::Windows::Forms::Button());
			this->Yrawnenie = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Textx1 = (gcnew System::Windows::Forms::TextBox());
			this->Textx2 = (gcnew System::Windows::Forms::TextBox());
			this->TextD = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->BClear = (gcnew System::Windows::Forms::Button());
			this->VasheY = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->менюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->теорияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->graphik = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Texta
			// 
			this->Texta->BackColor = System::Drawing::SystemColors::Menu;
			this->Texta->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Texta->Location = System::Drawing::Point(81, 136);
			this->Texta->Margin = System::Windows::Forms::Padding(4);
			this->Texta->Multiline = true;
			this->Texta->Name = L"Texta";
			this->Texta->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->Texta->Size = System::Drawing::Size(253, 24);
			this->Texta->TabIndex = 0;
			this->Texta->Text = L"2";
			// 
			// Textb
			// 
			this->Textb->BackColor = System::Drawing::SystemColors::Menu;
			this->Textb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Textb->Location = System::Drawing::Point(81, 178);
			this->Textb->Margin = System::Windows::Forms::Padding(4);
			this->Textb->Multiline = true;
			this->Textb->Name = L"Textb";
			this->Textb->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->Textb->Size = System::Drawing::Size(253, 24);
			this->Textb->TabIndex = 1;
			this->Textb->Text = L"-9";
			// 
			// Textc
			// 
			this->Textc->BackColor = System::Drawing::SystemColors::Menu;
			this->Textc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Textc->Location = System::Drawing::Point(81, 223);
			this->Textc->Margin = System::Windows::Forms::Padding(4);
			this->Textc->Multiline = true;
			this->Textc->Name = L"Textc";
			this->Textc->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->Textc->Size = System::Drawing::Size(253, 24);
			this->Textc->TabIndex = 2;
			this->Textc->Text = L"4";
			this->Textc->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// Enter
			// 
			this->Enter->BackColor = System::Drawing::Color::LightBlue;
			this->Enter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Enter->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Enter->Location = System::Drawing::Point(200, 503);
			this->Enter->Margin = System::Windows::Forms::Padding(4);
			this->Enter->Name = L"Enter";
			this->Enter->Size = System::Drawing::Size(147, 51);
			this->Enter->TabIndex = 6;
			this->Enter->Text = L"Ввод";
			this->Enter->UseVisualStyleBackColor = false;
			this->Enter->Click += gcnew System::EventHandler(this, &MyForm::Enter_Click);
			// 
			// Yrawnenie
			// 
			this->Yrawnenie->AutoSize = true;
			this->Yrawnenie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Yrawnenie->Location = System::Drawing::Point(59, 34);
			this->Yrawnenie->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Yrawnenie->Name = L"Yrawnenie";
			this->Yrawnenie->Size = System::Drawing::Size(239, 31);
			this->Yrawnenie->TabIndex = 8;
			this->Yrawnenie->Text = L"a*x^2 + b*x + c = 0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label1->Location = System::Drawing::Point(19, 135);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 25);
			this->label1->TabIndex = 9;
			this->label1->Text = L"a = ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label2->Location = System::Drawing::Point(19, 178);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 25);
			this->label2->TabIndex = 10;
			this->label2->Text = L"b = ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label3->Location = System::Drawing::Point(19, 223);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 25);
			this->label3->TabIndex = 11;
			this->label3->Text = L"c = ";
			// 
			// Textx1
			// 
			this->Textx1->BackColor = System::Drawing::Color::LightBlue;
			this->Textx1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Textx1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Textx1->Location = System::Drawing::Point(81, 318);
			this->Textx1->Margin = System::Windows::Forms::Padding(4);
			this->Textx1->Multiline = true;
			this->Textx1->Name = L"Textx1";
			this->Textx1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->Textx1->Size = System::Drawing::Size(253, 43);
			this->Textx1->TabIndex = 12;
			this->Textx1->TextChanged += gcnew System::EventHandler(this, &MyForm::Textx1_TextChanged);
			// 
			// Textx2
			// 
			this->Textx2->BackColor = System::Drawing::Color::LightBlue;
			this->Textx2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Textx2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Textx2->Location = System::Drawing::Point(81, 369);
			this->Textx2->Margin = System::Windows::Forms::Padding(4);
			this->Textx2->Multiline = true;
			this->Textx2->Name = L"Textx2";
			this->Textx2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->Textx2->Size = System::Drawing::Size(253, 45);
			this->Textx2->TabIndex = 13;
			this->Textx2->TextChanged += gcnew System::EventHandler(this, &MyForm::Textx2_TextChanged);
			// 
			// TextD
			// 
			this->TextD->BackColor = System::Drawing::Color::LightBlue;
			this->TextD->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->TextD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextD->Location = System::Drawing::Point(81, 270);
			this->TextD->Margin = System::Windows::Forms::Padding(4);
			this->TextD->Multiline = true;
			this->TextD->Name = L"TextD";
			this->TextD->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->TextD->Size = System::Drawing::Size(253, 40);
			this->TextD->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label4->Location = System::Drawing::Point(19, 276);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(50, 29);
			this->label4->TabIndex = 15;
			this->label4->Text = L"D =";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label5->Location = System::Drawing::Point(19, 324);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 29);
			this->label5->TabIndex = 16;
			this->label5->Text = L"x1 =";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label6->Location = System::Drawing::Point(19, 375);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(57, 29);
			this->label6->TabIndex = 17;
			this->label6->Text = L"x2 =";
			// 
			// BClear
			// 
			this->BClear->BackColor = System::Drawing::Color::LightBlue;
			this->BClear->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->BClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BClear->ForeColor = System::Drawing::SystemColors::ControlText;
			this->BClear->Location = System::Drawing::Point(13, 444);
			this->BClear->Margin = System::Windows::Forms::Padding(4);
			this->BClear->Name = L"BClear";
			this->BClear->Size = System::Drawing::Size(147, 110);
			this->BClear->TabIndex = 18;
			this->BClear->Text = L"Очистить";
			this->BClear->UseVisualStyleBackColor = false;
			this->BClear->Click += gcnew System::EventHandler(this, &MyForm::BClear_Click);
			// 
			// VasheY
			// 
			this->VasheY->BackColor = System::Drawing::Color::LightBlue;
			this->VasheY->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->VasheY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->VasheY->Location = System::Drawing::Point(13, 69);
			this->VasheY->Margin = System::Windows::Forms::Padding(4);
			this->VasheY->Multiline = true;
			this->VasheY->Name = L"VasheY";
			this->VasheY->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->VasheY->Size = System::Drawing::Size(334, 44);
			this->VasheY->TabIndex = 19;
			this->VasheY->TextChanged += gcnew System::EventHandler(this, &MyForm::VasheY_TextChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->менюToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(360, 24);
			this->menuStrip1->TabIndex = 20;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// менюToolStripMenuItem
			// 
			this->менюToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->теорияToolStripMenuItem,
					this->оПрограммеToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->менюToolStripMenuItem->Name = L"менюToolStripMenuItem";
			this->менюToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->менюToolStripMenuItem->Text = L"Меню";
			// 
			// теорияToolStripMenuItem
			// 
			this->теорияToolStripMenuItem->Name = L"теорияToolStripMenuItem";
			this->теорияToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->теорияToolStripMenuItem->Text = L"Теория";
			this->теорияToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::теорияToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::оПрограммеToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(149, 22);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// graphik
			// 
			this->graphik->BackColor = System::Drawing::Color::LightBlue;
			this->graphik->Location = System::Drawing::Point(201, 444);
			this->graphik->Name = L"graphik";
			this->graphik->Size = System::Drawing::Size(147, 52);
			this->graphik->TabIndex = 21;
			this->graphik->Text = L"Вид графика";
			this->graphik->UseVisualStyleBackColor = false;
			this->graphik->Click += gcnew System::EventHandler(this, &MyForm::graphik_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::LightSlateGray;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(360, 567);
			this->Controls->Add(this->graphik);
			this->Controls->Add(this->VasheY);
			this->Controls->Add(this->BClear);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->TextD);
			this->Controls->Add(this->Textx2);
			this->Controls->Add(this->Textx1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Yrawnenie);
			this->Controls->Add(this->Enter);
			this->Controls->Add(this->Textc);
			this->Controls->Add(this->Textb);
			this->Controls->Add(this->Texta);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::SystemColors::Desktop;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Калькулятор квадратных уравнений";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e){}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void Enter_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void BClear_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Textx1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void Textx2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void VasheY_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void теорияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void graphik_Click(System::Object^ sender, System::EventArgs^ e);
};
}
