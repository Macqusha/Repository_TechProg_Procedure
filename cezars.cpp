#include <fstream>
#include "cezar_atd.h"

using namespace std;

namespace simple_codes 
{
	// Ввод параметра шифра Цезаря из потока
	void In(cezar &t, ifstream &ifst)
	{
		ifst >> t.rot;
	}
	//Вывод параметров шифра Цезаря
	void Out(cezar &t, ofstream &ofst, char message[20])
	{
		//-----------------------------------------------------------cezar codiing
		string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
		string str_mes ="";
		int i = 0;
		while ((message[i]) != '\n' && alf.find(tolower(message[i])) >= 0 && alf.find(tolower(message[i])) < 26 && i < 20)
		{
			str_mes += message[i];
			i++;
		}

		for (int i = 0; i < str_mes.length(); i++) {
			int tmp = alf.find(tolower(str_mes[i])); //номер текущего символа в alf
			if (tmp >= 0)
				str_mes[i] = alf[tmp + (t.rot % 26)];				
		}			
		//-----------------------------------------------------------cezar codiing
		ofst << "It is Cezar: rot = "
			<< t.rot << ", open = " << message << ", code = " << str_mes << "." << endl;
	}
} // end simple_codes namespace

