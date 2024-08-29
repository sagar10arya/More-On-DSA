#include <bits/stdc++.h>
using namespace std;
/*
Given a binary search tree which is also a complete binary tree. The problem is to convert the given BST into a Min Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied to all the nodes, in the resultant converted Min Heap.

1. Min Property -> N < L and N < R
2. L < R
3. Combining 1 and 2 --> N < L < R --> preOrder(NLR)
*/