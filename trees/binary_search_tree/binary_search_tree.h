#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

class BinarySearchTree
{
public:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

private:
    Node *root;

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void tree_deconstructor(Node *node);
    BinarySearchTree::Node* removeNode(Node *node, int value);

    BinarySearchTree::Node* get_root() const;
    BinarySearchTree::Node* search(int value) const;

    BinarySearchTree::Node* findMin() const;
    BinarySearchTree::Node* findMax() const;

    BinarySearchTree::Node* findSuccessor() const;
    BinarySearchTree::Node* findPredecessor() const;

    int height() const;
    int depth(Node *node) const;

    void insert(int value);
    void remove(int value);

    void inorderTraversal(Node *node) const;
    void preorderTraversal(Node *node) const;
    void postorderTraversal(Node *node) const;

    void clear();
};

#endif