#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include "employee.h"

int main()
{
	SL employees;
	SLInit(&employees);
	char ans = 0;
	printf("�Ƿ���Ҫ�����ϴε����ݣ�y/n");
	scanf(" %c", &ans);
	if (ans == 'y')
	{
		LoadEmployee(&employees);
	}
	menu();
	printf("������ѡ�");
	int choice = 0;
	while (scanf("%d", &choice))
	{
		switch (choice)
		{
		case 1:
			employeeInfoGet(&employees);
			break;
		case 2:
			findEmployee_print(&employees);
			break;		
		case 3:
			modifyEmployee(&employees);
			break;
		case 4:
			insertEmployee(&employees);
			break;
		case 5:
			deleteEmployee(&employees);
			break;
		case 6:
			sortEmployees(&employees);
			break;
		case 7:
			printEmployees(&employees);
			break;
		case 8:
			destroyEmployee(&employees);
			printf("ллʹ��");
			return 1;
		default:
			printf("�밴�ղ˵���������\n");
			break;
		}
		menu();
		printf("������ѡ�");
	}
}