#include "conteiner.h"
#include "code_atd.h"	
#include <fstream>

using namespace std;

namespace simple_codes {
	// Инициализация контейнера
	void Init(container &c) { c.len = 0; }
	// Очистка контейнера от элементов 
	// (освобождение памяти)

	void Clear(container &c) {
		for (int i = 0; i < c.len; i++) {
			delete c.cont[i];
		}
		c.len = 0;
	}
	// Сигнатуры требуемых внешних функций
	code *In(ifstream &ifdt);

	// Ввод содержимого контейнера из указанного потока
	void In(container &c, ifstream &ifst) {
		while (!ifst.eof())
		{
			if (c.len > 99)
			{
				break;
			}
			else
			{
				if ((c.cont[c.len] = In(ifst)) != 0)
					c.len++;
			}
		}

	}

	int MesLength(code &s)
	{
		int length = 0;
		while (s.message[length] != '\0' && length < 20) length++;
		return length;
	};

	// Сигнатуры требуемых внешних функций
	void Out(code &s, ofstream &ofst);
	bool Compare(code *first, code *second);
	// Сортировка содержимого контейнера
	void Sort(container &c)
	{
		for (int i = 0; i < c.len - 1; i++)
		{
			for (int j = i + 1; j < c.len; j++)
			{
				if (Compare(c.cont[i], c.cont[j]))
				{
					code *tmp = c.cont[i];
					c.cont[i] = c.cont[j];
					c.cont[j] = tmp;
				}
			}
		}
	}
	
	// Сигнатуры требуемых внешних функций
	void Out(code &s, ofstream &ofst);
	// Вывод содержимого контейнера в указанный поток
	void Out(container &c, ofstream &ofst)
	{
		ofst << "Container contains " << c.len
			<< " elements." << endl;
		for (int i = 0; i < c.len; i++)
		{
			ofst << i << ": ";
			Out(*(c.cont[i]), ofst);
			ofst << "Length = "
				<< MesLength(*(c.cont[i])) << endl;
		}
	}
} // end simple_codes namespace




