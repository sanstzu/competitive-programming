#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

inline int add(int a, int b){
    return ((long long)a + b)%MOD;
}

inline int mul(int a, int b){
    return ((long long)a*b)%MOD;
}

int fp(int a, int b){
    if(b==0) return 1;
    if(b%2 == 1) return mul(fp(a,b-1),a);
    else {
        int res = fp(a,b>>1);
        return mul(res,res);
    }
}
/*
2 + 4 + 6 + ... + 2n = n(n+1)

sum of ((2i+1)/2 * 2 , (2j-1)/2 * 2) = 2i + 2(i+1) + .. 2j
= j(j+1) - i(i-1)

sum of +2 row (2i + 2m, 2j + 2m)
= (j+m)(j+m+1) - (i+m)(i+m-1)
= j(j+m+1) + m(j+m+1)
= j(j+1) + 2mj - i(i-1) - 2mi + 2m
= j(j+1) + 2m(j - i + 1)

sum from 1th ... 2k-1th row:
= k(j(j+1) - i(i-1)) + (0 + 2 + 4 + ... + 2k - 2)(m(j-i+1))
= k(j(j+1) - i(i-1)) + mk(k-1)(j-i+1);
next row 
sum of (2i + M, 2j + M) = 


Un = a + (n-1)*b
Sn = n/2 (2a + (n-1)*b)

valids * (0 + 2m + 4m + ... + 2m-2) = valids * m * (m-1)
*/
int main(){
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    int n,m; cin >> n >> m;
    int q; cin >> q;
    while(q--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        int ans = 0;
        int i,j,k;
        int val_i, val_j;
        // no of row +2 with 1st row (m+1)/2;
        if(a%2 == 0){
            //if need even
            i = ((c+1)>>1) << 1;
            j = (d>>1)<<1;
            k = (b-a+2)>>1;
            //ans = add(ans, mul(k, add(add( mul(j,j+1), 0 - mul(i,i-1)) , mul(m, mul(k-1, j-i + 1)) )));
        } else {
            //if need odd
            i = ((c>>1) << 1) +1;
            // un = a + b*(n-1)
            //sn = n/2 (2a + b*(n-1))
            j = (((d-1)>>1)<<1) + 1;
            k = (b-a+2)>>1;
            //ans = k*(j*(j+1) - i*(i-1) + m*(k-1)*(j-i+1));
            //ans = add(ans, mul(k, add(add( mul(j,j+1), 0 - mul(i,i-1)) , mul(m, mul(k-1, j-i + 1)) )));
        }
        //cout << i << " " << j << " " << k << "\n";
        val_i = add(mul((a-1),m) ,i);
        val_j = add(mul((a-1),m) ,j);
        //cout << val_i << " " << val_j  << "\n";
        int tmp_sum = mul(mul( (j-i + 2) , add(val_i,val_j)), fp(4,MOD-2));
        tmp_sum = mul(tmp_sum, k);
        ans = add(tmp_sum, mul(m, mul((j-i + 2)>>1, mul(k, k-1))));
        //cout << tmp_sum << " " << ans << "\n";
        // no of row +2 with 2st row (m+1)/2;
        if(a%2 == 1){
            //if need even
            i = ((c+1)>>1) << 1;
            j = (d>>1)<<1;
            k = (b-a+1)>>1;
            //ans = k*(j*(j+1) - i*(i-1) + m*(k-1)*(j-i+1));
            //ans = add(ans, mul(k, add(add( mul(j,j+1), 0 - mul(i,i-1)) , mul(m, mul(k-1, j-i + 1)) )));
        } else {
            //if need odd
            i = ((c>>1) << 1) +1;
            j = (((d-1)>>1)<<1) + 1;
            k = (b-a+1)>>1;
            //ans = k*(j*(j+1) - i*(i-1) + m*(k-1)*(j-i+1));
            //ans = add(ans, mul(k, add(add( mul(j,j+1), 0 - mul(i,i-1)) , mul(m, mul(k-1, j-i + 1)) )));
        }
        //cout << i << " " << j << " " << k << "\n";
        val_i = add(mul((a),m) ,i);
        val_j = add(mul((a),m) ,j);
        //cout << val_i << " " << val_j  << "\n";
        tmp_sum = mul(mul( (j-i + 2) , add(val_i,val_j)), fp(4,MOD-2));
        tmp_sum = mul(tmp_sum, k);
        int ans1 = add(tmp_sum, mul(m, mul((j-i + 2)>>1, mul(k, k-1))));
        ans = add(ans1, ans);
        cout << ans << "\n";
    }
}