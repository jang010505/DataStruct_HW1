#include "ATM.h"

void InitATM(ATM *atm){
	atm->size = 0;
	atm->leaveCustomer = 0;
	atm->waiting_time = 0;
	atm->use_customer = 0;
}
