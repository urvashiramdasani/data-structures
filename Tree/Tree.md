# Tree
## Applications of Tree Data Structure
1. To represent hierarchial data
a. Organization structure
b. Folder structure
c. XML/HTML content (JSON objects)
d. In OOP (Inheritance)
2. Binary Search Trees
3. Binary Heap
4. B and B+ Trees in DBMS
5. Spanning and Shortest Path Trees in networks
6. Parse tree, Expression tree in compilers

## Variations of Tree
1. Trie
Used to represent dictionaries. Also supports prefix search
2. Suffix Tree
Used to do fast searches in a string. Suppose we have a large text and we want to search a pattern in it. We can pre-process the text and create a suffix tree of it. The complexity to search the pattern in the suffix tree is proportional to the length of the pattern. Fastest possible way to search a pattern in a big text.
3. Binary Index Tree
Used for range query searches. More faster than Segment Tree.
4. Segment Tree
Used for range query searches. More powerful than Binary Index Tree.

## Tree Traversals
1. Breadth First (Level order)
2. Depth First (Inorder, Postorder, Preorder)
There are 3! traversals but these are popular ones. In all these, we visit left subtree before right subtree.

## Properties of Binary Tree
1. The maximum number of nodes at level 'l' of a binary tree is (2^l - 1). Level of root is 1.
2. Maximum number of nodes in a binary tree of height 'h' is (2^h – 1) or 2^(h+1) – 1 when root is at height 0.
3. In a Binary Tree with N nodes, the minimum possible height or the minimum number of levels is Log2(N+1) or log2(N+1) - 1.
4. A Binary Tree with L leaves has at least (Log2L + 1) levels.
5. In a Binary tree in which every node has 0 or 2 children, the number of leaf nodes is always one more than the nodes with two children.

## Types of Binary Tree
1. **Full Binary Tree**: A Binary Tree is full if every node has either 0 or 2 children. All nodes except leaves have 2 children.
2. **Complete Binary Tree**: A Binary Tree is a complete Binary Tree if all levels are completely filled except possibly the last level and the last level has all keys as left as possible.
3. **Perfect Binary Tree**: A Binary tree is a Perfect Binary Tree when all internal nodes have two children and all the leave nodes are at the same level.