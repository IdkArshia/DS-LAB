#include <iostream>
#include <vector>
using namespace std;

vector<int> badCharTable(string pattern) {
    vector<int> badChar(256, -1);
    for (int i = 0; i < pattern.size(); i++)
        badChar[(unsigned char)pattern[i]] = i;
    return badChar;
}

vector<int> goodSuffixTable(string pattern) {
    int m = pattern.size();
    vector<int> border(m + 1), shift(m + 1);

    int i = m, j = m + 1;
    border[i] = j;

    while (i > 0) {
        while (j <= m && pattern[i - 1] != pattern[j - 1]) {
            if (shift[j] == 0)
                shift[j] = j - i;
            j = border[j];
        }
        i--, j--;
        border[i] = j;
    }

    j = border[0];
    for (i = 0; i <= m; i++) {
        if (shift[i] == 0)
            shift[i] = j;
        if (i == j)
            j = border[j];
    }

    return shift;
}

vector<int> boyerMoore(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> badChar = badCharTable(pattern);
    vector<int> goodSuffix = goodSuffixTable(pattern);
    vector<int> positions;

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            positions.push_back(s);
            s += goodSuffix[0];
        }
        else {
            s += max(1, max(j - badChar[(unsigned char)text[s + j]], goodSuffix[j + 1]));
        }
    }
    return positions;
}

int main() {
    string DNA = "ACGTACGTGACG";
    string pattern = "ACG";

    vector<int> pos = boyerMoore(DNA, pattern);

    cout << "Positions: ";
    for (int p : pos) cout << p << " ";
}
