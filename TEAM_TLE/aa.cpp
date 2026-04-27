#include <bits/stdc++.h>

using namespace std;

bool isPossible(const vector<int>& arr, int h, int mid) {
    long long totalHours = 0;
    for (int bananas : arr) {
        totalHours += (bananas + mid - 1) / mid;
    }
    return totalHours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1; 
    int high = *max_element(piles.begin(), piles.end());
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (isPossible(piles, h, mid)) {
            result = mid;   
            high = mid - 1;
        } else {
            low = mid + 1;   
        }
    }
    return result;
}

int main() {
    int n, h;
    if (!(cin >> n >> h)) return 0;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << minEatingSpeed(arr, h) << endl;
    return 0;
}