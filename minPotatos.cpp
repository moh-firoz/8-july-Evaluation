#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int findMinPotatoes(int x, int y) {
    int sum = x + y;
    int minPotatoes = 0;
    
    while (!isPrime(sum + minPotatoes + 1))
        minPotatoes++;
    
    return minPotatoes + 1;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int x, y;
        cin >> x >> y;
        
        int minPotatoes = findMinPotatoes(x, y);
        cout << minPotatoes << endl;
    }
    
    return 0;
}
