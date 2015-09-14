#include "../Header/SNDLinkedList.h"

SNDLinkedListP  SNDLLCreateNode(int val) {
	SNDLinkedListP  node = new SNDLinkedList();
	node->val = val;
	node->next = node->prev = NULL;
	return node;
}

void SNDLLPrintNode(SNDLinkedListP  node) {
	if(node) std::cout << node->val << std::endl;
}

int SNDLLSize(SNDLinkedListP  head) {
	int count = 0;
	while (head) {
		head = head->next;
		count++;
	}
	return count;
}

int SNDLLSizeRec(SNDLinkedListP  head) {
	if (head == NULL) return 0;
	return 1 + SNDLLSizeRec(head->next);
}

int SNDLLPrintList(SNDLinkedListP  head) {

	std::cout << "Size of List " << SNDLLSize(head) << std::endl;
	while (head) {
		SNDLLPrintNode(head);
		head = head->next;
	}
	return 1;
}

void SNDLLInsertNodeInSortedOrder(SNDLinkedList** head, int val) {
	SNDLinkedListP  temp = *head, node = SNDLLCreateNode(val);
	
	if (temp == NULL || temp->val > val) {
		node->next = *head;
		*head = node;
		return;
	}else{
		while (temp && temp->next && (temp->next->val < val)) {
			temp = temp->next;
		}

		node->next = temp->next;
		temp->next = node;
		return;
	}
}

void SNDLLInsertNodeVar2(SNDLinkedList** head, int val, int pos) {
	SNDLinkedListP  temp = *head,  node = SNDLLCreateNode(val);
	int count = 0;

	if (pos == 0) {//push node in starting point...
		node->next = *head;
		*head = node;
		return;
	}

	if(SNDLLSize(temp) < pos){//push node in starting point...
		while (temp->next)
			temp = temp->next;

		temp->next = node;
		return;
	}

	//push node in between
	while (temp && temp->next && (count < pos - 1)) {
		temp = temp->next;
		count++;
	}

	node->next = temp->next;
	temp->next = node;
	return;
}

void SNDLLInsertNode(SNDLinkedListP * head, int val, int pos) {
	SNDLinkedListP  temp = *head, node = SNDLLCreateNode(val);
	int count = 0;

	if (pos == 0) {//push node in starting point...
		node->next = *head;
		*head = node;
		return;
	}

	//push node in between
	while (temp && temp->next && (count < pos - 1)) {
		temp = temp->next;
		count++;
	}

	node->next = temp->next;
	node->prev = temp;
	temp->next = node;
	return;
}

void SNDLLDeleteNode(SNDLinkedListP * head, int pos) {
	if (*head == NULL) return;

	if(pos == 0){//delete at start
		SNDLinkedListP  ptemp = *head;
		*head = (*head)->next;
		free(ptemp);
		return;
	}

	SNDLinkedListP  ptemp2, ptemp = *head;
	int size = SNDLLSize(*head), count = 1;

	if ((pos < 0) || (pos > size)) return;

	while(ptemp && ptemp->next && (count < pos -1)){
		ptemp = ptemp->next;
		count++;
	}

	if (ptemp->next) {
		ptemp2 = ptemp->next;
		ptemp->next = ptemp->next->next;
		free(ptemp2);
		ptemp2 = NULL;
		return;
	}
	else {
		free(*head);
		*head = NULL;
		return;
	}
}

void SNDLLDeleteList(SNDLinkedListP *head) {
	while (*head) {
		SNDLinkedListP  p = (*head)->next;
		SNDLLDeleteNode(head, 0);
		*head = p;
	}
}

void SNDLLDeleteListAlternateOddNodeVar1(SNDLinkedListP *head) {
	if (*head == NULL) return;
	SNDLinkedListP temp = (*head)->next;
	SNDLLDeleteNode(head, 0);
	SNDLLDeleteListAlternateEvenNode(&temp);
}

void SNDLLDeleteListAlternateEvenNode(SNDLinkedListP *head) {
	if (*head == NULL) return;
	SNDLinkedListP temp = *head;
	while (temp&&temp->next) {
		SNDLinkedListP  p = temp->next->next;
		SNDLLDeleteNode(&temp->next, 0);
		temp = p;
	}
}

bool SNDLLISListLoop(SNDLinkedListP  head) {
	bool isLoop = false;
	SNDLinkedListP temp1=head;
	SNDLinkedListP temp2= head;

	while (temp1&&temp2) {
		temp1 = temp1->next;
		temp2 = temp2->next;
		if(temp2) temp2 = temp2->next;

		if (temp1 == temp2) isLoop = true;
	}
	return isLoop;
}

SNDLinkedListP SNDLLFindNode(SNDLinkedListP  head, int val) {
	SNDLinkedListP temp = head;

	while (temp) {
		if (temp->val == val) break;
		temp  = temp->next;
	}
	return temp;
}

SNDLinkedListP SNDLLFindNodeRec(SNDLinkedListP  head, int val) {
	if (head == NULL) return NULL;
	
	if (head->val == val) return head;

	return SNDLLFindNodeRec(head->next, val);
}

SNDLinkedListP SNDLLFindNthNode(SNDLinkedListP  head, int pos) {
	SNDLinkedListP temp = head;
	int count = 0;
	while (temp && (++count < pos)) {
		temp = temp->next;
	}
	return temp;
}

SNDLinkedListP SNDLLFindNthNodeFromLast(SNDLinkedListP  head, int pos) {
	int count = SNDLLSize(head) - pos ;
	return SNDLLFindNthNode(head, count);
}

SNDLinkedListP SNDLLFindNthNodeFromLastRec(SNDLinkedListP  head, int pos) {
	SNDLinkedListP temp1 = head; 
	int count = 0;
	
	while (temp1 && (count++ <= pos)) 	temp1 = temp1->next; 

	SNDLinkedListP temp2 = head;
	while (temp1){
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return temp2;
}

SNDLinkedListP SNDLLReverseListRec(SNDLinkedList* head) {
	if (head == NULL || (head)->next == NULL) return head;

	SNDLinkedListP temp = SNDLLReverseListRec(head->next);
	head->next->next = head;
	head->next = NULL;
	return temp;
}

void SNDLLReverseList(SNDLinkedList** head) {
	if (*head == NULL) return;
	SNDLinkedListP temp = *head;
	SNDLinkedListP newHead = NULL;
	while (temp)
	{
		SNDLinkedListP temp2 = temp->next;
		temp->next = newHead;
		newHead = temp;
		temp = temp2;
	}

	*head = newHead;
	return;
}

SNDLinkedListP SNDLLFindMiddle(SNDLinkedListP head) {
	if (head == NULL) return NULL;

	if (head->next == NULL) return head;

	SNDLinkedListP temp = head;
	while (temp->next)
	{
		head = head->next;
		temp = temp->next;
		if(temp) temp = temp->next;
	}

	return head;
}

bool SNDLLGetInterSectionList(SNDLinkedListP head1, SNDLinkedListP head2) {
	if (head1 == NULL && head2 == NULL) return true;
	
	if (head1 == NULL || head2 == NULL) return false;

	int diff, l1 = SNDLLSize(head1), l2 = SNDLLSize(head2);
	if (l1 > l2) {
		diff = l1 - l2;
		while (diff--) head1 = head1->next; 
	}else {
		diff = l2 - l1;
		while (diff--) head2 = head2->next;
	}

	while (true)
	{
		if (head1 == head2) return true;
		head1 = head1->next;
		head2 = head2->next;
	}
	
	return false;
}

SNDLinkedListP SNDLLGetInterSectionListRec(SNDLinkedListP head1, SNDLinkedListP head2) {
	if (head1 == NULL && head2 == NULL) return head2;

	if (head1 == NULL || head2 == NULL) return NULL;

	if (head1->val > head2->val) return SNDLLGetInterSectionListRec(head1, head2->next);
	
	if (head1->val < head2->val) return SNDLLGetInterSectionListRec(head1->next, head2);

	if (head1->val == head2->val) {
		SNDLinkedListP temp = SNDLLCreateNode(head1->val);
		temp->next = SNDLLGetInterSectionListRec(head1->next,  head2->next);
		return temp;
	}

	return NULL;
}

bool SNDLLIsPalindrome(SNDLinkedListP head) {
	if (head == NULL) return true;

	return false;
}

bool SNDLLIsListIdentical(SNDLinkedListP head1, SNDLinkedListP head2) {
	if (head1 == NULL && head2 == NULL) return true;
	if (head1 == NULL || head2 == NULL) return false;

	if (head1->val == head2->val) return true&SNDLLIsListIdentical(head1->next, head2->next);

	return false;
}


SNDLinkedListP SNDLLSortedListMerge(SNDLinkedListP head1, SNDLinkedListP head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	
	if (head1->val >= head2->val) {
		SNDLinkedListP nl = SNDLLCreateNode(head2->val);
		nl->next = SNDLLSortedListMerge(head1, head2->next);
		return nl;
	}else{
		SNDLinkedListP nl = SNDLLCreateNode(head1->val);
		nl->next = SNDLLSortedListMerge(head1->next, head2);
		return nl;
	}

	return NULL;
}

SNDLinkedListP SNDLLSortedListMergeVar2(SNDLinkedListP head1, SNDLinkedListP head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;

	if (head1->val >= head2->val) {
		SNDLinkedListP nl = head2;
		nl->next = SNDLLSortedListMerge(head1, head2->next);
		return nl;
	}
	else {
		SNDLinkedListP nl = head1;
		nl->next = SNDLLSortedListMerge(head1->next, head2);
		return nl;
	}

	return NULL;
}

void SNDLLSplitList(SNDLinkedList**head, SNDLinkedList** firstHalf, SNDLinkedList** secHalf) {
	if (*head == NULL) return; 

	if ((*head)->next == NULL) {
		*firstHalf = *head;
		return;
	}

	//break the list into two half...
	SNDLinkedListP  tempHead2 = *head;
	SNDLinkedListP  tempHead = (*head)->next;
	
	while (tempHead && tempHead->next)
	{
		tempHead = tempHead->next->next;
		tempHead2 = tempHead2->next;
	}

	*firstHalf = *head;
	*secHalf = (tempHead2->next);
	tempHead2->next = NULL;
}

void SNDLLMergeSort(SNDLinkedList** head) {
	if (*head == NULL || (*head)->next == NULL) return;

	SNDLinkedListP firstHalf = NULL;
	SNDLinkedListP secHalf = NULL;

	SNDLLSplitList(head, &firstHalf, &secHalf);
	SNDLLMergeSort(&firstHalf);
	SNDLLMergeSort(&secHalf);

	*head = SNDLLSortedListMergeVar2(firstHalf, secHalf);

}

void SNDLLInsertionSort(SNDLinkedList** head) {
	if (*head == NULL || (*head)->next == NULL) return;
	SNDLinkedListP newList = NULL;
	SNDLinkedListP temp = *head;
	while (temp)
	{
		SNDLLInsertNodeInSortedOrder(&newList, temp->val);
		temp = temp->next;
	}

	*head = newList;
}

void SNDLLZigZagList(SNDLinkedList* head) {
	if (head == NULL) return;

	while ((head) && (head)->next) {
		swap(((head)->val), (head)->next->val);
		head = (head)->next->next;
	}
}

SNDLinkedListP SNDLLCloneList(SNDLinkedListP head) {
	if (head == NULL) return NULL;

	SNDLinkedListP newList = SNDLLCreateNode(head->val);

	newList->next = SNDLLCloneList(head->next);

	return newList;
}


int SNDLLMainFunction() {
	SNDLinkedListP  headList = NULL;
	SNDLLInsertNode(&headList, 1, 0);
	SNDLLInsertNode(&headList, 2, 0);
	SNDLLInsertNode(&headList, 3, 10);
	SNDLLInsertNode(&headList, 4, 2);
	SNDLLInsertNode(&headList, 5, 2);

	SNDLLPrintList(headList);

	SNDLLMergeSort(&headList);
	
	SNDLLInsertionSort(&headList);

	SNDLLPrintList(headList);

	headList = SNDLLReverseListRec(headList);

	SNDLinkedListP headListClone = SNDLLCloneList(headList);

//	SNDLLDeleteListAlternateEvenNode(&headList);
//	SNDLLDeleteListAlternateOddNodeVar1(&headList);

	SNDLLPrintList(headList);

	SNDLLZigZagList(headList);

	SNDLLPrintList(headList);

	///* Basic Checks...
	std::cout << (SNDLLIsListIdentical(headList, SNDLLCreateNode(5)) ? "Identical" : "Identical not exists") << std::endl;
	std::cout << (SNDLLFindNodeRec(headList, 4) ? "Value Exists" : "Value Does not exists") << std::endl;
	std::cout << (SNDLLFindNthNode(headList, 4) ? "Value Exists" : "Value Does not exists") << std::endl;
	std::cout << (SNDLLFindNthNodeFromLast(headList, 4) ? "Value Exists" : "Value Does not exists") << std::endl;
	std::cout << (SNDLLFindNthNodeFromLastRec(headList, 4) ? "Value Exists" : "Value Does not exists") << std::endl;
	std::cout << (SNDLLISListLoop(headList) ? "LoopExists" : "Loop Does not exists") << std::endl;
	std::cout << (SNDLLSize(headList) == SNDLLSizeRec(headList) ? "LoopExists" : "Loop Does not exists") << std::endl;
	std::cout << (SNDLLFindMiddle(headList) ? "Middle" : "Loop Does not exists") << std::endl;
//	*/
	
	SNDLLReverseList(&headList);
	SNDLLPrintList(headList);

	SNDLLDeleteNode(&headList, SNDLLSize(headList));

	SNDLLPrintList(headList);
	

	return 0;
}