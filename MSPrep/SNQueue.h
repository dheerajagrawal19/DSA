#include "BasicFunctionality.h"

typedef struct _SNQueue {
	int val;
	_SNQueue * next;
}SNQueue;

typedef SNQueue* SNQueueP;

typedef struct _SNQueueList {
	SNQueueP head, rear;
}SNQueueList;

typedef SNQueueList* SNQueueListP;

SNQueueP SNQueueCreateNode(int val);

SNQueueListP SNQueueListCreate();

void SNQueuePrintNode(SNQueueP node);

void SNQueuePrint(SNQueueListP head);

int SNQueuelength(SNQueueListP head);

void SNQueueInsertNode(SNQueueList ** head, int val);

int SNQueueRemoveNode(SNQueueList ** head);

int SNQueueGetTopNode(SNQueueList ** head);

void SNQueueEnQueue(SNQueueList ** queue, int val);

int SNQueueDeQueue(SNQueueList ** queue);

int SNQueuePop(SNQueueList ** head);

int SNQueueMainFunction();