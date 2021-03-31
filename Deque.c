#include "Deque.h"

void InitDeque(Deque *dq){			// 덱의 초기값 설정 
	dq->atm = (ATM *)malloc(sizeof(ATM));
	InitATM(dq->atm);					// ATM기의 초기값 설정 
	dq->rear = dq->front = NULL; 
}

int IsEmpty(Deque *dq){ 
	return dq->atm->size == 0;			// size가 0이면 1 아니면 0 
}

void front_push(Deque *dq, Customer *ct){
	Node *NewNode = (Node *)malloc(sizeof(Node));		// 새로운 노드를 생성하고 동적할당 
	NewNode->customer = ct;		// 손님 정보 입력 
	if(IsEmpty(dq) == 1){		// 만약 줄에 아무도 없다면 
		dq->front = NewNode;
		dq->rear = NewNode;
		NewNode->nxt = NewNode->prv = NULL;
	}
	else{							// 아니라면 
		dq->front->prv = NewNode;
		NewNode->prv = NULL;
		NewNode->nxt = dq->front;
		dq->front = NewNode;
	}
	dq->atm->size++;
}

void rear_push(Deque *dq, Customer *ct){
	Node *NewNode = (Node *)malloc(sizeof(Node));		// 새로운 노드를 생성하고 동적할당 
	NewNode->customer = ct;				// 손님 정보 입력 
	if(IsEmpty(dq) == 1){				// 만약 줄에 아무도 없다면 
		dq->front = NewNode;
		dq->rear = NewNode;
		NewNode->nxt = NewNode->prv = NULL;
	}
	else{										// 아니라면 
		dq->rear->nxt = NewNode;
		NewNode->prv = dq->rear;
		NewNode->nxt = NULL;
		dq->rear = NewNode;
	}
	dq->atm->size++;
}

Customer front_pop(Deque *dq){
	Node *front = dq->front;										// 덱의 front 주소값 저장 
	Customer ct = CustomerInfoCopy(front->customer);		// 손님 정보 저장 
	if(dq->front->nxt == NULL)										// 덱의 요소가 하나하면 
		dq->rear = dq->front = NULL;
	else{																	// 아니라면 
		dq->front = dq->front->nxt;
		dq->front->prv = NULL;
	}
	dq->atm->size--;													// ATM의 사이즈 감소 
	free(front->customer);											// 손님 메모리 해제 
	free(front);														// 노드 메모리 해제 
	return ct;
}

Customer rear_pop(Deque *dq){
	Node *rear = dq->rear;										// 덱의 rear의 주소값 저장 
	Customer ct = CustomerInfoCopy(rear->customer);		// 손님 정보 저장 
	if(dq->rear->prv == NULL)									// 덱의 원소가 하나라면 
		dq->rear = dq->front = NULL;
	else{																// 아니라면 
		dq->rear = dq->rear->prv;
		dq->rear->nxt = NULL;
	}
	dq->atm->size--;												// 덱의 사이즈 감소 
	free(rear->customer);										// 손님 메모리 해제 
	free(rear);														// 노드 메모리 해제 
	return ct;
}

void DelNode(Deque *dq, Node *target){
	if(dq->front == target && dq->rear == target){		// 덱의 요소가 하나라면 
		dq->front = NULL;
		dq->rear = NULL;
	}
	else if(dq->front == target){								// 덱의 제일 앞 요소라면 
		target->nxt->prv = NULL;
		dq->front = target->nxt;
		target->nxt = NULL;
	}
	else if(dq->rear == target){								// 덱의 제일 뒤 요소라면 
		target->prv->nxt = NULL;
		dq->rear = target->prv;
		target->prv = NULL;
	}
	else{																// 앞 뒤로 노드가 존재한다면 
		target->nxt->prv = target->prv;
		target->prv->nxt = target->nxt;
		target->nxt = NULL;
		target->prv = NULL;
	}
	free(target->customer);										// 손님 메모리 해제 
	free(target);													// 노드 메모리 해제 
	dq->atm->size--;												// 덱 사이즈 감소 
}
