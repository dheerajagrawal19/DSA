#include "../Header/SNMixedDataStructure.h"


SNBSTP SNBSTFromSortedArrayHelper(int arr[], int l, int h) {
	if (l>h) return NULL;
	int mid = (l + h )/ 2;
	SNBSTP root = SNBSTCreateNode(arr[mid]);
	root->left = SNBSTFromSortedArrayHelper(arr, l, mid-1);
	root->right = SNBSTFromSortedArrayHelper(arr, mid+1, h);
	return root;
}

SNBSTP SNBSTFromSortedArray(int arr[]) {
	int len = sizeof(arr) / sizeof(arr[0]);
	return SNBSTFromSortedArrayHelper(arr, 0, len);
}

int compareInt(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
SNBSTP SNBSTFromUnSortedArray(int arr[]) {
	int len = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, len, sizeof(int), compareInt);
	return SNBSTFromSortedArrayHelper(arr, 0, len);
}

SNBSTP SNBSTFromSortedLinkListHelper(SNLinkedListP *head, int h) {
	if (h <= 0) return NULL;
	SNBSTP left = SNBSTFromSortedLinkListHelper(head, h / 2);
	SNBSTP root = SNBSTCreateNode((*head)->val);
	root->left = left;
	*head = (*head)->next;
	root->right = SNBSTFromSortedLinkListHelper(head, h - h / 2);
}

SNBSTP SNBSTFromSortedLinkList(SNLinkedListP head) {
	int len = SNLLSize(head);
	return SNBSTFromSortedLinkListHelper(&head, len);
}

SNDLinkedListP SNBSTFromSortedDLinkListHelper(SNDLinkedListP *head, int h) {
	if(h <= 0) return NULL;
	SNDLinkedListP left = SNBSTFromSortedDLinkListHelper(head, h / 2);
	SNDLinkedListP root = SNDLLCreateNode((*head)->val);
	root->prev = left;
	*head = (*head)->next;
	root->next = SNBSTFromSortedDLinkListHelper(head, h - h / 2);
	return root;
}

SNDLinkedListP SNBSTFromSortedDLinkList(SNDLinkedListP head) {
	int len = SNDLLSize(head);
	return SNBSTFromSortedDLinkListHelper(&head, len);
}

void SNBSTPrintNodeLevelorder(SNBSTP node) {
	if (node == NULL) return;

	SNQueueListP qu = NULL;
	SNQueueEnQueue(&qu, (unsigned int)node);
	int nodesInCurrentLevel = 1;
	int nodesInNextLevel = 0;

	while(!SNQueueListIsEmpty(qu)) {
		node = (SNBSTP)SNQueueDeQueue(&qu);
		nodesInCurrentLevel--;
		if (node) {
			SNBSTPrintNode(node);
			if (node->left) {
				SNQueueEnQueue(&qu, (unsigned int)node->left); 
				nodesInNextLevel++;
			}
			if (node->right) {
				SNQueueEnQueue(&qu, (unsigned int)node->right); 
				nodesInNextLevel++;
			}
		}
		if (nodesInCurrentLevel == 0) {
			cout << endl;
			nodesInCurrentLevel = nodesInNextLevel;
			nodesInNextLevel = 0;
		}
	}
}

void SNBSTPrintNodeLevelorderRecursiveHelper(SNBSTP node, int level, int i) {
	if (node == NULL) return;

	if(level == i) SNBSTPrintNode(node);
	else {
		SNBSTPrintNodeLevelorderRecursiveHelper(node->left, level, i+1);
		SNBSTPrintNodeLevelorderRecursiveHelper(node->right, level, i+1);
	}
}

void SNBSTPrintNodeLevelorderRecursive(SNBSTP node) {
	if (node == NULL) return;
	
	int height = SNBSTDepth(node);

	cout << "Height of Tree " << height << endl;
	for (int i = 0; i < height; i++) {
		SNBSTPrintNodeLevelorderRecursiveHelper(node, i, 0);
		cout << endl;
	}
}

void SNBSTPrintNodeInorderIterative(SNBSTP node) {
	if (node == NULL) return;
	cout << "Size of Tree " << SNBSTSize(node) << endl;
	cout << "Depth  of Tree " << SNBSTDepth(node) << endl;

	SNStackP stack = NULL;
	SNStackPush(&stack, (unsigned)node);

	while(!SNStackIsEmpty(stack))
	{
		if (node) {
			if(node->left)SNStackPush(&stack, (unsigned)node->left);
			node = node->left;
		}else{
			node = (SNBSTP)SNStackPop(&stack);
			SNBSTPrintNode(node);
			if (node->right)SNStackPush(&stack, (unsigned)node->right);
			node = node->right;
		}
	}
}

