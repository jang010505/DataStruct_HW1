#ifndef __ATM_H_
#define __ATM_H_

typedef struct{
	int size;				// ATM기의 줄의 길이 
	int leaveCustomer;	// ATM기를 떠난 손님의 수 
	int waiting_time;		// 기다린 시간의 총합 
	int use_customer;		// ATM기를 사용한 손님의 수 
}ATM;

void InitATM(ATM *atm);	// ATM기 초기값 설정 

#endif
