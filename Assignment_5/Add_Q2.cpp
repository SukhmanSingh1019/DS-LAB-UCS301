
ListNode* reverseLinkedListKGroup(ListNode* head, int k) {
	if(!head) return head;
	ListNode* temp = head;
	for(int i=0;i<k;i++){
		if(temp==NULL) return head;
		temp = temp->next;
	}
			
	ListNode* pre = NULL;
	ListNode* cur = head;
	ListNode* nxt = NULL;
	int count = 0;
	while(cur && count<k){
		nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
		count++;
	}
	if(nxt) head->next = reverseLinkedListKGroup(nxt,k);
	return pre;
}
