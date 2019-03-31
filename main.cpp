#include <iostream>
#include <fstream>
#include <string>
#include "container_atd.h"

using namespace std;

namespace simple_codes {									
	// Сигнатуры требуемых внешних функций
	void Init(container &c);
	void Clear(container &c);
	void In(container &c, ifstream &ifst);
	void Out(container &c, ofstream &ofst);
	void Sort(container &c);
	void OutZamena(container &c, ofstream &ofst);
}

using namespace simple_codes;


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Incorrect command line! "
			"Waited: command infile outfile" << endl;
		return -8;
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	// Проверка наличия файла входных данных
	if (!ifst.is_open())
	{
		cout << "Error opening in.txt";
		return -6;
	}
	// Проверка возможности создания файла выходных данных
	if (!ofst.is_open())
	{
		cout << "Error opening out.txt";
		return -7;
	}

	// Проверка содержимого входного файла
	int i = 0; // Номер строки, которую будем считывать
	char* buferStr = new char; // Буфер для строки
	int typecode; // Тип шифра, с которым работаем
	int param; // Параметр шифра, с которым работаем
	string mes; // Исходный текст шифра, с которым работаем
	string owner; // Владелец шифра, с которым работаем

	// Цикл проверки
	while (!ifst.eof())
	{
		switch (i % 4) {
		case 0:
			i++;
			if (!(ifst >> typecode) || (typecode < 1) || (typecode > 3)) // Нельзя считать число или некорректный ключ
			{
				cout << "Error. Wrong type. Parametr #" << i << "." << endl;
				return -1;
			}
			break;
		case 1:
			i++;
			if (!(ifst >> param) ) // Нельзя считать число
			{
				cout << "Error. Wrong parameter. Parametr #" << i << "." << endl;
				return -2;
			}
			if ((param < 0) || ((typecode == 1) && ((param < 1) || (param > 3))))  // Некорректный параметр
			{
				cout << "Error. Wrong parameter. Parametr #" << i << "." << endl;
				return -2;
			} 
			break;
		case 2:
			i++;
			if (!(ifst >> mes)) // Нельзя считать строку
			{
				cout << "Error. Wrong message. Parametr #" << i << "." << endl;
				return -3;
			}
			break;
		case 3:
			i++;
			if (!(ifst >> owner)) // Нельзя считать строку
			{
				cout << "Error. Wrong owner. Parametr #" << i << "." << endl;
				return -4;
			}
			break;
		}
	}

	// Проверка, закончился ли файл в процессе введения шифра
	if (i % 4 != 0)
	{
		cout << "Error. Unexpected end of file. Parametr #" << i << "." << endl;
		return -5;
	}

	// Переоткрытие файла входных данных
	ifst.close();
	ifst.open(argv[1]);

	cout << "Start" << endl;
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container. " << endl;
	Sort(c);
	Out(c, ofst);
	ofst << endl;
	OutZamena(c, ofst);
	ofst << endl;
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;

	ifst.close();
	ofst.close();
	return 0;
}