
#include "LinearHashTable.h"

 
	auto LinearHashTable::hashFunc(int key)->int
	{ 
		if (key >= 0) {
			return key%capacity;
		}
		else {
			return (((key%capacity) + capacity) % capacity);
		}
	}



	 LinearHashTable::LinearHashTable()
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

	 auto LinearHashTable::getSize() -> int
	 {
		 return size;
	 }

	auto LinearHashTable::reHash()->void {

		capacity *= 2;
		HashNode *oldTable = table;
		int tempSize = size;
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
		size = tempSize;
		delete[] oldTable;
	}

	 auto LinearHashTable::insert(int key, int value)->void
	{
	 
		if (size == capacity) {
			reHash();
		}

		int hashIndex = hashFunc(key);
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
				hashIndex++;
				hashIndex %= capacity;
			}

		} while (!isFind);

		size++;
		table[hashIndex].key = key;
		table[hashIndex].value = value;
		table[hashIndex].info = Busy;

	}

	 auto LinearHashTable::remove(int key)->void
	{
		 if (size == 0) {
			 throw std::logic_error("Table is empty");
		 }
		int hashIndex = hashFunc(key);
		int firstIndex = hashIndex;
		do
		{

			if (table[hashIndex].info == Busy && table[hashIndex].key == key) {
				table[hashIndex].info = Deleted;
				size--;
			 
				return;
			}
			hashIndex++;
			hashIndex %= capacity;
			if (firstIndex == hashIndex) {
			 
				throw std::logic_error("remove doesnt exist element");
			}

		} while (true);

	}

	 auto LinearHashTable::search(int key)->std::pair<int, int>
	{

		int hashIndex = hashFunc(key);
		int firstIndex = hashIndex;

		do
		{

			if (table[hashIndex].info == Busy && table[hashIndex].key == key) {
				return std::make_pair(table[hashIndex].key, table[hashIndex].value);
			}
			hashIndex++;
			hashIndex %= capacity;
			if (firstIndex == hashIndex) {
				throw std::logic_error("get doesnt exist element");
			}

		} while (true);

	}

	 auto LinearHashTable::getMax()->std::pair<int, int> {
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

	 auto LinearHashTable::getMin()->std::pair<int, int> {
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

	auto LinearHashTable::  print(std::ofstream& fout) -> void
	{
		for (int i = 0; i <capacity; i++)
		{
			fout << i << ") ";
			int value = table[i].key;
			if (table[i].info == Busy) {			
					fout << table[i].key <<"  "
						<<  table[i].value;
				
			}
			fout << std::endl;
		}
	}

	LinearHashTable::~LinearHashTable()
	{
		delete[] table;
	}
