#include<iostream>
#include <unordered_set>
using namespace std;

int main(){
	unordered_set<int>hash_table;
	hash_table.insert(0);
	hash_table.insert(0);
	hash_table.insert(1);
	cout << "hash: " << hash_table.size() << endl;
	return 0;
}