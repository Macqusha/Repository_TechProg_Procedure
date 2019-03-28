#ifndef __conteiner__
#define __conteiner__
namespace simple_codes {
	// Ссылка на описание шифра. 
	// Знание структуры самого шифра для представленной 
	// реализации контейнера не требуется
	struct code;
	// Простейший контейнер на основе одномерного массива
	struct container
	{
		//const int max_len=100; //максимальная длина
		enum { max_len = 100 };
		int len; // текущая длина
		code *cont[max_len];
	};	
}
#endif