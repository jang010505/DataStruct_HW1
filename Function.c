#include "Function.h"

int is_prime(int x){								// �Ҽ� ���� �Լ� 
	if(x == 0 || x == 1)
		return 0;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return 0;
	return 1;
}

int min(int x, int y, int z){					// �� ������ �ּڰ� �Լ� 
	if(x <= y && x <= z)
		return x;
	else if(y <= x && y <= z)
		return y;
	else
		return z;
}

int ATMorder(int size1, int size2, int size3){	// ���� ª�� �ٿ� �����ϰ� ��ġ�ϴ� �Լ�. 
	int check_list[3] = {0, }, size_list[3] = {size1, size2, size3};
	int min_size = min(size1, size2, size3);		// ���� ª�� ���� ���� 
	for(int i = 0; i < 3; i++)
		if(min_size == size_list[i])
			check_list[i] = 1;							// ���� ª�� ���̸� 1�� ��üũ 
	if(check_list[0] == 1 && check_list[1] == 1 && check_list[2] == 1)	// ��� ���� ���� ª�� �� 
		return rand() % 3;
	else if(check_list[0] == 1 && check_list[1] == 1){		// 1�� ATM 2�� ATM �� �� 
		int tmp = rand() % 2;
		if(tmp)
			return 1;
		else
			return 0;
	}
	else if(check_list[0] == 1 && check_list[2] == 1){		// 1�� ATM 3�� ATM �� �� 
		int tmp = rand() % 2;
		if(tmp)
			return 2;
		else
			return 0;
	}
	else if(check_list[1] == 1 && check_list[2] == 1){		// 2�� ATM 3�� ATM �� �� 
		int tmp = rand() % 2;
		if(tmp)
			return 2;
		else
			return 1;
	}
	else							// ���� ª�� ���� �� �� �� �� 
		for(int i = 0; i < 3; i++)
			if(min_size == size_list[i])						 
				return i;
}
