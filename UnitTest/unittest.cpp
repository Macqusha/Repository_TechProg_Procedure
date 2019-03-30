#include "CppUnitTest.h"
#include "../Procedure/conteiner.h"
#include "../Procedure/code_atd.h"
#include "../Procedure/cezar_atd.h"
#include "../Procedure/numeric_atd.h"
#include "../Procedure/zamena_atd.h"
#include <string.h>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace simple_codes;
using namespace std;

namespace simple_codes {
	const int moreThanMax = maxStringeSize + 20;
	//Сигнатуры используемых внешних функций
	int MesLength(code &s);
	string codingCezar(char message[maxStringeSize], int rot);
	string codingZamena(char message[maxStringeSize], int rule);
	string codingNumeric(char message[maxStringeSize], int digit);
	void In(cezar &t, ifstream &ifst);
	void In(numeric &t, ifstream &ifst);
	void In(zamena &t, ifstream &ifst);
	code* In(ifstream &ifst);
	void In(container &c, ifstream &ifst);
	void Init(container &c);
	void Clear(container &c);
	void Out(container &c, ofstream &ofst);
	void Out(code &s, ofstream &ofst);
	void Out(cezar &t, ofstream &ofst, char message[maxStringeSize], char owner[maxStringeSize]);
	void Out(numeric &t, ofstream &ofst, char message[maxStringeSize], char owner[maxStringeSize]);
	void Out(zamena &t, ofstream &ofst, char message[maxStringeSize], char owner[maxStringeSize]);
	void Sort(container &c);
	void OutZamena(container &c, ofstream &ofst);
} // end simple_codes namespace



namespace coding_test {
TEST_CLASS(testing_codingCezar)
{
public:

	TEST_METHOD(Test1)
	{
		char message[maxStringeSize];
		int rot = 0;
		char testMes[moreThanMax] = "AbcdeFG 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingCezar(message, rot);
		string expected = "AbcdeFG 123 %^&";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2)
	{
		char message[maxStringeSize];
		int rot = 1;
		char testMes[moreThanMax] = "AbcdeFG 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingCezar(message, rot);
		string expected = "BcdefGH 123 %^&";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3)
	{
		char message[maxStringeSize];
		int rot = 25;
		char testMes[moreThanMax] = "AbcdeFG 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingCezar(message, rot);
		string expected = "ZabcdEF 123 %^&";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test4)
	{
		char message[maxStringeSize];
		int rot = 26;
		char testMes[moreThanMax] = "AbcdeFG 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingCezar(message, rot);
		string expected = "AbcdeFG 123 %^&";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test5)
	{
		char message[maxStringeSize];
		int rot = 53;
		char testMes[moreThanMax] = "AbcdeFG 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingCezar(message, rot);
		string expected = "BcdefGH 123 %^&";

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_codingZamena)
{
public:

	TEST_METHOD(Test1)
	{
		char message[maxStringeSize];
		int rule = 1;
		char testMes[moreThanMax] = "AbcdeFG..yZ 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingZamena(message, rule);
		string expected = "ZyxwvUT..bA 123 %^&";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2)
	{
		char message[maxStringeSize];
		int rule = 2;
		char testMes[moreThanMax] = "AbcdeFG..yZ 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingZamena(message, rule);
		string expected = "BadcfEH..zY 123 %^&";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3)
	{
		char message[maxStringeSize];
		int rule = 2;
		char testMes[moreThanMax] = "BadcfEH..zY 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingZamena(message, rule);
		string expected = "AbcdeFG..yZ 123 %^&";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test4)
	{
		char message[maxStringeSize];
		int rule = 3;
		char testMes[moreThanMax] = "AbcdeFG..yZ 123 %^&";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingZamena(message, rule);
		string expected = "ShifrZA..wX 123 %^&";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test5)
	{
		char message[maxStringeSize];
		int rule = 3;
		char testMes[moreThanMax] = "90 %(^& TEST";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingZamena(message, rule);
		string expected = "90 %(^& PROP";

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_codingNumeric)
{
public:

	TEST_METHOD(Test1)
	{
		char message[maxStringeSize];
		int digit = 0;
		char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingNumeric(message, digit);
		string expected = "012345678910111213141516171819202122232425 12390 !@#$%^&*";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2)
	{
		char message[maxStringeSize];
		int digit = 1;
		char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingNumeric(message, digit);
		string expected = "123456789101112131415161718192021222324250 12390 !@#$%^&*";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3)
	{
		char message[maxStringeSize];
		int digit = 25;
		char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingNumeric(message, digit);
		string expected = "250123456789101112131415161718192021222324 12390 !@#$%^&*";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test4)
	{
		char message[maxStringeSize];
		int digit = 26;
		char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingNumeric(message, digit);
		string expected = "012345678910111213141516171819202122232425 12390 !@#$%^&*";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test5)
	{
		char message[maxStringeSize];
		int digit = 53;
		char testMes[moreThanMax] = "ABCDEFGHIJKlmnopqrstuvwxyz 12390 !@#$%^&*";
		for (int i = 0; i < maxStringeSize; i++)
			message[i] = testMes[i];

		string actual = codingNumeric(message, digit);
		string expected = "123456789101112131415161718192021222324250 12390 !@#$%^&*";

		Assert::AreEqual(expected, actual);
	}
};
} // end coding_test namespace

TEST_CLASS(testing_In_lower)
{
public:

	TEST_METHOD(Test1_cezar)
	{
		cezar testing_type;
		ifstream test_file ("../Procedure/Test_Files/In_low_cezar.txt");
		In(testing_type, test_file);
		int actual = testing_type.rot;
		int expected = 53;
		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2_zamena)
	{
		zamena testing_type;
		ifstream test_file("../Procedure/Test_Files/In_low_zamena.txt");
		In(testing_type, test_file);
		int actual = testing_type.rule;
		int expected = 3;
		Assert::AreEqual(expected, actual);
	}
	
	TEST_METHOD(Test3_numeric)
	{
		numeric testing_type;
		ifstream test_file("../Procedure/Test_Files/In_low_numeric.txt");
		In(testing_type, test_file);
		int actual = testing_type.digit;
		int expected = 10;
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_In_middle)
{
public:

	TEST_METHOD(Test1_zamena_message)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_zamena.txt");
		testing_type = In(test_file);
		
		string actual = testing_type->message;
		string expected = "test";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		Assert::AreEqual(true, checkFlag);
	}

	TEST_METHOD(Test2_zamena_owner)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_zamena.txt");
		testing_type = In(test_file);

		string actual = testing_type->owner;
		string expected = "Aleev";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		Assert::AreEqual(true, checkFlag);
	}
	
	TEST_METHOD(Test3_zamena_key)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_zamena.txt");
		testing_type = In(test_file);

		int actual = testing_type->k;
		int expected = testing_type->ZAMENA;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test4_zamena_rule)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_zamena.txt");
		testing_type = In(test_file);

		int actual = testing_type->r.rule;
		int expected = 1;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test5_cezar_message)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_cezar.txt");
		testing_type = In(test_file);

		string actual = testing_type->message;
		string expected = "test";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		Assert::AreEqual(true, checkFlag);
	}

	TEST_METHOD(Test6_cezar_owner)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_cezar.txt");
		testing_type = In(test_file);

		string actual = testing_type->owner;
		string expected = "Aleev";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		Assert::AreEqual(true, checkFlag);
	}

	TEST_METHOD(Test7_cezar_key)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_cezar.txt");
		testing_type = In(test_file);

		int actual = testing_type->k;
		int expected = testing_type->CEZAR;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test8_cezar_rule)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_cezar.txt");
		testing_type = In(test_file);

		int actual = testing_type->r.rule;
		int expected = 4;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test9_numeric_message)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_numeric.txt");
		testing_type = In(test_file);

		string actual = testing_type->message;
		string expected = "test";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		Assert::AreEqual(true, checkFlag);
	}

	TEST_METHOD(Test10_numeric_owner)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_numeric.txt");
		testing_type = In(test_file);

		string actual = testing_type->owner;
		string expected = "Aleev";

		bool checkFlag = true;
		int i;
		for (i = 0; i < expected.length(); i++)
			if (actual[i] != expected[i])
				checkFlag = false;
		if (i < actual.length() && actual[i] != '\0')
			checkFlag = false;

		Assert::AreEqual(true, checkFlag);
	}

	TEST_METHOD(Test11_numeric_key)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_numeric.txt");
		testing_type = In(test_file);

		int actual = testing_type->k;
		int expected = testing_type->NUMERIC;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test12_numeric_rule)
	{
		code* testing_type;
		ifstream test_file("../Procedure/Test_Files/In_middle_numeric.txt");
		testing_type = In(test_file);

		int actual = testing_type->r.rule;
		int expected = 3;

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_In_higher)
{
public:

	TEST_METHOD(Test_cont_len)
	{
		container testing_cont;
		Init(testing_cont);
		ifstream test_file_in("../Procedure/Test_files/In_higher_1_in.txt");
		In(testing_cont, test_file_in);

		int actual = testing_cont.len;
		int expected = 3;

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test_cont_IN_OUT)
	{
		container testing_cont;
		Init(testing_cont);
		ifstream test_file_in("../Procedure/Test_files/In_higher_1_in.txt");
		In(testing_cont, test_file_in);
		ofstream test_file_out("../Procedure/Test_Files/In_higher_2_res.txt");
		Out(testing_cont, test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../Procedure/Test_Files/In_higher_2_res.txt", "r");;
		FILE *file_2 = fopen("../Procedure/Test_Files/In_higher_3_etalon.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Clear)
{
public:

	TEST_METHOD(Test)
	{
		container testing_cont;
		Init(testing_cont);
		ifstream test_file_in("../Procedure/Test_Files/In_higher_1_in.txt");
		In(testing_cont, test_file_in);
		Clear(testing_cont);

		int actual = testing_cont.len;
		int expected = 0;

		Assert::AreEqual(expected, actual);
	}

};

TEST_CLASS(testing_Out_lower)
{
public:

	TEST_METHOD(Test1_cezar)
	{
		cezar testing_type;
		testing_type.rot = 3;
		ofstream test_file_out("../Procedure/Test_Files/Out_lower_cezar.txt");
		Out(testing_type, test_file_out, "test1", "tester1");
		test_file_out.close();
		
		ifstream test_file_in("../Procedure/Test_Files/Out_lower_cezar.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "It is Cezar: rot = 3, open = test1, code = whvw1, owner = tester1. ";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2_zamena)
	{
		zamena testing_type;
		testing_type.rule = 3;
		ofstream test_file_out("../Procedure/Test_Files/Out_lower_zamena.txt");
		Out(testing_type, test_file_out, "test2", "tester2");
		test_file_out.close();

		ifstream test_file_in("../Procedure/Test_Files/Out_lower_zamena.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "It is Zamena: rule = Keyword-change, open = test2, code = prop2, owner = tester2. ";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3_numeric)
	{
		numeric testing_type;
		testing_type.digit = 3;
		ofstream test_file_out("../Procedure/Test_Files/Out_lower_numeric.txt");
		Out(testing_type, test_file_out, "test3", "tester3");
		test_file_out.close();

		ifstream test_file_in("../Procedure/Test_Files/Out_lower_numeric.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "It is Numeric: digit = 3, open = test3, code = 22721223, owner = tester3. ";

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Out_middle)
{
public:

	TEST_METHOD(Test1_cezar)
	{
		code* testing_type = new code;
		testing_type->k = testing_type->CEZAR;
		char tmp_mes[maxStringeSize] = "TestMes";
		strcpy(testing_type->message, tmp_mes);
		char tmp_own[maxStringeSize] = "TestOwn";
		strcpy(testing_type->owner, tmp_own);
		testing_type->t.rot = 3;
		ofstream test_file_out("../Procedure/Test_Files/Out_middle_cezar.txt");
		Out(testing_type[0], test_file_out);
		test_file_out.close();

		ifstream test_file_in("../Procedure/Test_Files/Out_middle_cezar.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "It is Cezar: rot = 3, open = TestMes, code = WhvwPhv, owner = TestOwn. ";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test2_zamena)
	{
		code* testing_type = new code;
		testing_type->k = testing_type->ZAMENA;
		char tmp_mes[maxStringeSize] = "TestMes";
		strcpy(testing_type->message, tmp_mes);
		char tmp_own[maxStringeSize] = "TestOwn";
		strcpy(testing_type->owner, tmp_own);
		testing_type->r.rule = 2;
		ofstream test_file_out("../Procedure/Test_Files/Out_middle_zamena.txt");
		Out(testing_type[0], test_file_out);
		test_file_out.close();

		ifstream test_file_in("../Procedure/Test_Files/Out_middle_zamena.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "It is Zamena: rule = Pare-change, open = TestMes, code = SftsNft, owner = TestOwn. ";

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(Test3_numeric)
	{
		code* testing_type = new code;
		testing_type->k = testing_type->NUMERIC;
		char tmp_mes[maxStringeSize] = "TestMes";
		strcpy(testing_type->message, tmp_mes);
		char tmp_own[maxStringeSize] = "TestOwn";
		strcpy(testing_type->owner, tmp_own);
		testing_type->b.digit = 5;
		ofstream test_file_out("../Procedure/Test_Files/Out_middle_numeric.txt");
		Out(testing_type[0], test_file_out);
		test_file_out.close();

		ifstream test_file_in("../Procedure/Test_Files/Out_middle_numeric.txt");
		string actual;
		getline(test_file_in, actual);
		test_file_in.close();
		string expected = "It is Numeric: digit = 5, open = TestMes, code = 249232417923, owner = TestOwn. ";

		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Out_higher)
{
public:

	TEST_METHOD(Test_cont_IN_OUT)
	{
		container testing_cont;
		Init(testing_cont);
		ifstream test_file_in("../Procedure/Test_files/Out_higher_1_in.txt");
		In(testing_cont, test_file_in);		
		ofstream test_file_out("../Procedure/Test_Files/Out_higher_2_res.txt");
		Out(testing_cont,test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../Procedure/Test_Files/Out_higher_2_res.txt", "r");;
		FILE *file_2 = fopen("../Procedure/Test_Files/Out_higher_3_etalon.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Sort)
{
public:

	TEST_METHOD(Test_sort_IN_OUT)
	{
		container testing_cont;
		Init(testing_cont);
		ifstream test_file_in("../Procedure/Test_files/Sort_1_in.txt");
		In(testing_cont, test_file_in);
		Sort(testing_cont);
		ofstream test_file_out("../Procedure/Test_Files/Sort_2_res.txt");
		Out(testing_cont, test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../Procedure/Test_Files/Sort_2_res.txt", "r");;
		FILE *file_2 = fopen("../Procedure/Test_Files/Sort_3_etalon.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_Filter)
{
public:

	TEST_METHOD(Test_filter_IN_OUT)
	{
		container testing_cont;
		Init(testing_cont);
		ifstream test_file_in("../Procedure/Test_files/Filter_1_in.txt");
		In(testing_cont, test_file_in);
		ofstream test_file_out("../Procedure/Test_Files/Filter_2_res.txt");
		OutZamena(testing_cont, test_file_out);

		int expected = true;
		int actual = true;

		int i = 0;
		char ch_1[20], ch_2[20];
		FILE *file_1 = fopen("../Procedure/Test_Files/Filter_2_res.txt", "r");;
		FILE *file_2 = fopen("../Procedure/Test_Files/Filter_3_etalon.txt", "r");
		while (!feof(file_1) && !feof(file_2))
		{
			fgets(ch_1, 20, file_1);
			fgets(ch_2, 20, file_2);
			i++;
			if (strcmp(ch_1, ch_2))
				actual = false;
		}
		Assert::AreEqual(expected, actual);
	}
};

TEST_CLASS(testing_MesLength)
{
public:

	TEST_METHOD(Test1)
	{
		code s;
		char testMes[moreThanMax] = "";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = MesLength(s);

		Assert::AreEqual(0, actual);
	}

	TEST_METHOD(Test2)
	{
		code s;
		char testMes[moreThanMax] = "ABC abc 1234567!@#&*";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = MesLength(s);

		Assert::AreEqual(20, actual);
	}

	TEST_METHOD(Test3)
	{
		code s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = MesLength(s);

		Assert::AreEqual(79, actual);
	}

	TEST_METHOD(Test4)
	{
		code s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = MesLength(s);

		Assert::AreEqual(80, actual);
	}

	TEST_METHOD(Test5)
	{
		code s;
		char testMes[moreThanMax] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		for (int i = 0; i < moreThanMax; i++)
			s.message[i] = testMes[i];
		int actual = MesLength(s);

		Assert::AreEqual(80, actual);
	}
};