#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED
#include <iostream>
#include <list>
#include "Node.h"

using namespace std;


class HashTable{
	private:
		int dim;
		list<Node> *T;
		int hashFunction(int x);
	public:
		HashTable(int N){dim=N;T = new list<Node>[dim];}
		void hashInsert(Node key, int x);
		void hashDelete(Node key, int x);
		bool hashSearch(int x);
		void printTable();
};

int HashTable::hashFunction(int x) {
   return x%dim;
}


void HashTable::hashInsert(Node key, int x){
    int index = hashFunction(x);
    T[index].push_back(key);
}


void HashTable::hashDelete(Node key, int x){
  int index = hashFunction(x);
  list<Node>::iterator lii;
  for (lii = T[index].begin(); lii != T[index].end(); lii++) {
        if ((*lii).getInfo() == key.getInfo())
        T[index].erase(lii);
        break;
    }
}


bool HashTable::hashSearch(int x){
    int index = hashFunction(x);
    for(auto v : T[index])
        if(v.getInfo() == x)
        return true;
    return false;
}


void HashTable::printTable() {
	for (int i = 0; i < dim; i++) {
		cout << i;
		for (auto x : T[i])
			cout << " --> " << x.getInfo();
		cout << endl;
	}
}

#endif // HASH_TABLE_H_INCLUDED
