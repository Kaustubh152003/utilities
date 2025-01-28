#include <math.h>
#include <stdio.h>
struct graph{
    struct node* list[200001];
    int mark[200001];
};
struct node{
    int key;
    struct node* next;
};
struct node* create(int k)
{
    struct node* ptr=(struct node*)malloc(1*sizeof(struct node));
    ptr->key=k;
    ptr->next=NULL;
    return ptr;
}
void insert_undir(struct graph* g,int x,int y)
{
    struct node* ptrx=create(x);
    struct node* ptry=create(y);
    ptry->next=g->list[x];
    g->list[x]=ptry;
    ptrx->next=g->list[y];
    g->list[y]=ptrx;
    
}
void read_and_insert_undir(struct graph* g,int n)
{
    int j=0;
    while(j<n)
    {
        int x,y;
        scanf("%d %d ",&x,&y);
        insert_undir(g,x,y);
        j++;
        
    }
}
void initialize_graph(struct graph* g)
{
    int j=0;
    while(j<200001)
    {
        g->list[j]=NULL;
        g->mark[j]=0;
        j++;
    }
}

void dfs_func(struct graph* g,int v)
{
    if(g->mark[v]==0)
    {
        g->mark[v]=1;
        printf("%d ",v);
        struct node* ptr=g->list[v];
        while(ptr!=0)
        {
            dfs_func(g,ptr->key);
            ptr=ptr->next;
        }
        
    }
}
void dfs(struct graph *g, int n) 
{
    int j=0;
    while(j<=n)
    {
        g->mark[j]=0;
        j++;
    }
    j=1;
    while(j<=n)
    {
        if(g->mark[j]==0)
        dfs_func(g,j);
        j++;
    }
}
void print_graph(struct graph* g,int n)
{
    int j=1;
    while(j<n+1)
    {
        printf("%d  ",j);
        struct node* cur=g->list[j];
        while(cur!=NULL)
        {
            printf("%d ",cur->key);
            cur=cur->next;
        }
        printf("\n");
        j++;
    }
}
void addnodes(struct graph *g,int v,int* queue,int* p)
{
    struct node* ptr=g->list[v];
    int count=0;
    while(ptr!=0)
    {
        if(g->mark[ptr->key]==0)
        {
            g->mark[ptr->key]=1;
            queue[*p]=ptr->key;
            *p=*p+1;
            count++;
        }
        ptr=ptr->next;
    }
}
void bfs(struct graph *g, int n) 
{
    
    int* queue=(int*)malloc(n*sizeof(int));
    int j=0;
    while(j<=n)
    {
        g->mark[j]=0;
        j++;
    }
    int sel=1;
    int p=1;
    queue[0]=1;
    j=0;
    while(j<p)
    {
        g->mark[queue[j]]=1;
        printf("%d ",queue[j]);
        addnodes(g,queue[j],queue,&p);
        j++;
    }
}
struct node* dll(struct node* ptr,int x)
{
    if(ptr!=0)
    {
        if(ptr->key==x)
        return ptr->next;
        else
        {
            ptr->next=dll(ptr->next,x);
            return ptr;
        }
    }
    else
    return 0;
}
void delete_edge(struct graph* g,int x,int y) //in building and verification. Not yet ready
{
    struct node* ptr=g->list[x];
    g->list[x]=dll(ptr,y);
    ptr=g->list[y];
    g->list[y]=dll(ptr,x);
}
int height(struct graph* g,int v)
{
    struct node* ptr=g->list[v];
    g->mark[v]=1;
    int max=1;
    while(ptr!=0)
    {
        if(g->mark[ptr->key]==0)
        {
            int h=height(g,ptr->key);
            if(1+h>max)
            max=1+h;
        }
            ptr=ptr->next;
    }
    return max;
}
int main()
{
    int n,m;
    struct graph g;
    initialize_graph(&g);
    scanf("%d ",&n);
    read_and_insert_undir(&g,n-1);
    print_graph(&g,n);
    
}
