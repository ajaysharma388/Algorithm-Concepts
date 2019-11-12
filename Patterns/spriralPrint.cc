#include <iostream>
using namespace std;

int main()
{
    int row,col;
    cin>>row>>col;
    int arr[row][col] = {};
    for(int i = 0;i<row;++i)
        for(int j=0;j<col;++j)
            cin>>arr[i][j];
    int startRow = 0,startCol = 0,endRow = row-1,endCol = col-1;
    while(startCol<=endCol && startRow<=endRow){
        //print startCol.
        for(int i=startRow;i<=endRow;++i)
            cout<<arr[i][startCol]<<", ";
        startCol++;
        //print endRpw.
        for(int i=startCol;i<=endCol;++i)
            cout<<arr[endRow][i]<<", ";
        endRow--;
        //print endCol.
        for(int i=endRow;i>=startRow;--i)
            cout<<arr[i][endCol]<<", ";
        endCol--;
        //print startRow.
        for(int i=endCol;i>=startCol;--i)
            cout<<arr[startRow][i]<<", ";
        startRow++;
    }
    cout<<"END"<<endl;
    return 0;
}
