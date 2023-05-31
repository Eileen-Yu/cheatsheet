// https://leetcode.com/problems/design-underground-system/
// 1. create a new struct to store info

// info only records the in & out info, don't care user id
struct Info {
  string from;
  string to;
  int in;
  int out;
};

class UndergroundSystem {
public:
  // maps specific user id with certain info
  // key: id, value: info
  map<int, Info> mp;

  // key: {from, to}, value: [period1, period2,...]
  map<pair<string, string>, vector<int>> record;

  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    // new instance
    Info i;
    // update info
    i.from = stationName;
    i.in = t;
    // map user with info
    mp[id] = i;
  }

  void checkOut(int id, string stationName, int t) {
    // get the corresponding info by user id
    Info i = mp[id];
    // update info
    i.to = stationName;
    i.out = t;

    // update record as this is a new sample
    record[{i.from, i.to}].push_back(i.out - i.in);
  }

  double getAverageTime(string startStation, string endStation) {
    // get periods vector of this certain {from, to}
    auto &period = record[{startStation, endStation}];
    // add up all samples
    int sum = accumulate(period.begin(), period.end(), 0);
    int n = period.size();
    return (double)sum / n;
  }
};

// 2. use hash table + map to store info
class UndergroundSystem {
public:
  // hash table:
  // idx: user id
  // pair: station, timepoint
  vector<pair<string, int>> record;
  // key:from-to, value:[period1, period2,...]
  map<string, vector<int>> mp;

  UndergroundSystem() { record.resize(1e6); }

  void checkIn(int id, string stationName, int t) {
    record[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    string info = record[id].first + "-" + stationName;
    int period = t - record[id].second;
    mp[info].push_back(period);
  }

  double getAverageTime(string startStation, string endStation) {
    string info = startStation + "-" + endStation;
    int sum = 0;
    int count = 0;
    for (auto i : mp[info]) {
      sum += i;
      count++;
    }

    return (double)sum / count;
  }
};
