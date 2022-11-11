//Добавить функции:
//Light. Удаления интервала значения. Например список 1,2,3,4,5. Удалить 2,3,4 в интевале 1-5. На выходе 1,5


#include<iostream>
using namespace std;
#include<vector>
#include<string>
template <typename T>//Шаблон
struct Node//Название структуры
{
	T value;// Полезные данные
	Node<T>* next;
	Node<T>* prev;
	int index;
	Node<T>(int _value)//Конструктор
	{
		value = _value;
		next = nullptr;
		prev = nullptr;
		index = 0;
	}

};
template <typename T>//Шаблон
struct List// Управляющая структура
{
	Node<T>* first; //Указатель на первый листок
	Node<T>* last;//Указатель на ппоследний листок

	List()
	{
		first = nullptr;
		last = nullptr;

	}
	bool is_empty()//Функция проверки есть ли листики
	{
		return first == nullptr;
	}
	void push_back(T _value)
	{
		Node<T>* p = new Node<T>(_value);
		if (is_empty())
		{
			first = p;
			last = p;
			p->index = 0;
			return;
		}
		last->next = p;
		p->prev = last;
		last = p;
		p->index = p->prev->index + 1;
	}
	void print()
	{
		Node<T>* p = first;
		if (is_empty())
			return;
		while (p)
		{
			cout << p->value << "\t";
			p = p->next;

		}
		cout << "\n";
	}
	Node <T>* find(T _value)
	{
		Node<T>* p = first;
		while (p && p->value != _value)
			p = p->next;
		return (p && p->value == _value) ? p : nullptr;
	}
	void remove_first()
	{
		if (is_empty())
			return;
		Node<T>* p = first;
		first = p->next;
		delete p;
		while (p != nullptr)
		{
			p->index = p->index - 1;
			p = p->next;
		}
		delete p;
	}
	void remove_last()
	{
		if (is_empty())
			return;
		Node<T>* p = last;
		first = p->prev;
		delete p;
	}
	void reverse_print()
	{
		Node<int>* p = last;
		if (is_empty())
			return;
		while (p)
		{
			cout << p->value << "\t";
			p = p->prev;
		}
		cout << "\n";
	}
	void removeAt(T _value)
	{
		Node<T>* p = find(_value);
		if (p == nullptr)
		{
			cout << "No item with value " << _value << "\n";
			return;
		}
		Node<T>* _left = p->prev;
		Node<T>* _right = p->next;
		//p->prev->next = p->next;
		//p->next->prev = p->prev;
		_left->next = _right;
		_right->prev = _left;
		while (p->next != nullptr)
		{
			p->next->index = (p->next->index) - 1;
			p = p->next;
		}
		delete p;

	}
	void push_After(T _value, T _new_value)
	{

		Node<T>* current = find(_value);
		if (current == nullptr)
		{
			cout << "No item with value " << _value << "\n";
			return;
		}
		Node<T>* p = new Node<T>(_new_value);
		Node<T>* right = current->next;
		current->next = p;
		p->next = right;
		right->prev = p;
		p->prev = current;


	}
	void push_Before(T _value, T _new_value)
	{

		Node<T>* current = find(_value);
		if (current == nullptr)
		{
			cout << "No item with value " << _value << "\n";
			return;
		}
		Node<T>* p = new Node<T>(_new_value);
		Node<T>* left = current->prev;
		current->prev = p;
		p->prev = left;
		left->next = p;
		p->next = current;


	}
	//функция дз
	void delete_bite(int _begin, int _end)
	{
		Node<T>* begin = find(_begin);
		Node<T>* end = find(_end);
		while (begin->next != end)
		{
			Node<T>* p = begin->next;
			begin->next = begin->next->next;
			begin->next->prev = begin;
			delete p;
		}
	}
};

int main()
{

	List<int> new_list;
	new_list.push_back(1);
	new_list.push_back(2);
	new_list.push_back(3);
	new_list.push_back(4);
	new_list.push_back(5);
	new_list.delete_bite(1, 5);
	new_list.print();

	return 0;
}