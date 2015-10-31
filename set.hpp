#ifndef _SET_H_
#define _SET_H_

//abstract base class of the set
class Set {
protected:
	const int domainHigh;
	const int domainLow;
	const int N;
public:
	Set(int domainHigh, int domainLow = 0)
	:domainHigh(domainHigh), domainLow(domainLow), N(domainHigh - domainLow)
	{}

	virtual bool insert(int) = 0;
	virtual bool remove(int) = 0;
	virtual bool lookup(int) = 0;
	virtual void clear() = 0;
	virtual int size() = 0;
	//virtual void iterate(void) = 0;
};

#endif
