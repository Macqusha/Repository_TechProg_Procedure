#ifndef __code_atd__
#define __code_atd__
// Подключение необходимых типов данных
#include "zamena_atd.h"		
#include "cezar_atd.h"	
#include "numeric_atd.h"
namespace simple_codes 
{
	// максимальная длина исходного текста
	const int maxStringeSize = 80;
	// структура, обобщающая все имеющиеся шифры
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
		char owner[maxStringeSize]; //исходный текст
	};
} // end simple_codes namespace
#endif
