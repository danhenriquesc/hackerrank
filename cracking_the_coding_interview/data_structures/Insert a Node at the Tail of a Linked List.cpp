/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
    struct Node *cur = (struct Node*) malloc(sizeof(struct Node));
    cur->data = data;
    cur->next = NULL;
    if(head == NULL)
    {
        head = cur;
    }
    else
    {
    struct Node *ptr = head;
    while(ptr->next != NULL)
    {
            ptr = ptr->next;
    }
    cur->next = ptr->next;
    ptr->next = cur;
    }
    return head;
}
