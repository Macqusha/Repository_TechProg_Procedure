#include <fstream>
#include "code_atd.h"
#include "conteiner.h"

using namespace std;

namespace simple_codes {
	// Сигнатуры требуемых внешних функций
	int MesLength(code &s);

	// Cравнение ключей двух программных объектов
	bool Compare(code *first, code *second) {
		return MesLength(*first) < MesLength(*second);
	}
}