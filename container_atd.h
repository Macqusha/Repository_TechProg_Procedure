#ifndef __container__
#define __container__
namespace simple_codes {
	// ������ �� �������� �����
	// ������ ��������� ������ ����� ��� �������������� ���������� ���������� �� ���������
	struct code;
	// ���������� ��������� �� ������ ����������� �������
	struct container
	{
		// ������������ �����
		enum { max_len = 100 };
		int len; // ������� �����
		code *cont[max_len];
	};	
}
#endif