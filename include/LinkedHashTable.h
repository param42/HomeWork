#pragma once
#include <iostream>

class LinkedHashTable
{
	class HashList {

	private:

		int key;
		int value;
		HashList *next;

	public:


		HashList(int key, int value) {
			this->key = key;
			this->value = value;
			this->next = NULL;
		}

		int getKey() {
			return key;
		}

		int getValue() {
			return value;
		}

		void setValue(int value) {
			this->value = value;
		}

		HashList *getNext() {
			return next;
		}

		void setNext(HashList *next) {
			this->next = next;
		}

	};
private:
	HashList **table;
	int tableSize;

	int HashFunc(int key) {
		return key % tableSize;
	}


public:
		LinkedHashTable();
		LinkedHashTable(int size);

		auto get(int key)->int;
		auto put(int key, int value)->void;
		auto remove(int key)->void;
		auto getMax()->int;
		auto getMin()->int;
		auto print()->void;

		~LinkedHashTable();
};

