#ifndef __code_atd__
#define __code_atd__
// Подключение необходимых типов данных
#include "zamena_atd.h"		
#include "cezar_atd.h"	
#include "numeric_atd.h"
namespace simple_codes 
{
	// Максимальная длина исходного текста
	const int MAX_STRING_SIZE = 80;
	// Структура, обобщающая все имеющиеся шифры
	struct code 
	{
		// Значения ключей для каждого из шифров
		enum key {ZAMENA, CEZAR, NUMERIC};
		key k; // Ключ
		// Используемые альтернативы
		union { // Используем включение
			zamena r;			
			cezar t;
			numeric b;
		};
		char message[MAX_STRING_SIZE]; // Исходный текст
		char owner[MAX_STRING_SIZE]; // Владелец
	};
} // end simple_codes namespace
#endif
