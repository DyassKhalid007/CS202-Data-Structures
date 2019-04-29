#include <iostream>
#include <map>
using namespace std;

void Test()
{
  map<int,string> customer;
  customer[100] = "Ali";
  customer[123] = "Ahmad";
  customer[145] = "Adil";
  customer[171] = "Shahid";
  customer[200] = "Rambheer";

  map<int,string>c
  {
    {100,"Ganjendra"},{123,"Dilip"},{145,"Aditaya"},
    {171,"Shahid"},{200,"Rajesh"}
  };
  // cout<<customer[100]<<endl;
  // cout<<customer[101]<<endl;
  customer.insert(pair<int,string>(205,"Saurabh"));
  map<int,string>::iterator p;
  for(p=customer.begin();p!=customer.end();p++)
  {
    cout<<p->first<<":"<<p->second<<endl;
  }
  cout<<customer.at(145)<<endl;
  cout<<customer.size()<<endl;
  cout<<customer.empty()<<endl;
  customer.insert(pair<int,string>(205,"Saurabh"));
  customer.clear();//delete things in customer

}
int main()
{
  Test();
  return 0;
}
