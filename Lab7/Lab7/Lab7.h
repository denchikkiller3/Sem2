//16. На основі контейнера list побудувати двозв’язні кільцеві списки цілих чисел та символьних рядків.Виконати операції занесення заданого елемента до списку,
//вилучення елемента зі списку, виведення елементів списку на екран, переставлення елементів у зворотному порядку.
#include<list>
#include<iostream>

template<typename T>
class DoublyList
{
	template<typename A>
	class Node {
	public:
		Node<A>* next;
		Node<A>* prev;
		A data;
	};
public:
	std::list<Node<T>*> list;
	DoublyList(T data) {
		list = std::list<Node<T>*>::list();  // Виділяємо пам'ять під перший елемент і ініціалізуємо його
		Node<T>* new_node = new Node<T>;
		new_node->data = data;
		new_node->next = new_node;
		new_node->prev = new_node;
		list.push_back(new_node); // Додаємо його до списку
	}
	void delete_item(typename std::list<Node<T>*>::iterator position) 
	{
		// Вилучаємо елемент з послідовності
		(*position)->next->next = (*position)->prev;
		(*position)->prev->prev = (*position)->next; 
		//Очищаємо пам'ять
		free((*position));
		//Видаляємо елемент зі списку
		this->list.erase(position);
	}
	void insert(typename std::list<Node<T>*>::iterator position, T data) {
				// Виділяємо пам'ять та ініціалізуємо новий нод
				Node<T>* new_node = new Node<T>; 
				new_node->data = data;

				// Вставляємо новий нод у послідовність
				new_node->prev = *position; 
				new_node->next = (*position)->next;
				(*position)->next = new_node;
				// Вставляємо новий нод у список
				this->list.insert(++position, new_node);

				// Якщо додаємо в кінець, то змінюємо вказівник першого елемента
				if (position == this->list.end()) {
					(*this->list.begin())->prev = new_node;
				}
	}
	void reverse() {

		this->list.reverse(); // Переставляємо в зворотньому порядку список
		typename std::list<Node<T>*>::iterator begin = this->list.begin();
		typename std::list<Node<T>*>::iterator end = this->list.end();
		
		// Перевертаємо вказівники в кожному елементу списка
		while (begin !=end) {
			Node<T>* temp = new Node<T>;
			temp = (*begin)->next;
			(*begin)->next = (*begin)->prev;
			(*begin)->prev = temp;
			begin++;
		}
	}
	void print_list() {
		Node<T>* temp = (*this->list.begin());
		//Виводимо всі елементи до останнього
		while (temp!= (*(--this->list.end()))) {
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
		//Виводимо останній елемент
		std::cout << temp->data << std::endl;
	}
};

