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

//class
class TreeSet
{
	public:
		
		//constructor
		TreeSet();
		~TreeSet();
		
		//public member functions
		void add(int value);
		int getMin() const;
		bool isEmpty() const;
		void print() ;
		bool contains(int value) const;
		void printSideways() const;
		void remove(int value);

	private:
		
		//private member variables
		TreeNode* root; //pointer to top overall node of the tree
		
		//private member functions
		//these are helper functions
		
		//addHelper function takes 2 arguments, the currect node and value to be added
		//'&' will make the pointer to point to the no box present after the last node 
		void addHelper(struct TreeNode*& node, int value);
		
		/* if we dont want to use '&' then uncomment the function in the next line and comment
		the function in the above line
		void addHelper(struct TreeNode* node, int value);*/
		
		//get min helper function
		int getMinHelper(struct TreeNode* node) const;
		
		//for the recursion
		//client will call the print() function and print() will call the helper
		void printHelper(struct TreeNode* node);
		
		//search helper function
		bool containsHelper(struct TreeNode* node, int value) const;
		
		//print sideways helper function
		void printSidewayshelper(struct TreeNode* node, string indent="") const;
		
		//remove function helper
		void removeHelper(struct TreeNode*& node, int value);
};

//construct a new empty set
TreeSet::TreeSet()
{
	//when we are constructing the tree, root will be null
	root=NULL;
}

TreeSet::~TreeSet()
{
	//to do
}

//Methods

//to add value to the tree if it is not already present
void TreeSet::add(int value)
{
	//if we want to add a no greater than the no where are at presently, move to the right
	//else move to the left. When we reach the null, add the no there
	//So, we need a helper function that will tell us where we are at present
	addHelper(root,value);
}

void TreeSet::addHelper(struct TreeNode*& node, int value)
{
	//base cases
	if(node==NULL)
	{
		node=new TreeNode();
		node->data=value;
	}
	else if(value<node->data)
	{
		addHelper(node->left,value);
	}
	else if(value>node->data)
	{
		addHelper(node->right,value);
	}
	//if the value is same as the present node
	else
	{
		//duplicate node, do nothing
	}
}

/* if we dont want to use the '&' then uncomment the below add and the helper function
and comment the above add the helper function
void TreeSet::add(int value)
{
	//if we want to add a no greater than the no where are at presently, move to the right
	//else move to the left. When we reach the null, add the no there
	//So, we need a helper function that will tell us where we are at present
	if(root==NULL)
	{
		root=new TreeNode();
		root->data=value;
	}
	else
	addHelper(root,value);
}

void TreeSet::addHelper(struct TreeNode* node, int value)
{
	//base cases
	if(node==NULL)
	{
		node=new TreeNode();
		node->data=value;
	}
	else if(value<node->data)
	{
		if(node->left==NULL)
		{
			node=new TreeNode();
			node->data=value;
		}
		else{
			addHelper(node->left,value);
		}
	}
	else if(value>node->data)
	{
		if(node->right==NULL)
		{
			node=new TreeNode();
			node->data=value;
		}
		else{
			addHelper(node->right,value);
		}
	}
	//if the value is same as the present node
	else
	{
		//duplicate node, do nothing
	}
}
*/

//get min method
int TreeSet::getMin() const
{
	if(root==NULL)
	{
		throw ":-(";
	}
	else
	return getMinHelper(root);
}

int TreeSet::getMinHelper(struct TreeNode* node) const
{
	if(node->left==NULL)
	{
		return node->data;
	}
	else
	{
		getMinHelper(node->left);
	}
	
}

// delete or remove method
void TreeSet::remove(int value)
{
	removeHelper(root,value);
}
//the remove helper function will modify the tree, so, we will pass the
//argument by reference so that the change is reflected in the original tree
void TreeSet::removeHelper(struct TreeNode*& node, int value)
{
	//base case
	if(node==NULL)
	{
		//if the node is not in the tree, do nothing
	}
	//if the value is <node that means we have to go left
	else if(value<node->data)
	{
		removeHelper(node->left,value);
	}
	else if(value>node->data)
	{
		removeHelper(node->right,value);
	}
	else
	{
		//the value to be deleted is the current node value
		//I am the node to remove
		
		// to prevent the memory leak
		struct TreeNode* trash=NULL;
		
		//Case I: if the node is a leaf node
		if(node->left==NULL && node->right==NULL)
		{
			trash=node;
			node=NULL;
		}
		//Case II: if left child only
		else if(node->right==NULL)
		{
			trash=node;
			//change me with my left
			node=node->left;
		}
		//Case III: if right child only
		else if(node->left==NULL)
		{
			trash=node;
			//change me with my right
			node=node->right;
		}
		//Case IV- left and right subtree
		else
		{
			//get the min from the right subtree of max from the left subtree to replace
			//the deleted value
			int newData=getMinHelper(node->right);
			node->data=newData;
			//now we have 2 newData values in the tree and we need to remove one of them
			removeHelper(node->right,newData); //this function call will results in any of the
			                                   //above three cases
		}
		if(trash!=NULL)
		{
			delete trash;
		}
	}

}

//use recursion to print the tree data
void TreeSet:: print()
{
	printHelper(root);	
}

//recursive function
void TreeSet:: printHelper(TreeNode* node)
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
//
////to search in the binary tree
//bool BinaryTree::contains(int value)
//{
//	return containsHelper(root, value);
//}
////seach helper function
//bool BinaryTree::containsHelper(struct TreeNode* node, int value)
//{
//	if(node==NULL) //if the next node is null->no other node is left
//	{
//		return false;
//	}
//	else if(node->data==value)
//	{
//		return true;
//	}
//	else
//	{
//		return containsHelper(node->left,value)||
//			   containsHelper(node->right,value);
//	}
//}
//
//to print sideways
void TreeSet::printSideways() const
{
	printSidewayshelper(root,"");
}
//print sideways helper
void TreeSet::printSidewayshelper(struct TreeNode* node, string indent) const
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

//client program
int main()
{
	TreeSet tree; //object
	
	tree.add(55);
	tree.add(29);
	tree.add(87);
	tree.add(-3);
	tree.add(42);
	tree.add(60);
	tree.add(91);
	
	
	//--------Call various functions on the tree-----------
	
	//print function
	cout<<"---print---"<<endl;
	tree.print();
	cout<<endl;
	cout<<"---printing sideways---"<<endl;
	tree.printSideways();
	cout<<endl;

	
	//getMin function
	cout<<"---min value in the tree---"<<endl;
	cout<<tree.getMin()<<endl;
	
	//remove function
	cout<<"---removing elements from the BST---"<<endl;
	tree.remove(91);
	tree.remove(29);
	tree.remove(55);
	tree.print();
	cout<<endl;
	cout<<"---printing sideways---"<<endl;
	tree.printSideways();
	cout<<endl;
	
	return 0;
	
}
