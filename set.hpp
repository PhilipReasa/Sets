#ifndef _SET_H_
#define _SET_H_

/*
* Abstract base class of the set
* A set has the following Properties:
* - Order doesn't matter
* - Duplicates are not allowed
*/
class Set {
protected:
	const int domainHigh; //ignore this
	const int domainLow;  //ignore this
	const int N;		  //just pay attention to this
public:
	//create a set. We will only use domain High. We will not use domain low
	Set(int domainHigh, int domainLow = 0)
	:domainHigh(domainHigh), domainLow(domainLow), N(domainHigh - domainLow)
	{}

	/*
	* insert an integer into the set
	* remember Sets do not allow duplicates
	* if the insert is successfull (the element is not already inserted), return true
	* else return false
	*/
	virtual bool insert(int) = 0;

	/*
	* remove an integer from the set
	* return true if anything was removed.
	* return false if the element was non existant (had not been inserted)
	*/
	virtual bool remove(int) = 0;

	/*
	* lookup to see if an element exists in the set
	* return true if the element has been inserted
	* else return false
	*/
	virtual bool lookup(int) = 0;

	/*
	* clear out all emenents in the set
	*/
	virtual void clear() = 0;

	/*
	* return the number of elements in the set
	*/
	virtual int size() = 0;
};

#endif
