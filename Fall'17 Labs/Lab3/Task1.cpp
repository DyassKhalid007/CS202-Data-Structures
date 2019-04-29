//program to encrypt information and decrypt information by an integer length
#include <iostream>
#include <string>
using namespace std;

int index(char word);
char newChar(int newShift);
string encrypt(string word,int shift);
string decrypt(string word,int backShift);
int main()
{
  //prompt the user for a string including space and characters after space
  cout<<"Please enter the string for encryption:";
  string word;
  getline(cin,word);
  //prompt the user for shift
  cout<<"Please enter the shift:";
  int shift;
  cin>>shift;
  //store the result of encrypt in result
  string result = encrypt(word,shift);
  cout<<"The result of encryption is:"<<result<<endl;
  string result2;
  if(word == result)
  {
    result2 = result;
  }
  else
  {
    result2 = decrypt(result,shift);
  }
  cout<<"The result of decryption is:"<<result2<<endl;

}

int index(char word)
{
  string alphabets = "abcdefghijklmnopqrstuvwxyz";
  int length = 0;
  for(int i=0;i<alphabets.length();i++)
  {
    if(alphabets[i]!=word)
    {
      length++;
    }
    else
    {
      break;
    }
  }
  return length;

}
char newChar(int newShift)
{
  string alphabets = "abcdefghijklmnopqrstuvwxyz";
  return alphabets[newShift];
}
string encrypt(string word,int shift)
{
  for(int i=0;i<word.length();i++)
  {
    //function to check if a character is lowe case or not
    if(islower(word[i]))
    {
      int new_index = (index(word[i])+shift)%26;
      word[i] = newChar(new_index);
    }
  }
  return word;
}
string decrypt(string word,int backShift)
{
  for(int i=0;i<word.length();i++)
  {
    if(islower(word[i]))
    {
      word[i] = word[i] - backShift;
      if(word[i]<'a')
      {
        word[i] = word[i]+26;
      }
    }
  }
  return word;
}
