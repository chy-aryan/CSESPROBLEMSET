#include<bits/stdc++.h>
#define mode 1000000007
#define ll long long
using namespace std;
void multiply(vector<vector<ll>>& matrix , vector<vector<ll>> temp){
   ll x = (matrix[0][0]*temp[0][0] + matrix[0][1]*temp[1][0])%mode;
   ll y = (matrix[0][0]*temp[0][1] + matrix[0][1]*temp[1][1])%mode;
   ll z = (matrix[1][0]*temp[0][0] + matrix[1][1]*temp[1][0])%mode;
   ll w = (matrix[1][0]*temp[0][1] + matrix[1][1]*temp[1][1])%mode;
   matrix[0][0] = x;
   matrix[0][1] = y;
   matrix[1][0] = z;
   matrix[1][1] = w;
}

void powerr(vector<vector<ll>>& matrix , ll n){
    if(n == 1) return;
    vector<vector<ll>> temp = {{1,1} , {1,0}};
    powerr(matrix , n/2);
    multiply(matrix , matrix);
    if(n % 2 != 0) multiply(matrix , temp);
}

int main(){
  ll n;
  cin >> n;
  if(n == 0 || n == 1) {
    cout << n << endl;
    return 0;
  }
  vector<vector<ll>> matrix(2);
  matrix[0] = {1 , 1};
  matrix[1] = {1 , 0};
  powerr(matrix , n-1);
  cout << matrix[0][0] << endl;
}