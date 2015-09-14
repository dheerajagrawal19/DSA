#include  "../Header/SNBST.h"

SNBSTP SNBSTCreateNode(int val) {
	SNBSTP temp = new SNBST();
	temp->val = val;
	temp->left = temp->right = NULL;
	return temp;
}

void SNBSTPrintNode(SNBSTP node) {
	if (node) cout << node->val << endl;
}

void SNBSTPrintNodeInorder(SNBSTP node) {
	if (node) {
		SNBSTPrintNodeInorder(node->left);
		SNBSTPrintNode(node);
		SNBSTPrintNodeInorder(node->right);
	}
}


void SNBSTPrintTree(SNBSTP node) {
	cout << "Size of Tree " << SNBSTSize(node) << endl;
	cout << "Depth  of Tree " << SNBSTDepth(node) << endl;
	SNBSTPrintNodeInorder(node);
}

void SNBSTPrintNodePreorder(SNBSTP node) {
	if (node) {
		SNBSTPrintNode(node);
		SNBSTPrintNodePreorder(node->left);
		SNBSTPrintNodePreorder(node->right);
	}
}

void SNBSTPrintNodePostorder(SNBSTP node) {
	if (node) {
		SNBSTPrintNodePostorder(node->left);
		SNBSTPrintNodePostorder(node->right);
		SNBSTPrintNode(node);
	}
}

void SNBSTPrintLeafNode(SNBSTP node) {	
	if (node->left == NULL && node->right == NULL) {
		SNBSTPrintNode(node);
	}
	SNBSTPrintNodePostorder(node->left);
	SNBSTPrintNodePostorder(node->right);
}

void SNBSTPrintNodesInRange(SNBSTP node, int min, int max) {
	if (node) {
		if(node->val >= min)SNBSTPrintNodesInRange(node->left, min, max);
		if (node->val >= min && node->val <= max) cout << node->val << endl;
		if (node->val <= max) SNBSTPrintNodesInRange(node->right, min, max);
	}
}

int SNBSTSize(SNBSTP head) {
	if (head == NULL) return 0;

	return 1 + SNBSTSize(head->left) + SNBSTSize(head->right);
}

int SNBSTDepth(SNBSTP head) {
	if (head == NULL) return 0;
	return max((1 + SNBSTDepth(head->left)), (1 + SNBSTDepth(head->right)));
}
int SNBSTDiameterhelper(SNBSTP head, int *h) {
	if (head == NULL) return 0;
	int lh = 0, rh = 0;
	int ld = SNBSTDiameterhelper(head->left, &lh);
	int rd = SNBSTDiameterhelper(head->right, &rh);

	//change the height..
	*h = max(lh, rh);
	*h = *h + 1;

	return max((max(ld, rd)), (lh + rh + 1));
}
int SNBSTDiameter(SNBSTP head) {
	if (head == NULL) return 0;
	int h = 0;
	return SNBSTDiameterhelper(head, &h);
}

SNBSTP SNBSTSuccessor(SNBSTP head) {
	if (head) {
		head = head->right;
		while (head->left)
			head = head->left;
		
		return head;
	}
	return NULL;
}

SNBSTP SNBSTPredecessor(SNBSTP head) {
	if (head) {
		head = head->left;
		while (head->right)
			head = head->right;

		return head;
	}
	return NULL;
}

SNBSTP SNBSTPredecessorOrSuccessor(SNBSTP head) {
	SNBSTP su = SNBSTSuccessor(head);
	if (su == NULL) return SNBSTPredecessor(head);
	else return su;
}

void SNBSTPredecessorAndSuccessor(SNBSTP head, int val, SNBSTP pre, SNBSTP succ) {
	if (head == NULL) return;

	if (head->val > val) {
		return SNBSTPredecessorAndSuccessor(head->left, val, pre, succ);
	}
	else if ((head)->val < val) {
		return SNBSTPredecessorAndSuccessor(head->right, val, pre, succ);
	}
	else if (head->val == val) {
		pre = SNBSTPredecessor(head);
		succ = SNBSTSuccessor(head);
		return;
	}
}

SNBSTP SNBSTInorderSuccessor(SNBSTP head, SNBSTP root) {
	if (head->right) return SNBSTSuccessor(head->right);
	SNBSTP temp = NULL;
	while (root)
	{
		if (head->val < root->val) {
			temp = root;
			root = root->right;
		}else if (head->val > root->val) root = root->left;
		else break;
	}
	return temp;
}

void SNBSTDeleteNodeUtility(SNBST** head) {
	if (*head == NULL) return;
	if ((*head)->left == NULL && (*head)->right == NULL) {
		free(*head);
		*head = NULL;
	}else if ((*head)->left != NULL && (*head)->right == NULL) {
		SNBSTP temp = (*head);
		(*head) = temp->left;
		free(temp);
	}else if ((*head)->right != NULL && (*head)->left == NULL) {
		SNBSTP temp = (*head);
		(*head) = temp->right;
		free(temp);
	}else {
		//long processing....
		SNBSTP temp = *head;
		SNBSTP tempSucc = SNBSTPredecessorOrSuccessor(temp);
		temp->val = tempSucc->val;
		SNBSTDeleteNode(&temp->right, temp->val);
	}
}

void SNBSTDeleteNode(SNBST** head, int val) {
	if (*head == NULL) return;

	if ((*head)->val > val) {
		return SNBSTDeleteNode(&(*head)->left, val);
	}
	else if ((*head)->val < val) {
		return SNBSTDeleteNode(&(*head)->right, val);
	}
	else  if ((*head)->val == val) {
		return SNBSTDeleteNodeUtility(head);
	}

return;
}


void SNBSTInsertNode(SNBST ** head, int val) {
	if (*head == NULL) {
		*head = SNBSTCreateNode(val);
		return;
	}

	if ((*head)->val > val) {
		return SNBSTInsertNode(&(*head)->left, val);
	}
	else {
		return SNBSTInsertNode(&(*head)->right, val);
	}

	return;
}

bool SNBSTFindNode(SNBSTP head, int val) {
	if (head == NULL) 	return false;

	if ((head)->val > val) {
		return SNBSTFindNode((head)->left, val);
	}
	else if ((head)->val < val) {
		return SNBSTFindNode((head)->right, val);
	}
	else if (head->val == val) {
		return true;
	}

	return false;
}

void SNBSTFindKthNodeHelper(SNBSTP head, int k, int *c, int *val) {
	if (head == NULL) 	return;
	SNBSTFindKthNodeHelper(head->right, k , c, val);
	if (++*c == k) {
		*val = head->val;
		return;
	}
	SNBSTFindKthNodeHelper(head->left, k , c, val);

}
int SNBSTFindKthNode(SNBSTP head, int k) {
	if (head == NULL) 	return INT_MIN;
	int c = 0;
	int val = 0;
	SNBSTFindKthNodeHelper(head, k, &c, &val);
	return val;
}

void SNBSTTransformtoSumBSTHelper(SNBSTP head, int *sum) {
	if (head == NULL) return;
	SNBSTTransformtoSumBSTHelper(head->right, sum);
	*sum = *sum + head->val;
	head->val = *sum;
	SNBSTTransformtoSumBSTHelper(head->left, sum);
}

void SNBSTTransformtoSumBST(SNBSTP head) {
	int sum = 0;
	return SNBSTTransformtoSumBSTHelper(head, &sum);
}

void SNBSTDeleteTree(SNBST** head) {
	if (*head != NULL) {
		SNBSTDeleteTree(&(*head)->left);
		SNBSTDeleteTree(&(*head)->right);
		free(*head);
		*head = NULL;
	}
}

SNBSTP SNBSTCloneTree(SNBSTP head) {
	if (head == NULL) return NULL;
	SNBSTP temp = SNBSTCreateNode(head->val);
	temp->left = SNBSTCloneTree(head->left);
	temp->right = SNBSTCloneTree(head->right);
	return temp;
}

SNBSTP SNBSTCreateMirrorTree(SNBSTP head) {
	if (head == NULL) return NULL;
	SNBSTP temp = SNBSTCreateNode(head->val);
	temp->left = SNBSTCreateMirrorTree(head->right);
	temp->right = SNBSTCreateMirrorTree(head->left);
	return temp;
}

void SNBSTMirrorTree(SNBSTP head) {
	if (head) {
		SNBSTMirrorTree(head->left);
		SNBSTMirrorTree(head->right);
		swap(head->left, head->right);
	}
}


bool SNBSTIsTreeIdentical(SNBSTP head1, SNBSTP head2) {
	if (head1 == NULL && head2 == NULL) return true;
	if (head1 != NULL && head2 != NULL) {
		return (head1->val == head2->val)
			&& SNBSTIsTreeIdentical(head1->left, head2->left)
			&& SNBSTIsTreeIdentical(head1->right, head2->right);
	}
	return false;
}

bool SNBSTIsBSTHelper(SNBSTP head, int min, int max) {
	if (head == NULL) return true;

	if (head->val > min && head->val < max) {
		return SNBSTIsBSTHelper(head->left, min, head->val) && SNBSTIsBSTHelper(head->right, head->val, max);
	}

	return false;
}

bool SNBSTIsBST(SNBSTP head) {
	if (head == NULL) return true;

	return SNBSTIsBSTHelper(head, INT_MIN, INT_MAX);
}

bool SNBSTIsBSTVar2Helper(SNBSTP head, int *prev) {
	if (head == NULL) return true;

	if (SNBSTIsBSTVar2Helper(head->left, prev)){
		if (*prev < head->val) {
			*prev = head->val;
			return SNBSTIsBSTVar2Helper(head->right, prev);
		}
		return false;
	}

	return false;
}

bool SNBSTIsBSTVar2(SNBSTP head) {
	if (head == NULL) return true;

	int prev = INT_MIN;

	return SNBSTIsBSTVar2Helper(head, &prev);
}

int SNBSTMinValue(SNBSTP head) {
	head = head->left;
	while (head->left)
		head = head->left;

	return head->val;
}

int SNBSTMaxValue(SNBSTP head) {
	head = head->right;
	while (head->right)
		head = head->right;

	return head->val;
}

bool SNBSTIsHeightBalancedHelper(SNBSTP head, int *h) {
	if (head == NULL) return true;

	int lh = 0, rh = 0;
	if (SNBSTIsHeightBalancedHelper(head->left, &lh) && SNBSTIsHeightBalancedHelper(head->right, &rh)) {
			*h = max(lh, rh);
			*h = *h + 1;
			if (abs(lh - rh) <= 1) {
				return true;
			}
			return false;
	}
	return false;
}
bool SNBSTIsHeightBalanced(SNBSTP head) {
	if (head == NULL) return true;
	int h = 0;
	return SNBSTIsHeightBalancedHelper(head, &h);
}


bool SNBSTFindLargestBSTHelper(SNBSTP head) {
	return NULL;
}
bool SNBSTFindLargestBST(SNBSTP head) {
	if (head == NULL) return true;

	return SNBSTFindLargestBSTHelper(head);
}
int SNBSTMainFunction() {
	SNBSTP bst = NULL;
	SNBSTInsertNode(&bst, 5);
	SNBSTInsertNode(&bst, 3);
	SNBSTInsertNode(&bst, 2);
	SNBSTInsertNode(&bst, 8);
	SNBSTInsertNode(&bst, 7);
	SNBSTInsertNode(&bst, 0);
	//SNBSTInsertNode(&bst, 1);
	//SNBSTInsertNode(&bst, -23);
///*	cloning and mirror stuff....

//	SNBSTPrintNodeLevelorder(bst);
	//SNBSTPrintNodeLevelorderRecursive(bst);
//	SNBSTPrintTree(bst);
	
	SNBSTPrintNodeInorderIterative(bst);
	
	SNBSTP clone = SNBSTCloneTree(bst);
	SNBSTP mirror = SNBSTCreateMirrorTree(bst);
	SNBSTPrintTree(clone);
	SNBSTPrintTree(mirror);
	SNBSTMirrorTree(clone);
	SNBSTPrintTree(clone);
	
	cout << "Find Kth Node " << SNBSTFindKthNode(bst, 3) << endl;
	cout << "Diameter  " << SNBSTDiameter(bst) << endl;
	cout << "Identical " << (SNBSTIsTreeIdentical(bst, clone) ? "Yes" : "No") << endl;
	cout << "Identical " << (SNBSTIsTreeIdentical(bst, mirror) ? "Yes" : "No") << endl;
	cout << "Identical " << (SNBSTIsTreeIdentical(clone, mirror) ? "Yes" : "No") << endl; 
	cout << "Node Exists " << (SNBSTFindNode(bst, 22) ? "Yes" : "No") << endl; 
	cout << "IS BST " << (SNBSTIsBST(bst) ? "Yes" : "No") << endl;
	cout << "IS BST " << (SNBSTIsBSTVar2(mirror) ? "Yes" : "No") << endl;
	cout << "IS BST " << (SNBSTIsBST(mirror) ? "Yes" : "No") << endl;
	cout << "IS Height Balanced " << (SNBSTIsHeightBalanced(bst) ? "Yes" : "No") << endl;
	cout << "BST Min Value " << SNBSTMinValue(bst) << endl;
	cout << "BST Max Value " << SNBSTMaxValue(bst) << endl;

	SNBSTPrintNodesInRange(bst, 3, 8);
	SNBSTDeleteTree(&clone);
	SNBSTPrintTree(clone);
	//*/
	

	SNBSTPrintTree(bst);
	SNBSTDeleteNode(&bst, 5);
	SNBSTPrintTree(bst);
	return 1;
}