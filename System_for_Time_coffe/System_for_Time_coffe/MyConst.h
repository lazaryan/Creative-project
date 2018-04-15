#ifndef _MyConst_
#define _MyConst_

using namespace System;

static int	day = DateTime::Now.DayOfYear,
		year = DateTime::Now.Year;

#define SOURCE_FILE_PRISE_LIST		"Data/prise.txt"		//цены
#define SOURCE_FILE_PRISE_ONE_MINUTE	"Data/prise_per_minute.txt"	//цена одной минуты
#define SOURCE_FILE_REPORT		"Data/report.txt"		//отчет
#define SOURCE_FILE_VISITS_LIST		"Data/" + "vis_" + day  + \
					    "_" + year + ".txt"	//кто в кафе (файл в имени имеет дату)
#endif
