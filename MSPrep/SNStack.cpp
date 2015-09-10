#include "SNStack.h"

SNStackP  SNStackCreateNode(int val) {
	SNStackP  node = new SNStack();
	node->val = val;
	node->next = NULL;
	return node;
}

void SNStackPrintNode(SNStackP  node) {
	if(node) std::cout << node->val << std::endl;
}

int SNStackSize(SNStackP  head) {
	int count = 0;
	while (head) {
		head = head->next;
		count++;
	}
	return count;
}

void SNStackInsertNode(SNStack**head, int val) {
	if (*head == NULL) {
		*head = SNStackCreateNode(val);
		return;
	}

	SNStackP temp = SNStackCreateNode(val);
	temp->next = *head;
	*head = temp;
	return;
}

int SNStackRemoveNode(SNStack**head) {
	if (*head == NULL) return INT_MIN;
	int val = (*head)->val;
	SNStackP temp = *head;
	*head = (*head)->next;
	free(temp);
	return val;
}

int SNStackGetTopNode(SNStack**head) {
	if (*head == NULL) return INT_MIN;
	return (*head)->val;
}

void SNStackPrint(SNStackP head) {
	if (head == NULL) return;

	while (head)
	{
		SNStackPrintNode(head);
		head = head->next;
	}
}

void SNStackPush(SNStack**head, int val) {
	return SNStackInsertNode(head, val);
}

int SNStackPop(SNStack**head) {
	return SNStackRemoveNode(head);
}

int SNStackTop(SNStack**head) {
	return SNStackGetTopNode(head);
}

int SNStackMainFunction() {
	SNStackP stack = NULL;
	SNStackPush(&stack, 5);
	SNStackPush(&stack, 15);
	SNStackPush(&stack, 25);
	SNStackPrint(stack);

	std::cout<< "Top Of Stack: "<< (SNStackTop(&stack)) <<endl;
	std::cout << "Pop Of Stack: " << (SNStackPop(&stack)) << endl;
	std::cout << "Top Of Stack: " << (SNStackTop(&stack)) << endl;
	
	return 1;
}