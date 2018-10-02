DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {

    if(head==NULL) return NULL;
    DoublyLinkedListNode* p = head;
    DoublyLinkedListNode* q = p->next;
    while(p->next != NULL){
        q = p->next;
        p->next = p->prev;
        p->prev = q;
        p = p->prev;
    }
    p->next = p->prev;
    p->prev = NULL;
    return p;

}