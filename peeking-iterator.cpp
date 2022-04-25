// https://leetcode.com/problems/peeking-iterator/
//
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
  int num;
  
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
    num = -1;    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
    if(num != -1) return num;  // if peek again
    num = Iterator::next();
    return num;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	  if(num != -1){  // already move to the next due to peek
      int t = num;
      num = -1;       // reset, as next&peek are the same state now
      return t;
    }
    return Iterator::next();
	}
	
	bool hasNext() const {
    // if num != -1, already go to next due to peek 
	  return (num != -1 || Iterator::hasNext());  
	}
};
