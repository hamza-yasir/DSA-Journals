#pragma once

#include <iostream>
using namespace std;

#define NUMNODES 100

class BinaryTree {
	struct TreeNode {
		int info;
		int left, right, parent;
	};

	TreeNode BT[NUMNODES];
	int nodeCount;

public:
	BinaryTree() {
		for (int i = 0; i < NUMNODES; i++) {
			BT[i].info = -1;
			BT[i].left = -1;
			BT[i].right = -1;
			BT[i].parent = -1;
		}
		nodeCount = 0;
	}

	void setRoot(int value) {
		int rootIndex = 1;
		BT[rootIndex].info = value;
		nodeCount = rootIndex + 1;
	}

	void setLeft(int parentIndex, int value) {
		int leftIndex = 2 * parentIndex;

		if (leftIndex >= NUMNODES) {
			cout << "Error: Left index out of bounds.\n";
			return;
		}

		if (BT[leftIndex].info != -1) {
			cout << "Left child already exists.\n";
			return;
		}

		BT[leftIndex].info = value;
		BT[leftIndex].parent = parentIndex;
		BT[parentIndex].left = leftIndex;

		if (leftIndex >= nodeCount) nodeCount = leftIndex + 1;
	}

	void setRight(int parentIndex, int value) {
		int rightIndex = 2 * parentIndex + 1;

		if (rightIndex >= NUMNODES) {
			cout << "Error: Right index out of bounds.\n";
			return;
		}

		if (BT[rightIndex].info != -1) {
			cout << "Right child already exists at index " << rightIndex << ".\n";
			return;
		}

		BT[rightIndex].info = value;
		BT[rightIndex].parent = parentIndex;
		BT[parentIndex].right = rightIndex;

		if (rightIndex >= nodeCount) nodeCount = rightIndex + 1;
	}

	void printTree() {
		for (int i = 1; i < nodeCount; ++i) {
			if (BT[i].info != -1) {
				cout << "Node[" << i << "]: ";
				cout << "Info = " << BT[i].info
					<< ", Left = " << BT[i].left
					<< ", Right = " << BT[i].right
					<< ", Parent = " << BT[i].parent << "\n";
			}
		}
	}

	int getRoot() {
		return 1;
	}

	int search(int value) {
		for (int i = 1; i < nodeCount; i++) {
			if (BT[i].info == value)
				return i;
		}
		return -1;
	}

	void inorder(int index) {
		if (index <= 0 || index >= NUMNODES) return;
		if (BT[index].info == -1) return;

		int left = BT[index].left;
		int right = BT[index].right;

		if (left > 0 ) inorder(left);
		cout << BT[index].info << " ";
		if (right > 0 ) inorder(right);
	}

	void preorder(int index) {
		if (index <= 0 || index >= NUMNODES) return;
		if (BT[index].info == -1) return;

		cout << BT[index].info << " ";
		int left = BT[index].left;
		int right = BT[index].right;

		if (left > 0 ) preorder(left);
		if (right > 0 ) preorder(right);
	}

	void postorder(int index) {
		if (index <= 0 || index >= NUMNODES) return;
		if (BT[index].info == -1) return;

		int left = BT[index].left;
		int right = BT[index].right;

		if (left > 0 ) postorder(left);
		if (right > 0 ) postorder(right);
		cout << BT[index].info << " ";
	}
};
