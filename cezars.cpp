#include <fstream>
#include <string>
#include "cezar_atd.h"

using namespace std;
const int MAX_STRING_SIZE = 80;

namespace simple_codes
{
	string CodingCezar(char message[MAX_STRING_SIZE], int rot)
	{
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\0' && i < MAX_STRING_SIZE)
		{
			str_mes += message[i];
			i++;
		}

		for (int i = 0; i < str_mes.length(); i++) 
		{
			int tmp = alf.find(str_mes[i]); // Номер текущего символа в alf
			if (tmp >= 0)
				str_mes[i] = alf[(tmp + (rot % 26)) % 26];
			tmp = ALF.find(str_mes[i]); // Номер текущего символа в ALF
			if (tmp >= 0)
				str_mes[i] = ALF[(tmp + (rot % 26)) % 26];
		}
		return str_mes;
	}

	// Ввод параметра шифра Цезаря из потока
	void In(cezar &t, ifstream &ifst)
	{
		ifst >> t.rot;
	}
	// Вывод параметров шифра Цезаря
	void Out(cezar &t, ofstream &ofst, char message[MAX_STRING_SIZE], char owner[MAX_STRING_SIZE])
	{
		ofst << "It is Cezar: rot = " << t.rot
			<< ", open = " << message
			<< ", code = " << CodingCezar(message, t.rot)
			<< ", owner = " << owner << ". ";
	}
} // end simple_codes namespace 
