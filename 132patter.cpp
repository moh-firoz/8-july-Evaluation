#include <iostream>
#include <stack>

using namespace std;

bool find132pattern(int nums[], int n) {
    if (n < 3)
        return false;

    int minVal[n];
    minVal[0] = nums[0];
    for (int i = 1; i < n; ++i)
        minVal[i] = min(nums[i], minVal[i - 1]);

    stack<int> stk;

    for (int i = n - 1; i >= 0; --i) {
        if (nums[i] > minVal[i]) {
  
            while (!stk.empty() && stk.top() <= minVal[i])
                stk.pop();
  
            if (!stk.empty() && stk.top() < nums[i])
                return true;

            stk.push(nums[i]);
        }
    }

    return false;
}

int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(find132pattern(arr, n)) cout<<"Pattern present"<<endl;
    else cout<<"Pattern not present";

    return 0;
}
