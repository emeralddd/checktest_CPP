#include <bits/stdc++.h>
using namespace std;
long long random(long long _L,long long _R) {
  	long long tmp=0;
 	for(int i=0; i<4; i++)
		tmp=(tmp<<15)^(rand()&((1<<15)-1));
	assert(_L<=_R);
	return _L+tmp%(_R-_L+1);
}
int main() {
    srand(time(nullptr));
    freopen("ahaha.inp","w",stdout);
    int n=50,q=50;
    cout<<n<<" "<<q<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout<<random(0,1);
        }
        cout<<'\n';
    }
    while(q--) {
        cout<<random(1,n)<<" "<<random(1,n)<<'\n';
    }
}
