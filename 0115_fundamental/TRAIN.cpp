#include <stdexcept>
#include <iostream>
#include <vector>
using namespace std;

class TrainComposition
{
public:
    void attachWagonFromLeft(int wagonId)
    {
        wagon.insert(wagon.begin(), wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        wagon.insert(wagon.end(), wagonId);
    }

    int detachWagonFromLeft()
    {
        int left = wagon.front();
        wagon.erase(wagon.begin());
        return left;
    }

    int detachWagonFromRight()
    {
        int right = wagon.back();
        wagon.erase(wagon.end()-1);
        return right;
    }
    vector<int> wagon;
};

#ifndef RunTests
int main()
{
    TrainComposition train;
    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    std::cout << train.detachWagonFromRight() << "\n"; // 7 
    std::cout << train.detachWagonFromLeft(); // 13
}
#endif