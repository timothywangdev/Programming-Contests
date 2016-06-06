
#include<stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Insertion:
First do a normal BST insertion. Then perform reblance operations on all ancestors of newly inserted node.

Delection:
First do a normal BST deletion. Then perform rebalance operations on all ancestors of deleted node.
*/

// An AVL tree node
struct node
{
	int key;
	struct node *left;
	struct node *right;
	int _height;
};

class AVL{
	struct node *root;


	/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
	struct node* newNode(int key)
	{
		struct node* node = (struct node*)
			malloc(sizeof(struct node));
		node->key = key;
		node->left = NULL;
		node->right = NULL;
		node->_height = 1;  // new node is initially added at leaf
		return(node);
	}

	// A utility function to get _height of the tree
	int _height(struct node *node)
	{
		if (node == NULL)
			return 0;
		return node->_height;
	}

	// A utility function to right rotate subtree rooted with y
	// See the diagram given above.
	struct node *rightRotate(struct node *y)
	{
		struct node *x = y->left;
		struct node *T2 = x->right;

		// Perform rotation
		x->right = y;
		y->left = T2;

		// Update _heights
		y->_height = max(_height(y->left), _height(y->right)) + 1;
		x->_height = max(_height(x->left), _height(x->right)) + 1;

		// Return new root
		return x;
	}

	// A utility function to left rotate subtree rooted with x
	// See the diagram given above.
	struct node *leftRotate(struct node *x)
	{
		struct node *y = x->right;
		struct node *T2 = y->left;

		// Perform rotation
		y->left = x;
		x->right = T2;

		//  Update _heights
		x->_height = max(_height(x->left), _height(x->right)) + 1;
		y->_height = max(_height(y->left), _height(y->right)) + 1;

		// Return new root
		return y;
	}

	// Get Balance factor of node N
	int getBalance(struct node *N)
	{
		if (N == NULL)
			return 0;
		return _height(N->left) - _height(N->right);
	}

	/* Given a non-empty binary search tree, return the node with minimum
	key value found in that tree. Note that the entire tree does not
	need to be searched. */
	struct node * minValueNode(struct node* node)
	{
		struct node* current = node;

		/* loop down to find the leftmost leaf */
		while (current->left != NULL)
			current = current->left;

		return current;
	}

	struct node* rebalance(struct node *root){
		// If the tree had only one node then return
		if (root == NULL)
			return root;

		// STEP 2: UPDATE _height OF THE CURRENT NODE
		root->_height = max(_height(root->left), _height(root->right)) + 1;

		// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
		//  this node became unbalanced)
		int balance = getBalance(root);

		// If this node becomes unbalanced, then there are 4 cases

		// Left Left Case
		if (balance > 1 && getBalance(root->left) >= 0)
			return rightRotate(root);

		// Left Right Case
		if (balance > 1 && getBalance(root->left) < 0)
		{
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		// Right Right Case
		if (balance < -1 && getBalance(root->right) <= 0)
			return leftRotate(root);

		// Right Left Case
		if (balance < -1 && getBalance(root->right) > 0)
		{
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	struct node* _insertNode(struct node* node, int key)
	{
		/* 1.  Perform the normal BST insertion */
		if (node == NULL)
			return(newNode(key));

		if (key < node->key)
			node->left = _insertNode(node->left, key);
		else
			node->right = _insertNode(node->right, key);

		/* 2. Update _height of this ancestor node */
		node->_height = max(_height(node->left), _height(node->right)) + 1;

		return rebalance(node);
	}

	struct node* _deleteNode(struct node* node, int key)
	{
		// STEP 1: PERFORM STANDARD BST DELETE

		if (node == NULL)
			return node;

		// If the key to be deleted is smaller than the node's key,
		// then it lies in left subtree
		if (key < node->key)
			node->left = _deleteNode(node->left, key);

		// If the key to be deleted is greater than the node's key,
		// then it lies in right subtree
		else if (key > node->key)
			node->right = _deleteNode(node->right, key);

		// if key is same as node's key, then This is the node
		// to be deleted
		else
		{
			// node with only one child or no child
			if ((node->left == NULL) || (node->right == NULL))
			{
				struct node *temp = node->left ? node->left : node->right;

				// No child case
				if (temp == NULL)
				{
					temp = node;
					node = NULL;
				}
				else // One child case
					*node = *temp; // Copy the contents of the non-empty child

				free(temp);
			}
			else
			{
				// node with two children: Get the inorder successor (smallest
				// in the right subtree)
				struct node* temp = minValueNode(node->right);

				// Copy the inorder successor's data to this node
				node->key = temp->key;

				// Delete the inorder successor
				node->right = _deleteNode(node->right, temp->key);
			}
		}

		return rebalance(node);
	}

	// A utility function to print preorder traversal of the tree.
	// The function also prints _height of every node
	void _preOrder(struct node *root)
	{
		if (root != NULL)
		{
			cout << root->key << " " << endl;
			_preOrder(root->left);
			_preOrder(root->right);
		}
	}

	void _deleteTree(struct node *node){
		if (node == NULL)return;
		_deleteTree(node->left);
		_deleteTree(node->right);
		free(node);
		
	}

public:
	AVL(){ root = NULL; }
	~AVL(){
		cout << "deleting AVL tree..." << endl;
		_deleteTree(root);
	}
	int height(){
		return _height(root);
	}
	void deleteNode(int key){
		root=_deleteNode(root,key);
	}
	void insertNode(int key){
		root=_insertNode(root, key);
	}
	void preOrder(){
		_preOrder(root);
	}
};


/* Drier program to test above function*/
int main()
{
	AVL *avltree=new AVL();

	/* Constructing tree given in the above figure */
	avltree->insertNode(9);
	avltree->insertNode(5);
	avltree->insertNode(10);
	avltree->insertNode(0);
	avltree->insertNode(6);
	avltree->insertNode(11);
	avltree->insertNode(-1);
	avltree->insertNode(1);
	avltree->insertNode(2);

	 /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */
 

	printf("Pre order traversal of the constructed AVL tree is \n");
	avltree->preOrder();

	avltree->deleteNode(10);

/* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
 

	printf("\nPre order traversal after deletion of 10 \n");
	avltree->preOrder();
	delete avltree;
	return 0;
}

