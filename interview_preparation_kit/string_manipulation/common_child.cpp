#include <iostream>
#include <string>
using namespace std;

int** data;
string a ,b;

int max ( int a , int b ){
  if ( a > b )
    return a;
  return b;
}

int ss ( int ina , int inb ) {
  if ( ina == a.size() or inb==b.size() )
    return 0;
  if ( data[ina][inb]!=-1 )
    return data[ina][inb];
  if ( a[ina]==b[inb] ){
    data[ina][inb] = ss(ina+1,inb+1) + 1;
    return data[ina][inb];
  }
  else{
    data[ina][inb] = max ( ss(ina+1,inb) , ss(ina,inb+1) );
    return data[ina][inb];
  }
  return 0;
}

int main(int argc, char const *argv[]) {
  cin>>a>>b;
  data = new int*[a.size()+1];
  for(int i=0;i<a.size()+1;i++){
    data[i] = new int[b.size()+1];
    for ( int j=0;j<b.size()+1;j++)
      data[i][j]=-1;
  }
  cout << ss (0,0) <<endl;
  return 0;
}
