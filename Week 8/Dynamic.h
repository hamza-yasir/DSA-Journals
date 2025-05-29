#include<iostream>
using namespace std;
class DynTree {
public:
	struct Treenode {
		int info;
		struct Treenode* left;
		struct Treenode* right;
		struct Treenode* parent;
	};
	typedef Treenode* NODEPTR;
	NODEPTR root;


	DynTree() {
		root = nullptr;
	}
	NODEPTR getRoot() {
		return root;
	}
	bool isEmpty() const {
		return root == nullptr;
	}
	NODEPTR makeTree(int x) {
		NODEPTR temp = new Treenode;
		temp->info = x;
		temp->right = nullptr;
		temp->left = nullptr;
		temp->parent = nullptr;
		return temp;
		
	}
	bool isLeft(NODEPTR p) { 
		if (isEmpty() || p == nullptr) return false;
		return (p->parent->left == p);
	}
	bool isRight(NODEPTR p) { 
		if (isEmpty() || p == nullptr) return false;
		return (p->parent->right == p);
	}
	void setRoot(int x) {
		if (!isEmpty()) {
			cout << "Root already exists. " << endl;
			return;
		}
		else {
			root = makeTree(x);
		}
	}
	void setLeft(NODEPTR p, int x) {
		if (p == nullptr) {
			cout << "parent does not exist." << endl;
			return;
		}
		if (p->left != nullptr) {
			cout << "Left child already exists." << endl;
			return;
		}
		NODEPTR child = makeTree(x);
		child->parent = p;
		p->left = child;
	}

	void setRight(NODEPTR p, int x) {
		if (p == nullptr) {
			cout << "parent does not exist." << endl;
			return;
		}
		if (p->right != nullptr) {
			cout << "Right child already exists." << endl;
			return;
		}
		NODEPTR child = makeTree(x);
		child->parent = p;
		p->right = child;
	}

	void pretrav(NODEPTR p) { 
		if (p != nullptr) {
			cout << p->info << " ";
			pretrav(p->left);
			pretrav(p->right);
		}
	}
	void posttrav(NODEPTR p) { 
		if (p != nullptr) {
			posttrav(p->left);
			posttrav(p->right);
			cout << p->info << " ";
		}
	}
	void intrav(NODEPTR p) { 
		if (p != nullptr) {
			intrav(p->left);
			cout << p->info << " ";
			intrav(p->right);
		}
	}
};

	
