#include <iostream>
using namespace std;
int main(){
    int n,a; cin >> n;
    // 인접한 두 수를 교환한다.
    // 홀수, 짝수 인접한 경우 최대 1번 등장하도록 하는 교환 최소 횟수
    // 홀수, 짝수는 중간에서 반드시 만나야 함
    // 즉, 홀 홀 홀 짝 짝 짝 이거나 짝 짝 짝 홀 홀 홀
    // 최소 교환, n이 백만. 전부는 불가
    long long left=0,right=0,k=0,j=0;
    for(int i=0; i<n; i++) {
        cin >> a;

        // 홀수일때 끄틍로 민다.
        if(a%2) {
            k += (j++);
            left += i;
            right += (n-1-i);
        }
    }

    cout << min(left, right) - k;


}