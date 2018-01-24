#include "stdafx.h"
#include "LinearHashTable.h"

 
	auto LinearHashTable::hashFunc(int key)->int
	{
		return key % capacity;
	}



	 LinearHashTable::LinearHashTable()
	{
		capacity = 3;//////////////////////////
		size = 0;
		table = new HashNode[capacity];

		for (int i = 0; i < capacity; i++)
		{
			table[i].info = Empty;
			table[i].key = NULL;
		}


	}

	auto LinearHashTable::reHash()->void {

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
				put(oldTable[i].key, oldTable[i].value);
			}
		}
		delete[] oldTable;
	}

	 auto LinearHashTable::put(int key, int value)->void
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
			 
				return; 
			}

		} while (true);

	}

	 auto LinearHashTable::get(int key)->int
	{
		int hashIndex = hashFunc(key);
		int firstIndex = hashIndex;

		do
		{

			if (table[hashIndex].info == Busy && table[hashIndex].key == key) {
				return table[hashIndex].value;
			}
			hashIndex++;
			hashIndex %= capacity;
			if (firstIndex == hashIndex) {
				throw std::logic_error("Key wasn't found");
			}

		} while (true);

	}

	 auto LinearHashTable::getMax()->int {
		if (size == 0) {
			return 0; // throw
		}

		int max;
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
				return 0; // throw 
			}
		} while (!isfindfirstBusy);


		for (int i = 0; i < capacity; i++) {
			if (table[i].info == Busy) {
				if (table[i].value> max) {
					max = table[i].value;
				}
			}
		}

		return max;
	}

	 auto LinearHashTable::getMin()->int {
		if (size == 0) {
			return 0; // throw
		}

		int min;
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
				return 0; // throw 
			}
		} while (!isfindfirstBusy);


		for (int i = 0; i < capacity; i++) {
			if (table[i].info == Busy) {
				if (table[i].value < min) {
					min = table[i].value;
				}
			}
		}

		return min;
	}

	auto LinearHashTable::  print()->void
	{
		 

		for (int i = 0; i<capacity; i++)
		{
		 
			if (table[i].info == Busy) {
				 
			}
			 
		}
	}

	LinearHashTable::~LinearHashTable()
	{
		delete[] table;
	}
