#include "BasicFunctionality.h"

typedef struct _SNStack {
	int val;
	_SNStack * next;
}SNStack;

typedef SNStack*  SNStackP;

SNStackP SNStackCreateNode(int val);

void SNStackPrintNode(SNStackP node);

int SNStackSize(SNStackP head);

void SNStackInsertNode(SNStack ** head, int val);

int SNStackRemoveNode(SNStack ** head);

int SNStackGetTopNode(SNStack ** head);

void SNStackPrint(SNStackP head);

int SNStackPop(SNStack ** head);

int SNStackMainFunction();
