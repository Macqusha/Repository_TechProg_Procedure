#ifndef __code_atd__
#define __code_atd__
// Подключение необходимых типов данных
#include "zamena_atd.h"		
#include "cezar_atd.h"
#include <string>		
namespace simple_codes 
{
	// структура, обобщающая все имеющиеся шифры
	struct code 
	{
		// значения ключей для каждого из шифров
		enum key {ZAMENA, CEZAR};
		key k; // ключ
		// используемые альтернативы
		union { // используем включение
			zamena r;			
			cezar t;			
		};
		char message[20]; //исходный текст
		//warning меняя размер массива, изменить также код зашифрования в файлах cezars.cpp и zamenas.cpp. искать по фразе: && i < 20)
	};
} // end simple_codes namespace
#endif
