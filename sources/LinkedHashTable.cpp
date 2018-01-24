#include "stdafx.h"
#include "LinkedHashTable.h"


LinkedHashTable::LinkedHashTable(int size) {
	tableSize = size;
	table = new HashList*[tableSize];
	for (int i = 0; i < tableSize; i++)
		table[i] = NULL;
}
LinkedHashTable::LinkedHashTable() {
	tableSize = 10;
	table = new HashList*[tableSize];
	for (int i = 0; i < tableSize; i++)
		table[i] = NULL;
}

auto LinkedHashTable::get(int key)->int {

	int hash = HashFunc(key);
	if (table[hash] == NULL)
		throw std::logic_error("Key wasn't found");
	else {
		HashList *entry = table[hash];
		while (entry != NULL && entry->getKey() != key)
			entry = entry->getNext();
		if (entry == NULL)
			throw std::logic_error("Key wasn't found");
		else
			return entry->getValue();
	}
}

auto LinkedHashTable::put(int key, int value)->void {
	int hash = HashFunc(key);
	if (table[hash] == NULL)
		table[hash] = new HashList(key, value);
	else {

		HashList *entry = table[hash];
		while (entry->getNext() != NULL) {
			entry = entry->getNext();
		}
		if (entry->getKey() == key) {
			entry->setValue(value);
		}

		else {
			entry->setNext(new HashList(key, value));
		}

	}

}

auto LinkedHashTable::remove(int key)->void {

	int hash = HashFunc(key);

	if (table[hash] != NULL) {

		HashList *prevEntry = NULL;
		HashList *entry = table[hash];
		while (entry->getNext() != NULL && entry->getKey() != key) { //проходим по связному списку
			prevEntry = entry;
			entry = entry->getNext();
		}

		if (entry->getKey() == key) {
			if (prevEntry == NULL) {
				//в случае если нужное значение в конце списка
				HashList *nextEntry = entry->getNext();
				delete entry;
				table[hash] = nextEntry;

			}
			else {
				//в случае если нужное значение не в конце списка
				HashList *next = entry->getNext();
				delete entry;
				prevEntry->setNext(next);

			}

		}

	}

}

auto LinkedHashTable::getMax()->int {

	int max;
	int cur = 0;

	bool isReturn = true;
	for (int i = 0; i < tableSize; i++) {
		if (table[i] != NULL) {
			max = table[i]->getValue();
			isReturn = false;
		}
	}
	if (isReturn)  throw std::logic_error("no table!");



	for (int i = 0; i < tableSize; i++) {

		if (table[i] != NULL) {
			HashList *prevEntry = NULL;
			HashList *entry = table[i];

			while (entry != NULL) {
				prevEntry = entry;


				cur = prevEntry->getValue();
				if (cur > max) {
					max = cur;
				}
				entry = entry->getNext();

			}
		 

		}
	}
	return max;

}

auto LinkedHashTable::getMin()->int {

	int min;
	int cur = 0;

	bool isReturn = true;
	for (int i = 0; i < tableSize; i++) {
		if (table[i] != NULL) {
			min = table[i]->getValue();
			isReturn = false;
		}
	}
	if (isReturn)  std::logic_error("no table!");



	for (int i = 0; i < tableSize; i++) {
		if (table[i] != NULL) {
			min = table[i]->getValue();
		}
	}
	if (min == NULL) return NULL;
	for (int i = 0; i < tableSize; i++) {

		if (table[i] != NULL) {
			HashList *prevEntry = NULL;
			HashList *entry = table[i];

			while (entry != NULL) {
				prevEntry = entry;


				cur = prevEntry->getValue();
				if (cur < min) {
					min = cur;
				}
				entry = entry->getNext();

			}
		 
		}
	}
	return min;

}

auto LinkedHashTable::print()->void {

	
	
}

LinkedHashTable::~LinkedHashTable() {

	for (int i = 0; i < tableSize; i++)
		if (table[i] != NULL) {
			HashList *prevEntry = NULL;
			HashList *entry = table[i];
			while (entry != NULL) {
				prevEntry = entry;
				entry = entry->getNext();
				delete prevEntry;

			}

		}

	delete[] table;

}
