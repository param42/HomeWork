 
#include "LinkedHashTable.h"


LinkedHashTable::LinkedHashTable(int _size) {
	capacity = _size;
	size = 0;
	table = new HashList*[capacity];
	for (int i = 0; i < capacity; i++)
		table[i] = NULL;
}
LinkedHashTable::LinkedHashTable() {
	capacity = 10;
	size = 0;
	table = new HashList*[capacity];
	for (int i = 0; i < capacity; i++)
		table[i] = NULL;
}

auto LinkedHashTable::getSize() -> int
{
	return size;
}

auto LinkedHashTable::search(int key)->std::pair<int, int> {

	int hash = HashFunc(key);
	if (table[hash] == NULL)
		throw std::logic_error("remove doesnt exist element");
	else {
		HashList *entry = table[hash];
		while (entry != NULL && entry->getKey() != key)
			entry = entry->getNext();
		if (entry == NULL)
			throw std::logic_error("remove doesnt exist element");
		else
			return std::make_pair(entry->getKey(), entry->getValue());
	}
}

auto LinkedHashTable::insert(int key, int value)->void {
	int hash = HashFunc(key);
	if (table[hash] == NULL) {
		table[hash] = new HashList(key, value);
		size++;
	}
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
			size++;
		}

	}

}

auto LinkedHashTable::remove(int key)->void {

	int hash = HashFunc(key);
	if (size == 0) {
		 throw std::logic_error("Table is empty");
	}
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
				size--;

			}
			else {
				//в случае если нужное значение не в конце списка
				HashList *next = entry->getNext();
				delete entry;
				prevEntry->setNext(next);
				size--;

			}

		}throw std::logic_error("remove doesnt exist element");

	}
	else {
		throw std::logic_error("remove doesnt exist element");
	}

}

auto LinkedHashTable::getMax()->std::pair<int, int> {

	int max;
	int cur = 0;
	int keyMax=0;
	bool isReturn = true;
	for (int i = 0; i < capacity; i++) {
		if (table[i] != NULL) {
			max = table[i]->getValue();
			keyMax = table[i]->getKey();
			isReturn = false;
		}
	}
	if (isReturn)  throw std::logic_error("no table!");

	

	for (int i = 0; i < capacity; i++) {

		if (table[i] != NULL) {
			HashList *prevEntry = NULL;
			HashList *entry = table[i];

			while (entry != NULL) {
				prevEntry = entry;


				cur = prevEntry->getValue();
				if (cur > max) {
					max = cur;
					keyMax = prevEntry->getKey();
					std::cout <<" ===== " <<prevEntry->getKey();
				}
				entry = entry->getNext();

			}
		 

		}
	}
	 
	return std::make_pair(keyMax, max);

}

auto LinkedHashTable::getMin()->std::pair<int, int> {

	int min;
	int keyMin;
	int cur = 0;

	bool isReturn = true;
	for (int i = 0; i < capacity; i++) {
		if (table[i] != NULL) {
			min = table[i]->getValue();
			keyMin = table[i]->getKey();
			isReturn = false;
		}
	}
	if (isReturn)  std::logic_error("no table!");



	for (int i = 0; i < capacity; i++) {
		if (table[i] != NULL) {
			min = table[i]->getValue();
		}
	}
	if (min == NULL)  std::logic_error("throw");
	for (int i = 0; i < capacity; i++) {

		if (table[i] != NULL) {
			HashList *prevEntry = NULL;
			HashList *entry = table[i];

			while (entry != NULL) {
				prevEntry = entry;


				cur = prevEntry->getValue();
				if (cur < min) {
					min = cur;
					keyMin = prevEntry->getKey();

				}
				entry = entry->getNext();

			}
		 
		}
	}
	return std::make_pair(keyMin, min);

}

auto LinkedHashTable::print()->void {

	
	
}

LinkedHashTable::~LinkedHashTable() {

	for (int i = 0; i < capacity; i++)
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
