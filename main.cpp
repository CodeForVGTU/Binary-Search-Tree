#include<bits/stdc++.h>  
#define COUNT 10

using namespace std;

// A binary tree node  
class Node  
{  
    public: 
    int data;  
    Node* left, *right;  
      
    /* Constructor that allocates a new node with the  
    given data and NULL left and right pointers. */
    Node(int data){ 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    } 
};  
  
// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void print2DUtil(Node *root, int space)  
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
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
  
// Wrapper over print2DUtil()  
void print2D(Node *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}  struct Node *newNode(int item) 
{ 
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node)); 
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
        Node->left  = insert(Node->left,data); 
    else if (data > Node->data) 
        Node->right = insert(Node->right, data);    
  
    /* return the (unchanged) node pointer */
    return Node; 
} 
// Driver code  

void Menu() {
  int choice = 0, size = 0;

	while (true) {
		system("cls");
		cout << "             MENU\n";
		cout << "#1. Create Binary Search Tree\n";
		cout << "#2. Add new element to Binary Tree\n";
		cout << "#3. Delete element from Binary Tree\n";
		cout << "#4. Find element in Binary Tree\n";
		cout << "#5. What's height of Binary Tree?\n";
		cout << "#6. Show Binary Tree\n";
		cout << "#7. Exit\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			{
				string txtname;
				system("cls");
				cout << "             MENU\n";
				cout << "#1. Create Binary Search in Console\n";
				cout << "#2. Create Binary Search Tree from .txt file\n";
				cout << "#3. Back to Main MENU\n";
				cin >> choice;

				switch (choice)
				{
				case 1:
					cout << "Input a size of Binary Tree: ";
					cin >> size;
					break;
				case 2:
				{
					cout << "Input file name (with extension - .txt): ";
					cin >> txtname;
					break;
				}
				case 3:
					break;
				default:
					cout << "Wrong number!";
					break;
				}
				if (choice != 3) {
					int* tree = new int[size];

					if (choice == 1)
					{
						for (int i = 0; i < size; i++)
							cin >> tree[i];
					}
					else if (choice == 2)
					{
						ifstream fd(txtname);

						if (fd.is_open()) {
							fd >> size;

							for (int i = 0; i < size; i++) {
								fd >> tree[i];
							}
						}

						fd.close();
					}

					cout << "Your Binary Search tree array:\n";
					for (int i = 0; i < size; i++) {
						cout << tree[i] << " ";
					}
					cout << endl;

          struct Node *root = NULL;

          for (int i = 0; i < size; i++)
            {
            if(i ==0) root= insert(root, tree[i]); 
            else 
            insert(root, tree[i]); 
            }
            
            print2D(root);  

					system("pause");
				}

			}
		case 2:
			cout << "Add new element to Binary Tree";
			break;
		case 3:
			cout << "Delete element from Binary Tree";
			break;
		case 4:
			cout << "Find element in Binary Tree";
			break;
		case 5:
			cout << "What's height of Binary Tree?";
			break;
		case 6:
			cout << "Show Binary Tree";
			break;
		case 7:
			cout << "Exit"; // cia reikia iterpti exita (Return 0???)
			break;
		default:
			cout << "Wrong number!";
			break;
		}
	}
}
int main()
{
  Menu();
}
