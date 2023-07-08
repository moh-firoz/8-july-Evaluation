#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void reduceRecipe(int recipe[], int N) {
    int commonFactor = recipe[0];
    for (int i = 1; i < N; ++i)
        commonFactor = gcd(commonFactor, recipe[i]);
    for (int i = 0; i < N; ++i)
        recipe[i] /= commonFactor;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int recipe[N];
        for (int i = 0; i < N; ++i)
            cin >> recipe[i];
        
        reduceRecipe(recipe, N);
        
        for (int i = 0; i < N; ++i)
            cout << recipe[i] << " ";
        cout << endl;
    }
    
    return 0;
}
