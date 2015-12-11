/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    /*
         Do a normal binary search to find target, remember the last point where
         we turned left, that's the potential successor;
         
         When we reach the target, if target->right != NULL, we know that inorder successor
         is the left most node of target->right's subtree.
         
         Otherwise we return the last node where we turned left
    */
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root)return NULL;
        TreeNode *lastTurnLeft=NULL;
        while(root){
            if(p->val<root->val){
                lastTurnLeft=root;
                root=root->left;
            }
            else if(p->val>root->val){
                root=root->right;
            }
            else{
                if(root->right){
                    root=root->right;
                    while(root->left){
                        root=root->left;
                    }
                    return root;
                }
                break;
            }
        }
        return lastTurnLeft;
    }
};
