#ifndef _MyConst_
#define _MyConst_

using namespace System;

static int	day	= DateTime::Now.Day,
		month	= DateTime::Now.Month,
		year	= DateTime::Now.Year;

#define SOURCE_FILE_PRISE_LIST		"Data/prise.txt"			//����
#define SOURCE_FILE_PRISE_ONE_MINUTE	"Data/prise_per_minute.txt"		//���� ����� ������
#define SOURCE_FILE_REPORT		L"������/" + L"�����_" + day  + \
					"_" + month + "_" + year + ".txt"	//������� �����
#define SOURCE_FILE_VISITS_LIST		"Data/" + "vis_" + day  + \
					"_" + month + "_" + year + ".txt"	//��� � ���� (���� � ����� ����� ����)
#endif
