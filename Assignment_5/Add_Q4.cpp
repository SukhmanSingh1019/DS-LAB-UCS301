Node* rotate(Node* head, int k) {
        
        if (!head || k==0)) return head;
        
        Node* temp = head;
        int i=1;
        while(i<k){
            temp=temp->next;
            i++;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
        Node* end = temp;
        Node* newhead = end->next;
        while(temp->next){
            temp=temp->next;
        }
        end->next = NULL;
        temp->next = head;
        return newhead;
    }
