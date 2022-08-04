#include <bits/stdc++.h>
using namespace std;
vector<bool> room(10,0);
int l(){
	for(int i=0; i<10;i++){
		if(room[i]==0){
			return i;
		}
	}
}

int r(){
	for(int i=9; i>=0;i--){
		if(room[i]==0){
			return i;
		}
	}
}

int main(){
	char temp;
	int n; cin >> n;
	

	for (int i=0; i<n ;i++){
		cin >> temp;
		switch(temp){
			case 'L':
				room[l()]=1;
				break;
			case 'R':
				room[r()]=1;
				break;
			default:
				room[(int)temp-'0']=0;
		}
	}
	for(bool i: room){
		cout << i;
	}
	cout << "\n";
}