#ifndef __Node_H_
#define __Node_H_
#include "Customer.h"

typedef struct Node{
	Customer *customer;		// 손님 정보 
	struct Node *nxt;			// 현재 손님의 뒤에서 기다리는 손님의 주소겂
	struct Node *prv;			// 현재 손님의 앞에서 기다리는 손님의 주소값
}Node;

#endif
