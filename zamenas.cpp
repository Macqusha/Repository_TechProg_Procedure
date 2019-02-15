#include <fstream>
#include <string>
#include "zamena_atd.h"

using namespace std;

string codingZamena(char message[20], int rule)
{
	string alf = "abcdefghijklmnopqrstuvwxyz";
	string SZ1 = "zyxwvutsrqponmlkjihgfedcba";
	string SZ2 = "badcfeghjilknmporqtsvuxwzy";
	string SZ3 = "shifrzamenybcdgjklopqtuvwx";
	string str_mes = "";
	int i = 0;
	while ((message[i]) != '\n' && alf.find(tolower(message[i])) >= 0 && alf.find(tolower(message[i])) < 26 && i < 20)
	{
		str_mes += message[i];
		i++;
	}

	for (int i = 0; i < str_mes.length(); i++) {
		int tmp = alf.find(tolower(str_mes[i])); //номер текущего символа в alf
		if (tmp >= 0) {
			if (rule == 1) {
				str_mes[i] = SZ1[tmp];
			}
			if (rule == 2) {
				str_mes[i] = SZ2[tmp];
			}
			if (rule == 3) {
				str_mes[i] = SZ3[tmp];
			}
		}
	}
	return str_mes;
}

namespace simple_codes
{
	// Ввод параметров шифра замены из файла
	void In(zamena &r, ifstream &ifst)
	{
		ifst >> r.rule;
	}
	// Вывод параметров шифра замены 
	void Out(zamena &r, ofstream &ofst, char message[20], char owner[20])
	{
		string rulename = "Incorrect rule number";
		if (r.rule == 1) rulename = "Atbash"; //Атбаш
		if (r.rule == 2) rulename = "Pare-change"; //попарная замена
		if (r.rule == 3) rulename = "Keyword-change"; //шифр замены с кодовым словом SHIFRZAMENY
		ofst << "It is Zamena: rule = " << rulename
			<< ", open = " << message 
			<< ", code = " << codingZamena(message,r.rule) 
			<< ", owner = " << owner << "." << endl;
	}
} // end simple_codes namespace


