#ifndef _Enums_
#define _Enums_

//тип открываемого файла
enum TypeFile {
	Writer,
	Reader
};

//загатовка для типа ошибки
enum Error {
	er_0,		//нет ошибок
	er_1001,	//ошибка открытия файла для записи
	er_1002		//ошибка открытия файла для чтения
};

#endif
