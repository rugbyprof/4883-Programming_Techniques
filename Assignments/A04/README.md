## Assignment 4 - Binary Trees 
#### Due: 09-16-2020 (Wednesday @ 1:00 p.m.)


### Overview

- Find 2 problems that deal with Binary Search Trees in some way that are part of the onlinejudge set of problems.
- Find multiple ways of implementing a Binary Search Trees in whichever language you are using. You should understand the implications of each method.

### Deliverables

1. Create a folder called `A04`
2. Create a README.md in your folder.
3. Add pdfs of your uva problems.
4. Add links and cut and paste code snippets to each of your implementations with a few sentences describing each.

### Example Num 4

- This is a typical BST implementation without using a class
- Its simple but still uses dynamic memory allocation won't run into problems that array based implementations have. 
- It doesn't deal with deleting nodes, but that could be added.

```cpp
struct node {
   int val;
   node* left;
   node* right;
};

node* createNewNode(int x)
{
    node* nn = new node;
    nn->val = x;
    nn->left  = nullptr;
    nn->right = nullptr;

    return nn;
}

void bstInsert(node* &root, int x)
{
    if(root == nullptr) {
        root = createNewNode(x);
        return;
    }

    if(x < root->val)
    {
        if(root->left == nullptr) {
            root->left = createNewNode(x);
            return;
        } else {
            bstInsert(root->left, x);
        }
    }

    if( x > root->val )
    {
        if(root->right == nullptr) {
            root->right = createNewNode(x);
            return;
        } else {
            bstInsert(root->right, x);
        }
    }
}

int main()
{
     node* root = nullptr;

     int x;
     while(cin >> x) {
         bstInsert(root, x);
     }

     return 0;
}
```
- Source: https://stackoverflow.com/questions/5085091/binary-search-tree-implementation-in-c-stl

