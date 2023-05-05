// https://leetcode.com/problems/dota2-senate/description/
// math: use +/- a variable to record the state

class Solution {
public:
  string predictPartyVictory(string senate) {
    // record whether D/R is more powerful
    int score = 0;
    for (int i = 0; i < senate.length(); i++) {
      char tmp = senate[i];
      if (tmp == 'R') {
        // this means this R should be banned actually, but we still increase
        // the score
        if (score < 0)
          // so we need to compensate a D for it
          senate += 'D';
        // should follow this order, otherwise it may fall to 0, missing the
        // compensation
        score++;
      }

      // if D
      else {
        // this D should have been banned
        if (score > 0)
          // compensate a R to balance
          senate += 'R';

        score--;
      }
    }

    return score > 0 ? "Radiant" : "Dire";
  }
};
