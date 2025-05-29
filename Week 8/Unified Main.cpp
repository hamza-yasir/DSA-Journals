#include "Header.h"
#include "Dynamic.h"

int main() {
	/*DynTree dynT;
	dynT.setRoot(10);
	DynTree::NODEPTR root = dynT.getRoot();
	dynT.setLeft(root, 5);
	dynT.setRight(root, 15);
	dynT.setLeft(root->left, 2);
	dynT.setRight(root->left, 7);

	cout << "Traversals using Dynamic\n\n";
	cout << "Preorder: ";
	dynT.pretrav(root);
	cout << "\n\nInorder: ";
	dynT.intrav(root);
	cout << "\n\nPostorder: ";
	dynT.posttrav(root);*/

	BinaryTree tree;

	tree.setRoot(10);
	tree.setLeft(1, 5);
	tree.setRight(1, 15);
	tree.setLeft(2, 3);
	tree.setRight(2, 7);

	cout << "\nTree Structure:\n";
	tree.printTree();

	cout << "\nInorder Traversal: ";
	tree.inorder(tree.getRoot());

	cout << "\nPreorder Traversal: ";
	tree.preorder(tree.getRoot());

	cout << "\nPostorder Traversal: ";
	tree.postorder(tree.getRoot());

	int k;
	cout << "\n\nEnter value to search: ";
	cin >> k;
	cout << "\n value " << k <<": ";
	int index = tree.search(k);
	if (index != -1)
		cout << "at index " << index << "\n";
	else
		cout << "Not found\n";

	return 0;
}
