#include <fstream>
#include "zamena_atd.h"

using namespace std;

namespace simple_codes
{
	// ���� ���������� ����� ������ �� �����
	void In(zamena &r, ifstream &ifst)
	{
		ifst >> r.rule;
	}
	// ����� ���������� ����� ������ 
	void Out(zamena &r, ofstream &ofst, string open_text)
	{
		//-----------------------------------------------------------codiing
		string alf = "abcdefghijklmnopqrstuvwxyz";
		string SZ1 = "zyxwvutsrqponmlkjihgfedcba";
		string SZ2 = "badcfeghjilknmporqtsvuxwzy";
		string SZ3 = "shifrzamenybcdgjklopqtuvwx";
		string rulename = "Incorrect rule number";
				for (int i = 0; i < open_text.length(); i++) {
			int tmp = alf.find(tolower(open_text[i])); //����� �������� ������� � alf
			if (tmp >= 0) {
				if (r.rule == 1) {
					rulename = "Atbash"; //�����
					open_text[i] = SZ1[tmp];
				}
				if (r.rule == 2) {
					rulename = "Pare-change"; //�������� ������
					open_text[i] = SZ2[tmp];
				}
				if (r.rule == 3) {
					rulename = "Keyword-change"; //���� ������ � ������� ������ SHIFRZAMENY
					open_text[i] = SZ3[tmp];
				}
			}
		}
		//-----------------------------------------------------------codiing
		ofst << "It is Zamena: rule = " << rulename
			<< ", code = " << open_text  << "." << endl;
	}
} // end simple_codes namespace


