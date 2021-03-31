#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ATM.h"
#include "Deque.h"
#include "Customer.h"
#include "Node.h"
#include "Function.h"
#define ATM_SIZE 3

int main(){
	srand(time(NULL));
	Deque *dq = (Deque *)malloc(sizeof(Deque) * ATM_SIZE);
	for(int i=0;i<ATM_SIZE;i++)
		InitDeque(&dq[i]);
		
	int H = 9, M = 0;  				// H : ��, M : �� 
	int use_time[3] = {0, };		// ATM�� ���� ��� �ð� 
	
	while(H != 11 || M != 0){	// 11�� 0���̸� �ݺ��� STOP 
		int size_list[3] = {dq[0].atm->size, dq[1].atm->size, dq[2].atm->size};	// ���� ������ == ���� ���� 
		for(int i = 0; i < 3; i++)
			if(use_time[i] > 0)
				size_list[i]++;		// ���� n�� ATM�⸦ ��� ���̶�� �� ���� 1���� 
		int order = ATMorder(size_list[0], size_list[1], size_list[2]);	// �� �� ATM�� �ٿ� �� �� ���� 
		
		int vip = (rand() % 10 == 0 ? 1 : 0);		// vip ���� : 0 ~ 9 �� 0�̸� VIP 
		int time = rand() % 9 + 2;						// �̿� �ð� : 0 ~ 8 �� ���� �߻� �� 2 ���� -> 2 ~ 10 ���� �߻� 
		Customer *ct = (Customer *)malloc(sizeof(Customer));
		
		ct->number = M;
		ct->time = time;
		ct->vip = vip;
		
		if(vip == 1)		// ���� VIP�̸� ���� ���� �տ� ���� 
			front_push(&dq[order], ct);
		else					// VIP�� �ƴ϶�� ���� ���� �ڿ� ���� 
			rear_push(&dq[order], ct);
		
		// printf("%d %d : %d\n", H, M, dq[0].atm->size + dq[1].atm->size + dq[2].atm->size);
		
		for(int i = 0; i < ATM_SIZE; i++){
			if(IsEmpty(&dq[i]) == 0){		// ���� i�� ATM�⿡ ���� �ִٸ� 
				if(use_time[i] == 0){	// ���� i�� ATM�Ⱑ ��� ������ �ʴٸ� 
					Customer tmp = front_pop(&dq[i]);	//	�� ���� 
					if(tmp.vip)			// vip ���� ��� 
						printf("VIP ");				
					printf("%d�� %d�� - %d�� ��(%d�� �ҿ�)�� %d�� ATM���� ���񽺸� ������\n\n", H, M, tmp.number, tmp.time, i + 1);
					use_time[i] = tmp.time;	// i�� ATM�� ���ð� ������Ʈ 
					dq[i].atm->use_customer++;
				}
			}
			
			if(use_time[i] > 0){			// i�� ATM�Ⱑ ��� ���̶�� 
				use_time[i]--;				// ��� �ð� ���� 
				dq[i].atm->waiting_time += dq[i].atm->size;	// i�� ATM�� �� ���̸�ŭ ���� 
			}
		}
		
		
		M++;			// 1�� ���� 
		H += M/60;	// ���� 60���̸� 1�ð� ���� �ƴ϶�� 0���� 
		M %= 60;		// M�� 60�̸� 0���� �ٲ� 
		if(M%10 == 0 && H != 11){	// ���� 10���̰� 11�� ������ �ƴϸ� 
			for(int i = 0; i < ATM_SIZE; i++){
				Node *NowNode = dq[i].front;
				Node *TmpNode;
				while(NowNode != NULL){
					TmpNode = NowNode->nxt;
					if(is_prime(NowNode->customer->number)){
						DelNode(&dq[i], NowNode);
						dq[i].atm->leaveCustomer++;
					}
					NowNode = TmpNode;
				}
			}
		}
	}
}
