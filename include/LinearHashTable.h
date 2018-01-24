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
	auto reHash()->void;
	auto get(int key)->int;
	auto put(int key, int value)->void;
	auto remove(int key)->void;
	auto getMax()->int;
	auto getMin()->int;
	auto print()->void;
	~LinearHashTable();
};

