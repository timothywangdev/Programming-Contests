#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mt make_tuple
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(i,a,b) for(int i=(b);i>=(a);i--)
#define F(i,n) for(int i=0;i<(n);i++)
#define FR(i,n) for(int i=(n)-1;i>=0;i--)
#define R(a,i,b) (a<=i&&i<=b)
typedef tuple<int,int,int> TIII;
typedef tuple<int,int> TII;
typedef pair<int,int> PII;
typedef long long LL;

class BST{
  class Node{
  public:
    Node *left, *right;
    int key;
    Node(int key):key(key),left(NULL),right(NULL){}
  };
  Node *root;
  void setPar(Node *par, bool left, Node *new_node){
    if(!par){
      root = new_node;
      return;
    }
    if(left)par->left = new_node;
    else par -> right = new_node;
  }
  
  void _remove(Node *cur, Node *par, int key){
    bool left = false;
    while(cur){
      if(key<cur->key){
	par = cur;
	cur = cur->left;
	left =true;
      }
      else if(key>cur->key){
	par = cur;
	cur = cur->right;
	left =false;
      }
      else{
	if(cur->left&&cur->right){
	  // inorder succesor
	  Node *tmp = cur->right;
	  while(tmp->left){
	    tmp = tmp->left;
	  }
	  swap(cur->key, tmp->key);
	  key = tmp->key;
	  par = cur;
	  cur = cur->right;
	  left = false;
	}
	else{
	  /*
	    Deleting a node with no children: simply remove the node from the tree.
	    Deleting a node with one child: remove the node and replace it with its child.
	  */
	  Node *target = cur->left?cur->left:(cur->right?cur->right:NULL);
	  setPar(par,left,target);
	  delete cur;
	  return;
	}
      }
    }
  }
  void _inorder(Node *cur){
    if(!cur)return;
    _inorder(cur->left);
    cout<<cur->key<<" ";
    _inorder(cur->right);
  }
public:
  BST():root(NULL){}
  void insert(int key){
    if(!root){
      root=new Node(key);
      return;
    }
    Node *cur = root, *par;
    bool left = false;
    while(cur){
      if(key<cur->key){
	par = cur;
	cur = cur->left;
	left =true;
      }
      else if(key>cur->key){
	par = cur;
	cur = cur->right;
	left =false;
      }
      else{
	cout<<"duplicated key!"<<endl;
	return;
      }
    }
    setPar(par,left,new Node(key));
  }

  bool search(int key){
    Node *cur = root;
    while(cur){
      if(cur->key==key)return true;
      if(key<cur->key)cur = cur->left;
      cur = cur->right;
    }
    return false;
  }
  
  void remove(int key){
    _remove(root, NULL, key);
  }

  void inorder(){
    _inorder(root);
    cout<<endl;
  }

};
