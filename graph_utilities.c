#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
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
            dfs_func(g,ptr->data,mark);
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
    j=0;
    while(j<n)
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
int main()
{
    int n,m;
    struct graph g;
    initialize_graph(&g);
    scanf("%d ",&n);
    read_and_insert_undir(&g,n-1);
    print_graph(&g,n);
    
}
