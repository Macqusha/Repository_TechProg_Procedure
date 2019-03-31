#include <fstream>
#include <string>
#include "cezar_atd.h"

using namespace std;
const int maxStringeSize = 80;

namespace simple_codes
{
	string �odingCezar(char message[maxStringeSize], int rot)
	{
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string ALF = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string str_mes = "";
		int i = 0;
		while ((message[i]) != '\0' && i < maxStringeSize)
		{
			str_mes += message[i];
			i++;
		}

		for (int i = 0; i < str_mes.length(); i++) 
		{
			int tmp = alf.find(str_mes[i]); // ����� �������� ������� � alf
			if (tmp >= 0)
				str_mes[i] = alf[(tmp + (rot % 26)) % 26];
			tmp = ALF.find(str_mes[i]); // ����� �������� ������� � ALF
			if (tmp >= 0)
				str_mes[i] = ALF[(tmp + (rot % 26)) % 26];
		}
		return str_mes;
	}

	// ���� ��������� ����� ������ �� ������
	void In(cezar &t, ifstream &ifst)
	{
		ifst >> t.rot;
	}
	// ����� ���������� ����� ������
	void Out(cezar &t, ofstream &ofst, char message[maxStringeSize], char owner[maxStringeSize])
	{
		ofst << "It is Cezar: rot = " << t.rot
			<< ", open = " << message
			<< ", code = " << �odingCezar(message, t.rot)
			<< ", owner = " << owner << ". ";
	}
} // end simple_codes namespace 
