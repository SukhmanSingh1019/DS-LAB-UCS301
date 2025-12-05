 Node *addPolynomial(Node *head1, Node *head2) {
   if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;
    
    if (head1->pow > head2->pow) {
      Node* nextPtr = addPolynomial(head1->next, head2);
      head1->next = nextPtr;
      return head1;
    }
    else if (head1->pow < head2->pow) {
      Node* nextPtr = addPolynomial(head1, head2->next);
      head2->next = nextPtr;
      return head2;
    }
    Node* nextPtr = addPolynomial(head1->next, head2->next);
    head1->coeff += head2->coeff;
    head1->next = nextPtr;
    return head1;
    }
