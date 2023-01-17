#include <stdexcept>
#include <iostream>
using namespace std;

enum Side { NONE, LEFT, RIGHT };
class ChainLink
{
public:
    void append(ChainLink* rightPart)
    {
        if (this->right != NULL)
            throw std::logic_error("Link is already connected.");

        this->right = rightPart;
        rightPart->left = this;
    }
    Side longerSide()
    {
        cout << "longer\n";
        int left_counter = 0;
        int right_counter = 0;
        ChainLink* leftPart = this->left;
        ChainLink* rightPart = this->right;
        while (leftPart != NULL) {
            left_counter += 1;
            leftPart = leftPart->left;
        }
        while (rightPart != NULL) {
            right_counter += 1;
            rightPart = rightPart->right;
        }
        if (left_counter < right_counter) {
            return Side::RIGHT;
        }
        else if (left_counter > right_counter) {
            return Side::LEFT;
        }
        return Side::NONE;
    }
private:
    ChainLink* left;
    ChainLink* right;
};
#ifndef RunTests
int main()
{
    cout << "it is : " << Side::LEFT << endl; // ENUM
    ChainLink* left = new ChainLink();
    ChainLink* middle = new ChainLink();
    ChainLink* right = new ChainLink();
    left->append(middle);
    middle->append(right);
    std::cout << left->longerSide();
}
#endif