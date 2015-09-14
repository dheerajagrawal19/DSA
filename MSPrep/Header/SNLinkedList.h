#include "../Header/../Header/BasicFunctionality.h"

typedef struct _SNLinkedList {
	int val;
	_SNLinkedList * next;
}SNLinkedList;


typedef SNLinkedList* SNLinkedListP;

SNLinkedListP SNLLCreateNode(int val);

void SNLLPrintNode(SNLinkedListP node);

int SNLLSize(SNLinkedListP head);

int SNLLSizeRec(SNLinkedListP head);

void SNLLInsertNodeInSortedOrder(SNLinkedList ** head, int val);

void SNLLInsertNodeVar2(SNLinkedListP * head, int val, int pos);

void SNLLInsertNode(SNLinkedListP * head, int val, int pos);

void SNLLDeleteNode(SNLinkedListP * head, int pos);

void SNLLDeleteList(SNLinkedListP * head);

void SNLLDeleteListAlternateEvenNode(SNLinkedListP * head);

bool SNLLISListLoop(SNLinkedListP head);

SNLinkedListP SNLLFindNode(SNLinkedListP head, int val);

SNLinkedListP SNLLFindNodeRec(SNLinkedListP head, int val);

SNLinkedListP SNLLFindNthNode(SNLinkedListP head, int pos);

SNLinkedListP SNLLFindNthNodeFromLast(SNLinkedListP head, int pos);

SNLinkedListP SNLLFindNthNodeFromLastRec(SNLinkedListP head, int pos);

void SNLLReverseList(SNLinkedList ** head);

SNLinkedListP SNLLFindMiddle(SNLinkedListP head);

bool SNLLGetInterSectionList(SNLinkedListP head1, SNLinkedListP head2);

SNLinkedListP SNLLGetInterSectionListRec(SNLinkedListP head1, SNLinkedListP head2);

bool SNLLIsPalindrome(SNLinkedListP head);

bool SNLLIsListIdentical(SNLinkedListP head1, SNLinkedListP head2);

SNLinkedListP SNLLSortedListMerge(SNLinkedListP head1, SNLinkedListP head2);

SNLinkedListP SNLLSortedListMergeVar2(SNLinkedListP head1, SNLinkedListP head2);

void SNLLSplitList(SNLinkedList ** head, SNLinkedList ** firstHalf, SNLinkedList ** secHalf);

void SNLLMergeSort(SNLinkedList ** head);

void SNLLInsertionSort(SNLinkedList ** head);

void SNLLZigZagList(SNLinkedList ** head);

int SNLLMainFunction();
