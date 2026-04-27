#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> left(n);
        vector<int> right(n);

        left[0] = -1;
        for (int i = 1; i < n; i++) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = left[p];
            }
            left[i] = p;
        }

        right[n - 1] = n;
        for (int i = n; i >= 0; i--) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = left[p];
            }
            left[i] = p;
        }

        maxx = 0;
        while(){

        }

        return maxx;
    }

    int main(){
        int n;
        cin>>n;
        vector<int>heights;
        for(int i = 0; i < n; i++){
            cin>>heights[i];
        }
    }