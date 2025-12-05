void removeLoop(ListNode* list) {
    
	if(!list) return;
	ListNode* slow = list;
	ListNode* fast = list;
	
	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
		
		if(slow == fast){
			if(slow==list){
				while(fast->next!=list) fast= fast->next;
				fast->next= NULL;
			}
			else {
				slow = list;
				while(slow->next != fast->next){
					slow = slow->next ;
					fast = fast->next;
				}
				fast->next = NULL;
			}
		return;
		}		
	}
}
