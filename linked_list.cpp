struct Node* create(int x)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=0;
    ptr->data=x;
    return ptr;
}
struct Node *insertAtBegining(struct Node *head, int x) {

    struct Node* ptr=create(x);
	ptr->next=head;
	return ptr;
}
struct Node *insertAtEnd(struct Node *head, int x)  {
    struct Node* ptr=create(x);
    struct Node* og=head;
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
