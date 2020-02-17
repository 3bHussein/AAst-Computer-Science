#include<stdio.h>
#include<conio.h>
#include<queue>

// Structure for the BST Node
struct Node {
	int data ;
	Node *left;
	Node *right;
};

// Initialize the Tree
void initialize(Node *&root){
	root = NULL;
}

Node* CreateNewNode(int x){
	Node *temp = new Node();
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//1- Insert a new node in the BST
void insert(Node *&root, int x){
	if(root == NULL){
		root = CreateNewNode(x);
		return;
	}
	else if(x <= root->data){
		insert(root->left,x);
	}
	else {
		insert(root->right,x);
	}
}

//2- Count elements in the BST
int count(Node *&root){
	if(root == NULL){
		return 0;
	}
	else {
		return 1+count(root->left)+count(root->right);
	}
}

//3- Sum elements in the BST
int sum(Node *&root){
	if(root == NULL){
		return 0;
	}
	return root->data+sum(root->left)+sum(root->right);
}


//4- Get the smallest element in a BST.
int ssum(Node *&root,int level){
	if(level==0) {
		return root->data;
	}
	else {
		return ssum(root->left,level-1)+ssum(root->right,level-1);
	}
}
// 5-Copy a BST
Node* copy(Node*& root) {
	if (root == NULL) {
		return NULL;
	}

	Node* root2 = new Node();
	root2->data = root->data;
	root2->left = copy(root->left);
	root2->right = copy(root->right);
	return root2;
}


//6- Checks if 2 Trees are equal
int isEqual(Node*& root1, Node*& root2) {
	if (root1 == NULL && root2 == NULL) {
		return 1;
	}
	else if (root1 == NULL || root2 == NULL) {
		return 0;
	}
	else if (root1->data == root2->data
		&& isEqual(root1->left, root2->left)
		&& isEqual(root1->right, root2->right)) {
		return 1;
	}
}







// 8-Delete a node from the BST
Node* del(Node *root, int x) {
	if(root == NULL) {
		return root;
	}
	else if(x < root->data) {
		root->left = del(root->left,x);
	}
	else if (x > root->data){
		root->right = del(root->right,x);
	}
	// Target Found, Let's Delete it
	else {
		// Case 1: No child
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		// Case 2: One child
		else if(root->left == NULL) {
			Node *p = root;
			root = root->right;
			delete p;
		}
		else if(root->right == NULL) {
			Node *p = root;
			root = root->left;
			delete p;
		}
		// Case 3: 2 children

	return root;
}
}

//10- Get the Depth of Node
int depth(Node*& root) {
	if (root == NULL) {
		return -1;
	}
	int l = depth(root->left);
	int r = depth(root->right);
	if (l > r) {
		return l + 1;
	}
	else {
		return r + 1;
	}
}


int main(){
	Node *tree1 ;
	initialize(tree1);
	insert(tree1,15);
	insert(tree1,10);
	insert(tree1,20);
	insert(tree1,25);
	insert(tree1,8);
	insert(tree1,12);

	printf("+========== Displaying the Binary Tree ==========+\n");
	printf("\t\t15\n\t     /\t    \\\n\t10\t\t20\n     /\t    \\\t\t    \\\n8\t\t12\t\t25\n");

	printf("\n* Breadth-First/Level-Order: ");
	printf("\n* Depth-First/Preorder: ");
	printf("\n* Depth-First/Inorder: ");
	printf("\n* Depth-First/Postorder: ");


	printf("\n\n* Number of Nodes: ");
	printf("%d",count(tree1));
	printf("\n* Sum: ");
	printf("%d",sum(tree1));
	printf("\n* Avg: ");
	printf("\n* Number of Nodes: ");
	printf("\n* Height: ");
	printf("%d",depth(tree1));
	printf("\n* Depth of Node 20: ");

	printf("\n* Test Searching for 11: ");
		printf("Found");

	printf("\n\n+======= Test Deleting Node 10 =======+\n");
	printf("\t\t15\n\t     /\t    \\\n\t12\t\t20\n     /\t\t\t    \\\n8\t\t\t\t25\n");
	tree1 = del(tree1,10);
	printf("\n* Breadth-First/Level-Order: ");
	printf("\n* Depth-First/Preorder: ");
	printf("\n* Depth-First/Inorder: ");
	printf("\n* Depth-First/Postorder: ");

	printf("\n\n+======= Test Copying the above BST =======+\n");
	Node *tree2 = copy(tree1);
	printf("* Depth-First/Inorder: ");

	printf("\n\n+======= Check if the Copied equals the Original =======+\n");

	getch();
	return 0;
}
