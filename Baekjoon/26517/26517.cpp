#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ll a,b,c,d,k; 
    cin >> k >> a >> b >> c >> d ;

    // k에 대해서 확인
    if((a*k) + b == (c*k) + d) {
        cout << "Yes " << (a*k) + b ;
    } else {
        cout << "No";
    }

}