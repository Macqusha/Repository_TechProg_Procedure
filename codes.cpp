#include <fstream>
#include "code_atd.h"

using namespace std;

namespace simple_codes {
	// Сигнатуры требуемых внешних функций 
	void In(zamena &r, ifstream &ist);
	void In(cezar  &t, ifstream &ist);

	// Ввод параметров обобщенного шифра из файла
	code* In(ifstream &ifst)
	{
		code *sp;
		int k;
		ifst >> k;
		switch (k) {
		case 1:
			sp = new code;
			sp->k = code::key::ZAMENA;
			In(sp->r, ifst);
			return sp;
		case 2:
			sp = new code;
			sp->k = code::key::CEZAR;
			In(sp->t, ifst);
			return sp;
		default:
			return 0;
		}
	}

	void Out(zamena &r, ofstream &ofst, string open_text);
	void Out(cezar  &t, ofstream &ofst, string open_text);

	// Вывод параметров текущего шифра в поток
	void Out(code &s, ofstream &ofst, string open_text) {
		switch (s.k) {
		case code::key::ZAMENA:
			Out(s.r, ofst, open_text);
			break;
		case code::key::CEZAR:
			Out(s.t, ofst, open_text);
			break;
		default:
			ofst << "Incorrect figure!" << endl;
		}
	}
} // end simple_codes namespace


