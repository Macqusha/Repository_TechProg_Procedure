#ifndef __code_atd__
#define __code_atd__
// ����������� ����������� ����� ������
#include "zamena_atd.h"		
#include "cezar_atd.h"
#include <string>		
namespace simple_codes 
{
	// ���������, ���������� ��� ��������� �����
	struct code 
	{
		// �������� ������ ��� ������� �� ������
		enum key {ZAMENA, CEZAR};
		key k; // ����
		// ������������ ������������
		union { // ���������� ���������
			zamena r;			
			cezar t;			
		};
		char message[20]; //�������� �����
		//warning ����� ������ �������, �������� ����� ��� ������������ � ������ cezars.cpp � zamenas.cpp. ������ �� �����: && i < 20)
	};
} // end simple_codes namespace
#endif
