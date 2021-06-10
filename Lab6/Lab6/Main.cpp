#include"Stack.h"
int main() {

	Stack<int> stack = Stack<int>(1);
	stack.print_stack();
	std::cout << "------------------" << std::endl;
	stack.push(2);
	stack.print_stack();
	std::cout << "------------------" << std::endl;
	stack.push(3);
	stack.print_stack();
	std::cout << "------------------" << std::endl;
	stack.pop();
	stack.print_stack();
	std::cout << "------------------" << std::endl;
	std::cout << stack.get_size() << std::endl;
	
}