#include "set.hpp"

class Set_Opt: public Set {
private:
	int* map;
	int* list;
	int count;

public:
	//O(1)
	Set_Opt(int domainHigh, int domainLow = 0)
	:Set(domainHigh, domainLow), count(0) {
		map = new int[N];
		list = new int[N];
	}

	//O(1)
	~Set_Opt() {
		delete[] map;
		delete[] list;
	}

	//O(1)
	bool insert(int val) {
		if(!lookup(val)) {
			list[count] = val;
			map[val] = count;
			count ++;
			return true;
		}
		return false;
	}

	//O(1)
	bool remove(int val) {
		if(lookup(val)) {
			list[map[val]] = list[count - 1];
			map[list[count - 1]] = map[val];
			count --;
			return true;
		}
		return false;
	}

	//O(1)
	bool lookup(int val) {
		return (
			map[val] < count
			&& map[val] <= domainHigh
			&& map[val] >= domainLow
			&& list[map[val]] == val
		);
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