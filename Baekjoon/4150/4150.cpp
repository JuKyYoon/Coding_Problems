#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;

string solve(string a, string b) {
    string answer = "";
    
    if(b.length() > a.length()) {
        string tmp = b;
        b = a; a = tmp;
    }
    int aa = a.length(), bb = b.length();
    int m = 0;
    
    for(int i = aa-1, j = bb-1; i >= 0; i--,j--) {
        int inta = a[i] - '0';
        int intb = 0;

        if(j >= 0) { intb = b[j] - '0';}

        int t = inta + intb + m;
        if(t >= 10) {
            m = 1; t -= 10;
        } else {
            m = 0;
        }
        answer += (char)(t + '0');
    }
    if(m != 0) { answer += "1";}
    reverse(answer.begin(), answer.end());
    return answer;
}

int main() {
    int n; cin >> n;
    v.push_back("0"); v.push_back("1");

    for(int i=2; i<=n; i++) {
        v.push_back(solve(v[i-1], v[i-2]));
    }
    cout << v[n];
}