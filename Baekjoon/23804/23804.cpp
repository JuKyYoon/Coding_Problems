#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;

    for(int i=1; i<=5*n; i++) {
        if(i<=n || i>4*n) {
            for(int k=0; k<5*n; k++) {
                cout << '@';
            }
            cout << '\n';
        } else {
            for(int j=0; j<n; j++) {
                cout << '@';
            }
            cout << '\n';
        }
    }
}