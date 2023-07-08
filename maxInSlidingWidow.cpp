#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSlidingWindow(int nums[], int size, int k) {
    vector<int> result;
    int maxIndex = 0;

    for (int i = 1; i < k; ++i) {
        if (nums[i] > nums[maxIndex])
            maxIndex = i;
    }
    result.push_back(nums[maxIndex]);

    for (int i = 1; i <= size - k; ++i) {
        if (maxIndex >= i) {
            if (nums[i + k - 1] > nums[maxIndex])
                maxIndex = i + k - 1;
        }
        else {
            maxIndex = i;
            for (int j = i + 1; j < i + k; ++j) {
                if (nums[j] > nums[maxIndex])
                    maxIndex = j;
            }
        }

        result.push_back(nums[maxIndex]);
    }

    return result;
}

int main() {
    int n;
    cout<<"Enter The size of array: ";
    cin>>n;
    int nums[n];
    cout<<"Enter The array: ";
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<"Enter The size of Window: ";
    int k;
    cin>>k;
    vector<int> result = maxSlidingWindow(nums, n, k);

    for (int num : result)
        cout << num << " ";

    return 0;
}
