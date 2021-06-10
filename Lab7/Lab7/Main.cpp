
#include"DoublyList.h"
int main() {

	DoublyList<int> list = DoublyList<int>(1);
	list.print_list();
	std::cout << "------------------" << std::endl;

	list.insert(list.list.begin(), 2);
	list.insert(++list.list.begin(), 3);
	list.print_list();
	std::cout << "------------------" << std::endl;
	list.reverse();
	list.print_list();
	std::cout << "------------------" << std::endl;
	list.delete_item(list.list.begin());
	list.print_list();
}