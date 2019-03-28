#include <fstream>
#include <string>
#include "numeric_atd.h"

using namespace std;
const int maxStringeSize = 80;

string codingNumeric(char message[maxStringeSize], int digit)
{
	string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
	string str_mes = "";
	int i = 0;
	while ((message[i]) != '\n' && alf.find(tolower(message[i])) >= 0 && alf.find(tolower(message[i])) < 26 && i < maxStringeSize)
	{
		str_mes += message[i];
		i++;
	}
	string str_result = "";
	for (int i = 0; i < str_mes.length(); i++) 
	{
		int tmp = alf.find(tolower(str_mes[i])); //номер текущего символа в alf
		if (tmp >= 0)
			str_result += to_string((tmp + (digit % 26))%26);
	}
	return str_result;
}

namespace simple_codes
{
	// Ввод параметра шифра Цезаря из потока
	void In(numeric &b, ifstream &ifst)
	{
		ifst >> b.digit;
	}
	//Вывод параметров шифра Цезаря
	void Out(numeric &b, ofstream &ofst, char message[maxStringeSize], char owner[maxStringeSize])
	{
		ofst << "It is Numeric: digit = " << b.digit
			<< ", open = " << message
			<< ", code = " << codingNumeric(message, b.digit)
			<< ", owner = " << owner << ". ";
	}
} // end simple_codes namespace

