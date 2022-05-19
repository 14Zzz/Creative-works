#include<iostream>
#include "MyForm.h"
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace System;
using namespace System::Windows::Forms;
using namespace sf;


[STAThread]
void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Kalkulator::MyForm form;
    Application::Run(% form);
}


//Кнопка ввода, решение уравнения
System::Void Kalkulator::MyForm::Enter_Click(System::Object^ sender, System::EventArgs^ e)
{
    double a, b, c, D, x1 = 0, x2 = 0, x = 0;
    try {
        a = System::Convert::ToDouble(Texta->Text);
        b = System::Convert::ToDouble(Textb->Text);
        c = System::Convert::ToDouble(Textc->Text);
        D = b * b - 4 * a * c;
        VasheY->Text = a + " * x^2 ";
        if (b >= 0)
            VasheY->Text += "+ " + b + " * x";
        else
            VasheY->Text += "- " + -1 * b + " * x";
        if (c >= 0)
            VasheY->Text += " + " + c;
        else
            VasheY->Text += " - " + -1 * c;
        VasheY->Text += " = 0";
        TextD->Text = System::Convert::ToString(D);

        if (a != 0)
        {
            if (D >= 0)
            {
                x1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
                x2 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
                if (x1 < x2) 
                {
                    Textx1->Text = System::Convert::ToString(x1);
                    Textx2->Text = System::Convert::ToString(x2);
                }
                else
                {
                    Textx1->Text = System::Convert::ToString(x2);
                    Textx2->Text = System::Convert::ToString(x1);
                }
            }
            if (D == 0)
            {
                x = -b / (2 * a);
                Textx1->Text = System::Convert::ToString(x);
                Textx2->Text = System::Convert::ToString("Уравнение имеет единственное решение");
            }
            if (D < 0)
            {
                x1 = (-1 * b ) / (2 * a);
                x2 = (-1 * b ) / (2 * a);
                Textx1->Text = System::Convert::ToString(x1) + " + " + 
                    System::Convert::ToString(sqrt(-1 * D)) + "i";
                Textx2->Text = System::Convert::ToString(x2) + " - " + 
                    System::Convert::ToString(sqrt(-1 * D)) + "i";
            }
        }
        else
        {
            MessageBox::Show("Аргумент 'a' равен 0, уравнение не квадратное.", "Ошибка",
                MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
        }
    }
    catch (...)
    {
        MessageBox::Show("Заполните поля 'a', 'b', 'c' численными значениями.", "Ошибка",
            MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
    }
}

// Кнока очистки полей
System::Void Kalkulator::MyForm::BClear_Click(System::Object^ sender, System::EventArgs^ e)
{
    Textx1->Text = System::Convert::ToString("");
    Textx2->Text = System::Convert::ToString("");
    Texta->Text = System::Convert::ToString("");
    Textb->Text = System::Convert::ToString("");
    Textc->Text = System::Convert::ToString("");
    TextD->Text = System::Convert::ToString("");
}

// Меню -> Теория
System::Void Kalkulator::MyForm::теорияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    RenderWindow window(VideoMode(1280, 720), L"Теория");

    Texture Picture;
    Picture.loadFromFile("C:/Users/User/Desktop/Teoria.png");
    Sprite Sprite1(Picture);

    Sprite1.setPosition(0, 0);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        window.draw(Sprite1);
        window.display();
    }
}

// Меню -> О программе
System::Void Kalkulator::MyForm::оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBox::Show("Калькулятор квадратных уравнений. Работу выполнил студент группы ИВТ-21-1б Бурылов Максим", "О программе",
        MessageBoxButtons::OK, MessageBoxIcon::Information);
}

// Меню -> Выход
System::Void Kalkulator::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    Application::Exit();
}

// Вид графика
System::Void Kalkulator::MyForm::graphik_Click(System::Object^ sender, System::EventArgs^ e)
{
    double a, b, c, D;
    std::string s = "";
    a = System::Convert::ToDouble(Texta->Text);
    b = System::Convert::ToDouble(Textb->Text);
    c = System::Convert::ToDouble(Textc->Text);
    D = b * b - 4 * a * c;

    if (a < 0 && D == 0) { s = "C:/Users/User/source/repos/Kalkulator/pictures/g1.jpg"; }
    else if (a > 0 && D < 0) { s = "C:/Users/User/source/repos/Kalkulator/pictures/g2.jpg"; }
    else if (a < 0 && D > 0) { s = "C:/Users/User/source/repos/Kalkulator/pictures/g3.jpg"; }
    else if (a > 0 && D > 0) { s = "C:/Users/User/source/repos/Kalkulator/pictures/g4.jpg"; }
    else if (a < 0 && D < 0) { s = "C:/Users/User/source/repos/Kalkulator/pictures/g5.jpg"; }
    else { s = "C:/Users/User/source/repos/Kalkulator/pictures/g6.jpg"; }

    RenderWindow window(VideoMode(180, 220), L"Вид");

    Texture Picture;
    Picture.loadFromFile(s);
    Sprite Sprite1(Picture);

    Sprite1.setPosition(0, 0);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.draw(Sprite1);
        window.display();
    }
}
