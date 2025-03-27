#include "../include/ds/BinarySearchTree.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree()
{
    tree_deconstructor(root);
}

void BinarySearchTree::tree_deconstructor(Node *root)
{
    if (!root)
    {
        return;
    }

    tree_deconstructor(root->left);
    tree_deconstructor(root->right);
    delete root;
}

BinarySearchTree::Node *BinarySearchTree::get_root() const
{
    return root;
}

void BinarySearchTree::inorderTraversal(Node *node) const
{
    if (!node)
    {
        return;
    }

    inorderTraversal(node->left);
    cout << node->data << endl;
    inorderTraversal(node->right);
}

void BinarySearchTree::preorderTraversal(Node *node) const
{
    if (!node)
    {
        return;
    }

    cout << node->data << endl;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void BinarySearchTree::postorderTraversal(Node *node) const
{
    if (!node)
    {
        return;
    }

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << endl;
}

BinarySearchTree::Node* BinarySearchTree::search(int value) const
{
    Node* current = root;

    while (current)
    {
        if (value == current->data)
            return current;
        else if (value < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return nullptr;
}

BinarySearchTree::Node* BinarySearchTree::findMin() const
{
    Node* current = root;
    if (!current) return nullptr;

    while (current->left)
        current = current->left;

    return current;
}

BinarySearchTree::Node* BinarySearchTree::findMax() const
{
    Node* current = root;
    if (!current) return nullptr;

    while (current->right)
        current = current->right;

    return current;
}

BinarySearchTree::Node* BinarySearchTree::findSuccessor() const
{
    if (!root || !root->right) return nullptr;

    Node* current = root->right;
    while (current->left)
        current = current->left;

    return current;
}

BinarySearchTree::Node* BinarySearchTree::findPredecessor() const
{
    if (!root || !root->left) return nullptr;

    Node* current = root->left;
    while (current->right)
        current = current->right;

    return current;
}

int getHeight(BinarySearchTree::Node* node)
{
    if (!node) return -1;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

int BinarySearchTree::height() const
{
    return getHeight(root);
}

int BinarySearchTree::depth(Node* node) const
{
    Node* current = root;
    int depth = 0;

    while (current)
    {
        if (node->data == current->data)
            return depth;
        else if (node->data < current->data)
            current = current->left;
        else
            current = current->right;

        depth++;
    }

    return -1;
}


void BinarySearchTree::insert(int value)
{
    Node *newNode = new Node(value);

    if (!root)
    {
        root = newNode;
        return;
    }

    Node *current = root;
    while (true)
    {
        if (value < current->data)
        {
            if (current->left)
            {
                current = current->left;
            }
            else
            {
                current->left = newNode;
                return;
            }
        }
        else if (value > current->data)
        {
            if (current->right)
            {
                current = current->right;
            }
            else
            {
                current->right = newNode;
                return;
            }
        }
        else // duplicate value
        {
            delete newNode;
            return;
        }
    }
}

BinarySearchTree::Node* BinarySearchTree::removeNode(Node* node, int value)
{
    if (!node)
        return nullptr;

    if (value < node->data)
    {
        node->left = removeNode(node->left, value);
    }
    else if (value > node->data)
    {
        node->right = removeNode(node->right, value);
    }
    else
    {
        // Case 1: No children
        if (!node->left && !node->right)
        {
            delete node;
            return nullptr;
        }
        // Case 2: One child
        else if (!node->left)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Case 3: Two children
        else
        {
            // Find in-order successor (smallest in right subtree)
            Node* successor = node->right;
            while (successor->left)
                successor = successor->left;

            // Copy successor's data to current node
            node->data = successor->data;

            // Delete successor
            node->right = removeNode(node->right, successor->data);
        }
    }

    return node;
}

void BinarySearchTree::remove(int value)
{
    root = removeNode(root, value);
}