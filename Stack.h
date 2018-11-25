#pragma once
class Stack
{
	//Нижняя и верхняя границы стека
	enum
	{
		EMPTY = 0,
		FULL = 30
	};
	//Массив для хранения данных
	unsigned char st[FULL];
	unsigned char bracket_open[FULL];
	//Указатель на вершину стека
	int top;
	int br_o;
public:
	//Конструктор
	Stack();
	//Добавление элемента
	void Push(unsigned char c);
	void Clear_Stack();
	//Извлечение элемента
	int Pop();
	void Check_Bracket();
	//Проверка существования элементов в стеке
	bool IsEmpty();
	//Проверка на переполнение стека
	bool IsFull();
	//Количество элементов в стеке
	int GetCount();
};
