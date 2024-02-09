#include<bits/stdc++.h>
using namespace std;
 
int n, f[111];
char s[111];
 
bool sam(char *s,char *t,int l){
  for (int i=1;i<=l;++i) if (s[i]!=t[i]) return 0;
  return 1;
}
 
int main(){
  cin>>n>>s+1;
  for (int i=n/2;i;--i){
    if (sam(s,s+i,i)){
      cout<<n-i+1; return 0;
    }
  }
  cout<<n;
}
