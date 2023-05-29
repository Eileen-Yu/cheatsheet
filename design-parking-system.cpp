// https://leetcode.com/problems/design-parking-system/description/
// map to record

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
