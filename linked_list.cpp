/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* create(int x)
{
    struct ListNode* ptr=(struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->next=0;
    ptr->val=x;
    return ptr;
}
struct ListNode *insertAtBegining(struct ListNode *head, int x) {

    struct ListNode* ptr=create(x);
	ptr->next=head;
	return ptr;
}
struct ListNode *insertAtEnd(struct ListNode *head, int x)  {
    struct ListNode* ptr=create(x);
    struct ListNode* og=head;
    if(head==0)
    return ptr;
    else
    {
        while(head->next!=0)
        head=head->next;
        head->next=ptr;
        return og;
    }
}
int size_of_ll(struct ListNode* head)
{
    int j=0;
    while(head!=0)
    {
        head=head->next;
        j++;
    }
    return j;
}
int* array_from_ll(struct ListNode* head,int* size_of_array)
{
    int j=0;
    int n=size_of_ll(head);
    int* arr=(int*)malloc(n*sizeof(int));
    while(j<n)
    {
        arr[j]=head->val;
        head=head->next;
        j++;
    }
    *size_of_array=n;
    return arr;
}
