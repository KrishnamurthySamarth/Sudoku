#include<iostream>
#include<string.h>

using namespace std;

bool issafe(int**arr, int x, int y, int n, int num)
{
    int startRow = 3 * (x / 3);
    int startCol = 3 * (y / 3);

    for(int row = 0; row < n; row++)
    {
        if(arr[row][y]==num)
        {
            return false;
        }
    }

    
    for(int col = 0; col < n; col++)
    {
        if(arr[x][col]==num)
        {
            return false;
        }
    }

    
    for(int row = startRow; row < startRow + 3; row++)
{
    for(int col = startCol; col < startCol + 3; col++)
    {
        if(arr[row][col] == num)
        {
            return false;
        }
    }
}
return true;
}

bool sudoku(int** arr, int x, int n)
{
    if(x==n)
    {
        return true;
    }
    int row = x;
    int col = 0;

    while(col<n)
    {
        if (arr[x][col] == 0)
        {
            for(int i=1;i<=9;i++)
            {
                if(issafe(arr,x,col,n,i))
                {
                    arr[x][col]=i;
            
                    if(sudoku(arr,x,n))
                    {
                        return true;
                    }
                   
            
                    arr[x][col]=0;
                }
            }
             return false;
        }
        col++;
        
    }
   
    return (sudoku(arr,x+1,n));
    
}




int main()
{
    
    int n;
    cin>>n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    if (sudoku(arr,0,n))
    {
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout << endl; 
    }
    }

  
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;

}