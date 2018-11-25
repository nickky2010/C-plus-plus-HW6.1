#include <iostream>
#include "Stack.h"
#include <string.h>
using namespace std;

Stack::Stack()
{
	//���������� ���� ����
	top = EMPTY;
	br_o = EMPTY;
}

bool Stack::IsEmpty()
{
	//����?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	//�����?
	return top == FULL;
}

int Stack::GetCount()
{
	//���������� �������������� � ����� ���������
	return top + 1;
}

void Stack::Push(unsigned char c)
{
	//���� � ����� ���� �����, �� ����������� ���������
	//�� ������� ����� � ��������� ����� �������
	if (!IsFull()) {
		st[top++] = c;
	}
}

void Stack::Clear_Stack()
{
	top = EMPTY;
}

int Stack::Pop()
{
	//���� � ����� ���� ��������, �� ����������
	//������� � ��������� ��������� �� ������� �����
	if (!IsEmpty())
		return st[--top];
	else
		//���� � ����� ��������� ���
		return 0;
}

void Stack::Check_Bracket()                     // �������� ������ ����� �� ����������� ������
{
	unsigned char c;
	br_o = 0;
	for (int i = 0; i < top; i++) {
		c = st[i];
		if (c == '(' || c == '{' || c == '[') {
			cout << c;
			bracket_open[br_o++]=c;
		}
		else if (c == ')') {
			if (bracket_open[br_o - 1] != '(') {
				while (bracket_open[br_o - 1] != '(')
					--br_o;
				if (br_o < 0) { cout << "\n������! ������ ������� �����������" << endl; break; }
			}
			if (br_o >= 0) {
				--br_o;
				cout << c;
			}
			else break;
		}
		else if (c == '}') {
			if (bracket_open[br_o - 1] != '{') {
				while (bracket_open[br_o - 1] != '{')
					--br_o;
				if (br_o < 0) { cout << "\n������! ������ ������� �����������" << endl; break; }
			}
			if (br_o >= 0) {
				--br_o;
				cout << c;
			}
			else break;
		}
		else if (c == ']') {
			if (bracket_open[br_o - 1] != '[') {
				while (bracket_open[br_o - 1] != '[')
					--br_o;
				if (br_o < 0) { cout << "\n������! ������ ������� �����������" << endl; break; }
			}
			if (br_o >= 0) {
				--br_o;
				cout << c;
			}
			else break;
		}
		else if (st[i + 1] == '\n' && c != ';') {
			cout << "\n������! ������� ����� ������� ����� ������" << endl;
			break;
		}
		else if (st[i + 1] == '\n' && c == ';') {
			if (br_o >= 0) {
				cout << "\n������! ������ �� ������� ��������������� �������" << endl;
				break;
			}
			cout << c << endl;
			cout << "\n������ ������� ���������" << endl;
			break; 
		}
		else cout << c;
	}
}
