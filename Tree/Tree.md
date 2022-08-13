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