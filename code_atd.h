#ifndef __code_atd__
#define __code_atd__
#include <string>
// Подключение необходимых типов данных
#include "zamena_atd.h"		
#include "cezar_atd.h"		
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
	};
} // end simple_codes namespace
#endif
