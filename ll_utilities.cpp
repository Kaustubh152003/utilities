/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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
