#include <iostream>
#include <string>
using namespace std;
int str[100001];
int main() {
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    int n,a,k,cnt=0;cin>>n;
    for(int i=0; i<n; i++) {
        cin >> a; str[a]++;
    }
    getchar();
    getline(cin, s);
    cnt = n;
    bool ans=1;
    for(int i=0; i<n; i++) {
        if(s[i] == ' ') {
            k = 0;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            k = s[i] - 'A' + 1;
        } else {
            k = s[i] - 'a' + 27;
        }
        if(str[k] > 0) {str[k]--;cnt--;}
        else{ans=0;break;}
    }
    if(ans&&cnt==0) {cout<<"y";}
    else{cout<<'n';}

}