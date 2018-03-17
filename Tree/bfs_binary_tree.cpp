//Example of uri 1466 exercise
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node* Tree;

Tree* make_tree(){
    Tree *tr = new Tree;
    *tr = NULL;
    return tr;
}

void insert(Tree* tr, int data){
    struct node *aux = new struct node;
    aux->data = data;
    aux->left = NULL;
    aux->right = NULL;

    if(*tr == NULL)
        *tr = aux;
    else{
        struct node *parent,*current;
        current = *tr;
        parent = NULL;

        while(current != NULL){
            parent = current;
            if(aux->data > current->data)
                current = current->right;
            else
                current = current->left;
        }

        if(aux->data > parent->data)
            parent->right = aux;
        else
            parent->left = aux;
    }
}

void bfs(Tree* tr){
    struct node *aux = *tr;
    queue<struct node*> q;

    cout << aux->data;
    q.push(aux->left);
    q.push(aux->right);
    while(!q.empty()){
        aux = q.front();
        q.pop();
        if(aux){
            cout << " " << aux->data;
            q.push(aux->left);
            q.push(aux->right);    
        }
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(0);
    int c,n,a;

    cin >> c;

    for(int k = 1; k <= c; k++){
        cin >> n;
        Tree *tr = make_tree();
        while(n--){
            cin >> a;
            insert(tr, a);
        }
        cout << "Case " << k << ":" << endl;
        bfs(tr);
        cout << endl << endl;
    }

    return 0;
}
