#include <iostream>
using namespace std;
int tanghulu[200001];
int fruit[10];
int main() {
    // 과일 종류는 1~9. 
    // 과일 두 종류 이하로. 앞 뒤에서 뺀다. 덱?
    int n; cin >> n; // 20만


    for(int i=0; i<n; i++) {
        cin >> tanghulu[i];
    }

    if(n==1){cout << 1; return 0;}

    // 과일 종류 
    int kind = 0;

    int left=0,right=1;
    if(tanghulu[left] == tanghulu[right]) { kind = 1; fruit[tanghulu[left]] = 2;}
    else {kind = 2; fruit[tanghulu[left]] = fruit[tanghulu[right]] = 1;}
    // 일단 두개를 선택한다. 그리고 right 증가시킨다. 이 떄 종류가 3이되면 2가 될때까지 왼쪽 버린다,.

    int ans = 2;
    while(right+1 < n) {
        right++;

        if(fruit[tanghulu[right]] == 0) { kind++; }
        fruit[tanghulu[right]]++;
        while(left < right && kind >= 3) {
            fruit[tanghulu[left]]--;
            if(fruit[tanghulu[left]] == 0) {kind--;}
            left++;
        }

        // cout << left << " " << right  << " : " << kind << "\n";

        ans = max(ans, right-left+1);

    }

    cout << ans;



}

/*
9
3 5 3 3 5 3 8 8 8
정답 6 오답 4


11
7 7 3 5 3 3 5 3 8 8 8
정답 6 오답 5

3 5 3 3 5

*/