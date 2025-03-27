#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

class BinarySearchTree
{
public:
    struct Node
    {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

private:
    Node* root;

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void tree_deconstructor(Node* node);
    Node* removeNode(Node* node, int value);

    Node* get_root() const;
    Node* search(int value) const;

    Node* findMin() const;
    Node* findMax() const;

    Node* findSuccessor() const;
    Node* findPredecessor() const;

    int height() const;
    int depth(Node* node) const;

    void insert(int value);
    void remove(int value);

    void inorderTraversal(Node* node) const;
    void preorderTraversal(Node* node) const;
    void postorderTraversal(Node* node) const;
};

#endif
