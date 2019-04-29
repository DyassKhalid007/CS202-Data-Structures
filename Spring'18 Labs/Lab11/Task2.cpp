#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Make
{
private:
  vector<T> v;
public:
  Make();
  Make(vector<T>p);
  void reverse();
  void reverseSTL();
};
template <class T>
Make<T>::Make()
{

}
template <class T>
Make<T>::Make(vector<T>p)
{
  for(int i=0;i<p.size();i++)
  {
    v.push_back(p[i]);
  }
  for(int i=0;i<v.size();i++)
  {
    // cout<<v[i]<<endl;
  }
}
template <class T>
void Make<T>::reverse()
{
  vector<T> copy;
  for(int i=0;i<v.size();i++)
  {
    copy.push_back(v[i]);
  }
  v.clear();
  // cout<<"Copy is:"<<endl;

  for(int i=copy.size()-1;i>=0;i--)
  {
    v.push_back(copy[i]);
    // cout<<copy[i]<<endl;
  }
  cout<<"The revers vector is:"<<endl;
  for(int i=0;i<v.size();i++)
  {
     cout<<v[i]<<endl;
  }
}
template<class T>
void Make<T>::reverseSTL()
{
  vector<T>copy;
  typename std::vector<T>::iterator p;
  for(p=v.begin();p!=v.end();p++)
  {
    copy.push_back(*p);
  }
  v.clear();
  typename std::vector<T>::reverse_iterator q;
  for(q=copy.rbegin();q!=copy.rend();q++)
  {
    v.push_back(*q);
  }
  cout<<"Reverse vector is:"<<endl;
  for(p=v.begin();p!=v.end();p++)
  {
    cout<<*p<<endl;
  }
}

void test1()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  Make<int> M(v);
  M.reverse();

}
void test2()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  Make<int> M(v);
  M.reverseSTL();
}
int main()
{
  test2();
  return 0;
}
