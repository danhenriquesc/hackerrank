// Complete the reverse function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* ptr = head, *next, *prev = head->prev;
    while(ptr)
    {
        next = ptr->next;
        ptr->next = prev;
        ptr->prev = next;
        prev = ptr;
        ptr = next;
    }
    return prev;
}
