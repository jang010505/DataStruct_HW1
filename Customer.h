#ifndef __Customer_H_
#define __Customer_H_

typedef struct{		// 손님 구조체 
	int number;			// 손님 번호 
	int time;			// ATM기 사용 시간 
	int vip;				// vip 여부 vip일 시 1, 아닐 시 0 
}Customer;

Customer CustomerInfoCopy(Customer *copy_ct);		// 손님정보를 입력하는 함수 

#endif
