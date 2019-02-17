#include <fstream>
#include "code_atd.h"

using namespace std;

namespace simple_codes {
	// Сигнатуры требуемых внешних функций
	void In(zamena &r, ifstream &ist);
	void In(cezar  &t, ifstream &ist);
	void In(numeric  &t, ifstream &ist);

	// Ввод параметров обобщенного шифра из файла
	code* In(ifstream &ifst)
	{
		code *sp;
		int k;
		ifst >> k;
		sp = new code;
		switch (k) {
		case 1:
			sp->k = code::key::ZAMENA;
			In(sp->r, ifst);
			ifst >> sp->message;
			ifst >> sp->owner;
			return sp;
		case 2:
			sp->k = code::key::CEZAR;
			In(sp->t, ifst);
			ifst >> sp->message;
			ifst >> sp->owner;
			return sp;
		case 3:
			sp->k = code::key::NUMERIC;
			In(sp->b, ifst);
			ifst >> sp->message;
			ifst >> sp->owner;
			return sp;
		default:
			return 0;
		}
	}

	// Сигнатуры требуемых внешних функций 
	void Out(zamena &r, ofstream &ofst, char message[20], char owner[20]);
	void Out(cezar  &t, ofstream &ofst, char message[20], char owner[20]);
	void Out(numeric  &t, ofstream &ofst, char message[20], char owner[20]);

	// Вывод параметров текущего шифра в поток
	void Out(code &s, ofstream &ofst) {
		switch (s.k) {
		case code::key::ZAMENA:
			Out(s.r, ofst, s.message, s.owner);
			break;
		case code::key::CEZAR:
			Out(s.t, ofst, s.message, s.owner);
			break;
		case code::key::NUMERIC:
			Out(s.b, ofst, s.message, s.owner);
			break;
		default:
			ofst << "Incorrect figure!" << endl;
		}
	}

	//Вычисление длины исходного текста
	int MesLength(code &s)
	{
		int length = 0;
		while (s.message[length] != '\0' && length < 20) length++;
		return length;
	};
} // end simple_codes namespace


