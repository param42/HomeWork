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
	int capacity;
	int size;
	int HashFunc(int key) {
		return key % capacity;
	}


public:
		LinkedHashTable();
		LinkedHashTable(int size);

		auto getSize()->int;
		auto search(int key)->std::pair<int, int>;
		auto insert(int key, int value)->void;
		auto remove(int key)->void;
		auto getMax()->std::pair<int, int>;
		auto getMin()->std::pair<int, int>;
		auto print()->void;

		~LinkedHashTable();
};

