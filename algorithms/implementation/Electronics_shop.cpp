#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int b, n, m;
  int x;
  int max=0;

  cin >> b >> n >> m;

  vector<int> vec_k;
  vector<int> vec_m;

  for(int i=0 ; i<n; i++)
  {
    cin >> x;
    vec_k.push_back(x);
  }

  for(int j=0; j<m; j++)
  {
    cin >> x;
    vec_m.push_back(x);
  }

  vector<int>::iterator i1;
  vector<int>::iterator i2;
  i1=vec_k.begin();
  i2=vec_m.begin();

  for(i1=vec_k.begin(); i1!=vec_k.end(); ++i1)
  {
    for(i2=vec_m.begin(); i2!=vec_m.end(); ++i2)
    {
      if(((*i1)+(*i2))>max && ((*i1)+(*i2))<=b)
        max=(*i1)+(*i2);
    }
  }

  if(max!=0)
   cout << max <<endl;

  else
   cout << "-1" << endl;
}

