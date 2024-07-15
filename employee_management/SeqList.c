#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

//˳���ĳ�ʼ��
void SLInit(SL* ps)
{
	assert(ps);//ȷ��û�д����ָ��
	ps->SeqList = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//˳��������
void SLDestroy(SL* ps)
{
	assert(ps);

	if (ps->SeqList)
	{
		free(ps->SeqList);
	}

	ps->SeqList = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//˳�������� 
void SLCheckCapacity(SL* ps)
{
	assert(ps);

	SLDataType* temp = NULL;
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity;
		temp = (SLDataType*)realloc(ps->SeqList, (newCapacity = (ps->capacity == 0) ? 4 : (ps->capacity * 2)) * sizeof(SLDataType));//���ݹ��򣺳ɱ������ӣ�һ��1.5����2����
		assert(temp);
		ps->SeqList = temp;
		ps->capacity = newCapacity;
		temp = NULL;
	}
}

//˳����β������
//��˳������㹻�Ŀռ����ʱ�����������ݺ�˳���Ϊ�գ�
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	//˳�������� 
	SLCheckCapacity(ps);//ȷ��SeqListָ�벻Ϊ��֮���ж������Ƿ��㹻

	//��˳������㹻�Ŀռ����ʱ�����������ݺ�˳���Ϊ�գ�
	ps->SeqList[ps->size] = x;
	ps->size++;

}

//˳����ͷ������
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	//˳��������
	SLCheckCapacity(ps);//ȷ��SeqListָ�벻Ϊ��֮���ж������Ƿ��㹻

	//˳������㹻�Ŀռ����ʱ�����������ݺ�˳���Ϊ�գ�
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->SeqList[i + 1] = ps->SeqList[i];//ps->SeqList[0] = ps->SeqList[1]
	}
	ps->SeqList[0] = x;
	ps->size++;

}

//˳����β��ɾ��
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);//ȷ��˳����ڲ�Ϊ��
	ps->size--;
}

//˳����ͷ��ɾ��
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);

	for (int i = 0; i < ps->size - 1; i++)//ע��˴���size - 1��λ�ã���ֹ�Ѷ�������ݽ�����Ų��
	{
		ps->SeqList[i] = ps->SeqList[i + 1];
	}
	ps->size--;
}

//˳����ָ��λ��֮ǰ����
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(0 <= pos && pos >= ps->size);//ȷ��posΪ��Чλ��
	//˳��������
	SLCheckCapacity(ps);//ȷ��SeqListָ�벻Ϊ��֮���ж������Ƿ��㹻

	for (int i = ps->size - 1; i >= pos - 1; i--)
	{
		if (pos != ps->size)
		{
			ps->SeqList[i + 1] = ps->SeqList[i];
		}
	}
	ps->SeqList[pos - 1] = x;
	ps->size++;
}

//˳����ָ��λ��ɾ��
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(0 <= pos && pos <= ps->size);//ȷ��posΪ��Чλ��

	for (int i = pos + 1; i < ps->size; i++)
	{
		ps->SeqList[i - 1] = ps->SeqList[i];
	}
	ps->size--;
}
