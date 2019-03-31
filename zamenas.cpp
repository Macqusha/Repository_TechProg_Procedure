#include <fstream>
#include <string>
#include "zamena_atd.h"

using namespace std;
const int maxStringeSize = 80;

namespace simple_codes
{
	string CodingZamena(char message[maxStringeSize], int rule)
	{
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string sz1 = "zyxwvutsrqponmlkjihgfedcba";
		string sz2 = "badcfehgjilknmporqtsvuxwzy";
		string sz3 = "shifrzamenybcdgjklopqtuvwx";
		string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string SZ1 = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
		string SZ2 = "BADCFEHGJILKNMPORQTSVUXWZY";
		string SZ3 = "SHIFRZAMENYBCDGJKLOPQTUVWX";

		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\0' && i < maxStringeSize)
		{
			str_mes += message[i];
			i++;
		}

		for (int i = 0; i < str_mes.length(); i++) 
		{
			int tmp = alf.find(str_mes[i]); // Номер текущего символа в alf
			if (tmp >= 0) 
			{
				if (rule == 1) 
					str_mes[i] = sz1[tmp];
				if (rule == 2)
					str_mes[i] = sz2[tmp];
				if (rule == 3) 
					str_mes[i] = sz3[tmp];
			}

			tmp = ALF.find(str_mes[i]); // Номер текущего символа в ALF
			if (tmp >= 0) 
			{
				if (rule == 1) 
					str_mes[i] = SZ1[tmp];
				if (rule == 2) 
					str_mes[i] = SZ2[tmp];
				if (rule == 3) 
					str_mes[i] = SZ3[tmp];
			}
		}
		return str_mes;
	}

	// Ввод параметров шифра замены из файла
	void In(zamena &r, ifstream &ifst)
	{
		ifst >> r.rule;
	}

	// Вывод параметров шифра замены 
	void Out(zamena &r, ofstream &ofst, char message[maxStringeSize], char owner[maxStringeSize])
	{
		string rulename = "Incorrect rule number";
		if (r.rule == 1) rulename = "Atbash"; // Атбаш
		if (r.rule == 2) rulename = "Pare-change"; // Попарная замена
		if (r.rule == 3) rulename = "Keyword-change"; // Шифр замены с кодовым словом SHIFRZAMENY
		ofst << "It is Zamena: rule = " << rulename
			<< ", open = " << message 
			<< ", code = " << CodingZamena(message,r.rule) 
			<< ", owner = " << owner << ". ";
	}
} // end simple_codes namespace


