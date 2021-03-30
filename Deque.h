#ifndef __Deque_H_
#define __Deque_H_

typedef struct{
	ATM *atm;			// ATM���� ���� 
	Node *front;		// ATM���� ���� �տ� �� �մ��� �ּҰ� 
	Node *rear;			// ATM���� ���� �ڿ� �� �մ��� �ּҰ� 
}Deque;

void InitDeque(Deque *dq);						// ���� �ʱⰪ�� �����ϴ� �Լ� 
int IsEmpty(Deque *dq);							// ���� ������� Ȯ���ϴ� �Լ� 
void front_push(Deque *dq, Customer ct);	// ���� �տ� ��Ҹ� �ִ� �Լ� 
void rear_push(Deque *dq, Customer ct);	// ���� �ڿ� ��Ҹ� �ִ� �Լ� 
Customer front_pop(Deque *dq);				// ���� �տ� ��Ҹ� ��ȯ�ϰ� �����ϴ� �Լ� 
Customer rear_pop(Deque *dq);					// ���� �ڿ� ��Ҹ� ��ȯ�ϰ� �����ϴ� �Լ� 

#endif
