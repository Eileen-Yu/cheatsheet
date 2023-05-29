// https://leetcode.com/problems/design-parking-system/description/
// 1. hash table
class ParkingSystem {
public:
  // hash table:
  // idx: type-1, value: number
  vector<int> vehicle;

  ParkingSystem(int big, int medium, int small) {
    vehicle = {big, medium, small};
  }
  // first check if vehicle[carType] > 0, then --
  bool addCar(int carType) { return vehicle[carType - 1]-- > 0; }
};

// 2. map to record
class ParkingSystem {
public:
  // kind: number
  map<int, int> mp;

  ParkingSystem(int big, int medium, int small) {
    if (!big)
      mp[1] = 0;
    else
      mp[1] = big;

    if (!medium)
      mp[2] = 0;
    else
      mp[2] = medium;

    if (!small)
      mp[3] = 0;
    else
      mp[3] = small;
  }

  bool addCar(int carType) {
    if (mp[carType] != 0) {
      mp[carType]--;
      return true;
    }

    else
      return false;
  }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
