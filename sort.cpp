#include <fstream>
#include "code_atd.h"
#include "container_atd.h"

using namespace std;

namespace simple_codes {
	// ��������� ��������� ������� �������
	int MesLength(code &s);

	// C�������� ������ ���� ����������� ��������
	bool Compare(code *first, code *second) 
	{
		return MesLength(*first) < MesLength(*second);
	}
}