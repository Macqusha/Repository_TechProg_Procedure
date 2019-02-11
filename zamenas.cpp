#include <fstream>
#include "zamena_atd.h"

using namespace std;

namespace simple_codes
{
	// Ввод параметров шифра замены из файла
	void In(zamena &r, ifstream &ifst)
	{
		ifst >> r.rule;
	}
	// Вывод параметров шифра замены 
	void Out(zamena &r, ofstream &ofst, string open_text)
	{
		//-----------------------------------------------------------codiing
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string SZ1 = "zyxwvutsrqponmlkjihgfedcba";
		string SZ2 = "badcfeghjilknmporqtsvuxwzy";
		string SZ3 = "shifrzamenybcdgjklopqtuvwx";
		string rulename = "Incorrect rule number";
				for (int i = 0; i < open_text.length(); i++) {
			int tmp = alf.find(tolower(open_text[i])); //номер текущего символа в alf
			if (tmp >= 0) {
				if (r.rule == 1) {
					rulename = "Atbash"; //Атбаш
					open_text[i] = SZ1[tmp];
				}
				if (r.rule == 2) {
					rulename = "Pare-change"; //попарная замена
					open_text[i] = SZ2[tmp];
				}
				if (r.rule == 3) {
					rulename = "Keyword-change"; //шифр замены с кодовым словом SHIFRZAMENY
					open_text[i] = SZ3[tmp];
				}
			}
		}
		//-----------------------------------------------------------codiing
		ofst << "It is Zamena: rule = " << rulename
			<< ", code = " << open_text  << "." << endl;
	}
} // end simple_codes namespace


