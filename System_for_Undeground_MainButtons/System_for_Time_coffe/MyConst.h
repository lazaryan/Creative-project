#ifndef _MyConst_
#define _MyConst_

using namespace System;

static int	day	= DateTime::Now.Day,
		month	= DateTime::Now.Month,
		year	= DateTime::Now.Year;

/*пути*/

#define FOLDER_SYSTEM			"Data\\"				//системная папка
#define FOLDER_REPORT			 L"Отчеты\\"				//папка для отчетов

#define SOURCE_FILE_PRISE_LIST		FOLDER_SYSTEM + "prise.txt"		//цены
#define SOURCE_FILE_PRISE_ONE_MINUTE	FOLDER_SYSTEM + "prise_per_minute.txt"	//цена одной минуты

#define SOURCE_FILE_REPORT		FOLDER_REPORT + L"Отчет_" + day  + \
					"_" + month + "_" + year + ".txt"	//дневной отчет
#define SOURCE_FILE_VISITS_LIST		FOLDER_SYSTEM + "vis_" + day  + \
					"_" + month + "_" + year + ".txt"	//кто в кафе (файл в имени имеет дату)
#define SOURCE_FILE_TABLE FOLDER_SYSTEM +"Table.txt"
/*дефолтные значения*/

#define DEFAULT_PRISE			3
#endif
