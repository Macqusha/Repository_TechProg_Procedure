#include "code_atd.h"
#include "cezar_atd.h"
#include "zamena_atd.h"
#include "numeric_atd.h"
#include "conteiner.h"
#include <string.h>
#include <iostream>
using namespace std;

namespace simple_codes
{
	const int moreThanMax = maxStringeSize + 20;
	//Ñèãíàòóğû èñïîëüçóåìûõ âíåøíèõ ôóíêöèé
	int MesLength(code &s);
	string codingCezar(char message[maxStringeSize], int rot);
	string codingZamena(char message[maxStringeSize], int rule);
	string codingNumeric(char message[maxStringeSize], int digit);

	void test_MesLength_1()
	{
		code s;
		char testMes[moreThanMax] = "";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = MesLength(s);
		int expected = 0;
		if (actual == expected)
			cout << "Test 1: Successfully passed." << endl;
		else
			cout << "Test 1: Failed." << endl;
	}

	void test_MesLength_2()
	{
		code s;
		char testMes[moreThanMax] = "ABC abc 1234567!@#&*";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = MesLength(s);
		int expected = 20;
		if (actual == expected)
			cout << "Test 2: Successfully passed." << endl;
		else
			cout << "Test 2: Failed." << endl;
	}

	void test_MesLength_3()
	{
		code s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = MesLength(s);
		int expected = 79;
		if (actual == expected)
			cout << "Test 3: Successfully passed." << endl;
		else
			cout << "Test 3: Failed." << endl;
	}

	void test_MesLength_4()
	{
		code s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = MesLength(s);
		int expected = 80;
		if (actual == expected)
			cout << "Test 4: Successfully passed." << endl;
		else
			cout << "Test 4: Failed." << endl;
	}

	void test_MesLength_5()
	{
		code s;
		char testMes[moreThanMax] = "aaaaàaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = MesLength(s);
		int expected = 80;
		if (actual == expected)
			cout << "Test 5: Successfully passed." << endl;
		else
			cout << "Test 5: Failed." << endl;
	}

	void test_codingCezar_1()
	{
		char message[maxStringeSize];
		int rot = 0;
		char testMes[moreThanMax] = "AbcdeFG 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingCezar(message, rot);
		string expected = "AbcdeFG 123 %^&";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
				if (actual[i] != expected[i])
					checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 1: Successfully passed." << endl;
		else
			cout << "Test 1: Failed." << endl;
	}

	void test_codingCezar_2()
	{
		char message[maxStringeSize];
		int rot = 1;
		char testMes[moreThanMax] = "AbcdeFG 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingCezar(message, rot);
		string expected = "BcdefGH 123 %^&";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
				if (actual[i] != expected[i])
					checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 2: Successfully passed." << endl;
		else
			cout << "Test 2: Failed." << endl;
	}

	void test_codingCezar_3()
	{
		char message[maxStringeSize];
		int rot = 25;
		char testMes[moreThanMax] = "AbcdeFG 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingCezar(message, rot);
		string expected = "ZabcdEF 123 %^&";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 3: Successfully passed." << endl;
		else
			cout << "Test 3: Failed." << endl;
	}

	void test_codingCezar_4()
	{
		char message[maxStringeSize];
		int rot = 26;
		char testMes[moreThanMax] = "AbcdeFG 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingCezar(message, rot);
		string expected = "AbcdeFG 123 %^&";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 4: Successfully passed." << endl;
		else
			cout << "Test 4: Failed." << endl;
	}

	void test_codingCezar_5()
	{
		char message[maxStringeSize];
		int rot = 53;
		char testMes[moreThanMax] = "AbcdeFG 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingCezar(message, rot);
		string expected = "BcdefGH 123 %^&";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 5: Successfully passed." << endl;
		else
			cout << "Test 5: Failed." << endl;
	}
	
	void test_codingZamena_1()
	{
		char message[maxStringeSize];
		int rule = 1;
		char testMes[moreThanMax] = "AbcdeFG..yZ 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingZamena(message, rule);
		string expected = "ZyxwvUT..bA 123 %^&";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 1: Successfully passed." << endl;
		else
			cout << "Test 1: Failed." << endl;
	}

	void test_codingZamena_2()
	{
		char message[maxStringeSize];
		int rule = 2;
		char testMes[moreThanMax] = "AbcdeFG..yZ 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingZamena(message, rule);
		string expected = "BadcfEH..zY 123 %^&";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 2: Successfully passed." << endl;
		else
			cout << "Test 2: Failed." << endl;
	}

	void test_codingZamena_3()
	{
		char message[maxStringeSize];
		int rule = 2;
		char testMes[moreThanMax] = "BadcfEH..zY 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingZamena(message, rule);
		string expected = "AbcdeFG..yZ 123 %^&";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 3: Successfully passed." << endl;
		else
			cout << "Test 3: Failed." << endl;
	}

	void test_codingZamena_4()
	{
		char message[maxStringeSize];
		int rule = 3;
		char testMes[moreThanMax] = "AbcdeFG..yZ 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingZamena(message, rule);
		string expected = "ShifrZA..wX 123 %^&";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 4: Successfully passed." << endl;
		else
			cout << "Test 4: Failed." << endl;
	}
	
	void test_codingZamena_5()
	{
		char message[maxStringeSize];
		int rule = 3;
		char testMes[moreThanMax] = "90 %(^& TEST";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingZamena(message, rule);
		string expected = "90 %(^& PROP";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 5: Successfully passed." << endl;
		else
			cout << "Test 5: Failed." << endl;
	}

	void test_codingNumeric_1()
	{
		char message[maxStringeSize];
		int digit = 0;
		char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingNumeric(message, digit);
		string expected = "012345678910111213141516171819202122232425 12390 !@#$%^&*";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 1: Successfully passed." << endl;
		else
			cout << "Test 1: Failed." << endl;
	}

	void test_codingNumeric_2()
	{
		char message[maxStringeSize];
		int digit = 1;
		char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingNumeric(message, digit);
		string expected = "123456789101112131415161718192021222324250 12390 !@#$%^&*";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 2: Successfully passed." << endl;
		else
			cout << "Test 2: Failed." << endl;
	}

	void test_codingNumeric_3()
	{
		char message[maxStringeSize];
		int digit = 25;
		char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingNumeric(message, digit);
		string expected = "250123456789101112131415161718192021222324 12390 !@#$%^&*";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 3: Successfully passed." << endl;
		else
			cout << "Test 3: Failed." << endl;
	}

	void test_codingNumeric_4()
	{
		char message[maxStringeSize];
		int digit = 26;
		char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingNumeric(message, digit);
		string expected = "012345678910111213141516171819202122232425 12390 !@#$%^&*";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 4: Successfully passed." << endl;
		else
			cout << "Test 4: Failed." << endl;
	}

	void test_codingNumeric_5()
	{
		char message[maxStringeSize];
		int digit = 53;
		char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingNumeric(message, digit);
		string expected = "123456789101112131415161718192021222324250 12390 !@#$%^&*";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		if (checkFlag)
			cout << "Test 5: Successfully passed." << endl;
		else
			cout << "Test 5: Failed." << endl;
	}

	void UnitTest_CallAllTests()
	{
		cout << "Tests checking the function MesLength:" << endl;
		test_MesLength_1();
		test_MesLength_2();
		test_MesLength_3();
		test_MesLength_4();
		test_MesLength_5();
		cout << endl << "Tests checking the function codingCezar:" << endl;
		test_codingCezar_1();
		test_codingCezar_2();
		test_codingCezar_3();
		test_codingCezar_4();
		test_codingCezar_5();
		cout << endl << "Tests checking the function codingZamena:" << endl;
		test_codingZamena_1();
		test_codingZamena_2();
		test_codingZamena_3();
		test_codingZamena_4();
		test_codingZamena_5();
		cout << endl << "Tests checking the function codingNumeric:" << endl;
		test_codingNumeric_1();
		test_codingNumeric_2();
		test_codingNumeric_3();
		test_codingNumeric_4();
		test_codingNumeric_5();
	}
}
	