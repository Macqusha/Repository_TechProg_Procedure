#ifndef __code_atd__
#define __code_atd__
// Подключение необходимых типов данных
#include "zamena_atd.h"		
#include "cezar_atd.h"	
#include "numeric_atd.h"
namespace simple_codes 
{
	// Максимальная длина исходного текста
	const int maxStringeSize = 80;
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
		char message[maxStringeSize]; // Исходный текст
		char owner[maxStringeSize]; // Владелец
	};
} // end simple_codes namespace
#endif
