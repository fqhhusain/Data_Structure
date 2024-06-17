#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Define struktur Node BST
struct BSTNode {
    int key;
    struct BSTNode *left, *right;

    // Constructor
    BSTNode(int item) {
        key = item;
        left = right = nullptr;
    }
};

// Define struktur Queue
struct Queue {
    struct Node {
        BSTNode* data;
        Node* next;
    };

    Node* front;
    Node* rear;

    Queue() : front(nullptr), rear(nullptr) {}

    void push(BSTNode* item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    BSTNode* pop() {
        if (front == nullptr)
            return nullptr;

        Node* temp = front;
        BSTNode* item = temp->data;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
        return item;
    }

    bool empty() {
        return front == nullptr;
    }
};

// Fungsi untuk membuat Node BST baru
BSTNode* newNode(int key) {
    return new BSTNode(key);
}

// Fungsi untuk Inorder Traversal
void __inorder(BSTNode* root) {
    // Lengkapi disini
    if (root != nullptr) {
        __inorder(root->left);
        cout << root->key << " ";
        __inorder(root->right);
    }
}

// Fungsi untuk membuat pohon biner dengan urutan level-wise
BSTNode* buildBST(Queue& input) {
    if (input.empty())
        return nullptr;

    BSTNode* root = newNode(input.pop()->key);

    Queue q;
    q.push(root);

    while (!input.empty()) {
        BSTNode* curr = q.pop();

        int leftKey = input.pop()->key;
        if (leftKey != -1) {
            curr->left = newNode(leftKey);
            q.push(curr->left);
        }

        if (!input.empty()) {
            int rightKey = input.pop()->key;
            if (rightKey != -1) {
                curr->right = newNode(rightKey);
                q.push(curr->right);
            }
        }
    }

    return root;
}

// Fungsi untuk melakukan traverse kepada pohon biner
void traverseInorder(BSTNode* root) {
    
    __inorder(root);
    cout << endl;
}

int main() {

    int n;
    Queue q;
    while (cin >> n) {
        q.push(newNode(n));
    }
    BSTNode* root = buildBST(q);
    traverseInorder(root);
}
