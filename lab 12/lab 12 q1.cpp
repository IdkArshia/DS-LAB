#include <iostream>
#include <vector>
using namespace std;

pair<vector<int>, int> bruteForceSearch(string text, string pattern) {
    vector<int> positions;
    int n = text.size(), m = pattern.size();
    int comparisons = 0;

    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            comparisons++;
            if (text[i + j] != pattern[j]) {
                match = false;
                break;
            }
        }
        if (match) positions.push_back(i);
    }

    return {positions, comparisons};
}

int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";

    auto result = bruteForceSearch(text, pattern);

    cout << "Positions: ";
    for (int x : result.first) cout << x << " ";
    cout << "\nTotal Comparisons: " << result.second << endl;
}
