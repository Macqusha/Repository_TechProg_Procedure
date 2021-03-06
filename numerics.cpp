#include <fstream>
#include <string>
#include "numeric_atd.h"

using namespace std;
const int MAX_STRING_SIZE = 80;

namespace simple_codes
{
	string CodingNumeric(char message[MAX_STRING_SIZE], int digit)
	{
		string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\0' && i < MAX_STRING_SIZE)
		{
			str_mes += message[i];
			i++;
		}
		string str_result = "";
		for (int i = 0; i < str_mes.length(); i++) 
		{
			int tmp = alf.find(tolower(str_mes[i])); // ����� �������� ������� � alf
			if (tmp >= 0)
				str_result += to_string((tmp + (digit % 26)) % 26);
			else
				str_result += str_mes[i];
		}
		return str_result;
	}

	// ���� ��������� ����� ������ �� ������
	void In(numeric &b, ifstream &ifst)
	{
		ifst >> b.digit;
	}

	// ����� ���������� ����� ������
	void Out(numeric &b, ofstream &ofst, char message[MAX_STRING_SIZE], char owner[MAX_STRING_SIZE])
	{
		ofst << "It is Numeric: digit = " << b.digit
			<< ", open = " << message
			<< ", code = " << CodingNumeric(message, b.digit)
			<< ", owner = " << owner << ". ";
	}
} // end simple_codes namespace

