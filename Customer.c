#include "Customer.h"

Customer CustomerInfoCopy(Customer *copy_ct){
	Customer ct;
	ct.number = copy_ct->number;
	ct.time = copy_ct->time;
	ct.vip = copy_ct->vip;
	return ct;
}
