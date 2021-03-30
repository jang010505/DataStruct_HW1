#ifndef __Deque_H_
#define __Deque_H_

typedef struct{
	ATM *atm;			// ATM기의 정보 
	Node *front;		// ATM기의 제일 앞에 선 손님의 주소값 
	Node *rear;			// ATM기의 제일 뒤에 선 손님의 주소값 
}Deque;

void InitDeque(Deque *dq);						// 덱의 초기값을 설정하는 함수 
int IsEmpty(Deque *dq);							// 덱이 비었는지 확인하는 함수 
void front_push(Deque *dq, Customer ct);	// 덱의 앞에 요소를 넣는 함수 
void rear_push(Deque *dq, Customer ct);	// 덱의 뒤에 요소를 넣는 함수 
Customer front_pop(Deque *dq);				// 덱의 앞에 요소를 반환하고 삭제하는 함수 
Customer rear_pop(Deque *dq);					// 덱의 뒤에 요소를 반환하고 삭제하는 함수 

#endif
