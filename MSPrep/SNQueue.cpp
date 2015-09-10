#include "SNQueue.h"


SNQueueP SNQueueCreateNode(int val) {
	SNQueueP  node = new SNQueue();
	node->val = val;
	node->next = NULL;
	return node;
}

SNQueueListP SNQueueListCreate() {
	SNQueueListP q = new SNQueueList();
	q->rear = q->head = NULL;
	return q;
}
void SNQueuePrintNode(SNQueueP node) {
	if (node) std::cout << node->val << std::endl;
}

int SNQueuelength(SNQueueListP queue) {
	if (queue == NULL) return 0;

	int count = 0;
	SNQueueP head = queue->head;
	while (head) {
		head = head->next;
		count++;
	}
	return count;
}

void SNQueuePrint(SNQueueListP queue) {
	if (queue == NULL) return;
	SNQueueP head = queue->head;
	while (head)
	{
		SNQueuePrintNode(head);
		head = head->next;
	}
}

void SNQueueInsertNode(SNQueueList ** queue, int val) {
	if (*queue == NULL)	{
		*queue = SNQueueListCreate();
	}
	SNQueueP head = (*queue)->head;
	if (head == NULL) {
		(*queue)->rear = (*queue)->head = SNQueueCreateNode(val);
		return;
	}

	(*queue)->rear->next = SNQueueCreateNode(val);
	(*queue)->rear = (*queue)->rear->next;
	return;
}

int SNQueueRemoveNode(SNQueueList ** head) {
	if (*head == NULL) return INT_MIN;
	int headNodeVal = (*head)->head->val;
	SNQueueP headNode = (*head)->head;
	(*head)->head = (*head)->head->next;
	free(headNode);
	return headNodeVal;
}

int SNQueueGetTopNode(SNQueueList ** head) {
	if (*head == NULL) return INT_MIN;
	return (*head)->head->val;
}

void SNQueueEnQueue(SNQueueList ** queue, int val) {
	return SNQueueInsertNode(queue, val);
}

int SNQueueDeQueue(SNQueueList ** queue) {
	return SNQueueRemoveNode(queue);
}

int SNQueueMainFunction() {
	SNQueueListP queue = NULL;
	SNQueueEnQueue(&queue, 12);
	SNQueueEnQueue(&queue, 142);
	SNQueueEnQueue(&queue, 122);

	SNQueuePrint(queue);
	SNQueueDeQueue(&queue);
	SNQueuePrint(queue);
	return 1;
}