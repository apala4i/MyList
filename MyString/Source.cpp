#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

template<typename T>
class List
{

public:
	List();
	~List();

	void print();
	void clear();
	void insert(T value, int index);
	void removeAt(int index);
	void pop_front();
	void pop_back();
	void push_back(T);
	void push_front(T);
	int get_size() { return Size; }
	T& operator [] (int index);
private:
	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};

template<typename T>
void List<T>::removeAt(int index)
{
	Node<T>* del_index = head;
	if (index == 0)
	{
		head = head->pNext;
		delete del_index;
	}
	else
	{
		Node<T>* current_Node = head;
		int current_index = 0;
		while (current_index + 1 != index)
		{
			current_Node = current_Node->pNext;
		}
		del_index = current_Node->pNext;
		current_Node->pNext = del_index->pNext;
		delete del_index;
	}
	--Size;
}

template<typename T>
void List<T>::insert(T value, int index)
{

	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		int current_index = 0;
		Node<T>* current_Node = head;
		while (current_index + 1 != index)
		{
			current_Node = current_Node->pNext;
			++current_index;
		}
		current_Node->pNext = new Node<T>(value, current_Node->pNext);
	}
	++Size;
}

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template <typename T>
T& List<T>::operator [] (int index)
{
	Node<T> *current = this->head;
	for (int i = 0; i < index; i++)
	{
		current = current->pNext;
	}
	return current->data;
}

template <typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	--Size;
}

template <typename T>
void List<T>::clear()
{
	while (Size)
		this->pop_front();
}

template <typename T>
void List<T>::print()
{
	for (int i = 0; i < Size; i++)
	{
		cout << this->operator[](i) << endl;
	}
}

template <typename T>
void List<T>::push_front(T value)
{
	head = new Node<T>(value, head);
	++Size;
}

template <typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

int main()
{

	List<int> joopa;
	joopa.push_back(1);
	joopa.push_back(2);
	joopa.push_back(3);
	joopa.push_back(4);
	joopa.print();
	joopa.insert(0, 1);
	joopa.insert(0, 0);
	cout << endl << endl;
	joopa.print();
	cout << endl;

}

