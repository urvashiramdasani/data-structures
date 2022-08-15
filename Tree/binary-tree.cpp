#include <iostream>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};

// Time Complexity O(n), Space Complexity O(h)
void inorder(Node* root) {
    if(root) {
        inorder(root -> left);
        cout << root -> key << " ";
        inorder(root -> right);
    }
}

// Time Complexity O(n), Space Complexity O(h)
void preorder(Node* root) {
    if(root) {
        cout << root -> key << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

// Time Complexity O(n), Space Complexity O(h)
void postorder(Node* root) {
    if(root) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> key << " ";
    }
}

// Time Complexity O(n), Space Complexity O(h)
int height(Node* root) {
    if(!root)
        return 0;
    
    return 1 + max(height(root -> left), height(root -> right));
}

// Time Complexity O(n), Space Complexity O(h)
void nodesAtDistanceK(Node* root, int k, int x) {
    if(root) {
        if(x == k + 1) {
            cout << root -> key << " ";
            return;
        }

        nodesAtDistanceK(root -> left, k, x + 1);
        nodesAtDistanceK(root -> right, k, x + 1);
    }
}

// Time Complexity O(n), Space Complexity O(h)
void maxNodeBT(Node* root, int& maxNode) {
    if(root) {
        if(root -> key > maxNode)
            maxNode = root -> key;

        maxNodeBT(root -> left, maxNode);
        maxNodeBT(root -> right, maxNode);
    }
}

// Time Complexity theta(n), Space Complexity O(n) or theta(width)
void levelOrderTraversal(Node* root) {
    if(root) {
        queue<Node* > q;
        q.push(root);

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            cout << curr -> key << " ";

            if(curr -> left)
                q.push(curr -> left);

            if(curr -> right)
                q.push(curr -> right);
        }
    }
}

// Time Complexity O(n), Space Complexity O(h)
int size(Node* root) {
    if(!root)
        return 0;

    return size(root -> left) + size(root -> right) + 1;
}

// void inorderIterative(Node* root) {
//     if(root) {
//         stack<Node* > s;
//         Node* curr = root;

//         while(curr) {
//             s.push(curr);
//             curr = curr -> left;
//         }

//         while(!s.empty()) {
//             curr = s.top();
//             s.pop();
//             cout << curr -> key << " ";
            
//             if(curr -> left)
//                 s.push(curr -> left);
            
//             if(curr -> right)
//                 s.push(curr -> right);
//         }
//     }
// }

void insert(Node* root, int key) {
    if(root) {
        queue<Node* > q;
        q.push(root);
        Node* newNode = new Node(key);

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if(!curr -> left) {
                curr -> left = newNode;
                return;
            } else
                q.push(curr -> left);

            if(!curr -> right) {
                curr -> right = newNode;
                return;
            } else
                q.push(curr -> right);
        }
    }
}

int main() {
    Node* root = new Node(10);
    root -> left = new Node(20);
    root -> right = new Node(30);
    root -> right -> left = new Node(40);
    root -> right -> right = new Node(50);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << "\nHeight of Binary Tree : " << height(root);
    int k = 2;
    cout << "\nNodes at Distance k = " << k << " : ";
    nodesAtDistanceK(root, k, 1);
    cout << "\nLevel Order Traversal : ";
    levelOrderTraversal(root);
    cout << "\nSize of Binary Tree : " << size(root);
    int maxNode = INT_MIN;
    maxNodeBT(root, maxNode);
    cout << "\nMaximum in Binary Tree : " << maxNode;
    // cout << "\nIterative Inorder Traversal : ";
    // inorderIterative(root);
    int key = 60;
    insert(root, key);
    cout << "\nInorder Traversal after insertion : ";
    inorder(root);

    // Empty Tree
    // Node* root = NULL;
    return 0;
}