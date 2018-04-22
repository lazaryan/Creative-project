#ifndef _MyConst_
#define _MyConst_

using namespace System;

static int	day	= DateTime::Now.Day,
		month	= DateTime::Now.Month,
		year	= DateTime::Now.Year;

/*����*/

#define FOLDER_SYSTEM			"Data\\"				//��������� �����
#define FOLDER_REPORT			 L"������\\"				//����� ��� �������

#define SOURCE_FILE_PRISE_LIST		FOLDER_SYSTEM + "prise.txt"		//����
#define SOURCE_FILE_PRISE_ONE_MINUTE	FOLDER_SYSTEM + "prise_per_minute.txt"	//���� ����� ������

#define SOURCE_FILE_REPORT		FOLDER_REPORT + L"�����_" + day  + \
					"_" + month + "_" + year + ".txt"	//������� �����
#define SOURCE_FILE_VISITS_LIST		FOLDER_SYSTEM + "vis_" + day  + \
					"_" + month + "_" + year + ".txt"	//��� � ���� (���� � ����� ����� ����)
#define SOURCE_FILE_TABLE FOLDER_SYSTEM +"Table.txt"
/*��������� ��������*/

#define DEFAULT_PRISE			3
#endif
