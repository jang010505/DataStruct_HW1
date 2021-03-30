#include "Function.h"

int is_prime(int x){								// 소수 판정 함수 
	if(x == 0 || x == 1)
		return 0;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return 0;
	return 1;
}

int min(int x, int y, int z){					// 세 정수의 최솟값 함수 
	if(x <= y && x <= z)
		return x;
	else if(y <= x && y <= z)
		return y;
	else
		return z;
}

int ATMorder(int size1, int size2, int size3){	// 가장 짧은 줄에 랜덤하게 배치하는 함수. 
	int check_list[3] = {0, }, size_list[3] = {size1, size2, size3};
	int min_size = min(size1, size2, size3);		// 가장 짧은 줄의 길이 
	for(int i = 0; i < 3; i++)
		if(min_size == size_list[i])
			check_list[i] = 1;							// 가장 짧은 줄이면 1로 ㅍ체크 
	if(check_list[0] == 1 && check_list[1] == 1 && check_list[2] == 1)	// 모든 줄이 가장 짧은 줄 
		return rand() % 3;
	else if(check_list[0] == 1 && check_list[1] == 1){		// 1번 ATM 2번 ATM 일 때 
		int tmp = rand() % 2;
		if(tmp)
			return 1;
		else
			return 0;
	}
	else if(check_list[0] == 1 && check_list[2] == 1){		// 1번 ATM 3번 ATM 일 때 
		int tmp = rand() % 2;
		if(tmp)
			return 2;
		else
			return 0;
	}
	else if(check_list[1] == 1 && check_list[2] == 1){		// 2번 ATM 3번 ATM 일 때 
		int tmp = rand() % 2;
		if(tmp)
			return 2;
		else
			return 1;
	}
	else							// 가장 짧은 줄이 한 개 일 때 
		for(int i = 0; i < 3; i++)
			if(min_size == size_list[i])						 
				return i;
}
