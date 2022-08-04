#include <bits/stdc++.h>
#define start ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define tcase int t; cin >> t; while(t--)

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
	start;
	tcase{
		ll n; cin >>n;
		map<ll,int> primefac;
		while(n%2==0 && n>1){
			primefac[2]++;
			n/=2;
		}
		for(int i=3; i<=sqrt(n); i++){
			while(n%i==0 && n>1){
				primefac[i]++;
				n/=i;
			}
		}
		if(n>1)primefac[n]++;
		/*
		for(pii i: primefac){
			cout << i.f << " " << i.s << "\n";
		}
		*/
		vector<ll> seq;
		for(int i=34; i>0; i--){
			ll temp=1;
			for(pair<ll,int> j: primefac){
				if(j.s>=i) temp*=j.f;
			}
			if(temp>1)seq.push_back(temp);
		}
		cout << seq.size() << "\n";
		for(ll i:seq)cout << i << " ";
		cout << "\n";
		/*
		vector<int> seq;
		while(true){
			int maxi=0, maxip=1;
			vector<int> nums;
			for(pii i:primefac){
				if(i.s>maxi){
					nums.clear();
					maxip=i.f; maxi=i.s; nums.push_back(i.f);
				} else  if(i.s==maxi){
					maxip*=i.f; nums.push_back(i.f);
				}
			}
			if(maxip==1) break;
			seq.push_back(maxip);
			for(int i: nums)primefac[i]--;
		}
		cout << seq.size() << "\n";
		for(int i: seq) cout << i << " ";
		cout << "\n";
		*/
	}
}