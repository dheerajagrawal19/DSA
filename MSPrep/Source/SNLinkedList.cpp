#include "../Header/SNLinkedList.h"

SNLinkedListP  SNLLCreateNode(int val) {
	SNLinkedListP  node = new SNLinkedList();
	node->val = val;
	node->next = NULL;
	return node;
}

void SNLLPrintNode(SNLinkedListP  node) {
	if(node) std::cout << node->val << std::endl;
}

int SNLLSize(SNLinkedListP  head) {
	int count = 0;
	while (head) {
		head = head->next;
		count++;
	}
	return count;
}

int SNLLSizeRec(SNLinkedListP  head) {
	if (head == NULL) return 0;
	return 1 + SNLLSizeRec(head->next);
}

int SNLLPrintList(SNLinkedListP  head) {

	std::cout << "Size of List " << SNLLSize(head) << std::endl;
	while (head) {
		SNLLPrintNode(head);
		head = head->next;
	}
	return 1;
}

void SNLLInsertNodeInSortedOrder(SNLinkedList** head, int val) {
	SNLinkedListP  temp = *head, node = SNLLCreateNode(val);
	
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

void SNLLInsertNodeVar2(SNLinkedList** head, int val, int pos) {
	SNLinkedListP  temp = *head,  node = SNLLCreateNode(val);
	int count = 0;

	if (pos == 0) {//push node in starting point...
		node->next = *head;
		*head = node;
		return;
	}

	if(SNLLSize(temp) < pos){//push node in starting point...
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

void SNLLInsertNode(SNLinkedListP * head, int val, int pos) {
	//return SNLLInsertNodeInSortedOrder(head, val);

	SNLinkedListP  temp = *head, node = SNLLCreateNode(val);
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
	temp->next = node;
	return;
}

void SNLLDeleteNode(SNLinkedListP * head, int pos) {
	if (*head == NULL) return;

	if(pos == 0){//delete at start
		SNLinkedListP  ptemp = *head;
		*head = (*head)->next;
		free(ptemp);
		return;
	}

	SNLinkedListP  ptemp2, ptemp = *head;
	int size = SNLLSize(*head), count = 1;

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

void SNLLDeleteList(SNLinkedListP *head) {
	while (*head) {
		SNLinkedListP  p = (*head)->next;
		SNLLDeleteNode(head, 0);
		*head = p;
	}
}

void SNLLDeleteListAlternateOddNodeVar1(SNLinkedListP *head) {
	if (*head == NULL) return;
	SNLinkedListP temp = (*head)->next;
	SNLLDeleteNode(head, 0);
	SNLLDeleteListAlternateEvenNode(&temp);
}

void SNLLDeleteListAlternateEvenNode(SNLinkedListP *head) {
	if (*head == NULL) return;
	SNLinkedListP temp = *head;
	while (temp&&temp->next) {
		SNLinkedListP  p = temp->next->next;
		SNLLDeleteNode(&temp->next, 0);
		temp = p;
	}
}

bool SNLLISListLoop(SNLinkedListP  head) {
	bool isLoop = false;
	SNLinkedListP temp1=head;
	SNLinkedListP temp2= head;

	while (temp1&&temp2) {
		temp1 = temp1->next;
		temp2 = temp2->next;
		if(temp2) temp2 = temp2->next;

		if (temp1 == temp2) isLoop = true;
	}
	return isLoop;
}

SNLinkedListP SNLLFindNode(SNLinkedListP  head, int val) {
	SNLinkedListP temp = head;

	while (temp) {
		if (temp->val == val) break;
		temp  = temp->next;
	}
	return temp;
}

SNLinkedListP SNLLFindNodeRec(SNLinkedListP  head, int val) {
	if (head == NULL) return NULL;
	
	if (head->val == val) return head;

	return SNLLFindNodeRec(head->next, val);
}

SNLinkedListP SNLLFindNthNode(SNLinkedListP  head, int pos) {
	SNLinkedListP temp = head;
	int count = 0;
	while (temp && (++count < pos)) {
		temp = temp->next;
	}
	return temp;
}

SNLinkedListP SNLLFindNthNodeFromLast(SNLinkedListP  head, int pos) {
	int count = SNLLSize(head) - pos ;
	return SNLLFindNthNode(head, count);
}

SNLinkedListP SNLLFindNthNodeFromLastRec(SNLinkedListP  head, int pos) {
	SNLinkedListP temp1 = head; 
	int count = 0;
	
	while (temp1 && (count++ <= pos)) 	temp1 = temp1->next; 

	SNLinkedListP temp2 = head;
	while (temp1){
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return temp2;
}

SNLinkedListP SNLLReverseListRec(SNLinkedList* head) {
	if (head == NULL || (head)->next == NULL) return head;

	SNLinkedListP temp = SNLLReverseListRec(head->next);
	head->next->next = head;
	head->next = NULL;
	return temp;
}

void SNLLReverseList(SNLinkedList** head) {
	if (*head == NULL) return;
	SNLinkedListP temp = *head;
	SNLinkedListP newHead = NULL;
	while (temp)
	{
		SNLinkedListP temp2 = temp->next;
		temp->next = newHead;
		newHead = temp;
		temp = temp2;
	}

	*head = newHead;
	return;
}

SNLinkedListP SNLLFindMiddle(SNLinkedListP head) {
	if (head == NULL) return NULL;

	if (head->next == NULL) return head;

	SNLinkedListP temp = head;
	while (temp->next)
	{
		head = head->next;
		temp = temp->next;
		if(temp) temp = temp->next;
	}

	return head;
}

bool SNLLGetInterSectionList(SNLinkedListP head1, SNLinkedListP head2) {
	if (head1 == NULL && head2 == NULL) return true;
	
	if (head1 == NULL || head2 == NULL) return false;

	int diff, l1 = SNLLSize(head1), l2 = SNLLSize(head2);
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

SNLinkedListP SNLLGetInterSectionListRec(SNLinkedListP head1, SNLinkedListP head2) {
	if (head1 == NULL && head2 == NULL) return head2;

	if (head1 == NULL || head2 == NULL) return NULL;

	if (head1->val > head2->val) return SNLLGetInterSectionListRec(head1, head2->next);
	
	if (head1->val < head2->val) return SNLLGetInterSectionListRec(head1->next, head2);

	if (head1->val == head2->val) {
		SNLinkedListP temp = SNLLCreateNode(head1->val);
		temp->next = SNLLGetInterSectionListRec(head1->next,  head2->next);
		return temp;
	}

	return NULL;
}

bool SNLLIsPalindrome(SNLinkedListP head) {
	if (head == NULL) return true;

	return false;
}

bool SNLLIsListIdentical(SNLinkedListP head1, SNLinkedListP head2) {
	if (head1 == NULL && head2 == NULL) return true;
	if (head1 == NULL || head2 == NULL) return false;

	if (head1->val == head2->val) return true&SNLLIsListIdentical(head1->next, head2->next);

	return false;
}


SNLinkedListP SNLLSortedListMerge(SNLinkedListP head1, SNLinkedListP head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	
	if (head1->val >= head2->val) {
		SNLinkedListP nl = SNLLCreateNode(head2->val);
		nl->next = SNLLSortedListMerge(head1, head2->next);
		return nl;
	}else{
		SNLinkedListP nl = SNLLCreateNode(head1->val);
		nl->next = SNLLSortedListMerge(head1->next, head2);
		return nl;
	}

	return NULL;
}

SNLinkedListP SNLLSortedListMergeVar2(SNLinkedListP head1, SNLinkedListP head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;

	if (head1->val >= head2->val) {
		SNLinkedListP nl = head2;
		nl->next = SNLLSortedListMerge(head1, head2->next);
		return nl;
	}
	else {
		SNLinkedListP nl = head1;
		nl->next = SNLLSortedListMerge(head1->next, head2);
		return nl;
	}

	return NULL;
}

void SNLLSplitList(SNLinkedList**head, SNLinkedList** firstHalf, SNLinkedList** secHalf) {
	if (*head == NULL) return; 

	if ((*head)->next == NULL) {
		*firstHalf = *head;
		return;
	}

	//break the list into two half...
	SNLinkedListP  tempHead2 = *head;
	SNLinkedListP  tempHead = (*head)->next;
	
	while (tempHead && tempHead->next)
	{
		tempHead = tempHead->next->next;
		tempHead2 = tempHead2->next;
	}

	*firstHalf = *head;
	*secHalf = (tempHead2->next);
	tempHead2->next = NULL;
}

void SNLLMergeSort(SNLinkedList** head) {
	if (*head == NULL || (*head)->next == NULL) return;

	SNLinkedListP firstHalf = NULL;
	SNLinkedListP secHalf = NULL;

	SNLLSplitList(head, &firstHalf, &secHalf);
	SNLLMergeSort(&firstHalf);
	SNLLMergeSort(&secHalf);

	*head = SNLLSortedListMergeVar2(firstHalf, secHalf);

}

void SNLLInsertionSort(SNLinkedList** head) {
	if (*head == NULL || (*head)->next == NULL) return;
	SNLinkedListP newList = NULL;
	SNLinkedListP temp = *head;
	while (temp)
	{
		SNLLInsertNodeInSortedOrder(&newList, temp->val);
		temp = temp->next;
	}

	*head = newList;
}

void SNLLZigZagList(SNLinkedList* head) {
	if (head == NULL) return;

	while ((head) && (head)->next) {
		swap(((head)->val), (head)->next->val);
		head = (head)->next->next;
	}
}

SNLinkedListP SNLLCloneList(SNLinkedListP head) {
	if (head == NULL) return NULL;

	SNLinkedListP newList = SNLLCreateNode(head->val);

	newList->next = SNLLCloneList(head->next);

	return newList;
}


int SNLLMainFunction() {
	SNLinkedListP  headList = NULL;
	SNLLInsertNode(&headList, 1, 0);
	SNLLInsertNode(&headList, 2, 0);
	SNLLInsertNode(&headList, 3, 10);
	SNLLInsertNode(&headList, 4, 2);
	SNLLInsertNode(&headList, 5, 2);

	SNLLPrintList(headList);

	SNLLMergeSort(&headList);
	
	SNLLInsertionSort(&headList);

	SNLLPrintList(headList);

	headList = SNLLReverseListRec(headList);

	SNLinkedListP headListClone = SNLLCloneList(headList);

//	SNLLDeleteListAlternateEvenNode(&headList);
//	SNLLDeleteListAlternateOddNodeVar1(&headList);

	SNLLPrintList(headList);

	SNLLZigZagList(headList);

	SNLLPrintList(headList);

	///* Basic Checks...
	std::cout << (SNLLIsListIdentical(headList, SNLLCreateNode(5)) ? "Identical" : "Identical not exists") << std::endl;
	std::cout << (SNLLFindNodeRec(headList, 4) ? "Value Exists" : "Value Does not exists") << std::endl;
	std::cout << (SNLLFindNthNode(headList, 4) ? "Value Exists" : "Value Does not exists") << std::endl;
	std::cout << (SNLLFindNthNodeFromLast(headList, 4) ? "Value Exists" : "Value Does not exists") << std::endl;
	std::cout << (SNLLFindNthNodeFromLastRec(headList, 4) ? "Value Exists" : "Value Does not exists") << std::endl;
	std::cout << (SNLLISListLoop(headList) ? "LoopExists" : "Loop Does not exists") << std::endl;
	std::cout << (SNLLSize(headList) == SNLLSizeRec(headList) ? "LoopExists" : "Loop Does not exists") << std::endl;
	std::cout << (SNLLFindMiddle(headList) ? "Middle" : "Loop Does not exists") << std::endl;
//	*/
	
	SNLLReverseList(&headList);
	SNLLPrintList(headList);

	SNLLDeleteNode(&headList, SNLLSize(headList));

	SNLLPrintList(headList);
	

	return 0;
}