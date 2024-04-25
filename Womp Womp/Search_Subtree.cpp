#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(
                sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    return node;
}
void inorder(struct node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
struct node* search(struct node* root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

struct node* search_subtree(struct node* root, int key)
{
    if (root == NULL )
    {
        
        return root;
    }
    if (root->key == key){
        inorder(root);
        
        return root;
    }
    if (root->key < key)
        return search_subtree(root->right, key);
    return search_subtree(root->left, key);
}

int main()
{
    struct node* root = NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(i==0){
            root = insert(root, tmp);
        }else{
            insert(root, tmp);
        }
    }
    int key;
    cin>>key;
    
    if (search_subtree(root, key) == NULL)
    {
        cout<<"womp-womp"<<endl;    
    }

    return 0;
}
