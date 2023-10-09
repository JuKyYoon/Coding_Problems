#include <iostream>
#include <cstring>
using namespace std;
char str[15];

void horizon(int s, int len, bool top) {
    for(int i=0; i<len; i++) {
        for(int j=0; j<s+2; j++) {
            if(str[i] == '1' || str[i] == '4') {cout << " ";}
            else if (str[i] =='7' && !top) {
                cout << " ";
            } else {
                if(j==0 || j == s+1) { cout << " ";}
                else {cout << "-";}
            }
        }
        cout << " ";
    }
    cout << "\n";
}

int main() {
    int s,n,len; cin >> s ;
    cin >> str;
    len = strlen(str);


    horizon(s, len, 1);

    for(int k=0; k<s; k++) {
        for(int i=0; i<len; i++) {
            for(int j=0; j<s+2; j++) {
                if(str[i] == '4' || str[i] == '8' || str[i] == '9' || str[i] == '0') {
                    if(j==0 || j==s+1) {
                        cout << "|";
                    } else {
                        cout << " ";
                    }
                } else if (str[i] == '5' || str[i] == '6') {
                    if(j == 0) {
                        cout << "|";
                    } else {
                        cout << " ";
                    }
                } else {
                    if(j == s+1) {
                        cout << "|";
                    } else {
                        cout << " ";
                    }
                }
            }
            cout << " ";
        }
        cout << "\n";
    }

    for(int i=0; i<len; i++) {
        for(int j=0; j<s+2; j++) {
            if(str[i] == '1' || str[i] == '7' || str[i] == '0') {cout << " ";}
            else {
                if(j==0 || j == s+1) { cout << " ";}
                else {cout << "-";}
            }
        }
        cout << " ";
    }
    cout << "\n";


    for(int k=0; k<s; k++) {
        for(int i=0; i<len; i++) {
            for(int j=0; j<s+2; j++) {
                if(str[i] == '6' || str[i] == '8' || str[i] == '0') {
                    if(j==0 || j==s+1) {
                        cout << "|";
                    } else {
                        cout << " ";
                    }
                } else if (str[i] =='2') {
                    if(j == 0) {
                        cout << "|";
                    } else {
                        cout << " ";
                    }
                } else {
                    if(j == s+1) {
                        cout << "|";
                    } else {
                        cout << " ";
                    }
                }
            }
            cout << " ";
        }
        cout << "\n";
    }
    horizon(s, len, 0);
}