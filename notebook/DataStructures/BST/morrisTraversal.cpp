/*
 Proof:http://blog.m-s-t.org/2015/06/22/morris-traversal/
 Inorder Traversal in O(n) with space O(1)
 */
void MorrisTraversal(TreeNode *root){
  while(root){
    cout<<root->val<<endl;
    if(root->left){
      TreeNode *pred=root->left;
      while(pred->right&&pred->right!=root)pred=pred->right;
            
      if(pred->right==root){
	pred->right=NULL;
	// Do something with root
	print(root->val);
	root=root->right;
      }
      else{
	pred->right=root;
	root=root->left;
      }
    }
    else{
      // Do something with root
      print(root->val);
      root=root->right;
    }
  }
}
