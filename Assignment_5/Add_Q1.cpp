class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};
ListNode* getIntersectionNode(ListNode *A, ListNode *B) {
    if (!A || !B) return NULL;
	
	ListNode*a = A;
	ListNode*b = B;

	while(a!=b){
	if(a==NULL) a = B;
	else a = a->next;
	if (b==NULL) b = A;
	else b = b->next;
}
	return a;
}
