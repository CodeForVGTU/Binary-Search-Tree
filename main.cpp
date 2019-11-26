//#include<bits/stdc++.h>  
#include <iostream>
#include <fstream>
#define COUNT 10

using namespace std;

// A binary tree node  
struct Node
{
	int data;
	Node* left, * right;

	/* Constructor that allocates a new node with the
	given data and NULL left and right pointers. */
	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void print2DUtil(Node* root, int space)
{
	// Base case  
	if (root == NULL)
		return;

	// Increase distance between levels  
	space += COUNT;

	// Process right child first  
	print2DUtil(root->right, space);

	// Print current node after space  
	// count  
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->data << "\n";

	// Process left child  
	print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()  
void print2D(Node* root)
{
	// Pass initial space count as 0  
	print2DUtil(root, 0);
}  struct Node* newNode(int item)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}
struct Node* insert(struct Node* Node, int data)
{
	/* If the tree is empty, return a new node */
	if (Node == NULL) return newNode(data);

	/* Otherwise, recur down the tree */
	if (data < Node->data)
		Node->left = insert(Node->left, data);
	else if (data > Node->data)
		Node->right = insert(Node->right, data);

	/* return the (unchanged) node pointer */
	return Node;
}
// Driver code  

bool ifNodeExists(struct Node* Node, int key)
{
	if (Node == NULL)
		return false;

	if (Node->data == key)
		return true;

	/* then recur on left sutree */
	bool res1 = ifNodeExists(Node->left, key);

	/* now recur on right subtree */
	bool res2 = ifNodeExists(Node->right, key);

	return res1 || res2;
}

int maxDepth(Node* Node)
{
	if (Node == NULL)
		return 0;
	else
	{
		/* compute the depth of each subtree */
		int lDepth = maxDepth(Node->left);
		int rDepth = maxDepth(Node->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return(lDepth + 1);
		else return(rDepth + 1);
	}
}

// FOR DELETING ELEMENT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
struct Node* minValueNode(struct Node* node)
{
	struct Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}
struct Node* maxValueNode(struct Node* node)
{
	struct Node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->right != NULL)
		current = current->right;

	return current;
}

//-----------------------
struct Node* deleteNode(struct Node* root, int key,int first_node)
{
	cout << "STEP: " << first_node << endl;
	// base case 
	if (root == NULL) return root;

	// If the key to be deleted is smaller than the root's key, 
	// then it lies in left subtree 
	if (key < root->data)
		root->left = deleteNode(root->left, key,first_node);

	// If the key to be deleted is greater than the root's key, 
	// then it lies in right subtree 
	else if (key > root->data)
		root->right = deleteNode(root->right, key,first_node);

	// if key is same as root's key, then This is the node 
	// to be deleted 
	else
	{
		// node with only one child or no child 
		if (root->left == NULL)
		{
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		if (key > first_node)//if key is bigger use right subtree rules (delete key and swap with right smallest subtree value)
		{
			// node with two children: Get the inorder successor (smallest 
			// in the right subtree) 
			struct Node* temp = minValueNode(root->right);

			// Copy the inorder successor's content to this node 
			root->data = temp->data;

			// Delete the inorder successor 
			root->right = deleteNode(root->right, temp->data, first_node);
		}
		else if (key<first_node)//if key is smaller use left subtree rules(delete key and swap with left biggest subtree value)
		{
			struct Node* temp = maxValueNode(root->left);

			// Copy the inorder successor's content to this node 
			root->data = temp->data;

			// Delete the inorder successor 
			root->left = deleteNode(root->left, temp->data, first_node);

		}
	}
	return root;
}
// END OF DELETING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void Menu() {
	int choice = 0, size = 0, input_number;
	string txtname;
	struct Node* root = NULL;

	while (choice != 1)
	{
		system("cls");
		cout << "             MENU\n";
		cout << "#1. Create Binary Search Tree in Console.\n";
		cout << "#2. Create Binary Search Tree from .txt file.\n";

		cin >> choice;
		if (choice == 1)
		{
			cout << "Input a size of Binary Tree: ";
			cin >> size;
		}
		else if (choice == 2)
		{
			cout << "Input file name (with extension - .txt): ";
			cin >> txtname;
		}
		else
			cout << " Error! Wrong number! Try again.\n";
	}
	int* tree = new int[size];

	if (choice == 1)
	{
		for (int i = 0; i < size; i++)
			cin >> tree[i];
	}
	else if (choice == 2)
	{
		ifstream fd(txtname);
		if (fd.is_open())
		{
			fd >> size;

			for (int i = 0; i < size; i++)
				fd >> tree[i];
		}
		fd.close();
	} // Now we have our binary tree numbers stored in tree[] array

	for (int i = 0; i < size; i++)
	{
		if (i == 0) root = insert(root, tree[i]);
		else insert(root, tree[i]);
	}// Now we have our binary tree numbers stored in STRUCTURE

	while (true)
	{
		system("cls");

		cout << "             MENU\n";
		cout << "#1. Add new element to Binary Tree\n";
		cout << "#2. Delete element from Binary Tree\n";
		cout << "#3. Find element in Binary Tree\n";
		cout << "#4. What's height of Binary Tree?\n";
		cout << "#5. Show Binary Tree\n";
		cout << "#6. Exit\n";

		cin >> choice;

		if (choice == 1)
		{
			cout << "Add new element to Binary Tree\nEnter number:";
			cin >> input_number;
			insert(root, input_number);
		}
		else if (choice == 2)
		{
			cout << "Delete element from Binary Tree\nEnter number: ";

			cin >> input_number;
			int firstnode = root->data;//first tree element
			root = deleteNode(root, input_number,firstnode);
		}
		else if (choice == 3)
		{
			cout << "Find element in Binary Tree\nEnter number: ";

			cin >> input_number;
			if (ifNodeExists(root, input_number))
			{
				cout << "Number " << input_number << " was found!\n";
			}
			else { cout << " Number doesn't exist.. \n"; }
		}
		else if (choice == 4)
		{
			cout << "Show height of Binary Tree\n";
			cout << "Height of the tree: " << maxDepth(root) << endl;
		}
		else if (choice == 5)
		{
			cout << "Show Binary Tree\n";
			print2D(root);
		}
		else if (choice == 6)
		{
			exit(1); // breaking from while loop - exit
		}
		else {
			cout << "Wrong number!\n"; // cia reikia iterpti exita (Return 0???)
		}
		system("pause");
	}
}
int main()
{
	Menu();
}//test data insert: 1 13 15 10 26 8 14 29 6 20 16 12 4 24 7 5 
//deletes: 2 7 5 2 14 5 2 10 5 2 26 5
