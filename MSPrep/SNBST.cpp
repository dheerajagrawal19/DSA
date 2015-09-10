#include  "SNBST.h"

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

int SNBSTSize(SNBSTP head) {
	if (head == NULL) return 0;

	return 1 + SNBSTSize(head->left) + SNBSTSize(head->right);
}

int SNBSTDepth(SNBSTP head) {
	if (head == NULL) return 0;
	return max((1 + SNBSTDepth(head->left)), (1 + SNBSTDepth(head->right)));
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
		SNBSTP tempSucc = SNBSTSuccessor(temp);
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

	}
}

bool SNBSTIsBSTVar2(SNBSTP head) {
	if (head == NULL) return true;

	int prev = INT_MIN;

	return SNBSTIsBSTVar2Helper(head, &prev);
}

int SNBSTMainFunction() {
	SNBSTP bst = NULL;
	SNBSTInsertNode(&bst, 5);
	SNBSTInsertNode(&bst, 2);
	SNBSTInsertNode(&bst, 3);
	SNBSTInsertNode(&bst, 8);
	SNBSTInsertNode(&bst, 7);
	
///*	cloning and mirror stuff....
	SNBSTP clone = SNBSTCloneTree(bst);
	SNBSTP mirror = SNBSTCreateMirrorTree(bst);
	SNBSTPrintTree(clone);
	SNBSTPrintTree(mirror);
	SNBSTMirrorTree(clone);
	SNBSTPrintTree(clone);
	cout << "Identical " << (SNBSTIsTreeIdentical(bst, clone) ? "Yes" : "No") << endl;
	cout << "Identical " << (SNBSTIsTreeIdentical(bst, mirror) ? "Yes" : "No") << endl;
	cout << "Identical " << (SNBSTIsTreeIdentical(clone, mirror) ? "Yes" : "No") << endl; 
	cout << "Node Exists " << (SNBSTFindNode(bst, 22) ? "Yes" : "No") << endl; 
	cout << "IS BST " << (SNBSTIsBST(bst) ? "Yes" : "No") << endl;
	cout << "IS BST " << (SNBSTIsBST(mirror) ? "Yes" : "No") << endl;
	
	SNBSTDeleteTree(&clone);
	SNBSTPrintTree(clone);
	//*/
	

	SNBSTPrintTree(bst);
	SNBSTDeleteNode(&bst, 5);
	SNBSTPrintTree(bst);
	return 1;
}