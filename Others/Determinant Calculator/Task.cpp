//program to calculate important properites of matrces
#include <iostream>
using namespace std;

//defining a macro for size
#define N 10

void getCoFactor(int matrix[N][N],int temp[N][N],int a,int b,int c)
{
  int i=0;
  int j=0;
  for(int row=0;row<c;row++)
  {
    for(int col=0;col<c;col++)
    {
      if(row!=a&&col!=b)
      {
        temp[i][j++]=matrix[row][col];
        if(j==c-1)
        {
          j=0;
          i++;
        }
      }
    }
  }
}
//declaring the function to calculate determinant
int determinant(int matrix[N][N],int n)
{
  //function to calculate determinant recursively
  //here n is order of the matrix
  if(n==1)
  {
    return matrix[0][0];
  }
  //result is to be calculated in det
  int det = 0;
  //declaring the matrix to calculate the cofactor
  int temp[N][N];
  //iterating over columns to calculate cofactors
  int sign=1;
  for(int i=0;i<n;i++)
  {
    getCoFactor(matrix,temp,0,i,n);
    det+=sign*matrix[0][i]*determinant(temp,n-1);
    sign=-sign;
  }
  return det;
}
void adjoint(int A[N][N],int adj[N][N])
{
  if(N==1)
  {
    adj[0][0]=1;
    return;
  }
  int sign=1;
  int temp[N][N];
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      getCoFactor(A,temp,i,j,N);
      sign = ((i+j)%2==0)?1:-1;
      adj[j][i] = sign*determinant(temp,N-1);
    }
  }
}
bool inverse(int A[N][N],double inverse[N][N])
{
  int det = determinant(A,N);
  if(det==0)
  {
    cout<<"Matrix is singular.Cannot find its inverse.";
    return false;
  }
  int adj[N][N];
  adjoint(A,adj);
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      inverse[i][j]=adj[i][j]/(double)det;
    }
  }
  return true;
}
template<class T>
void display(T A[N][N])
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}
int main()
{
  int A[N][N] = { {5, -2, 2, 7},
                    {1, 0, 0, 3},
                    {-3, 1, 5, 0},
                    {3, -1, -9, 4}};

    int adj[N][N];  // To store adjoint of A[][]

    double inv[N][N]; // To store inverse of A[][]

    cout << "Input matrix is :\n";
    display(A);

    cout << "\nThe Adjoint is :\n";
    adjoint(A, adj);
    display(adj);

    cout << "\nThe Inverse is :\n";
    if (inverse(A, inv))
        display(inv);

    return 0;
}
