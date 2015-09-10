#include "BasicFunctionality.h"

typedef struct _SNBST {
	int val;
	_SNBST *left, *right;
}SNBST;

typedef SNBST* SNBSTP;



void SNBSTMirrorTree(SNBSTP head);

bool SNBSTIsTreeIdentical(SNBSTP head1, SNBSTP head2);

int SNBSTMainFunction();

SNBSTP SNBSTCreateNode(int val);

void SNBSTPrintNode(SNBSTP node);

void SNBSTPrintNodeInorder(SNBSTP node);

void SNBSTPrintNodePreorder(SNBSTP node);

void SNBSTPrintNodePostorder(SNBSTP node);

void SNBSTPrintLeafNode(SNBSTP node);

int SNBSTSize(SNBSTP head);

int SNBSTDepth(SNBSTP head);

void SNBSTDeleteNode(SNBST ** head, int val);

void SNBSTInsertNode(SNBST ** head, int val);

bool SNBSTFindNode(SNBSTP head, int val);

SNBSTP SNBSTCloneTree(SNBSTP head);

SNBSTP SNBSTCreateMirrorTree(SNBSTP head);
