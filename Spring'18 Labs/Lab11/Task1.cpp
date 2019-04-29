#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

template <class T>
T add(vector<T>p1)
{
  T sum=0;
  for(int i=0;i<p1.size();i++)
  {
    sum+=p1[i]*p1[i]*p1[i];
  }
  return sum;
}
string add(vector<string>p1)
{
  string sum;
  for(int i=0;i<p1.size();i++)
  {
    sum+=p1[i];
  }
  return sum;
}
void TestInt()
{
  vector<int> v;
  v.push_back(5);
  v.push_back(1);
  v.push_back(2);
  cout<<add(v)<<endl;
}
void TestDouble()
{
  vector<double> v;
  v.push_back(2.3);
  v.push_back(1.9);
  v.push_back(1.5);
  cout<<add(v)<<endl;
}
void TestString()
{
  vector<string> v;
  v.push_back("a");
  v.push_back("bcA");
  v.push_back("xyz");
  cout<<add(v)<<endl;
}
int main()
{
  TestInt();
  TestDouble();
  TestString();
  return 0;
}
