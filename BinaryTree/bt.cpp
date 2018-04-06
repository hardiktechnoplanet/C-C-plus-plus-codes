//#include "BinaryTree.h"
#include<bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
};
class BinaryTree
{
	public:
		//make a constructor such that the main program gives us the pointer 
		//to the root and we will hold down the whole tree under that root
		BinaryTree(struct TreeNode*);
		
		//to print the tree
		void print();
		
		//to search in the tree
		bool contains(int);
		
		//to print the tree sideways
		void printSideways();
		
	private:
		//only tree can call the private methods not any one else
		
		struct TreeNode *root;
		
		//for the recursion
		//client will call the print() function and print() will call the helper
		void printHelper(struct TreeNode* node);
		
		//search helper function
		bool containsHelper(struct TreeNode* node, int value);
		
		//print sideways helper function
		void printSidewayshelper(struct TreeNode* node, string indent="");
};

BinaryTree::BinaryTree(struct TreeNode* initialRoot)
{
	root=initialRoot; 
}

//use recursion to print the tree data
void BinaryTree:: print()
{
	printHelper(root);	
}

//recursive function
void BinaryTree:: printHelper(TreeNode* node)
{
	//in the recursive function we need to write a base case
	//base case which is: if null -> do nothing
	if(node!=NULL)
	{
		//pre-order traversal
		cout<<"data: "<<node->data<<endl;
		printHelper(node->left);
		printHelper(node->right);
		
		/*in-order traversal
		printHelper(node->left);
		cout<<"data: "<<node->data<<endl;
		printHelper(node->right);
		*/
		
		/*post-order traversal
		printHelper(node->left);
		printHelper(node->right);
		cout<<"data: "<<node->data<<endl;
		*/
	}
}

//to search in the binary tree
bool BinaryTree::contains(int value)
{
	return containsHelper(root, value);
}
//seach helper function
bool BinaryTree::containsHelper(struct TreeNode* node, int value)
{
	if(node==NULL) //if the next node is null->no other node is left
	{
		return false;
	}
	else if(node->data==value)
	{
		return true;
	}
	else
	{
		return containsHelper(node->left,value)||
			   containsHelper(node->right,value);
	}
}

//to print sideways
void BinaryTree::printSideways()
{
	printSidewayshelper(root,"");
}
//print sideways helper
void BinaryTree::printSidewayshelper(struct TreeNode* node, string indent)
{
	//print right subtree, then me, then left subtree
	//base case
	if(node!=NULL)
	{
		printSidewayshelper(node->right, indent+"    "); //right sub tree
		cout<<indent<<node->data<<endl; //me
		printSidewayshelper(node->left, indent+"    "); //left sub tree
	}
	
}
int main()
{
	struct TreeNode* node=new TreeNode();
	node->data=42;
	/*node->left=new TreeNode(59);
	node->right=new TreeNode(27);
	node->right->right=new TreeNode(86);
	*///node->left->data=59;
	
	node->left=new TreeNode();
	node->left->data=59;
	node->right=new TreeNode();
	node->right->data=26;
	
	node->left->left=new TreeNode();
	node->left->left->data=5;
	node->left->right=new TreeNode();
	node->left->right->data=2;
	
	node->right->left=new TreeNode();
	node->right->left->data=7;
	node->right->right=new TreeNode();
	node->right->right->data=10;

	//node->right->right=new TreeNode();
	//node->data=86;
	
	//now pass this tree to the BinaryTree class
	BinaryTree tree(node);
	
	//to print all the nodes
	cout<<"-----print-----"<<endl;
	tree.print();
	
	cout<<"-----contains-----"<<endl;
	
	cout<<"contains 1: "<<boolalpha<<tree.contains(1)<<endl; //boolalpha is a modifier to cout that
	                                                         //prints bool like words (true or false) 
	cout<<"contains 26: "<<boolalpha<<tree.contains(26)<<endl;
	cout<<"contains 7: "<<boolalpha<<tree.contains(7)<<endl;
	cout<<"contains 59: "<<boolalpha<<tree.contains(59)<<endl;
	
	//print sideways
	cout<<"----print sideways----"<<endl;
	tree.printSideways();
}
