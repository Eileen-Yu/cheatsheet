// https://leetcode.com/problems/design-underground-system/
//
struct info {
  string from;
  string to;
  int in;
  int out;
};

class UndergroundSystem {
public:
  // from-to station : duration time
  map<pair<string, string>, vector<int>> loc;
  // id : info
  map<int, info> p;

  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    info i;
    i.from = stationName;
    i.in = t;
    p[id] = i;
  }

  void checkOut(int id, string stationName, int t) {
    info i = p[id];
    i.to = stationName;
    i.out = t;
    loc[{i.from, i.to}].push_back(i.out - i.in);
  }

  double getAverageTime(string startStation, string endStation) {
    auto &time = loc[{startStation, endStation}]; // vector
    double size = time.size();
    return accumulate(time.begin(), time.end(), 0) / size;
  }
};
