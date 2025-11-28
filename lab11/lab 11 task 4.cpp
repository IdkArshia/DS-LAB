#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = 7;

    unordered_map<int, pair<int,int>> mp;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int sum = arr[i] + arr[j];

            if(mp.find(sum) != mp.end()) {
                auto p = mp[sum];
                cout << "(" << p.first << ", " << p.second << ") and (";
                cout << arr[i] << ", " << arr[j] << ")\n";
                return 0;
            }
            else
                mp[sum] = {arr[i], arr[j]};
        }
    }

    cout << "No pairs found";
    return 0;
}
