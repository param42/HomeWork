#pragma once
#include <iostream>

class LinearHashTable
{

private:
	enum EntryType { Busy, Empty, Deleted };

	struct HashNode
	{
		int key;
		int value;
		enum EntryType info;
	};
	HashNode *table;
	int capacity;
	int size;

	auto hashFunc(int key)->int;
 
	 
public:
	LinearHashTable();
	auto getSize()->int;
	auto reHash()->void;
	auto search(int key)->std::pair<int, int>;
	auto insert(int key, int value)->void;
	auto remove(int key)->void;
	auto getMax()->std::pair<int, int>;
	auto getMin()->std::pair<int, int>;
	auto print()->void;
	~LinearHashTable();
};

