#include <iostream>
using namespace std;

int multiplication(int n1,int n2);
int division(int n1,int n2);

int main()
{
  
  //prompting the user for the operation *,/ for this problem
  cout<<"Please enter your operation:";
  char operation;
  cin>>operation;
  //prompt the user to enter the first number
  cout<<"Please enter your first number:";
  int number1;
  cin>>number1;
  //promp the user for second number1
  cout<<"Please enter your second number:";
  int number2;
  cin>>number2;
  //declaring a variable result to store the result of operations
  int result = 0;
  //now switching the operation for * and / and default for other char values
  switch(operation)
  {
    case '*':
      result = multiplication(number1,number2);
      cout<<"The result of "<<operation<<" is:"<<result<<endl;
      break;
    case '/':
      result = division(number1,number2);
      cout<<"The result of "<<operation<<" is:"<<result<<endl;
      break;
    default:
      cout<<"You have entered an invalid operation.Aborting the program."<<endl;
  }
  return 0;


}
int multiplication(int n1,int n2)
{
  //function to do integral multiplication
  //quite easy to work for negative numbers just use the absolute value function and at the end
  //check if any number is less than 0 return the negative of that number but that is not required for the task
  int result = 0;
  for(int i=0;i<n1;i++)
  {
    for(int j=0;j<n2;j++)
    {
      result++;
    }
  }
  return result;
}
int division(int n1,int n2)
{
  //function to do integral division
  //if n1>n2 simply return 0
  int result = 0;
  if(n2>n1)
  {
    return result;
  }
  if(n2 == 0)
  {
    cout<<"Division by zero error."<<endl;
    cout<<"Returning negative 1"<<endl;
    return -1;
  }
  if(n1 == 0)
  {
    return result;
  }
  //variable to count subtractions of -1 to the number
  int counter = 0;
  while(n1>0)
  {
    n1-=1;
    counter++;
    if(counter == n2)
    {
      result++;
      counter = 0;
    }
  }
  return result;

}
