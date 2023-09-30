#include <iostream>
using namespace std;
int main() {
    int n,l,t=0,d,r,g,tmp; cin >> n >> l;
    for(int i=0; i<n; i++) {
        // 이전 신호등 부터 현재 신호등 까지 이동
        if(i!=0){ tmp = d;}


        // 신호등 만남
        cin >> d >> r >> g;

        // 이전 신호등 부터 현재 신호등 까지 이동
        if(i!=0) {t += (d - tmp);}
        else{ t = d;}

        int rest_t = t % (r+g); // 사이클에서 지난 시간
        bool now = 0; //0은 빨강
        if(rest_t <= r) {
            now = 0;
        } else {
            now = 1;
        }

        if(!now) {
            t += (r-rest_t);
        }
    
    }

    cout << t + (l - d);

}