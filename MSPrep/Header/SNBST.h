#include "../Header/BasicFunctionality.h"

typedef struct _SNBST {
	int val;
	_SNBST *left, *right, *next;
}SNBST;

typedef SNBST* SNBSTP;

void SNBSTPrintNodeLevelorder(SNBSTP node);

void SNBSTPrintNodeLevelorderRecursive(SNBSTP node);

void SNBSTPrintNodeInorderIterative(SNBSTP node);

void SNBSTPrintNodeInorderIterativeVar2(SNBSTP node);

void SNBSTMirrorTree(SNBSTP head);

bool SNBSTIsTreeIdentical(SNBSTP head1, SNBSTP head2);

int SNBSTMinValue(SNBSTP head);

int SNBSTMaxValue(SNBSTP head);

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
