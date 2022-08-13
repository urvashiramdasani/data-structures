#include <iostream>
#include <queue>

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

    // Empty Tree
    // Node* root = NULL;
    return 0;
}