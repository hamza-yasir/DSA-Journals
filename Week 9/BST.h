#include<fstream>
#include<iostream>
using namespace std;

template<class T>
struct TreeNode {
	T info;               // Data member
	TreeNode<T>* left;    // Pointer to left child
	TreeNode<T>* right;   // Pointer to right child
};

template<class T>

// BINARY SEARCH TREE SPECIFICATION
class TreeType {
private:
	TreeNode<T>* root;
public:
	TreeType();
	~TreeType();

	bool IsEmpty() const;
	

	TreeNode<T>* GetRoot() const {
		return root;
	}

	int NumberOfNodes() const;

	void InsertItem(T item);
	void DeleteItem(T item);

	void RetrieveItem(T& item, bool& found);
	void PrintTree(ofstream& outfile);

	void PrintHelper(TreeNode<T>* ptr, ofstream& outfile);
	void InsertHelper(TreeNode<T>*& ptr, T item);
	void RetrieveHelper(TreeNode<T>* ptr, T& item, bool& found);
	int CountNodes(TreeNode<T>* ptr);


	void DestroyHelper(TreeNode<T>* ptr);
};

template<class T>
TreeType<T>::TreeType() {
	root = NULL;
}

template<class T>
bool TreeType<T>::IsEmpty() const {
	return(root == NULL);
}


template<class T>
void TreeType<T>::RetrieveItem(T& item, bool& found) {
	RetrieveHelper(root, item, found);
}

template<class T>
void TreeType<T>::RetrieveHelper(TreeNode<T>* ptr, T& item, bool& found) {
	if (ptr == NULL)
		found = false;
	else if (item < ptr->info)
		RetrieveHelper(ptr->left, item, found);
	else if (item > ptr->info)
		RetrieveHelper(ptr->right, item, found);
	else {
		item = ptr->info;
		found = true;
	}
}

template<class T>
void TreeType<T>::InsertItem(T item) {
	InsertHelper(root, item);
}

template<class T>
void TreeType<T>::InsertHelper(TreeNode<T>*& ptr, T item) {
	if (ptr == NULL) {
		ptr = new TreeNode<T>;
		ptr->right = NULL;
		ptr->left = NULL;
		ptr->info = item;
	}
	else if (item < ptr->info)            // GO LEFT
		InsertHelper(ptr->left, item);
	else if (item > ptr->info)            // GO RIGHT
		InsertHelper(ptr->right, item);
}

template<class T>
void TreeType<T>::PrintTree(ofstream& outfile) {
	PrintHelper(root, outfile);
}

template<class T>
void TreeType<T>::PrintHelper(TreeNode<T>* ptr, ofstream& outfile) {
	if (ptr != NULL) {
		PrintHelper(ptr->left, outfile);    // Print Left subtree
		outfile << ptr->info;
		PrintHelper(ptr->right, outfile);   // Print right subtree
	}
}

template<class T>
TreeType<T>::~TreeType() {                  // Destructor
	DestroyHelper(root);
}

template<class T>
void TreeType<T>::DestroyHelper(TreeNode<T>* ptr)
// All nodes of the tree pointed to by ptr are deallocated.
{
	if (ptr != NULL) {
		DestroyHelper(ptr->left);
		DestroyHelper(ptr->right);
		delete ptr;
	}
}

template<class T>
int TreeType<T>::NumberOfNodes() const {
	return CountNodes(root);
}

template<class T>
int TreeType<T>::CountNodes(TreeNode<T>* ptr) {
	if (ptr == NULL)
		return 0;
	else
		return 1 + CountNodes(ptr->left) + CountNodes(ptr->right);
}

template<class T>
void TreeType<T>::DeleteItem(T item) {
	DeleteHelper(root, item);
}

void SortStrings(string arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;

		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		// Swap
		string temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

template<class T>
void StoreInOrder(TreeNode<T>* ptr, T sortedArr[], int& index) {
	if (ptr != nullptr) {
		StoreInOrder(ptr->left, sortedArr, index);
		sortedArr[index++] = ptr->info;
		StoreInOrder(ptr->right, sortedArr, index);
	}
}

void SortWithTreeType(string arr[], int size) {
	TreeType<string> tree;

	// Insert all elements into the tree
	for (int i = 0; i < size; ++i) {
		tree.InsertItem(arr[i]);
	}

	// In-order traversal to collect sorted elements
	int index = 0;
	StoreInOrder(tree.GetRoot(), arr, index); // arr gets overwritten in sorted order
}