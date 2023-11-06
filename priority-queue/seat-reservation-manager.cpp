// https://leetcode.com/problems/seat-reservation-manager
// always try to reserve the smallest seat --> priority queue
// 1. pq optimized version
class SeatManager {
public:
  // track the final reserved seat of a contiguous reserved seats
  int last;
  // track the unreserved seats, sort from small to big
  priority_queue<int, vector<int>, greater<int>> pq;

  SeatManager(int n) {
    // init vars
    // seat start from the 1
    last = 0;
    pq = priority_queue<int, vector<int>, greater<int>>();
  }

  int reserve() {
    // if there's no candidiate in pq(those have been unreserved)
    // directly continue to reserve the next one
    if (pq.empty()) {
      // increase the idx of the final reserved seat
      last++;
      return last;
    }

    // else, try to reserve the smallest in pq
    int ans = pq.top();
    pq.pop();
    return ans;
  }

  void unreserve(int seatNumber) {
    // if unreserve the last seat
    if (seatNumber == last) {
      // reduce the last reserved idx
      last--;
    }

    // else push this into pq
    else
      pq.push(seatNumber);
  }
};

// 2. pq plain version
class SeatManager {
public:
  // put small elements first
  priority_queue<int, vector<int>, greater<int>> pq;

  SeatManager(int n) {
    // push each seat into pq
    for (int i = 1; i <= n; i++)
      pq.push(i);
  }

  int reserve() {
    // each time return the smallest item
    int ans = pq.top();
    pq.pop();
    return ans;
  }

  void unreserve(int seatNumber) { pq.push(seatNumber); }
};

// 2. hash table to mark if a seat has been reserved, would TLE in some cases
class SeatManager {
public:
  // seats[i] mark if the i-th seat has been reserved
  vector<bool> seats;

  SeatManager(int n) {
    // range: [1,n], 0 is the base case
    seats.resize(n + 1, false);
  }

  int reserve() {
    for (int i = 1; i < seats.size(); i++) {
      if (seats[i])
        continue;

      // else
      seats[i] = true;
      return i;
    }

    return -1;
  }

  void unreserve(int seatNumber) { seats[seatNumber] = false; }
};
