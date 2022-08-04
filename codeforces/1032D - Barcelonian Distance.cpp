#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;
typedef long double ld;

ld dist(ld x1, ld y1, ld x2, ld y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

ld mdist(ld x1, ld y1, ld x2, ld y2){
    return abs(x2-x1)+ abs(y2-y1);
}
/*
                side y+
        start - - - - a - - - - -
        |                       |
        |                       b
side x- |                       |     side x+
        |                       |
        |                       |
        . - - - - - - - - - - end
                side y-
*/
int main(){
    ld a,b,c; cin >> a >> b >> c;
    ld x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    ld x[2], y[2];
    int ptr=0;
    if(ptr<2 && ((-b*y1-c)/a)<=max(x1,x2) && (-b*y1-c)/a>=min(x1,x2)){
        x[ptr]= -(b*y1+c)/a;
        y[ptr++]= y1;
    }
    if(ptr<2 && ((-a*x1-c)/b)<max(y1,y2) && (-a*x1-c)/b>=min(y1,y2)){
        x[ptr]= x1;
        y[ptr++]= -(a*x1+c)/b;
    }
    if(ptr<2 && ((-b*y2-c)/a)<=max(x1,x2) && (-b*y2-c)/a>=min(x1,x2)){
        x[ptr]= -((b*y2)+c)/a;
        y[ptr++]= y2;
    }
    if(ptr<2 && ((-a*x2-c)/b)<max(y1,y2) && (-a*x2-c)/b>=min(y1,y2)){
        x[ptr]= x2;
        y[ptr++]= -(a*x2+c)/b;
    }
    //cout << x[0] << " " << y[0] << " " << x[1] << " " << y[1] << "\n";
    ld ans;
    if(ptr>1){
        ans = min((abs(x2-x1))+ abs(y2-y1),mdist(x1,y1,x[0],y[0])+dist(x[0],y[0],x[1],y[1])+mdist(x[1],y[1],x2,y2));
    } else {
        ans = abs(x2-x1) + abs(y2-y1);
    }
   
    cout << setprecision(numeric_limits<long double>::digits10 + 1)
        << fixed << ans << "\n";
}