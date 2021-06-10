//16. �� ����� ���������� list ���������� �������� ������ ������ ����� ����� �� ���������� �����.�������� �������� ��������� �������� �������� �� ������,
//��������� �������� � ������, ��������� �������� ������ �� �����, ������������� �������� � ���������� �������.
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
		list = std::list<Node<T>*>::list();  // �������� ���'��� �� ������ ������� � ���������� ����
		Node<T>* new_node = new Node<T>;
		new_node->data = data;
		new_node->next = new_node;
		new_node->prev = new_node;
		list.push_back(new_node); // ������ ���� �� ������
	}
	void delete_item(typename std::list<Node<T>*>::iterator position) 
	{
		// �������� ������� � �����������
		(*position)->next->next = (*position)->prev;
		(*position)->prev->prev = (*position)->next; 
		//������� ���'���
		free((*position));
		//��������� ������� � ������
		this->list.erase(position);
	}
	void insert(typename std::list<Node<T>*>::iterator position, T data) {
				// �������� ���'��� �� ���������� ����� ���
				Node<T>* new_node = new Node<T>; 
				new_node->data = data;

				// ���������� ����� ��� � �����������
				new_node->prev = *position; 
				new_node->next = (*position)->next;
				(*position)->next = new_node;
				// ���������� ����� ��� � ������
				this->list.insert(++position, new_node);

				// ���� ������ � �����, �� ������� �������� ������� ��������
				if (position == this->list.end()) {
					(*this->list.begin())->prev = new_node;
				}
	}
	void reverse() {

		this->list.reverse(); // ������������� � ����������� ������� ������
		typename std::list<Node<T>*>::iterator begin = this->list.begin();
		typename std::list<Node<T>*>::iterator end = this->list.end();
		
		// ����������� ��������� � ������� �������� ������
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
		//�������� �� �������� �� ����������
		while (temp!= (*(--this->list.end()))) {
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
		//�������� ������� �������
		std::cout << temp->data << std::endl;
	}
};

