// https://leetcode.com/problems/seat-reservation-manager
// 1. hash table to mark if a seat has been reserved, would TLE in some cases
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
