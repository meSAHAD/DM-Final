#include <bits/stdc++.h>
using namespace std;
 //0 1 1 2 3 5 8 13 21 44  
int main() {
    int n;
    cin >> n;
    int a = 0, b = 1, c;

    while(a+b <= n) {
        c = a + b;
        a = b;
        b = c;

        if (c % 5 == 0) cout << c << " is divisible by 5" << endl;
        if (c % 7 == 0) cout << c << " is divisible by 7" << endl;
        if (c % 11 == 0) cout  << c << " is divisible by 11" << endl;
    }

    cout << "Conjectures are correct." << endl;

    return 0;
}
