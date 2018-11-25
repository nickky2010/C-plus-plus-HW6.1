#pragma once
class Stack
{
	//������ � ������� ������� �����
	enum
	{
		EMPTY = 0,
		FULL = 30
	};
	//������ ��� �������� ������
	unsigned char st[FULL];
	unsigned char bracket_open[FULL];
	//��������� �� ������� �����
	int top;
	int br_o;
public:
	//�����������
	Stack();
	//���������� ��������
	void Push(unsigned char c);
	void Clear_Stack();
	//���������� ��������
	int Pop();
	void Check_Bracket();
	//�������� ������������� ��������� � �����
	bool IsEmpty();
	//�������� �� ������������ �����
	bool IsFull();
	//���������� ��������� � �����
	int GetCount();
};
