#ifndef __ATM_H_
#define __ATM_H_

typedef struct{
	int size;				// ATM���� ���� ���� 
	int leaveCustomer;	// ATM�⸦ ���� �մ��� �� 
	int waiting_time;		// ��ٸ� �ð��� ���� 
	int use_customer;		// ATM�⸦ ����� �մ��� �� 
}ATM;

void InitATM(ATM *atm);	// ATM�� �ʱⰪ ���� 

#endif
