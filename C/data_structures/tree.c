#include "tree.h"

void print_tree(struct node* root)
{
    if(root==NULL) return;
    print_tree(root->left);
    printf("%d ",root->data);
    print_tree(root->right);
    return;
}


struct node* sort_tree(struct node* root)
{
    if(root==NULL) return root;
    if((root->right==NULL)&&(root->left==NULL)) return root;
    struct node *buffer=(struct node*)malloc(sizeof(struct node));
    if(root->right!=NULL){
        if(root->right->data<root->data)
        {
            buffer->data=root->right->data;
            root->right->data=root->data;
            root->data=buffer->data;
        }
    }
    if(root->left!=NULL){
        if(root->left->data>root->data)
        {
            buffer->data=root->left->data;
            root->left->data=root->data;
            root->data=buffer->data;
        }
    }
    if(root->right!=NULL){
        if(root->right->data<root->data)
        {
            buffer->data=root->right->data;
            root->right->data=root->data;
            root->data=buffer->data;
        }
    }
    if(root->right!=NULL)
    {
        root->right=sort_tree(root->right);    
    }
    if(root->left!=NULL)
    {
        root->left=sort_tree(root->left);
    }
    return root;    
}

void inOrder( struct node* root)
{
    root=sort_tree(root);
    print_tree(root);
}   
