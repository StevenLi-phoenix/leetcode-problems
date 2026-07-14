// @leetcode id=284 questionId=284 slug=peeking-iterator lang=cpp site=leetcode.com title="Peeking Iterator"
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	bool hasPeeked = false;
	int peeked = 0;

	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    if (!hasPeeked) {
	        peeked = Iterator::next();
	        hasPeeked = true;
	    }
	    return peeked;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (hasPeeked) {
	        hasPeeked = false;
	        return peeked;
	    }
	    return Iterator::next();
	}

	bool hasNext() const {
	    return hasPeeked || Iterator::hasNext();
	}
};
