#include "set.hpp"

class Set_Map: public Set {
private:
	bool* map;
	int count;

public:
	//O(1)
	Set_Map(int domainHigh, int domainLow = 0)
	:Set(domainHigh, domainLow), count(0) {
		map = new bool[N];
	}

	//O(1)
	~Set_Map() {
		delete map;
	}

	//O(1)
	bool insert(int val) {
		bool exists=map[val];
		if(!exists) {
			count ++;
		}
		map[val] = true;
		return !exists;
	}

	//O(1)
	bool remove(int val) {
		bool exists=map[val];
		if(exists) {
			count --;
		}
		map[val] = false;
		return exists;
	}

	//O(1)
	bool lookup(int val) {
		return map[val];
	}

	//O(n)
	void clear() {
		for(int i = 0; i < N; i ++) {
			map[i] = false;
		}
		count = 0;
	}

	//O(1)
	int size() {
		return count;
	}
};