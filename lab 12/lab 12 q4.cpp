#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i] = ++len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

pair<vector<int>, vector<int>> KMP(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    vector<int> positions;

    int i = 0, j = 0;

    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }

        if (j == pattern.size()) {
            positions.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < text.size() && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }

    return {positions, lps};
}

int main() {
    string text = "ababababc";
    string pattern = "abab";

    auto result = KMP(text, pattern);

    cout << "Positions: ";
    for (int x : result.first) cout << x << " ";

    cout << "\nLPS Array: ";
    for (int x : result.second) cout << x << " ";
}
