#include <iostream>
using namespace std;
//We have to use initializer list for parameterized constructor
class publication
{
private:
  string title;
  double price;
public:
  publication();
  publication(string t,double p);
  void setTitle(string t);
  void setPrice(double p);
  double getPrice();
  string getTitle();
  ~publication();
};
publication::publication()
{
  cout<<"Calling from default publication constructor"<<endl;
  title = "NONE";
  price = 0.0;
}
publication::publication(string t,double p)
{
  cout<<"Calling from parameterized publication constructor"<<endl;
  title = t;
  price = p;
}
void publication::setTitle(string t)
{
  title = t;
}
void publication::setPrice(double p)
{
  price = p;
}
string publication::getTitle()
{
  return title;
}
double publication::getPrice()
{
  return price;
}
publication::~publication()
{
  cout<<"Calling from publication destructor"<<endl;
  cout<<"Title:"<<title<<endl;
  cout<<"Price:"<<price<<endl;
}
class Book:public publication
{
private:
  int page_count;
public:
  Book();
  Book(string t,double p,int pc);
  void setPageCount(int pc);
  int getPageCount();
  ~Book();
};
Book::Book()
{
  cout<<"Calling from Book default constructor"<<endl;
  page_count = 0;
}
Book::Book(string t,double p,int pc):publication(t,p),page_count(pc)
{

  cout<<"Calling from Book parameterized constructor"<<endl;

}
void Book::setPageCount(int pc)
{
  page_count = pc;
}
int Book::getPageCount()
{
  return page_count;
}
Book::~Book()
{
  cout<<"Calling from Book destructor"<<endl;
  cout<<"Page Count:"<<page_count<<endl;
}
class AudioBook:public publication
{
private:
  double playing_time;
public:
  AudioBook();
  AudioBook(string t,double p,double pt);
  void setPlayingTime(double pt);
  double getPlayingTime();
  ~AudioBook();
};
AudioBook::AudioBook()
{
  cout<<"Calling from default AudioBook constructor"<<endl;
  playing_time = 0;
}
AudioBook::AudioBook(string t,double p,double pt):publication(t,p),playing_time(pt)
{
  cout<<"Calling from parameterized AudioBook constructor"<<endl;
  //publication(t,p);

}
void AudioBook::setPlayingTime(double pt)
{
  playing_time = pt;
}
double AudioBook::getPlayingTime()
{
  return playing_time;
}
AudioBook::~AudioBook()
{
  cout<<"Calling from AudioBook destructor"<<endl;
  cout<<"Playing time:"<<playing_time<<endl;
}
void TestPublicationClassDefault()
{
  publication P;
  P.setTitle("Optics");
  P.setPrice(1500);
}
void TestPublicationClassParameterized()
{
  publication P("Data Structures",1000);
}
void TestBookDefault()
{
  Book B;
  B.setTitle("Optimization");
  B.setPrice(1200);
  B.setPageCount(33);
}
void TestBookParameterized()
{
  Book B1("Knapsack Problem",1350.0,15);
}
void TestAudioBookDefault()
{
  AudioBook A;
  A.setTitle("Alibi");
  A.setPrice(2570);
  A.setPlayingTime(4.57);
}
void TestAudioBookParameterized()
{
  AudioBook A("Shikwa/Jawab-e-Shikwa",0,13.52);
}
void TestTaskPublication()
{
  publication*p = new publication;
  p->setTitle("Alif Allah");
  p->setPrice(1230);
  delete p;
  cout<<"Creating a new object now"<<endl;
  publication*p2 = new publication("Molecular Biology",1210);
  delete p2;
}
void TestTaskBook()
{
  Book*b = new Book;
  b->setTitle("Life");
  b->setPrice(0);
  b->setPageCount(2000);
  delete b;
  cout<<"Creating a new object now"<<endl;
  Book*b2 = new Book("BioLab",20,10);
  delete b2;
}
void TestTaskAudioBook()
{
  AudioBook* a = new AudioBook;
  a->setTitle("Posiedon");
  a->setPrice(10000);
  a->setPlayingTime(5.9);
  delete a;
  cout<<"Creating a new object now"<<endl;
  AudioBook* a2 = new AudioBook("Kangana",0,18);
  delete a2;
}

int main()
{
  // TestPublicationClass();
  // TestPublicationClassParameterized();
  // TestBookDefault();
  // TestBookParameterized();
  // TestAudioBookDefault();
  // TestAudioBookParameterized();
  // TestTaskPublication();
  // TestTaskBook();
  TestTaskAudioBook();
  return 0;
}
