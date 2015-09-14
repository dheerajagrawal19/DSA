#include "../Header/BasicFunctionality.h"

typedef struct _SNDLinkedList {
	int val;
	_SNDLinkedList * next;
	_SNDLinkedList * prev;
}SNDLinkedList;


typedef SNDLinkedList* SNDLinkedListP; 

SNDLinkedListP SNDLLCreateNode(int val);

void SNDLLPrintNode(SNDLinkedListP node);

int SNDLLSize(SNDLinkedListP head);

int SNDLLSizeRec(SNDLinkedListP head);

void SNDLLInsertNodeInSortedOrder(SNDLinkedList ** head, int val);

void SNDLLInsertNodeVar2(SNDLinkedListP * head, int val, int pos);

void SNDLLInsertNode(SNDLinkedListP * head, int val, int pos);

void SNDLLDeleteNode(SNDLinkedListP * head, int pos);

void SNDLLDeleteList(SNDLinkedListP * head);

void SNDLLDeleteListAlternateEvenNode(SNDLinkedListP * head);

bool SNDLLISListLoop(SNDLinkedListP head);

SNDLinkedListP SNDLLFindNode(SNDLinkedListP head, int val);

SNDLinkedListP SNDLLFindNodeRec(SNDLinkedListP head, int val);

SNDLinkedListP SNDLLFindNthNode(SNDLinkedListP head, int pos);

SNDLinkedListP SNDLLFindNthNodeFromLast(SNDLinkedListP head, int pos);

SNDLinkedListP SNDLLFindNthNodeFromLastRec(SNDLinkedListP head, int pos);

void SNDLLReverseList(SNDLinkedList ** head);

SNDLinkedListP SNDLLFindMiddle(SNDLinkedListP head);

bool SNDLLGetInterSectionList(SNDLinkedListP head1, SNDLinkedListP head2);

SNDLinkedListP SNDLLGetInterSectionListRec(SNDLinkedListP head1, SNDLinkedListP head2);

bool SNDLLIsPalindrome(SNDLinkedListP head);

bool SNDLLIsListIdentical(SNDLinkedListP head1, SNDLinkedListP head2);

SNDLinkedListP SNDLLSortedListMerge(SNDLinkedListP head1, SNDLinkedListP head2);

SNDLinkedListP SNDLLSortedListMergeVar2(SNDLinkedListP head1, SNDLinkedListP head2);

void SNDLLSplitList(SNDLinkedList ** head, SNDLinkedList ** firstHalf, SNDLinkedList ** secHalf);

void SNDLLMergeSort(SNDLinkedList ** head);

void SNDLLInsertionSort(SNDLinkedList ** head);

void SNDLLZigZagList(SNDLinkedList ** head);

int SNDLLMainFunction();
