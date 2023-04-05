#include "Hash_Table.h"

HashTable::HashTable(std::ifstream& file, size_t MaxSize)
{
	maxSize = MaxSize;
	hashTable.resize(maxSize);
	std::string rus, eng;
	while (file >> eng && file >> rus)
	{
		Pair tmp = std::make_pair(eng, rus);
		int index = hash(eng);
		if (std::find(hashTable[index].begin(), hashTable[index].end(), tmp) == hashTable[index].end())
		{
			hashTable[index].push_back(tmp);
		}
	}
	file.close();
}

size_t HashTable::hash(std::string key)
{
	size_t res = 0, len = key.length();
	for (int i = 0; i < len; ++i)
		res += key[i];
	return res % maxSize;
}

Iterator HashTable::find(std::string key)
{
	int index = hash(key);
	return std::find_if(hashTable[index].begin(), hashTable[index].end(), [&key](Pair elem)->bool {return elem.first == key; });

}

bool HashTable::find(std::string key, Pair& pair)
{
	bool result = false;
	int index = hash(key);
	Iterator it = std::find_if(hashTable[index].begin(), hashTable[index].end(), [&key](Pair elem)->bool {return elem.first == key; });
	if (it != hashTable[index].end()) {
		pair = *it;
		result = true;
	}
	return result;
}

bool HashTable::remove(std::string key)
{
	bool result = false;
	Iterator it = find(key);
	size_t index = hash(key);
	if (it != hashTable[index].end()) {
		result = true;
		hashTable[index].remove(*it);
	}
	return result;
}

bool HashTable::add(Pair pair)
{
	bool res = false;
	int index = hash(pair.first);
	if (std::find_if(hashTable[index].begin(), hashTable[index].end(), [&pair](Pair elem)->bool {return elem.first == pair.first; }) == hashTable[index].end())
	{
		hashTable[index].push_back(pair);
		res = true;
	}

	return res;
}

void HashTable::print()
{
	for (int i = 0; i < maxSize; i++)
	{
		for (auto pair : hashTable[i])
			std::cout << i << ": " << pair.first << ' ' << pair.second << '\n';
	}
}
