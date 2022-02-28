#include <bits/stdc++.h>
using namespace std;
long long randInt(long long _L,long long _R) {
  	long long tmp=0;
 	for(int i=0; i<4; i++)
		tmp=(tmp<<15)^(rand()&((1<<15)-1));
	assert(_L<=_R);
	return _L+tmp%(_R-_L+1);
}
int main() {
    srand(time(nullptr));
    freopen("ahaha.inp","w",stdout);
    cout<<randInt(1,100)<<" "<<randInt(1,100);
}
