#define STRESS_REPS 1000000
#define DOMAIN_MAX  5000000
#include "evaluate.hpp"

int main() {
	cout << "Evaluate List(1), Map(2), or Optimal(3)? " << endl;
	int method;
	cin >> method;

	Set* set;
	if(method == 1) {
		set = new Set_List(DOMAIN_MAX);
	} else if(method == 2) {
		set = new Set_Map(DOMAIN_MAX);
	} else {
		set = new Set_Opt(DOMAIN_MAX);
	}

	auto start = get_time::now();
	stress(set);
	auto end = get_time::now();
	auto diff = end - start;
	cout<<"Elapsed time is :  "<< chrono::duration_cast<ns>(diff).count()<<" ms "<<endl;
	return 0;
}

void stress(Set* set) {
	cout << "inserting" << endl;
	for(int i = 0; i < STRESS_REPS; i ++) {
		set->insert(i);
	}

	cout << "removing" << endl;
	for(int i = 0; i < (STRESS_REPS/2); i += 2) {
		set->remove(i);
	}

	cout << "looking-up" << endl;
	for(int i = 1; i < (STRESS_REPS/2); i += 2) {
		if(!set->lookup(i)) {
			cout << "error lookup failed: " << i << endl;
			break;
		}
	} 

	cout << "clearing" <<endl;
	set->clear();
}