#include <fstream>
#include <string>
#include "numeric_atd.h"

using namespace std;
const int maxStringeSize = 80;

namespace simple_codes
{
	string СodingNumeric(char message[maxStringeSize], int digit)
	{
		string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\0' && i < maxStringeSize)
		{
			str_mes += message[i];
			i++;
		}
		string str_result = "";
		for (int i = 0; i < str_mes.length(); i++) 
		{
			int tmp = alf.find(tolower(str_mes[i])); // Номер текущего символа в alf
			if (tmp >= 0)
				str_result += to_string((tmp + (digit % 26)) % 26);
			else
				str_result += str_mes[i];
		}
		return str_result;
	}

	// Ввод параметра шифра Цезаря из потока
	void In(numeric &b, ifstream &ifst)
	{
		ifst >> b.digit;
	}
	// Вывод параметров шифра Цезаря
	void Out(numeric &b, ofstream &ofst, char message[maxStringeSize], char owner[maxStringeSize])
	{
		ofst << "It is Numeric: digit = " << b.digit
			<< ", open = " << message
			<< ", code = " << СodingNumeric(message, b.digit)
			<< ", owner = " << owner << ". ";
	}
} // end simple_codes namespace

