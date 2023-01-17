#include <iostream>
#include <vector>
using namespace std;
#include <unordered_set>

int getMinimumConnections(const std::vector<std::vector<bool> > & matrix)
{
    //throw std::logic_error("Waiting to be implemented");
    unordered_set<int> hash_table;
    int needed = 0;
    for (int index_i = 0; index_i < matrix.size(); index_i++){
    	for (int index_j = 0; index_j < matrix[0].size(); index_j++){
    		if (matrix[index_i][index_j] == true){
    			if (not (hash_table.count(index_i+1) or hash_table.count(index_j+1))){
    				needed++;
    			}
    			hash_table.insert(index_i+1);
    			hash_table.insert(index_j+1);
    			
    		}
    	}	
	}
	return needed - 1 + (5 - hash_table.size());
}

int main()
{
    vector< vector<bool> > matrix
    {
        {false, true, false, false, true}, // 1,2,5
        {true, false, false, false, false},
        {false, false, false, true, false}, // 3,4
        {false, false, true, false, false},
        {true, false, false, false, false}
    };
    std::cout << getMinimumConnections(matrix) << std::endl; // should print 1
}