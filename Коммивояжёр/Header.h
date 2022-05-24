#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int Win_W; 
int Win_H; 

int n; 
int** dynamic_mas; 
int* result; 
int*** ukazatel_na_matrix; 


const int maxSize = 15;
int kolvo_vershin; 

template<class T>

class Graph 
{
	vector<T> vertList;	
	vector<T> labelList; 
	bool* visitedVerts = new bool[vertList.size()];
public:	
	int adjMatrix[maxSize][maxSize]; 
	Graph(); 
	~Graph(); 
	void RenderingGraph(); 
	void Way_km(const T& vertex1, const T& vertex2, int weight); 
	void Add_Vertex(const T& vertex); 
	void Delete_this_Vertex(); 
	int GetVertPos(const T& vertex);
	bool IsEmpty(); 
	bool IsFull(); 
	int Getter_kolvo_veshin(); 
	int Getter_kolvo_border(); 
	int Getter_length(const T& vertex1, const T& vertex2); 
	vector<T> Getter_n(const T& vertex); 
	void Print(); 
};

const int Predel = 100000; // заглушка для прохода в цикл
int parametr; // 

struct vertCoord
{
	int x, y;
};
vertCoord vertC[20];

Graph<int> graph; 


void creating_variables(int***& matrix, int& n, int**& dynamic_mas, int*& result)
{ 
	n = kolvo_vershin; 
	dynamic_mas = new int* [n]; 

	result = new int[n]; 

	matrix = new int** [n];

	for (int i = 0; i <= n; i++) 
	{
		dynamic_mas[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int* [n];
		for (int j = 0; j < n; j++)
		{
			if (graph.adjMatrix[i][j] == 0)
			{
				matrix[i][j] = nullptr; 
				continue;	
			}
			matrix[i][j] = new int(graph.adjMatrix[i][j]);
		}
	}
}

void task_solution(int*** matrix, int n, int** dynamic_mas, int* path) 
{
	int fist_min;
	int second_min;

	for (int l = 0; l < n; l++) // Редукция строк
	{
		for (int i = 0; i < n; i++)
		{
			int min = Predel;
			for (int j = 0; j < n; j++)
				if (matrix[i][j] && min > *matrix[i][j])
					min = *matrix[i][j];
			for (int j = 0; j < n; j++)
				if (matrix[i][j])
					*matrix[i][j] -= min;
		}
		for (int j = 0; j < n; j++) // Редукция столбцов
		{
			int min = Predel;
			for (int i = 0; i < n; i++)
				if (matrix[i][j] && min > *matrix[i][j])
					min = *matrix[i][j];
			for (int i = 0; i < n; i++)
				if (matrix[i][j])
					*matrix[i][j] -= min;
		}

		for (int i = 0; i < n; i++) // Происходит оценка нулевых элементов
			for (int j = 0; j < n; j++)
				dynamic_mas[i][j] = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] && !*matrix[i][j])
				{
					fist_min = Predel; 
					second_min = Predel;

					for (int l = 0; l < n; l++)
						if (l != i && matrix[l][j] && fist_min > *matrix[l][j])
							fist_min = *matrix[l][j];

					for (int l = 0; l < n; l++)
						if (l != j && matrix[i][l] && second_min > *matrix[i][l])
							second_min = *matrix[i][l];

					dynamic_mas[i][j] = fist_min + second_min;
				}
			}

		int waste = 0, line_i = 0, column_j = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][j] && waste < dynamic_mas[i][j])
				{
					waste = dynamic_mas[i][j];
					line_i = i;
					column_j = j;
				}
		path[line_i] = column_j;

		for (int i = 0; i < n; i++) 
			matrix[i][column_j] = nullptr;

		for (int i = 0; i < n; i++)
			matrix[line_i][i] = nullptr;

		matrix[column_j][line_i] = nullptr;
	}
}

void traveler_man(int*** matrix, int n, int** dynamic_mas, int* result)
{
	creating_variables(matrix, n, dynamic_mas, result); 
	task_solution(matrix, n, dynamic_mas, result); 

	cout << "\nЗаданные пути: ";

	int s = 0; 
	int j; 
	for (int i = 0; i < n; i++)
	{
		j = result[i];
		cout << "( " << i + 1 << " --> " << j + 1 << " )" << "  "; // вывод путей между пунктами
		s += graph.adjMatrix[i][j];
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "-------------";
	}
	cout << endl << "Лучший путь: ";
	int temp = 0; // переменная для сравнения
	for (int l = 0; l < n;)
	{
		for (int i = 0, j = 0; i < n; i++)
		{
			if (temp == 0 || i + 1 == temp)
			{
				if (temp == 0) cout << i + 1; 
				j = result[i];
				temp = j + 1;
				if (temp > 0)
				{
					cout << " --> " << temp; 
					l++;
				}
			}
		}
	}
	cout << endl << "\nПуть равен: " << s << endl;
}


template<class T>
vector<T> Graph<T>::Getter_n(const T& vertex) 
{
	vector<T> nbrsList;
	int vertPos = this->GetVertPos(vertex);
	if (vertPos != (-1)) // если позиция вершины не равна -1,  
	{

		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			if (this->adjMatrix[vertPos][i] != 0 && this->adjMatrix[i][vertPos] != 0)
				nbrsList.push_back(this->vertList[i]);
		}
	}
	return nbrsList;
}



template<class T>
void Graph<T>::Add_Vertex(const T& vertex) // добавление вершины
{
	if (!this->IsFull())
	{
		this->vertList.push_back(vertex);
	}
	else
	{
		cout << "Граф заполнен. Нужно добавить новую вершину " << endl;
		return;
	}
}

template<class T>
void Graph<T>::Delete_this_Vertex() // удаление вершины
{
	this->vertList.pop_back(); // удаляет вершины в стиле стека, те начиная с вершины
}


template<class T>
int Graph<T>::Getter_kolvo_border() // количество границ
{
	int amount = 0;
	if (!this->IsEmpty())
	{
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			for (int j = 0; j < vertListSize; ++j)
			{
				if (this->adjMatrix[i][j] == this->adjMatrix[j][i] && this->adjMatrix[i][j] != 0)
					amount += 1;
			}
		}
		return (amount / 2);
	}
	else
		return 0;
}

template<class T>
int Graph<T>::Getter_length(const T& vertex1, const T& vertex2) // получение длины пути
{
	if (!this->IsEmpty())
	{
		int vertPos1 = GetVertPos(vertex1);
		int vertPos2 = GetVertPos(vertex2);
		return adjMatrix[vertPos1][vertPos2];
	}
	return 0;
}

template<class T>
int Graph<T>::Getter_kolvo_veshin() // получение количества вершин
{
	return this->vertList.size(); // возвращает размер 
}

template<class T>
bool Graph<T>::IsEmpty() // пустота
{
	if (this->vertList.size() != 0)
		return false;
	else
		return true;
}

template<class T>
bool Graph<T>::IsFull() // Места нет
{
	return (vertList.size() == maxSize);
}

template <class T>
int Graph<T>::GetVertPos(const T& vertex) // получение позиции вершины
{
	for (int i = 0; i < this->vertList.size(); ++i)
	{
		if (this->vertList[i] == vertex)
			return i;
	}
	return -1;
}

template<class T>
Graph<T>::Graph()
{
	for (int i = 0; i < maxSize; ++i)
	{
		for (int j = 0; j < maxSize; ++j)
		{
			this->adjMatrix[i][j] = 0;
		}
	}
}

template<class T>
Graph<T>::~Graph()
{
}


Graph<int> graph_implementation() // реализация графа, его логики работы...
{
	Graph<int> graph; // объект класса Graph
	int amountEdges, sourceVertex, targetVertex, edgeWeight; // создаем переменные
	cout << endl << "Укажите, в скольких городах вы хотите побывать: ";
	cin >> kolvo_vershin; // вводим количество вершин
	cout << endl;
	while (kolvo_vershin < 0) // проверка ввода
	{
		cout << "Количество городов не может быть отрицательным числом!" << endl << endl;
		cout << "Попробуйте еще раз: ";
		cin >> kolvo_vershin;
		cout << endl;
	}
	cout << endl;
	cout << "Введите количество дорог между городами: ";
	cin >> amountEdges;
	cout << endl;
	while (amountEdges < 0)
	{
		cout << endl << "Количество дорог не может быть отрицательным числом!" << endl << endl;
		cout << "Попробуйте еще раз: ";
		cin >> amountEdges;
		cout << endl;
	}
	cout << endl;

	for (int i = 1; i <= kolvo_vershin; ++i) // проход до количества вершин(включительно)
	{
		int* vertPtr = &i;
		graph.Add_Vertex(*vertPtr);
	}

	for (int i = 0; i < amountEdges; ++i)
	{
		cout << "----------------------" << endl;
		cout << "Введите " << i + 1 << " пару вершин: " << endl;
		cout << "----------------------" << endl << endl;
		cout << "Идём из вершины: ";
		cin >> sourceVertex;
		cout << endl;
		int* sourceVertPtr = &sourceVertex;
		cout << "В вершину: ";
		cin >> targetVertex;
		cout << endl;
		int* targetVertPtr = &targetVertex;

		cout << "Введите длину пути между данными вершинами(пунктами): ";
		cin >> edgeWeight;
		while (edgeWeight < 0) { cout << endl << "Длина пути не может быть отрицательной велечиной. Введите еще раз: "; cin >> edgeWeight; cout << endl; }
		cout << endl;
		graph.Way_km(*sourceVertPtr, *targetVertPtr, edgeWeight);
	}
	cout << endl;
	return graph;
}

template<class T>
void Graph<T>::Way_km(const T& vertex1, const T& vertex2, int weight) // работа с длиной пути
{
	if (this->GetVertPos(vertex1) != (-1) && this->GetVertPos(vertex2) != (-1))
	{
		int vertPos1 = GetVertPos(vertex1); // присваиваем позицию 
		int vertPos2 = GetVertPos(vertex2);
		if (this->adjMatrix[vertPos1][vertPos2] != 0 && this->adjMatrix[vertPos2][vertPos1] != 0)
		{
			cout << endl << "Переопределяем длину данного пути " << endl << endl;
			if (weight < 0) { cout << endl << "Длина добавляемого пути не может быть отрицательной велечиной" << endl; return; }
			this->adjMatrix[vertPos1][vertPos2] = weight;
			this->adjMatrix[vertPos2][vertPos1] = weight;
			return;
		}
		else
		{
			if (weight < 0) { cout << endl << "Длина добавляемого пути не может быть отрицательной велечиной" << endl; return; }
			this->adjMatrix[vertPos1][vertPos2] = weight;
			this->adjMatrix[vertPos2][vertPos1] = weight;
		}
	}
	else
	{
		cout << endl << "Таких пунктов нет" << endl;
		cout << "Подрузамевается, что вы хотели добавить пункт, поэтому даже в случае ошибочного ввода, в граф добавляется пункт " << endl << endl;
		return;
	}
}

template<class T>
void Graph<T>::Print() // вывод матрицы смежности
{
	if (!this->IsEmpty()) // если не пусто
	{
		cout << endl << "Матрица смежности: " << endl;
		for (int i = 0, vertListSize = this->vertList.size(); i < vertListSize; ++i)
		{
			cout << this->vertList[i] << " ";
			for (int j = 0; j < vertListSize; ++j)
			{
				cout << " " << this->adjMatrix[i][j] << " ";
			}
			cout << endl;
		}

	}

}

void setCoord(int i, int n) // устанавливаем координаты
{
	int R_; // в зависимости от случая принимает ширину окна или длину окна

	int x0 = Win_W / 2;
	int y0 = Win_H / 2;
	if (Win_W > Win_H)
	{
		parametr = 5 * (Win_H / 13) / n;
		R_ = Win_H / 2 - parametr - 10;
	}
	else {
		parametr = 5 * (Win_W / 13) / n;
		R_ = Win_W / 2 - parametr - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = R_ * cos(theta) + y0; // cos угла для вычисления положения линии(путя)
	float x1 = R_ * sin(theta) + x0; // sin угла для вычисления положения линии(путя)

	vertC[i].x = x1;
	vertC[i].y = y1;
}

void drawCircle(int x, int y, int R) // отрисовка круга

	glColor3f(0.3, 0.9, 0.7); // установка цвета
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.141592653589793f * float(i) / float(360); // формула точности круга
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f); // установка цвета
	float x2, y2;
	glLineWidth(2); // установка ширины прямой
	glBegin(GL_LINE_LOOP); // отличие от предыдущего примитива только в том, что последний отрезок определяется последней и первой вершиной, образуя замкнутую ломаную
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawText(int nom, int x1, int y1) // отрисовка текста
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18; // шрифт по умолчанию есть в Opengl
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawVertex(int n) // отрисовка вершины
{
	for (int i = 0; i < n; i++)
	{
		drawCircle(vertC[i].x, vertC[i].y, parametr);
		drawText(i + 1, vertC[i].x, vertC[i].y);
	}
}

void draw_Line_for_way(int text, int x0, int y0, int x1, int y1) // отрисовка линий для путей
{
	glColor3d(0.6, 0.6, 0.6);
	glLineWidth(2);
	glBegin(GL_LINES); // каждая отдельная пара вершин определяет отрезок; если задано нечетное число вершин, то последняя вершина игнорируется
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();

	drawText(text, (x0 + x1) / 2 + 10, (y0 + y1) / 2 + 10); // отрисовка текста



template<class T>
void Graph<T>::RenderingGraph() // отрисовка графа
{
	int n = vertList.size();
	for (int i = 0; i < n; i++)
	{
		setCoord(i, n); // установка координат
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = adjMatrix[i][j];
			if (a != 0)
			{
				draw_Line_for_way(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			}
		}
	}
	drawVertex(n); // отрисовка вершины
}

void reshape(int w, int h) // функция изменения окна
{
	Win_W = w;
	Win_H = h;
	glViewport(0, 0, (GLsizei)Win_W, (GLsizei)Win_H);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)Win_W, 0, (GLdouble)Win_H);
	glutPostRedisplay();
}

void draw_Text_for_menu(string text, int x1, int y1) // отрисовка текста для меню
{
	GLvoid* font = GLUT_BITMAP_HELVETICA_18; // установка шрифта
	string s = text;
	glRasterPos2i(x1 + 5, y1 - 20);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawMenu() // отрисовка меню
{
	int move_right = 45;
	int height = 330;

	glColor3d(0.14, 0.10, 0.45);
	glBegin(GL_QUADS);
	glVertex2i(move_right, height - move_right - 110);
	glVertex2i(move_right + 145, height - move_right - 110);
	glVertex2i(move_right + 145, height - move_right - 80);
	glVertex2i(move_right, height - move_right - 80);
	glEnd();
	glColor3d(0.8, 1.0, 0.9);
	draw_Text_for_menu("Solution", move_right, height - move_right - 82);

	glColor3d(0.14, 0.10, 0.45);
	glBegin(GL_QUADS);
	glVertex2i(move_right, height - move_right - 150);
	glVertex2i(move_right + 145, height - move_right - 150);
	glVertex2i(move_right + 145, height - move_right - 120);
	glVertex2i(move_right, height - move_right - 120);
	glEnd();
	glColor3d(0.8, 1.0, 0.9);
	draw_Text_for_menu("Add element", move_right, height - move_right - 122);

	glColor3d(0.14, 0.10, 0.45);
	glBegin(GL_QUADS);
	glVertex2i(move_right, height - move_right - 190);
	glVertex2i(move_right + 145, height - move_right - 190);
	glVertex2i(move_right + 145, height - move_right - 160);
	glVertex2i(move_right, height - move_right - 160);
	glEnd();
	glColor3d(0.8, 1.0, 0.9);
	draw_Text_for_menu("Delete element", move_right, height - move_right - 162);
}


void button_click(int btn, int stat, int x, int y) // реализация кнопок и их расположения
{
	int move = 15;
	int height = 300;
	if (stat == GLUT_DOWN)
	{

		if (x > move + 30 && x < move + 145 && y >  move + 110 && y < move + 140)
		{
			graph = graph_implementation();
		}

		if (x > move + 30 && x < move + 145 && y > move + 150 && y < move + 180)
		{
			graph.Print();
		}

		if (x > move + 30 && x < move + 145 && y >  move + 190 && y < move + 220)
		{
			traveler_man(ukazatel_na_matrix, n, dynamic_mas, result);
		}

		if (x > move + 30 && x < move + 145 && y >  move + 230 && y < move + 260)
		{
			int sourceVertex;
			int targetVertex;
			int edgeWeight;

			cout << endl << "Добавить пункт: ";
			cin >> sourceVertex;
			cout << endl;
			int* sourceVertPtr = &sourceVertex;
			cout << "Соединить с пунктом: ";
			cin >> targetVertex;
			cout << endl;
			int* targetVertPtr = &targetVertex;

			if (sourceVertex > kolvo_vershin || targetVertex > kolvo_vershin)
			{
				kolvo_vershin++;
				int* vertPtr = &kolvo_vershin;
				graph.Add_Vertex(*vertPtr);
			}

			cout << "Длина дороги: ";
			cin >> edgeWeight;
			cout << endl;
			graph.Way_km(*sourceVertPtr, *targetVertPtr, edgeWeight);
		}

		if (x > move + 30 && x < move + 145 && y >  move + 270 && y < move + 300)
		{
			int sourceVertex;
			cout << endl << "Удалим пункт: ";
			cin >> sourceVertex;
			cout << endl;
			int* sourceVertPtr = &sourceVertex;
			if (sourceVertex == kolvo_vershin)
			{
				kolvo_vershin--;
				graph.Delete_this_Vertex();
			}
			else cout << "Такого пункта нет. Удалять нечего! " << endl << endl;
		}
	}
	glutPostRedisplay();
}


void watch_display() 
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, Win_W, 0, Win_H);
	glViewport(0, 0, Win_W, Win_H);
	glClearColor(0.52, 0.92, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT); 

	graph.RenderingGraph(); 
	drawMenu(); 
	glutSwapBuffers(); 
}
