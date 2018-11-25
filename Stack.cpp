#include <iostream>
#include "Stack.h"
#include <string.h>
using namespace std;

Stack::Stack()
{
	//Изначально стек пуст
	top = EMPTY;
	br_o = EMPTY;
}

bool Stack::IsEmpty()
{
	//Пуст?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	//Полон?
	return top == FULL;
}

int Stack::GetCount()
{
	//Количество присутствующих в стеке элементов
	return top + 1;
}

void Stack::Push(unsigned char c)
{
	//Если в стеке есть место, то увеличиваем указатель
	//на вершину стека и вставляем новый элемент
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
	//Если в стеке есть элементы, то возвращаем
	//верхний и уменьшаем указатель на вершину стека
	if (!IsEmpty())
		return st[--top];
	else
		//Если в стеке элементов нет
		return 0;
}

void Stack::Check_Bracket()                     // проверка строки стека на расстановку скобок
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
				if (br_o < 0) { cout << "\nОшибка! Скобка закрыта неправильно" << endl; break; }
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
				if (br_o < 0) { cout << "\nОшибка! Скобка закрыта неправильно" << endl; break; }
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
				if (br_o < 0) { cout << "\nОшибка! Скобка закрыта неправильно" << endl; break; }
			}
			if (br_o >= 0) {
				--br_o;
				cout << c;
			}
			else break;
		}
		else if (st[i + 1] == '\n' && c != ';') {
			cout << "\nОшибка! Неверно задан признак конца строки" << endl;
			break;
		}
		else if (st[i + 1] == '\n' && c == ';') {
			if (br_o >= 0) {
				cout << "\nОшибка! Строка не закрыта соответствующей скобкой" << endl;
				break;
			}
			cout << c << endl;
			cout << "\nСтрока введена правильно" << endl;
			break; 
		}
		else cout << c;
	}
}
