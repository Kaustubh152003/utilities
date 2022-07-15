void copy_list(Node** list1,Node** list2,int n)
{
    int j=0;
    while(j<n)
    {
        list1[j]=list2[j];
        j++;
    }
}

void level_order_by_level(Node *root)
{
    if(root!=0)
    {
        Node* list[100000];
        Node* list2[100000];
        list[0]=root;
        int p=1;
        while(p>0)
        {
            int j=0;
            copy_list(list2,list,p);
            int q=0;
            j=0;
            while(j<p)
            {
                
                root=list2[j];
                printf("%d ",root->data);
                if(root->left!=0)
                {
                    list[q]=root->left;
                    q++;
                }
                if(root->right!=0)
                {
                    list[q]=root->right;
                    q++;
                }
                j++;
            }
            p=q;
        }
    }
}
