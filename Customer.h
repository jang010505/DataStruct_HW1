#ifndef __Customer_H_
#define __Customer_H_

typedef struct{		// �մ� ����ü 
	int number;			// �մ� ��ȣ 
	int time;			// ATM�� ��� �ð� 
	int vip;				// vip ���� vip�� �� 1, �ƴ� �� 0 
}Customer;

Customer CustomerInfoCopy(Customer *copy_ct);		// �մ������� �Է��ϴ� �Լ� 

#endif
