// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description
// greedy + game theory:
// we can know that one player's score won't be affected by the other player's
// choice at each step namely, who will win is certain at the beginning
class Solution {
public:
  bool winnerOfGame(string colors) {
    int n = colors.length();
    // special case
    if (n < 3)
      return false;

    // score of alice & bob
    int alice = 0, bob = 0;

    // exclude the edges
    for (int i = 1; i < n - 1; i++) {
      char cur = colors[i];
      char prev = colors[i - 1];
      char post = colors[i + 1];

      // if there're 3 consecutive A's
      if (prev == 'A' && cur == 'A' && post == 'A')
        alice++;

      // if there're 3 consecutive A's
      if (prev == 'B' && cur == 'B' && post == 'B')
        bob++;
    }

    // if bob's score >= alice, bob win
    return alice > bob;
  }
};
