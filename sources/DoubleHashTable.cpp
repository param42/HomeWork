#include "stdafx.h"
#include "DoubleHashTable.h"


auto DoubleHashTable::HashFunc1(int key)->int {
	return key % capacity;
}
auto DoubleHashTable::HashFunc2(int key)->int {
	return (key * capacity - 1) % capacity;
}

 
DoubleHashTable::DoubleHashTable()
{

	capacity = 10;
	size = 0;
	table = new HashNode[capacity];

	for (int i = 0; i < capacity; i++)
	{
		table[i].info = Empty;
		table[i].key = NULL;
	}

}

auto DoubleHashTable::reHash()->void {

	capacity *= 2;
	HashNode *oldTable = table;

	table = new HashNode[capacity];

	for (int i = 0; i < capacity; i++)
	{
		table[i].info = Empty;
		table[i].key = NULL;
	}
	for (int i = 0; i < size; i++)
	{
		if (oldTable[i].info == Busy) {
			insert(oldTable[i].key, oldTable[i].value);
		}
	}
	delete[] oldTable;
}

auto DoubleHashTable::getSize() -> int
{
	return size;
}

auto DoubleHashTable::insert(int key, int value)->void
{

	if (size == capacity) {
		reHash();
	}

	int hashIndex = HashFunc1(key);
	int stepSize = HashFunc2(key);

	bool isFind = false;
	do
	{

		if (table[hashIndex].info == Busy && table[hashIndex].key == key) {
			return;
		}
		if (table[hashIndex].info == Empty || table[hashIndex].info == Deleted) {
			isFind = true;

		}
		if (!isFind) {
			hashIndex += stepSize;
			hashIndex %= capacity;
		}

	} while (!isFind);

	size++;
	table[hashIndex].key = key;
	table[hashIndex].value = value;
	table[hashIndex].info = Busy;

}

auto DoubleHashTable::remove(int key)->void
{
	if (size == 0) {
		throw std::logic_error("Table is empty");
	}

	int hashIndex = HashFunc1(key);
	int stepSize = HashFunc2(key);
	int firstIndex = hashIndex;
	do
	{

		if (table[hashIndex].info == Busy && table[hashIndex].key == key) {
			table[hashIndex].info = Deleted;
			size--;
		 
			return;
		}
		hashIndex += stepSize;
		hashIndex %= capacity;
		if (firstIndex == hashIndex) {
			 
			 throw std::logic_error("remove doesnt exist element");
		}

	} while (true);

}

auto DoubleHashTable::search(int key)->std::pair<int, int>
{
	int hashIndex = HashFunc1(key);
	int stepSize = HashFunc2(key);
	int firstIndex = hashIndex;

	do
	{

		if (table[hashIndex].info == Busy && table[hashIndex].key == key) {
			return std::make_pair(table[hashIndex].key, table[hashIndex].value);
		}
		hashIndex += stepSize;
		hashIndex %= capacity;
		if (firstIndex == hashIndex) {
			throw std::logic_error("Key wasn't found");
		}

	} while (true);

}

auto DoubleHashTable::getMax()->std::pair<int, int> {
	if (size == 0) {
		throw std::logic_error("Table is empty");
	}

	int max;
	int keyMax;
	bool isfindfirstBusy = false;
	int i = 0;
	do
	{
		if (table[i].info == Busy) {
			max = table[i].value;
			isfindfirstBusy = true;
		}
		i++;
		if (i > capacity) {
			throw std::logic_error("key not find");
		}
	} while (!isfindfirstBusy);


	for (int i = 0; i < capacity; i++) {
		if (table[i].info == Busy) {
			if (table[i].value> max) {
				max = table[i].value;
				keyMax = table[i].key;
			}
		}
	}

	return std::make_pair(keyMax, max);
}

auto DoubleHashTable::getMin()->std::pair<int, int> {
	if (size == 0) {
		throw std::logic_error("Table is empty");
	}

	int min;
	int keyMin;

	bool isfindfirstBusy = false;
	int i = 0;
	do
	{
		if (table[i].info == Busy) {
			min = table[i].value;
			isfindfirstBusy = true;
		}
		i++;
		if (i > capacity) {
			throw std::logic_error("key not find");
		}
	} while (!isfindfirstBusy);


	for (int i = 0; i < capacity; i++) {
		if (table[i].info == Busy) {
			if (table[i].value < min) {
				min = table[i].value;
				keyMin = table[i].key;
			}
		}
	}

	return std::make_pair(keyMin, min);
}

auto DoubleHashTable::print()->void
{
	 

	for (int i = 0; i<capacity; i++)
	{
	 
		if (table[i].info == Busy) {
			 
		}
	 
	}
}

DoubleHashTable::~DoubleHashTable() {
	delete[] table;
}
