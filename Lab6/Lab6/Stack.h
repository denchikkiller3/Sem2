//16. Створити шаблонний клас – стек на основі зв’язного списку у динамічній пам’яті.
//Тип елементів стеку визначається параметром шаблона (цілі числа, дійсні числа, символи або символьні рядки).
//Передбачити функції для виконання таких операцій: занесення елемента у стек, вилучення значення з вершини стеку,
//виведення усіх значень стеку на екран, визначення кількості елементів стеку.
#include<iostream>
template<typename T>
class Node {
public:
	Node<T>* next;
	T data;
};
template<typename T>
class Stack
{
private:
	int size;
public:
	Node<T>* top;
	Stack(T data) {
		top = (Node<T>*)malloc(sizeof(Node<T>)); 
		top->data = data;
		top->next = nullptr;
		this->size = 1;
	}
	~Stack() {
		Node<T>* next;
		while (top != nullptr) {
			next = this->top->next;
			delete top;
			this->top = next; 
			
		}
	}
	void push(T data) {
		Node<T>* new_node = (Node<T>*)malloc(sizeof(Node<T>)); 
		new_node->data = data;
		new_node->next = this->top;
		this->top = new_node;
		this->size += 1; 
	}
	void pop() {
		if (top != nullptr) {
			Node<T>* temp = this->top->next;
			free(this->top); 
			this->top = temp;
			this->size -= 1; 
		}
	}
	void print_stack() {
		Node<T>* temp = this->top;
		while (temp != nullptr) { 
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}

	int get_size() {
		return size;
	}
};
