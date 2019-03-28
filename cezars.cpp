#include <fstream>
#include <string>
#include "cezar_atd.h"

using namespace std;
const int maxStringeSize = 80;

string codingCezar(char message[maxStringeSize], int rot)
{
	string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
	string str_mes = "";
	int i = 0;
	while ((message[i]) != '\n' && alf.find(tolower(message[i])) >= 0 && alf.find(tolower(message[i])) < 26 && i < maxStringeSize)
	{
		str_mes += message[i];
		i++;
	}

	for (int i = 0; i < str_mes.length(); i++) {
		int tmp = alf.find(tolower(str_mes[i])); //номер текущего символа в alf
		if (tmp >= 0)
			str_mes[i] = alf[tmp + (rot % 26)];
	}
	return str_mes;
}

namespace simple_codes 
{
	// Ввод параметра шифра Цезаря из потока
	void In(cezar &t, ifstream &ifst)
	{
		ifst >> t.rot;
	}
	//Вывод параметров шифра Цезаря
	void Out(cezar &t, ofstream &ofst, char message[maxStringeSize], char owner[maxStringeSize])
	{
		ofst << "It is Cezar: rot = " << t.rot 
			<< ", open = " << message 
			<< ", code = " << codingCezar(message, t.rot) 
			<< ", owner = " << owner << ". ";
	}
} // end simple_codes namespace

