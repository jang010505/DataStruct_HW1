#ifndef __Node_H_
#define __Node_H_
#include "Customer.h"

typedef struct Node{
	Customer *customer;		// �մ� ���� 
	struct Node *nxt;			// ���� �մ��� �ڿ��� ��ٸ��� �մ��� �ּҁ�
	struct Node *prv;			// ���� �մ��� �տ��� ��ٸ��� �մ��� �ּҰ�
}Node;

#endif
