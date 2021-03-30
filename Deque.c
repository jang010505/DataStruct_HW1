#include "Deque.h"

void InitDeque(Deque *dq){			// 덱의 초기값 설정 
	dq->atm = (ATM *)malloc(sizeof(ATM));
	InitATM(dq->atm);					// ATM기의 초기값 설정 
	dq->rear = dq->front = NULL;
}

int IsEmpty(Deque *dq){ 
	return dq->atm->size == 0;
}

void front_push(Deque *dq, Customer ct){
	Node *NewNode = (Node *)malloc(sizeof(Node));		// 새로운 노드를 생성하고 동적할당 
	NewNode->customer = (Customer *)malloc(sizeof(Customer));	// 그 노드에 손님 정보 동적할당 
	NewNode->customer = ct;		// 손님 정보 입력 
	if(IsEmpty(dq) == 1){
		dq->front = NewNode;
		dq->rear = NewNode;
		NewNode->nxt = NewNode->prv = NULL;
	}
	else{
		dq->front->prv = NewNode;
		NewNode->prv = NULL;
		NewNode->nxt = dq->front;
		dq->front = NewNode;
	}
	dq->atm->size++;
}

void rear_push(Deque *dq, Customer ct){
	Node *NewNode = (Node *)malloc(sizeof(Node));
	NewNode->customer = (Customer *)malloc(sizeof(Customer));
	NewNode->customer = ct;
	if(IsEmpty(dq) == 1){
		dq->front = NewNode;
		dq->rear = NewNode;
		NewNode->nxt = NewNode->prv = NULL;
	}
	else{
		dq->rear->nxt = NewNode;
		NewNode->prv = dq->rear;
		NewNode->nxt = NULL;
		dq->rear = NewNode;
	}
	dq->atm->size++;
}

Customer front_pop(Deque *dq){
	Node *front = dq->front;
	Customer ct = front->customer;
	if(dq->front->nxt == NULL)
		dq->rear = dq->front = NULL;
	else{
		dq->front = dq->front->nxt;
		dq->front->prv = NULL;
	}
	dq->atm->size--;
	free(front->customer);
	free(front);
	return ct;
}

Customer rear_pop(Deque *dq){
	Node *rear = dq->rear;
	Customer ct = rear->customer;
	if(dq->rear->prv == NULL)
		dq->rear = dq->front = NULL;
	else{
		dq->rear = dq->rear->prv;
		dq->rear->nxt = NULL;
	}
	dq->atm->size--;
	free(rear->customer);
	free(rear);
	return ct;
}

void DelNode(Deque *dq, Node *target){
	if(dq->front == target && dq->rear == target){
		dq->front = NULL;
		dq->rear = NULL;
	}
	else if(dq->front == target){
		target->nxt->prv = NULL;
		dq->front = target->nxt;
		target->nxt = NULL;
	}
	else if(dq->rear == target){
		target->prv->nxt = NULL;
		dq->rear = target->prv;
		target->prv = NULL;
	}
	else{
		target->nxt->prv = target->prv;
		target->prv->nxt = target->nxt;
		target->nxt = NULL;
		target->prv = NULL;
	}
	free(target->customer);
	free(target);
	dq->atm->size--;
}
