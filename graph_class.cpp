class graph
{
    private:
    struct node{
        int key;
        struct node* next;
    };
    struct node** list;
    int* mark; //-1 doesnt exist 0 not vistited 1 visited
    int n;
    struct node* create(int x)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node)*1);
        ptr->key=x;
        ptr->next=NULL;
        return ptr;
    }
    struct node* add_node_to_list(struct node* head,int x) //returns head of the new list
    {
        struct node* ptr=this->create(x);
        ptr->next=head;
        return ptr;
    }
    struct node* delete_node_to_list(struct node* head,int x)
    {
        struct node* ptr=head;
        struct node* oghead=ptr;
        struct node* prev=NULL;
        while(ptr!=0 && ptr->key!=x)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        if(ptr!=0)
        {
            if(prev!=0)
            prev->next=ptr->next;
            else
            oghead=ptr->next;
        }
        return oghead;
    }
    
    
    public:
    graph(int max_size)
    {
        this->n=max_size;
        max_size++;
        this->list=(struct node**)malloc(sizeof(struct node *)*max_size);
        this->mark=(int*)malloc(sizeof(int)*max_size);
        int j=0;
        while(j<max_size)
        {
            this->list[j]=NULL;
            this->mark[j]=-1;
            j++;
        }
    }
    graph()
    {
        int max_size=200000;
        this->n=max_size;
        max_size++;
        this->list=(struct node**)malloc(sizeof(struct node *)*max_size);
        this->mark=(int*)malloc(sizeof(int)*max_size);
        int j=0;
        while(j<max_size)
        {
            this->list[j]=NULL;
            this->mark[j]=-1;
            j++;
        }
    }
    void add_vertex(int u)
    {
        if(mark[u]==-1)
        mark[u]=0;
    }
    void add_edge(int u,int v)
    {
        this->add_vertex(u);
        this->add_vertex(v);
        list[u]=this->add_node_to_list(list[u],v);
        
    }
    void add_undirected_edge(int u,int v)
    {
        this->add_edge(u,v);
        this->add_edge(v,u);
    }
    void delete_edge(int u,int v)
    {
        this->delete_node_to_list(this->list[u],v);
    }
    void delete_undirected_edge(int u,int v)
    {
        delete_edge(u,v);
        delete_edge(v,u);
    }
    void initialize_marks(int k)
    {
        int j=0;
        while(j<n+1)
        {
            mark[j]=k;
            j++;
        }
    }
    void dfs_func(int v) //0 is unvisted, 1 is visited
    {
        if(mark[v]==0)
        {
            mark[v]=1;
            printf("%d ",v);
            struct node* ptr=this->list[v];
            while(ptr!=NULL)
            {
                dfs_func(ptr->key);
                ptr=ptr->next;
            }
        }
    }
    void dfs()
    {
        this->initialize_marks(0);
        int j=0;
        while(j<n)
        {
            if(mark[j]==0)
            this->dfs_func(j);
            j++;
            
        }
        
    }
    void print_graph()
    {
        int j=1;
        while(j<n+1)
        {
            printf("%d : ",j);
            struct node* cur=this->list[j];
            while(cur!=NULL)
            {
                printf("%d ",cur->key);
                cur=cur->next;
            }
            printf("\n");
            j++;
        }
    }
    
    
    
};
