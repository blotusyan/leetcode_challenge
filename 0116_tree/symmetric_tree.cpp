#include  <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int isSymmetric(TreeNode* root){
            return check(root, root);
        }
        bool check(TreeNode* tree1, TreeNoed* tree2){
            if (!tree1 && !tree2){
                return true;
            }
            else if (!tree1 || !tree2){
                return false;
            }
            return tree1->val == tree2->val && check(tree1->left, tree2->right) && check(tree1->right, tree2->left);
        }
};