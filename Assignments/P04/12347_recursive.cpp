// preorder to postorder recursive solution
//https://www.techiedelight.com/find-postorder-traversal-binary-tree-from-inorder-preorder-sequence/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Recursive function to find postorder traversal of binary tree
// from its inorder and preorder sequence
void printPostorder(int start, int end,
				   vector<int> const &preorder, int &preIndex,
				   unordered_map<int,int> &map)
{
	// base case
	if (start > end)
		return;

	// The next element in preorder sequence will be the root node of
	// subtree formed by inorder[start, end]
	int value = preorder[preIndex++];

	// if current node is leaf node (no children)
	if (start == end)
	{
		// print the value of root node and return
		cout << value << ' ';
		return;
	}

	// get the index of root node in inorder sequence to determine the
	// boundary of its left and right subtree
	int i = map[value];

	// recur for left subtree
	printPostorder(start, i - 1, preorder, preIndex, map);

	// recur for right subtree
	printPostorder(i + 1, end, preorder, preIndex, map);

	// print the value of root node
	cout << value << ' ';
}

// Find postorder traversal of a binary tree from its inorder and
// preorder sequence. This function assumes that the input is valid
// i.e. given inorder and preorder sequence forms a binary tree
void findPostorder(vector<int> const &inorder, vector<int> const &preorder)
{
	// create a map to efficiently find the index of any element in
	// given inorder sequence
	unordered_map<int,int> map;

	// fill the map
	for (int i = 0; i < inorder.size(); i++)
		map[inorder[i]] = i;

	// preIndex stores index of next unprocessed node in preorder sequence
	// start with root node (present at 0'th index)
	int preIndex = 0;

	cout << "Postorder Traversal is: ";
	printPostorder(0, inorder.size() - 1, preorder, preIndex, map);
}

int main()
{
	/* Consider below tree
		  1
		/   \
	   /	 \
	  2	   3
	 /	   / \
	/	   /   \
   4	   5	 6
		  / \
		 /   \
		7	 8
	*/

	vector<int> inorder  = { 4, 2, 1, 7, 5, 8, 3, 6 };
	vector<int> preorder = { 1, 2, 4, 3, 5, 7, 8, 6 };

	findPostorder(inorder, preorder);

	return 0;
}