#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#include <unordered_map>

std::pair<int, int> findTwoSum(const std::vector<int>& list, int sum)
{
    unordered_map<int, int> hash_table;
    for (int i = 0; i < list.size(); i++) {
    	auto itr = hash_table.find(sum-list[i]);
    	if (itr != hash_table.end()) {
    		return make_pair(i, itr->second);
    	}
    	hash_table[list[i]] = i;
    }
    return make_pair(-1, -1);
}

#ifndef RunTests
int main()
{
    std::vector<int> list = {3, 1, 5, 7, 5, 9};
    std::pair<int, int> indices = findTwoSum(list, 10);
    std::cout << indices.first << '\n' << indices.second;
}
#endif