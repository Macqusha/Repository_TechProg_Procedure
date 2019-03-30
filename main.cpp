// Procedure.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <fstream>
#include "conteiner.h"

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
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	//проверка, что в файле только цифры  - не актуальна
	/*char symb;
	while (!ifst.eof())
	{
		ifst >> symb;
		if ((symb < 48 || symb >57) && symb != 45 && symb != 46)
		{
			cout << "Incorrect input file!" << endl;
			exit(1);
		}
	}
	ifst.close();
	ifst.open(argv[1]);			*/
	ofstream ofst(argv[2]);

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

	system("pause");
	return 0;
}