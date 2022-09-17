#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double

#define fi first
#define se second

#define debug(x) cout << #x << " => " << x << "\n"

int n, a[200005], b[200005], ans;
vector <int> va, vb, vc, vd;
map <int,int> mp;
int d[15];

void solve () {
    ans = 0;
    mp.clear();
    va.clear();
    vb.clear();
    vc.clear();
    vd.clear();
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++)
        mp[b[i]]++;
    for(int i = 1; i <= n; i++) {
        if(mp[a[i]] > 0) {
            mp[a[i]]--;
            continue;
        }
        va.push_back(a[i]);
    }
    for(auto i : mp) for(int j = 0; j < i.se; j++) vb.push_back(i.fi);
    mp.clear();
    for(int i = 0; i < va.size(); i++)
        if(floor(log10(va[i])) > 0) {
            va[i] = floor(log10(va[i])) + 1;
            ans++;
        }
    for(int i = 0; i < vb.size(); i++)
        if(floor(log10(vb[i])) > 0) {
            vb[i] = floor(log10(vb[i])) + 1;
            ans++;
        }
    for(int i = 0; i < vb.size(); i++)
        mp[vb[i]]++;
    for(auto i : va) {
        if(mp[i] > 0) {
            mp[i]--;
            continue;
        }
        vc.push_back(i);
    }
    for(auto i : mp) for(int j = 0; j < i.se; j++) vd.push_back(i.fi);
    for(auto i : vc) if(i > 1) ans++;
    for(auto i : vd) if(i > 1) ans++;
    cout << ans << "\n";
}

signed main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc; cin >> tc;
    while(tc--) solve ();
}