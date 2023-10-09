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
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

class AVL_Tree {
    private: 
        Node* root;
        int height(Node* no) {
            if(no == NULL) return 0;
            return no->height;
        }

        int balance_factor(Node* no) {
            if(no == NULL) return 0;
            return height(no->left) - height(no->right);
        }

        Node* right_rotate(Node* no) {
            Node* aux = no->left;
            no->left = aux->right;
            aux->right = no;
            no->height = ::max(height(no->left), height(no->right)) + 1;
            aux->height = ::max(height(aux->left), height(aux->right)) + 1;
            return aux;
        }

        Node* left_rotate(Node* no) {
            Node* aux = no->right;
            no->right = aux->left;
            aux->left = no;
            no->height = ::max(height(no->left), height(no->right)) + 1;
            aux->height = ::max(height(aux->left), height(aux->right)) + 1;
            return aux;
        }

        Node* insert(Node* no, int data) {
            if(no == NULL) return new Node(data);
            if(data < no->data) no->left = insert(no->left, data);
            else if(data > no->data) no->right = insert(no->right, data);
            else return no;
            no->height = ::max(height(no->left), height(no->right)) + 1;
            int bf = balance_factor(no);
            if(bf > 1 && data < no->left->data) return right_rotate(no);
            if(bf < -1 && data > no->right->data) return left_rotate(no);
            if(bf > 1 && data > no->left->data) {
                no->left = left_rotate(no->left);
                return right_rotate(no);
            }
            if(bf < -1 && data < no->right->data) {
                no->right = right_rotate(no->right);
                return left_rotate(no);
            }
            return no;
        }

        Node* remove(Node* no, int data) {
            if(no == NULL) return no;
            if(data < no->data) no->left = remove(no->left, data);
            else if(data > no->data) no->right = remove(no->right, data);
            else {
                if(no->left == NULL || no->right == NULL) {
                    Node* aux = no->left ? no->left : no->right;
                    if(aux == NULL) {
                        aux = no;
                        no = NULL;
                    } else {
                        *no = *aux;
                    }
                    free(aux);
                } else {
                    Node* aux = min(no->right);
                    no->data = aux->data;
                    no->right = remove(no->right, aux->data);
                }
            }
            if(no == NULL) return no;
            no->height = ::max(height(no->left), height(no->right)) + 1;
            int bf = balance_factor(no);
            if(bf > 1 && balance_factor(no->left) >= 0) return right_rotate(no);
            if(bf > 1 && balance_factor(no->left) < 0) {
                no->left = left_rotate(no->left);
                return right_rotate(no);
            }
            if(bf < -1 && balance_factor(no->right) <= 0) return left_rotate(no);
            if(bf < -1 && balance_factor(no->right) > 0) {
                no->right = right_rotate(no->right);
                return left_rotate(no);
            }
            return no;
        }

        Node* min(Node* no) {
            Node* aux = no;
            while(aux->left != NULL) aux = aux->left;
            return aux;
        }

        Node* max(Node* no) {
            Node* aux = no;
            while(aux->right != NULL) aux = aux->right;
            return aux;
        }

        Node* search(Node* no, int data) {
            if(no == NULL || no->data == data) return no;
            if(data < no->data) return search(no->left, data);
            return search(no->right, data);
        }

        void pre_order(Node* no) {
            if(no != NULL) {
                cout << no->data << " ";
                pre_order(no->left);
                pre_order(no->right);
            }
        }

        void in_order(Node* no) {
            if(no != NULL) {
                in_order(no->left);
                cout << no->data << " ";
                in_order(no->right);
            }
        }

        void post_order(Node* no) {
            if(no != NULL) {
                post_order(no->left);
                post_order(no->right);
                cout << no->data << " ";
            }
        }
    
    public:
        void AVLInicializa() {
            this->root = NULL;
        }

        void AVLInserir(int data) {
            this->root = insert(this->root, data);
        }

        Node* AVLBusca(int data) {
            return search(this->root, data);
        }

        void AVLRemove(int data) {
            this->root = remove(this->root, data);
        }

        void AVLMostra() {
            pre_order(this->root);
        }

        void AVLRightRotation() {
            this->root = right_rotate(this->root);
        }

        void AVLLeftRotation() {
            this->root = left_rotate(this->root);
        }

        void AVLLeftRightRotation() {
            this->root->left = left_rotate(this->root->left);
            this->root = right_rotate(this->root);
        }

        void AVLRightLeftRotation() {
            this->root->right = right_rotate(this->root->right);
            this->root = left_rotate(this->root);
        }        
};

int main() {
    AVL_Tree avl;
    avl.AVLInserir(10);
    avl.AVLInserir(20);
    avl.AVLInserir(30);
    avl.AVLInserir(40);
    avl.AVLInserir(50);
    avl.AVLInserir(25);
    //avl.AVLMostra();
    // cout << endl;
    // avl.AVLRemove(30);
    // avl.AVLMostra();
    // cout << endl;
    // avl.AVLRemove(40);
    // avl.AVLMostra();
    // cout << endl;
    // avl.AVLRemove(50);
    // avl.AVLMostra();
    // cout << endl;
    // avl.AVLRemove(20);
    // avl.AVLMostra();
    // cout << endl;
    // avl.AVLRemove(25);
    // avl.AVLMostra();
    // cout << endl;
    // avl.AVLRemove(10);
    // avl.AVLMostra();
    // cout << endl;
    return 0;
}