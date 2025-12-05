
Node* reverseDLLinGroups(Node* head, int k) {
    if (!head) return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next; 
        prev = curr;
        curr = next;
        count++;
    }
    if (next != NULL) {
       head->next = reverseDLLinGroups(next, k);
        if ( head->next)  head->next->prev = head;  
    }
    return prev; 
}
