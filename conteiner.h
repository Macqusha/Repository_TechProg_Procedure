#ifndef __conteiner__
#define __conteiner__
namespace simple_codes {
	// ������ �� �������� �����. 
	// ������ ��������� ������ ����� ��� �������������� 
	// ���������� ���������� �� ���������
	struct code;
	// ���������� ��������� �� ������ ����������� �������
	struct container
	{
		//const int max_len=100; //������������ �����
		enum { max_len = 100 };
		int len; // ������� �����
		code *cont[max_len];
	};	
}
#endif