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
		
	int H = 9, M = 0;  				// H : 시, M : 분 
	int use_time[3] = {0, };		// ATM기 남은 사용 시간 
	
	while(H != 11 || M != 0){	// 11시 0분이면 반복문 STOP 
		int size_list[3] = {dq[0].atm->size, dq[1].atm->size, dq[2].atm->size};	// 덱의 사이즈 == 줄의 길이 
		for(int i = 0; i < 3; i++)
			if(use_time[i] > 0)
				size_list[i]++;		// 만약 n번 ATM기를 사용 중이라면 줄 길이 1증가 
		int order = ATMorder(size_list[0], size_list[1], size_list[2]);	// 몇 번 ATM기 줄에 설 지 결정 
		
		int vip = (rand() % 10 == 0 ? 1 : 0);		// vip 여부 : 0 ~ 9 중 0이면 VIP 
		int time = rand() % 9 + 2;						// 이용 시간 : 0 ~ 8 중 난수 발생 후 2 증기 -> 2 ~ 10 난수 발생 
		Customer *ct = (Customer *)malloc(sizeof(Customer));
		
		ct->number = M;
		ct->time = time;
		ct->vip = vip;
		
		if(vip == 1)		// 만약 VIP이면 덱의 제일 앞에 삽입 
			front_push(&dq[order], ct);
		else					// VIP가 아니라면 덱의 제일 뒤에 삽입 
			rear_push(&dq[order], ct);
		
		// printf("%d %d : %d\n", H, M, dq[0].atm->size + dq[1].atm->size + dq[2].atm->size);
		
		for(int i = 0; i < ATM_SIZE; i++){
			if(IsEmpty(&dq[i]) == 0){		// 만약 i번 ATM기에 줄이 있다면 
				if(use_time[i] == 0){	// 만약 i번 ATM기가 사용 중이지 않다면 
					Customer tmp = front_pop(&dq[i]);	//	고객 추출 
					if(tmp.vip)			// vip 여부 출력 
						printf("VIP ");				
					printf("%d시 %d분 - %d번 고객(%d분 소요)이 %d번 ATM에서 서비스를 시작함\n\n", H, M, tmp.number, tmp.time, i + 1);
					use_time[i] = tmp.time;	// i번 ATM기 사용시간 업데이트 
					dq[i].atm->use_customer++;
				}
			}
			
			if(use_time[i] > 0){			// i번 ATM기가 사용 중이라면 
				use_time[i]--;				// 사용 시간 감소 
				dq[i].atm->waiting_time += dq[i].atm->size;	// i번 ATM기 줄 길이만큼 증가 
			}
		}
		
		
		M++;			// 1분 증가 
		H += M/60;	// 만약 60분이면 1시간 증가 아니라면 0증가 
		M %= 60;		// M이 60이면 0으로 바꿈 
		if(M%10 == 0 && H != 11){	// 만약 10분이고 11시 정각이 아니면 
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
