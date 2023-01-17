#include  <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int isSameTree(TreeNode* p, TreeNode* q){
            if (!q && !p){
                return true;
            }
            else if (!q || !p){
                return false;
            }
            else if (q->val != p->val){
                return false;
            }
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        }
};