#include <iostream>
#include <string>

using namespace std;

int *pre_kmp(string pattern) {
  int size = pattern.size();
  int *pie = new int[size];
  pie[0] = 0;
  int k = 0;
  for (int i = 1; i < size; i++) {
    cout << "k before: " << k << "; ";
    cout << "pattern[k]: " << pattern[k] << "; ";
    cout << "i: " << i << "; ";
    cout << "pattern[i]: " << pattern[i] << "; ";

    while (k > 0 && pattern[k] != pattern[i]) {
      k = pie[k - 1];
    }
    if (pattern[k] == pattern[i]) {
      k = k + 1;
    }

    cout << "k after: " << k << "\n";

    pie[i] = k;
  }

  return pie;
}

void displayPre(int size, int *p) {
  for (int i = 0; i < size; i++) {
    cout << p[i] << " ";
  }
  cout << "\n";
}

void kmp(string text, string pattern) {
  int *pie = pre_kmp(pattern);

  displayPre(pattern.length(), pie);

  int matched_pos = 0;
  for (int current = 0; current < text.length(); current++) {

    while (matched_pos > 0 && pattern[matched_pos] != text[current])
      matched_pos = pie[matched_pos - 1];

    if (pattern[matched_pos] == text[current])
      matched_pos = matched_pos + 1;

    if (matched_pos == (pattern.length())) {
      cout << "Pattern occurs with shift " << current - (pattern.length() - 1)
           << "\n";
      matched_pos = pie[matched_pos - 1];
    }
  }
}
int main() {
  // string text = "ababababc", pattern = "abababc";
  // string text = "abcdef", pattern = "cde";
  string text = "abccdf", pattern = "ccd";
  // string text = "aaaaabbbcccdddeaaab", pattern = "abbabbdd";
  cout << text << "\n";
  cout << pattern << "\n";

  cout << kmp(text, pattern);

  return 0;
}
