#include <iostream>
#include <vector>

using namespace std;

void nullifyRow(vector<vector<int>> &matrix, int row){
    for(int j=0; j<matrix[0].size(); j++)
        matrix[row][j] = 0;
}

void nullifyColumn(vector<vector<int>> &matrix, int col){
    for(int i=0; i<matrix.size(); i++)
        matrix[i][col] = 0;
}

void setZeros(vector<vector<int>> matrix){
    vector<bool> row(matrix.size());
    vector<bool> column(matrix[0].size());

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[i][j]==0){
                row[i] = true;
                column[j] = true;
            }
        } 
    }

    for(int i=0; i<row.size(); i++)
        if(row[i]){
            nullifyRow(matrix, i);
        }
    
    for(int j=0; j<column.size(); j++)
        if(column[j]){
            nullifyColumn(matrix, j);
        }

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }    
}

int main(){
    vector<vector<int>> matrix
    {
        {1, 0, 2, 3},
        {4, 7, 6, 9},
        {5, 3, 9, 2}
    };

    setZeros(matrix);

    return 0;
}