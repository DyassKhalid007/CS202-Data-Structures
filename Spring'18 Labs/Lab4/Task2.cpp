#include <iostream>
using namespace std;

class Matrix
{
private:
  int**p;
  int rows;
  int cols;
public:
  Matrix();
  Matrix(int*m,int r,int c);
  void transpose();
  void printMatrix();
  friend ostream& operator <<(ostream&output,const Matrix&m);
};
Matrix::Matrix()
{
  rows = 5;
  cols = 5;
  p = new int*[rows];
  for(int i=0;i<rows;i++)
  {
    *(p+i) = new int[cols];
  }
  //setting element to zero
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      *(*(p+i)+j) = 0;
    }
  }
}
Matrix::Matrix(int*m,int r,int c)
{
  rows = r;
  cols = c;
  p = new int*[rows];
  for(int i=0;i<rows;i++)
  {
    *(p+i) = new int[cols];
  }
  //setting elements to that of passed pointer array
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      *(*(p+i)+j) = *(m+i*cols+j);
    }
  }
}
void Matrix::transpose()
{
  cout<<"The transpose of the matrix is:";
  for(int i=0;i<cols;i++)
  {
    for(int j=0;j<rows;j++)
    {
      cout<<p[j][i]<<" ";
    }
    cout<<endl;
  }
}
void Matrix::printMatrix()
{
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      cout<<*(*(p+i)+j)<<" ";
    }
    cout<<endl;
  }
}
ostream& operator <<(ostream&output,const Matrix&m)
{
  for(int i=0;i<m.rows;i++)
  {
    for(int j=0;j<m.cols;j++)
    {
      output<<*(*(m.p+i)+j)<<" ";
    }
    output<<endl;
  }
}
//test function
void Test_Matrix()
{
  // Matrix m;//worked fine
  // cout<<m;//worked fine
  // cout<<endl;
  // m.printMatrix();//worked fine
  // cout<<endl;
  int array[4][5];
  int k=0;
  for(int i=0;i<4;i++)
  {
    for(int j=0;j<5;j++)
    {
      array[i][j] =k++;
    }
  }
  int *p = &array[0][0];
  Matrix m2(p,4,5);//works fine
  m2.printMatrix();
  cout<<endl;
  m2.transpose();//works fine for r==c and r!=c
  cout<<endl;

}
int main()
{
  Test_Matrix();
}
