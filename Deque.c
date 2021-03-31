#include "Deque.h"

void InitDeque(Deque *dq){			// ���� �ʱⰪ ���� 
	dq->atm = (ATM *)malloc(sizeof(ATM));
	InitATM(dq->atm);					// ATM���� �ʱⰪ ���� 
	dq->rear = dq->front = NULL; 
}

int IsEmpty(Deque *dq){ 
	return dq->atm->size == 0;			// size�� 0�̸� 1 �ƴϸ� 0 
}

void front_push(Deque *dq, Customer *ct){
	Node *NewNode = (Node *)malloc(sizeof(Node));		// ���ο� ��带 �����ϰ� �����Ҵ� 
	NewNode->customer = ct;		// �մ� ���� �Է� 
	if(IsEmpty(dq) == 1){		// ���� �ٿ� �ƹ��� ���ٸ� 
		dq->front = NewNode;
		dq->rear = NewNode;
		NewNode->nxt = NewNode->prv = NULL;
	}
	else{							// �ƴ϶�� 
		dq->front->prv = NewNode;
		NewNode->prv = NULL;
		NewNode->nxt = dq->front;
		dq->front = NewNode;
	}
	dq->atm->size++;
}

void rear_push(Deque *dq, Customer *ct){
	Node *NewNode = (Node *)malloc(sizeof(Node));		// ���ο� ��带 �����ϰ� �����Ҵ� 
	NewNode->customer = ct;				// �մ� ���� �Է� 
	if(IsEmpty(dq) == 1){				// ���� �ٿ� �ƹ��� ���ٸ� 
		dq->front = NewNode;
		dq->rear = NewNode;
		NewNode->nxt = NewNode->prv = NULL;
	}
	else{										// �ƴ϶�� 
		dq->rear->nxt = NewNode;
		NewNode->prv = dq->rear;
		NewNode->nxt = NULL;
		dq->rear = NewNode;
	}
	dq->atm->size++;
}

Customer front_pop(Deque *dq){
	Node *front = dq->front;										// ���� front �ּҰ� ���� 
	Customer ct = CustomerInfoCopy(front->customer);		// �մ� ���� ���� 
	if(dq->front->nxt == NULL)										// ���� ��Ұ� �ϳ��ϸ� 
		dq->rear = dq->front = NULL;
	else{																	// �ƴ϶�� 
		dq->front = dq->front->nxt;
		dq->front->prv = NULL;
	}
	dq->atm->size--;													// ATM�� ������ ���� 
	free(front->customer);											// �մ� �޸� ���� 
	free(front);														// ��� �޸� ���� 
	return ct;
}

Customer rear_pop(Deque *dq){
	Node *rear = dq->rear;										// ���� rear�� �ּҰ� ���� 
	Customer ct = CustomerInfoCopy(rear->customer);		// �մ� ���� ���� 
	if(dq->rear->prv == NULL)									// ���� ���Ұ� �ϳ���� 
		dq->rear = dq->front = NULL;
	else{																// �ƴ϶�� 
		dq->rear = dq->rear->prv;
		dq->rear->nxt = NULL;
	}
	dq->atm->size--;												// ���� ������ ���� 
	free(rear->customer);										// �մ� �޸� ���� 
	free(rear);														// ��� �޸� ���� 
	return ct;
}

void DelNode(Deque *dq, Node *target){
	if(dq->front == target && dq->rear == target){		// ���� ��Ұ� �ϳ���� 
		dq->front = NULL;
		dq->rear = NULL;
	}
	else if(dq->front == target){								// ���� ���� �� ��Ҷ�� 
		target->nxt->prv = NULL;
		dq->front = target->nxt;
		target->nxt = NULL;
	}
	else if(dq->rear == target){								// ���� ���� �� ��Ҷ�� 
		target->prv->nxt = NULL;
		dq->rear = target->prv;
		target->prv = NULL;
	}
	else{																// �� �ڷ� ��尡 �����Ѵٸ� 
		target->nxt->prv = target->prv;
		target->prv->nxt = target->nxt;
		target->nxt = NULL;
		target->prv = NULL;
	}
	free(target->customer);										// �մ� �޸� ���� 
	free(target);													// ��� �޸� ���� 
	dq->atm->size--;												// �� ������ ���� 
}
