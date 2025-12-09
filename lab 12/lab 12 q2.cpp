#include <iostream>
#include <vector>
using namespace std;

struct RKResult {
    vector<int> positions;
    vector<int> falsePositives;
};

RKResult rabinKarp(string text, string pattern, int prime = 101) {
    int n = text.size();
    int m = pattern.size();
    vector<int> positions, falsePositives;

    int d = 256; // ASCII alphabet
    int pHash = 0, tHash = 0, h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    for (int i = 0; i < m; i++) {
        pHash = (d * pHash + pattern[i]) % prime;
        tHash = (d * tHash + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {

        if (pHash == tHash) {
            if (text.substr(i, m) == pattern)
                positions.push_back(i);
            else
                falsePositives.push_back(i);
        }

        if (i < n - m) {
            tHash = (d * (tHash - text[i] * h) + text[i + m]) % prime;
            if (tHash < 0) tHash += prime;
        }
    }

    return {positions, falsePositives};
}

int main() {
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    RKResult r = rabinKarp(text, pattern);

    cout << "Positions: ";
    for (int x : r.positions) cout << x << " ";

    cout << "\nFalse Positives: ";
    for (int x : r.falsePositives) cout << x << " ";
}
