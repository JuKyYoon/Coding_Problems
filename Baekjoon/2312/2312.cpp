#include <iostream>
#define MN 100001
using namespace std;
bool non_prime[MN];
void init() {
    for(int i=2; i*i<=MN; i++) {
        if(!non_prime[i]) {
            for(int j=i*i; j<=MN; j+=i) {
                if(!non_prime[j]) {non_prime[j] = 1;}
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,t; cin >> t;
    init();

    while(t--) {
        cin >> n;
        for(int i=2; i<=n; i++) {
            if(!non_prime[i] && n%i == 0) {
                int tmp = 0;
                while(n%i == 0) {
                    tmp++;
                    n /= i;
                }
                cout << i << " " << tmp << "\n";
            } 
        }
    }
}