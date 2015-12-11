/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 [1,2,3]
 
       1
      / \
     2   3
     
[1,null,2,3,null]

       1
        \
         2
        /
       3
       
       
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "[]";
        vector<TreeNode *> curLevel;
        vector<TreeNode *> nextLevel;
        curLevel.push_back(root);
        string rv="["+to_string(root->val);
        while(curLevel.size()){
            string tmp;
            for(int i=0;i<curLevel.size();i++){
                if(!curLevel[i]->left){
                    tmp=tmp+",null";
                }
                else{
                    tmp=tmp+","+to_string(curLevel[i]->left->val);
                    nextLevel.push_back(curLevel[i]->left);
                }
                if(!curLevel[i]->right){
                    tmp=tmp+",null";
                }
                else{
                    tmp=tmp+","+to_string(curLevel[i]->right->val);
                    nextLevel.push_back(curLevel[i]->right);
                }
            }
            if(nextLevel.size())rv=rv+tmp;
            curLevel=nextLevel;
            nextLevel.clear();
        }
        cout<<rv<<endl;
        return rv+"]";
    }
    
    int get(int pos, string &data, string &num){
       num="";
       while(data[pos]!=','&&data[pos]!=']'){
           num=num+data[pos];
           pos++;
       }
       if(data[pos]==','){
           pos++;
       }
       return pos;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="[]")return NULL;
        int pos=1;
        string num;
        pos=get(pos,data,num);
        TreeNode *root=new TreeNode(atoi(num.c_str()));
        vector<TreeNode *> curLevel;
        vector<TreeNode *> nextLevel;
        curLevel.push_back(root);
        while(pos<data.size()-1){
            for(int i=0;i<curLevel.size();i++){
                // left
                pos=get(pos,data,num);
                if(num!="null"){
                    curLevel[i]->left=new TreeNode(atoi(num.c_str()));
                    nextLevel.push_back(curLevel[i]->left);
                }
                // right
                pos=get(pos,data,num);
                if(num!="null"){
                    curLevel[i]->right=new TreeNode(atoi(num.c_str()));
                    nextLevel.push_back(curLevel[i]->right);
                }
            }
            curLevel=nextLevel;
            nextLevel.clear();
        }
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
