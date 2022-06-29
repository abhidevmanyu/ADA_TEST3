#include<iostream>
#include<limits.h>
using namespace std;
void MatrixChainMultiplication(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
    for (i=0; i<n; i++){
        for(int j=0;j<n;j++)
        m[i][j] = 0;   
    }
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;    
                }
            }
        }
    }
    cout<<"Mininum number of multiplication is : "<<m[1][n-1];  
}
int main()
{
    int n,i;
    cout<<"enter number of matrices\n";
	cin>>n;
	int arr[n+1];
	cout<<"enter order of matrices in form of array\n";
	for(int i=0;i<=n;i++)
	cin>>arr[i];  
    MatrixChainMultiplication(arr, n+1);
    return 0;
}
