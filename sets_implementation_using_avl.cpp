#include <stdlib.h>
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}
int mod(int a)
{
    if(a<0)
    return -a;
    else
    return a;
}
Node* create(int k)
{
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->left=0;
    ptr->right=0;
    ptr->data=k;
    ptr->height=1;
    return ptr;
}
void reval_height(Node* root)
{
    int a,b;
    a=b=0;
    if(root->left!=0)
    a=root->left->height;
    if(root->right!=0)
    b=root->right->height;
    root->height=1+max(a,b);
}
Node* rotate_left(Node* root)
{
    Node* rootr=root->right;
    root->right=rootr->left;
    rootr->left=root;
    reval_height(root);
    reval_height(rootr);
    return rootr;
    
}
Node* rotate_right(Node* root)
{
    Node* rootl=root->left;
    root->left=rootl->right;
    rootl->right=root;
    reval_height(root);
    reval_height(rootl);
    return rootl;
    
}
Node* drl(Node* root)
{
    root->right=rotate_right(root->right);
    return rotate_left(root);
}
Node* drr(Node* root)
{
    root->left=rotate_left(root->left);
    return rotate_right(root);
}
Node* balance(Node* root)
{
    int rlh,rrh;
    rlh=rrh=0;
    if(root->left!=0)
    rlh=root->left->height;
    if(root->right!=0)
    rrh=root->right->height;
    if(mod(rlh -rrh)>1)
    {
        if(rlh>rrh)
        {
            Node* rootl=root->left;
            int rllh=0;
            if(rootl->left!=0)
            rllh=rootl->left->height;
            if(rootl->right!=0 && rootl->right->height>rllh)
            return drr(root);
            else
            return rotate_right(root);
        }
        else
        {
            Node* rootr=root->right;
            int rrrh=0;
            if(rootr->right!=0)
            rrrh=rootr->right->height;
            if(rootr->left!=0 && rootr->left->height>rrrh)
            return drl(root);
            else
            return rotate_left(root);
            
        }
    }
    else
    return root;
    
}
Node* insertToAVL(Node* root, int k)
{
    if(root==0)
    return create(k);
    else
    {
        if(k<root->data)
        {
            root->left=insertToAVL(root->left,k);
            reval_height(root);
            root=balance(root);
        }
        else
        {
            root->right=insertToAVL(root->right,k);
            reval_height(root);
            root=balance(root);
        }
        return root;
    }
}
Node* min_delete(Node* root,int* val)
{
    if(root->left==0)
    {
        *val=root->data;
        return root->right;
    }
    else
    {
        root->left=min_delete(root->left,val);
        reval_height(root);
        return balance(root);
    }
}
Node* deleteNode(Node* root, int k)
{
    if(root==0)
    return 0;
    else
    {
        if(k==root->data)
        {
            if(root->left==0)
            return root->right;
            else
            {
                if(root->right==0)
                return root->left;
                else
                {
                    int v=-1;
                    root->right=min_delete(root->right,&v);
                    root->data=v;
                    reval_height(root);
                    return balance(root);
                }
            }
        }
        else
        {
            if(k<root->data)
            root->left=deleteNode(root->left,k);
            else
            root->right=deleteNode(root->right,k);
            reval_height(root);
            return balance(root);
        }
    }
}
struct Node* bst_search(struct Node* root,int k)
{
    if(root!=0)
    {
        if(root->data==k)
        return root;
        else
        {
            if(k<root->data)
            return bst_search(root->left,k);
            else
            return bst_search(root->right,k);
        }
    }
    else
    return 0;
}
int maxi(struct Node* root)
{
    if(root!=0)
    {
        if(root->right==0)
        return root->data;
        else
        return maxi(root->right);
    }
    else
    return NULL;
}
int mini(struct Node* root)
{
    if(root!=0)
    {
        if(root->left==0)
        return root->data;
        else
        return maxi(root->left);
    }
    else
    return NULL;
}
