#ifndef __code_atd__
#define __code_atd__
// Подключение необходимых типов данных
#include "zamena_atd.h"		
#include "cezar_atd.h"	
#include "numeric_atd.h"
namespace simple_codes 
{
	// структура, обобщающая все имеющиеся шифры
	const int maxStringeSize = 80;
	struct code 
	{
		// значения ключей для каждого из шифров
		enum key {ZAMENA, CEZAR, NUMERIC};
		key k; // ключ
		// используемые альтернативы
		union { // используем включение
			zamena r;			
			cezar t;
			numeric b;
		};
		char message[maxStringeSize]; //исходный текст
		//Warning. Меняя размер массива, изменить также условие в коде зашифрования в файлах cezars.cpp и zamenas.cpp. 
		char owner[maxStringeSize]; //исходный текст
	};
} // end simple_codes namespace
#endif
