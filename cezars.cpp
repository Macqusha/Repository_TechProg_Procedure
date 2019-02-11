#include <fstream>
#include "cezar_atd.h"

using namespace std;

namespace simple_codes 
{
	// ���� ��������� ����� ������ �� ������
	void In(cezar &t, ifstream &ifst)
	{
		ifst >> t.rot;
	}
	//����� ���������� ����� ������
	void Out(cezar &t, ofstream &ofst, string open_text)
	{
		//-----------------------------------------------------------cezar codiing

		string alf = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxy";
		for (int i = 0; i < open_text.length(); i++) {
			int tmp = alf.find(tolower(open_text[i])); //����� �������� ������� � alf
			if (tmp >= 0)
				open_text[i] = alf[tmp + (t.rot % 26)];
			
				
		}			
		//-----------------------------------------------------------cezar codiing
		ofst << "It is Cezar: rot = "
			<< t.rot << ", code = " << open_text << "." << endl; 
	}
} // end simple_codes namespace

