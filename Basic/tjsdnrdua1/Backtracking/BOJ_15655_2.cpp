#include<iostream>
#include<queue>
using namespace std;
int n;
string cmd; int in_key;
template<typename T1, typename T2>
class binNode {
    template<typename, typename> friend class BST;
    T1 key;    T2 value;
    binNode* left;
    binNode* right;
public:
    binNode(T1 key = 0, T2 val = 0, binNode* l = nullptr, binNode* r = nullptr)
        :key{ key }, value{ val }, left{ l }, right{ r }{}
    void setKey(T1 k) { this->key = k; }
    void setData(T2 val) { this->value = val; }
    void setLeft(binNode* l) { this->left = l; }
    void setRight(binNode* r) { this->left = r; }
    T1 getKey() { return this->key; }
    T2 getData() { return this->value; }
    binNode* getLeft() { return this->left; }
    binNode* getRight() { return this->right; }
    bool isLeaf() { return this->left == nullptr && this->right == nullptr; }
    bool hasTwoChild() { return this->left != nullptr && this->right != nullptr; }
    bool hasOneChild() {
        bool hasOnlyLeft = this->left != nullptr && this->right == nullptr;
        bool hasOnlyRight = this->left == nullptr && this->right != nullptr;
        return hasOnlyLeft || hasOnlyRight;
    }
};
template<typename T1, typename T2>
class binTree {
protected:
    binNode<T1, T2>* root;
    int getCount(binNode<T1, T2>* node) {//post_
        if (node == nullptr)return 0;
        int cnt = getCount(node->getLeft());
        cnt += getCount(node->getRight());
        cnt += 1;
        return cnt;
    }
    void preorder(binNode<T1, T2>* node) {
        if (node != nullptr) {
            cout << node->getData() << ' ';
            preorder(node->getLeft());
            preorder(node->getRight());
        }
    }void inorder(binNode<T1, T2>* node) {
        if (node != nullptr) {
            inorder(node->getLeft());
            cout << node->getData() << ' ';
            inorder(node->getRight());
        }
    }void postorder(binNode<T1, T2>* node) {
        if (node != nullptr) {
            postorder(node->getLeft());
            postorder(node->getRight());
            cout << node->getData() << ' ';
        }
    }
    void removeNodes(binNode<T1, T2>* node) {//post
        if (node != nullptr) {
            removeNodes(node->getLeft());
            removeNodes(node->getRight());
            delete node;
        }
    }
public:
    binTree() :root{ nullptr } {}
    bool empty() { return this->root == nullptr; }
    int getCount() { return (empty()) ? 0 : getCount(this->root); }
    void setRoot(binNode<T1, T2>* node) { this->root = node; }
    binNode<T1, T2>* getRoot() { return this->root; }
    void preorder() {
        cout << "preorder: ";
        preorder(this->root); cout << '\n';
    }void inorder() {
        cout << "inorder: ";
        inorder(this->root); cout << '\n';
    }void postorder() {
        cout << "postorder: ";
        postorder(this->root); cout << '\n';
    }void levelorder() {
        cout << "levelorder: ";
        queue<binNode<T1, T2>*> q;   q.push(this->root);
        while (!q.empty()) {
            binNode<T1, T2>* cur_node = q.front();  q.pop();
            cout << cur_node->getData() << ' ';
            q.push(cur_node->getLeft());
            q.push(cur_node->getRight());
        }cout << '\n';
    }
    ~binTree() { removeNodes(this->root); }
};
template<typename T1, typename T2>
class BST :public binTree<T1, T2> {
    binNode<T1, T2>* search(binNode<T1, T2>* node, T1 key) {
        if (node == nullptr || key == node->key)
            return node;
        else if (key < node->key)
            return search(node->getLeft(), key);
        else
            return search(node->getRight(), key);
    }
    void insert(binNode<T1, T2>* node, T1 key, T2 val) {
        if (key == (node->key))node->value = val;
        else if (key < node->key) {
            if (node->left == nullptr)
                node->left = new binNode<T1, T2>{ key,val };
            else insert(node->left, key, val);
        }
        else {
            if (node->right == nullptr)
                node->right = new binNode<T1, T2>{ key,val };
            else insert(node->right, key, val);
        }
    }
    binNode<T1, T2>* remove(binNode<T1, T2>* node, binNode<T1, T2>* parent, T1 key) {
        if (node == nullptr) return nullptr;   //no node with key
        if (key < node->key) return remove(node->left, node, key);
        else if (key > node->key) return remove(node->right, node, key);
        else {   //key==node->key: search() finished
            if (node->hasTwoChild()) {
                binNode<T1, T2>* succ = leftmost(node->right);
                node->key = succ->key;   node->value = succ->value;
                //remove the successor
                succ = this->remove(node->right, node, succ->key);
                return succ;
            }
            else if (node->hasOneChild()) {
                binNode<T1, T2>* child = (node->left != nullptr) ? node->left : node->right;
                if (node == this->root)return nullptr;
                else {
                    if (parent->left == node) parent->left = child;
                    else                   parent->right = child;
                }return node;
            }
            else if (node->isLeaf()) {
                if (node == this->root)this->root = nullptr;
                else {
                    if (parent->left == node) parent->left = nullptr;
                    else                   parent->right = nullptr;
                }return node;
            }
        }
    }
public:
    T2 search(T1 key) {
        binNode<T1, T2>* node = search(this->root, key);
        if (node == nullptr)throw std::runtime_error("out-of-key");
        return node->value;
    }
    void insert(T1 key, T2 val) {
        if (binTree<T1, T2>::empty()) this->root = new binNode<T1, T2>{ key,val };
        else insert(this->root, key, val);
    }
    void remove(T1 key) {
        binNode<T1, T2>* node = remove(this->root, nullptr, key);
        if (node == nullptr)throw std::runtime_error("out-of-key");
        delete node;
    }
    binNode<T1, T2>* leftmost(binNode<T1, T2>* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    BST<int, int> tra;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cmd >> in_key;
        if (cmd == "insert") {
            tra.insert(in_key, in_key);
            if (i == 0)tra.setRoot(tra.getRoot());
        }
        else if (cmd == "remove") {
            tra.remove(in_key);
        }
    }tra.preorder();
    tra.inorder();
    tra.postorder();
    tra.levelorder();
}