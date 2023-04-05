#include <Windows.h>
#include "Hash_Table.h"

int main()
{
	int size = 15;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::ifstream file("eng_rus.txt");

	HashTable hash(file, size);

	std::cout << (hash.remove("suit") ? "removed\n" : "not removed\n");
	Pair pair;

	if (hash.find("cow", pair)) {
		std::cout << pair.second << '\n';
	}
	else {
		std::cout << "not found\n";
	}
	if (hash.add(std::make_pair("cow", "Корова"))) {
		std::cout << "add\n";
	}
	else {
		std::cout << "not add\n";
	}
	hash.print();

	std::cin.get();
}
