#include<stdio.h>
#include<conio.h>
#include<queue>
// Binary Search Tree Implementation by Mhmoudko

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

// Insert a new node in the BST
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

// Display using Breadth-First/Level-Order Traversal
void display(Node *&root){
	if(root == NULL){
		printf("Empty BST");
		return;
	}
	std::queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *current = q.front();
		printf("%d ",current->data);
		if(current->left!=NULL){
			q.push(current->left);
		}
		if(current->right!=NULL){
			q.push(current->right);
		}
		q.pop();
	}
}

// Display using Depth-First (Preorder)
void displayDLR(Node *&root){
	if(root == NULL){
		return;
	}
	printf("%d ",root->data);
	displayDLR(root->left);
	displayDLR(root->right);
}

// Display using Depth-First (Inorder)
void displayLDR(Node *&root){
	if(root == NULL){
		return;
	}
	displayLDR(root->left);
	printf("%d ",root->data);
	displayLDR(root->right);
}

// Display using Depth-First (Postorder)
void displayLRD(Node *&root){
	if(root == NULL){
		return;
	}
	displayLRD(root->left);
	displayLRD(root->right);
	printf("%d ",root->data);
}

// Count elements in the BST
int count(Node *&root){
	if(root == NULL){
		return 0;
	}
	else {
		return 1+count(root->left)+count(root->right);
	}
}

// Count elements in the BST > x
int count(Node *&root, float x){
	if(root == NULL){
		return 0;
	}
	else if(root->data > x) {
		return 1+count(root->left,x)+count(root->right,x);
	}
	else {
		return 0+count(root->left,x)+count(root->right,x);
	}
}

// Count elements between x and y
int count(Node *&root, float x , float y){
	if(root == NULL){
		return 0;
	}
	else if(root->data >= x && root->data <= y) {
		return 1+count(root->left,x,y)+count(root->right,x,y);
	}
	else {
		return 0+count(root->left,x,y)+count(root->right,x,y);
	}
}

// Sum elements in the BST
int sum(Node *&root){
	if(root == NULL){
		return 0;
	}
	return root->data+sum(root->left)+sum(root->right);
}

// Avg elements in the BST
float avg(Node *&root){
	if(root == NULL){
		return 0;
	}
	return sum(root)/count(root);
}

// Search for a node in the BST , returns a pointer to it
Node* search(Node *&root, int x){
	if(root == NULL){
		return NULL;
	}
	else if(x == root->data){
		return root;
	}
	else if(x < root->data){
		return search(root->left,x);
	}
	else if(x > root->data){
		return search(root->right,x);
	}
}

// Returns the min element in the BST
int min(Node *&root){
	if(root == NULL){
		return -1;
	}
	else if(root->left == NULL){
		return root->data;
	}
	else {
		return min(root->left);
	}
}

// Returns the max element in the BST
int max(Node *&root){
	if(root == NULL){
		return -1;
	}
	else if(root->right == NULL){
		return root->data;
	}
	else {
		return max(root->right);
	}
}

// Get the Depth of Node
int depth(Node *&root){
	if(root == NULL){
		return -1;
	}
	int l = depth(root->left);
	int r = depth(root->right);
	if(l > r){
		return l+1;
	}
	else {
		return r+1;
	}
}

int ssum(Node *&root,int level){
	if(level==0) {
		return root->data;
	}
	else {
		return ssum(root->left,level-1)+ssum(root->right,level-1);
	}
}

// Checks if Sub Tree is lesser than x
int isSubTreeLesser(Node *&root, int x){
	if(root == NULL){
		return 1;
	}
	else if(root->data <= x
	&& isSubTreeLesser(root->left,x)
	&& isSubTreeLesser(root->right,x)){
		return 1;
	}
	else {
		return 0;
	}
}

// Checks if Sub Tree is greater than x
int isSubTreeGreater(Node *&root, int x){
	if(root == NULL){
		return 1;
	}
	else if(root->data > x
	&& isSubTreeGreater(root->left,x)
	&& isSubTreeGreater(root->right,x)){
		return 1;
	}
	else {
		return 0;
	}
}

// Check if Binary Tree is a BST
int isBST(Node *&root){
	if(root == NULL){
		return 1;
	}
	if(isSubTreeLesser(root->left,root->data)
	&& isSubTreeGreater(root->right,root->data)
	&& isBST(root->left)
	&& isBST(root->right)){
		return 1;
	}
	else {
		return 0;
	}
}

// Returns a Pointer to the min node in the BST
Node* ptrToMin(Node* root)
{
	if(root == NULL){
		return NULL;
	}
	else if(root->left == NULL){
		return root;
	}
	else {
		return ptrToMin(root->left);
	}
}
 
// Delete a node from the BST
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
		else { 
			Node *p = ptrToMin(root->right);
			root->data = p->data;
			root->right = del(root->right,p->data);
		}
	}
	return root;
}

// Copy a BST
Node* copy(Node *&root){
	if(root == NULL){
		return NULL;
	}
	
	Node *root2 = new Node();
	root2->data = root->data;
	root2->left = copy(root->left);
	root2->right = copy(root->right);
	return root2;
}

// Checks if 2 Trees are equal
int isEqual(Node *&root1,Node *&root2){
	if(root1 == NULL && root2 == NULL){
		return 1;
	}
	else if(root1 == NULL || root2 == NULL){
		return 0;
	}
	else if(root1->data == root2->data
	&& isEqual(root1->left,root2->left)
	&& isEqual(root1->right,root2->right)){
		return 1;
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
	display(tree1);
	printf("\n* Depth-First/Preorder: ");
	displayDLR(tree1);
	printf("\n* Depth-First/Inorder: ");
	displayLDR(tree1);
	printf("\n* Depth-First/Postorder: ");
	displayLRD(tree1);
	
	int flag = isBST(tree1);
	if(flag){
		printf("\n* It's a Binary Search Tree");
	}
	else {
		printf("\n* It's Not a Binary Search Tree");
	}
	
	printf("\n\n* Number of Nodes: ");
	printf("%d",count(tree1));
	printf("\n* Sum: ");
	printf("%d",sum(tree1));
	printf("\n* Avg: ");
	float a = avg(tree1);
	printf("%.2f",a);
	printf("\n* Number of Nodes: ");
	printf("%d",count(tree1,a));
	printf("\n* Min: ");
	printf("%d",min(tree1));
	printf("\n* Max: ");
	printf("%d",max(tree1));
	printf("\n* Height: ");
	printf("%d",depth(tree1));
	printf("\n* Depth of Node 20: ");
	Node *temp = search(tree1,20);
	printf("%d",depth(temp));
	
	printf("\n\n* Test Searching for 12: ");
	if(search(tree1,12)!=NULL){
		printf("Found");
	}
	else {
		printf("Not Found");
	}
	printf("\n* Test Searching for 11: ");
	if(search(tree1,11)!=NULL){
		printf("Found");
	}
	else {
		printf("Not Found");
	}
	
	printf("\n\n+======= Test Deleting Node 10 =======+\n");
	printf("\t\t15\n\t     /\t    \\\n\t12\t\t20\n     /\t\t\t    \\\n8\t\t\t\t25\n");
	tree1 = del(tree1,10);
	printf("\n* Breadth-First/Level-Order: ");
	display(tree1);
	printf("\n* Depth-First/Preorder: ");
	displayDLR(tree1);
	printf("\n* Depth-First/Inorder: ");
	displayLDR(tree1);
	printf("\n* Depth-First/Postorder: ");
	displayLRD(tree1);
	
	printf("\n\n+======= Test Copying the above BST =======+\n");
	Node *tree2 = copy(tree1);
	printf("* Depth-First/Inorder: ");
	displayLDR(tree2);
	
	printf("\n\n+======= Check if the Copied equals the Original =======+\n");
	flag = isEqual(tree1,tree2);
	if(flag){
		printf("The 2 Trees are equal");
	}
	else {
		printf("The 2 Trees are Not equal");
	}
	
	getch();
	return 0;
}
