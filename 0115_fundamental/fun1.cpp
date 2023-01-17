#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node* getLeft() const
    {
        return left;
    }

    Node* getRight() const
    {
        return right;
    }

private:
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree
{
public:
    static bool contains(const Node& root, int value)
    {   
        if (root.getValue() == NULL){
            cout << "null\n";
            return false;
        }
        if (root.getValue() == value){
            cout << "got\n";
            return true;
        }
        if (root.getValue() < value){
            cout << "right\n";
            if (root.getRight()){return contains(*root.getRight(), value);}
            else {return false;}
            
        }
        else {
            cout << "left\n";
            if (root.getLeft()){return contains(*root.getLeft(), value);}
            else {return false;}
        }
        return false;
    }
};

int main()
{
    Node n1(1, NULL, NULL);
    Node n3(3, NULL, NULL);
    Node n2(2, &n1, &n3);
    std::cout << BinarySearchTree::contains(n2, 0) << std::endl;
    return 0;
}