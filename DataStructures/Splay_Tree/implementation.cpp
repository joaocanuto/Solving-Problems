#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class Splay_Tree {
private:
    Node* root;
    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balance_factor(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node* right_rotate(Node* node) {
        Node* aux = node->left;
        node->left = aux->right;
        aux->right = node;
        node->height = max(height(node->left), height(node->right)) + 1;
        aux->height = max(height(aux->left), height(aux->right)) + 1;
        return aux;
    }

    Node* left_rotate(Node* node) {
        Node* aux = node->right;
        node->right = aux->left;
        aux->left = node;
        node->height = max(height(node->left), height(node->right)) + 1;
        aux->height = max(height(aux->left), height(aux->right)) + 1;
        return aux;
    }

    Node* insert(Node* node, int data) {
        if (node == nullptr) return new Node(data);
        if (data < node->data) node->left = insert(node->left, data);
        else if (data > node->data) node->right = insert(node->right, data);
        else return node;
        node->height = max(height(node->left), height(node->right)) + 1;
        int bf = balance_factor(node);
        if (bf > 1 && data < node->left->data) return right_rotate(node);
        if (bf < -1 && data > node->right->data) return left_rotate(node);
        if (bf > 1 && data > node->left->data) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
        if (bf < -1 && data < node->right->data) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }
        return node;
    }

    Node* search(Node* node, int data) {
        if (node == nullptr) return nullptr;
        if (data < node->data) return search(node->left, data);
        else if (data > node->data) return search(node->right, data);
        else return node;
    }

    Node* remove(Node* node, int data) {
        if (node == nullptr) return nullptr;
        if (data < node->data) node->left = remove(node->left, data);
        else if (data > node->data) node->right = remove(node->right, data);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* aux = (node->left) ? node->left : node->right;
                if (aux == nullptr) {
                    aux = node;
                    node = nullptr;
                } else *node = *aux;
                delete aux;
            } else {
                Node* aux = node->right;
                while (aux->left != nullptr) aux = aux->left;
                node->data = aux->data;
                node->right = remove(node->right, aux->data);
            }
        }
        if (node == nullptr) return node;
        node->height = max(height(node->left), height(node->right)) + 1;
        int bf = balance_factor(node);
        if (bf > 1 && balance_factor(node->left) >= 0) return right_rotate(node);
        if (bf < -1 && balance_factor(node->right) <= 0) return left_rotate(node);
        if (bf > 1 && balance_factor(node->left) < 0) {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
        if (bf < -1 && balance_factor(node->right) > 0) {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }
        return node;
    }

    void pre_order(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        pre_order(node->left);
        pre_order(node->right);
    }

    void in_order(Node* node) {
        if (node == nullptr) return;
        in_order(node->left);
        cout << node->data << " ";
        in_order(node->right);
    }

    void post_order(Node* node) {
        if (node == nullptr) return;
        post_order(node->left);
        post_order(node->right);
        cout << node->data << " ";
    }

    void show(Node* node) {
        cout << "Pre-Order: ";
        pre_order(node);
        cout << endl;
        cout << "In-Order: ";
        in_order(node);
        cout << endl;
        cout << "Post-Order: ";
        post_order(node);
        cout << endl;
    }

public:
    Splay_Tree() {
        this->root = nullptr;
    }

    void SPLAYInicializa() {
        this->root = nullptr;
    }

    void SPLAY(int data) {
        this->root = search(this->root, data);
    }

    void SPLAYInserirBusca(int data) {
        this->root = insert(this->root, data);
    }

    void SPLAYRemove(int data) {
        this->root = remove(this->root, data);
    }

    void SPLAYMostra() {
        show(this->root);
    }

    void SPLAYFinaliza() {
        this->root = nullptr;
    }
};

int main() {
    Splay_Tree splay;
    splay.SPLAYInicializa();

    splay.SPLAYInserirBusca(10);
    splay.SPLAYInserirBusca(20);
    splay.SPLAYInserirBusca(30);
    splay.SPLAYInserirBusca(40);
    splay.SPLAYInserirBusca(50);
    splay.SPLAYInserirBusca(25);
    splay.SPLAYInserirBusca(35);
    splay.SPLAYInserirBusca(45);
    splay.SPLAYInserirBusca(55);
    splay.SPLAYInserirBusca(60);
    splay.SPLAYInserirBusca(70);
    splay.SPLAYInserirBusca(80);
    splay.SPLAYInserirBusca(90);
    splay.SPLAYInserirBusca(100);
    splay.SPLAYMostra();

    splay.SPLAYFinaliza();

    return 0;
}
