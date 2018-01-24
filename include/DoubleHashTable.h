#pragma once
 #include <iostream>

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

	auto get(int key)->int;
	auto put(int key, int value)->void;
	auto remove(int key)->void;
	auto getMax()->int;
	auto getMin()->int;
	auto print()->void;
	~DoubleHashTable();
};

