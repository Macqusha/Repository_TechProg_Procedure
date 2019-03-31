#ifndef __container__
#define __container__
namespace simple_codes {
	// Ссылка на описание шифра
	// Знание структуры самого шифра для представленной реализации контейнера не требуется
	struct code;
	// Простейший контейнер на основе одномерного массива
	struct container
	{
		// Максимальная длина
		enum { max_len = 100 };
		int len; // Текущая длина
		code *cont[max_len];
	};	
}
#endif