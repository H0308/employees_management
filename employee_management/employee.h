#pragma once

#include "SeqList.h"

//typedef int (*cmp)(const void*, const void*);

typedef struct SeqList_dynamic SL;

typedef struct birthday
{
	int year;
	int month;
	int day;
}birthday;

typedef struct employee
{
	int id;
	char name[50];
	char gender[10];
	birthday birthday;
	char qualification[20];
	char job[30];
	char teleNum[15];
	char location[50];
}employee;

// ����˵�
void menu();

// ��������
void LoadEmployee(SL* employees);

// ��ʼ����������
void employeeInfoGet(SL* employees);

// ����Ա��
// ���ҷ�ʽ�˵�
void menuForFind();
// ����Ա�����������±�
int findEmployee(SL* employees);
// ����Ա��������ʾ��ӦԱ����Ϣ
void findEmployee_print(SL* employees);

// �޸Ĳ˵�
void menuForModify();
// �޸�Ա����Ϣ
void modifyEmployee(SL* employees);

// ����Ա����Ϣ
void insertEmployee(SL* employees);

// ɾ��Ա����Ϣ
void deleteEmployee(SL* employees);

// ����˵�
void menuForSort();
// ����ָ����������
void sortEmployees(SL* employees);
// ��ӡ����������
void printSortedEmp(employee* tmp, int size);

// ���ļ���д������
void writeIntoFile(SL* employees);

// ����ϵͳ����
void destroyEmployee(SL* employees);

// ��ӡ����Ա����Ϣ
void printEmployees(SL* employees);
