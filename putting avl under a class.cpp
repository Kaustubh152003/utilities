class AVLtree
{
    struct Node //change this according to your node description
    {
        int data;
        Node *left; //always keep this field
        Node *right; //always keep this field
        int height; //always keep this field
    };
    Node* root;
    AVLtree()
    {
        root=NULL;
    }
    int compare(Node* a,Node* b) //change this according to your node description(//less than returns -1 equals return 0 greater than return 1) 
    {
        if(a->data<b->data)
        return -1;
        else
        {
            if(a->data==b->data)
            return 0;
            else
            return -1;
        }
    }
    Node* create(int k) //change this according to your node description
    {
        Node* ptr=(Node*)malloc(sizeof(Node));
        ptr->left=0;
        ptr->right=0;
        ptr->data=k;
        ptr->height=1;
        return ptr;
    }
    void Node_datacopy(Node* a,Node* b) //change this according to your node description
    {
        a->data=b->data;
    }
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
    struct Node* search(struct Node* root,Node* x)
    {
        if(root!=0)
        {
            if(compare(root,x)==0)
            return root;
            else
            {
                if(compare(x,root)<0)
                return search(root->left,x);
                else
                return search(root->right,x);
            }
        }
        else
        return 0;
    }
    Node* insertToAVL(Node* root, Node* x)
    {
        if(root==0)
        return x;
        else
        {
            if(compare(root,x)<0)
            {
                root->left=insertToAVL(root->left,x);
                reval_height(root);
                root=balance(root);
            }
            else
            {
                root->right=insertToAVL(root->right,x);
                reval_height(root);
                root=balance(root);
            }
            return root;
        }
    }
    Node* min_delete(Node* root,Node** x)
    {
        if(root->left==0)
        {
            *x=root;
            return root->right;
        }
        else
        {
            root->left=min_delete(root->left,x);
            reval_height(root);
            return balance(root);
        }
    }
    Node* deleteNode(Node* root, Node* x)
    {
        if(root==0)
        return 0;
        else
        {
            if(compare(root,x)==0)
            {
                if(root->left==0)
                return root->right;
                else
                {
                    if(root->right==0)
                    return root->left;
                    else
                    {
                        Node* v;
                        root->right=min_delete(root->right,&v);
                        Node_datacopy(root,v);
                        reval_height(root);
                        return balance(root);
                    }
                }
            }
            else
            {
                if(compare(x,root)<1)
                root->left=deleteNode(root->left,x);
                else
                root->right=deleteNode(root->right,x);
                reval_height(root);
                return balance(root);
            }
        }
    }
    Node* maxi(struct Node* root)
    {
        if(root!=0)
        {
            if(root->right==0)
            return root;
            else
            return maxi(root->right);
        }
        else
        return NULL;
    }
    Node* mini(struct Node* root)
    {
        if(root!=0)
        {
            if(root->left==0)
            return root;
            else
            return mini(root->left);
        }
        else
        return NULL;
    }
    public:
    void insert_element()
    {
        
    }
    void search_element()
    {
        
    }
    void delete_element()
    {
        
    }
    void min_of_tree()
    {
        
    }
    void max_of_tree()
    {
        
    }
};
