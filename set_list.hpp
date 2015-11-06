#include "set.hpp"

class Set_List: public Set {
private:
	int* list;
	int count;

public:
	//O(1)
	Set_List(int domainHigh, int domainLow = 0)
	:Set(domainHigh, domainLow), count(0) {
		list = new int[N];
	}

	//O(1)
	~Set_List() {
		delete[] list;
	}

	//O(count)
	bool insert(int val) {
		if(!lookup(val)) {
			list[count++] = val;
			return true;
		}
		return false;
	}

	//O(count)
	bool remove(int val) {
		for(int i = 0; i < count; i ++) {
			if(list[i] == val) {
				list[i] = list[--count];
				return true;
			}
		}
		return false;
	}

	//O(count)
	bool lookup(int val) {
		for(int i = 0; i < count; i ++) {
			if(list[i] == val) {
				return true;
			}
		}
		return false;
	}

	//O(1)
	void clear() {
		count = 0;
	}

	//O(1)
	int size() {
		return count;
	}
};