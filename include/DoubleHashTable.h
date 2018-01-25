#pragma once
 #include <iostream>
#include <fstream>
class DoubleHashTable
{
private:
	enum EntryType { Busy, Empty, Deleted };

	struct HashNode
	{
		int key;
		int value;
		enum EntryType info;
	};

	int size;// busy slots
	int capacity;
	HashNode *table;

	 
	auto HashFunc1(int key)->int;

	auto HashFunc2(int key)->int;

	 

public:
	 
	DoubleHashTable();
	auto reHash()->void;
	auto getSize()->int;
	auto search(int key)->std::pair<int, int>;
	auto insert(int key, int value)->void;
	auto remove(int key)->void;
	auto getMax()->std::pair<int, int>;
	auto getMin()->std::pair<int, int>;
	auto print(std::ofstream& fout) -> void;
	~DoubleHashTable();
};

