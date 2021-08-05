// https://leetcode.com/problems/design-hashmap/

struct Node {
    int key;
    int val;
    Node *left;
    Node *right;
    Node(int k, int v) {
        key = k;
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* tree;
    
    Node* _findMin(Node* root) {
        Node* curr = root;
        
        while(curr->left)
            curr = curr->left;
        
        return curr;
    }
    
    Node* _insert(Node* root, int key, int val) {
        if(!root)
            return new Node(key, val);
        
        if(root->key > key)
            root->left = _insert(root->left, key, val);
        else if(root->key < key)
            root->right = _insert(root->right, key, val);
        else
            root->val = val;
        
        return root;
    }
    
    Node* _search(Node* root, int key) {
        if(!root)
            return nullptr;
        
        if(root->key == key)
            return root;
        
        if(root->key > key)
            return _search(root->left, key);
        return _search(root->right, key);
    }
    
    Node* _remove(Node* root, int key) {
        if(!root)
            return nullptr;
        
        if(root->key > key)
            root->left = _remove(root->left, key);
        else if(root->key < key)
            root->right = _remove(root->right, key);
        else {
            if(!root->left && !root->right)
                return nullptr;
            
            if(!root->left) {
                Node* tmp = root->right;
                delete root;
                return tmp;
            }
            
            if(!root->right) {
                Node* tmp = root->left;
                delete root;
                return tmp;
            }
            
            Node* tmp = _findMin(root->right);
            root->key = tmp->key;
            root->val = tmp->val;
            root->right = _remove(root->right, root->key);
        }
        
        return root;
    }
    
public:
    BST() {
        tree = nullptr;
    }
    
    void insert(int key, int val) {
        tree = _insert(tree, key, val);
    }
    
    int search(int key) {
        Node* node = _search(tree, key);
        return node ? node->val : -1;
    }
    
    void remove(int key) {
        tree = _remove(tree, key);
    }
};

class MyHashMap {
private:
    int size;
    vector<BST> hashmap;
    
    int hash(int key) {
        return key % size;
    }

public:    
    /** Initialize your data structure here. */
    MyHashMap() {
        size = 797;
        hashmap.resize(size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        hashmap[index].insert(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        return hashmap[index].search(key);
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        hashmap[index].remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
