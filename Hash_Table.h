#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>

using Pair = std::pair<std::string, std::string>;
using THashTable = std::vector<std::list<Pair>>;
using Iterator = std::list<Pair>::iterator;
class HashTable
{
private:
	THashTable hashTable;
	size_t maxSize;
public:
	HashTable(size_t maxSize) : maxSize(maxSize)
	{
		hashTable.resize(maxSize);
	};
	HashTable(std::ifstream& file, size_t MaxSize);
	size_t hash(std::string key);
	Iterator find(std::string key);
	bool find(std::string key, Pair& pair);
	bool remove(std::string key);
	bool add(Pair pair);
	void print();
};
