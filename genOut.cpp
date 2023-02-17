/**
darkemeralddd
**/
#define emerald "ahaha"
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define l2 long long
#define ld long double
#define _ld (ld)
#define _l2 (l2)
#define st first
#define nd second
#define ll2 pair<l2,l2>
#define ii pair<int,int>
#define iii pair<int,ii>
#define il2 pair<int,l2>
#define l2i pair<l2,int>
#define memset(a,b) memset(a,b,sizeof(a))
#define ladd(a) a=" "+a
#define bit(x,y) (((y)>>(x))&1)
#define infinity() for(;;)
#define cntbit(x) __builtin_popcountll((x))
#define all(v) (v).begin(),(v).end()
#define __unique(v) (v).resize(distance((v).begin(),unique(all((v)))))
#define eb emplace_back
#define pb push_back
const l2 mod = 1000000007;
using namespace std;
bool a[5005][5005];
int n,q,h[405],L[405],R[405];
void getresult1() {
    l2 kq=0;
    memset(h,0);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            h[j]=a[i][j]?0:h[j]+1;
        }

        for(int j=1; j<=n; j++) {
            int mn=h[j];
            for(int k=j; k<=n; k++) {
                mn=min(mn,h[k]);
                kq+=mn;
            }
        }
    }

    cout<<kq<<'\n';
}
void s1() {
    getresult1();
    while(q--) {
        int r,c;
        cin>>r>>c;
        a[r][c]^=1;
        getresult1();
    }
}
void getresult() {
    l2 kq=0;
    memset(h,0);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            h[j]=a[i][j]?0:h[j]+1;
        }

        for(int j=1; j<=n; j++) {
            int mn=h[j];
            for(int k=j; k<=n; k++) {
                mn=min(mn,h[k]);
                kq+=mn;
            }
        }

        for(int j=1; j<=n; j++)  {
            L[j]=j-1;
            while(L[j]>0&&h[L[j]]>=h[j]) L[j]=L[L[j]];
        }

        for(int j=n; j>0; j--) {
            R[j]=j+1;
            while(R[j]<=n&&h[R[j]]>h[j]) R[j]=R[R[j]];
        }

        for(int j=1; j<=n; j++) {
            kq+=h[j]*(j-L[j])*(R[j]-j);
        }
    }

    cout<<kq<<'\n';
}
void s23() {
    getresult();
    while(q--) {
        int r,c;
        cin>>r>>c;
        a[r][c]^=1;
        getresult();
    }
}
void s45() {
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(emerald".INP","r",stdin);
    freopen(emerald".ANS","w",stdout);

    cin>>n>>q;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            char ch;
            cin>>ch;
            a[i][j]=ch=='1';
        }
    }

    s1();

//    if(n<=50) s1();
//    else if(n<=400) s23();
//    else s45();
}

