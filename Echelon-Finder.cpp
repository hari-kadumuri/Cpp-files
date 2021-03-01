#include <bits/stdc++.h>
using namespace std;

bool debug;

double magnitude(double x) {
    return (x < 0 ? -1*x : x);
}

void readMatrix(vector<vector<float>>& M, int rows, int cols) {
    cout<<"enter matrix row by row:"<<endl;
    for(int i=0;i<rows;i++) {
        cout<<"Row "<<i+1<<" => ";
        vector<float> tempRow(cols);
        for(int j=0;j<cols;j++) {
            float temp;
            cin>>temp;
            tempRow[j] = temp;
        }
        M[i] = tempRow;
        cout<<endl;
    }
}

void printMatrix(vector<vector<float>>& M, int rows, int cols) {
    for(int i=0;i<rows;i++) {
        cout<<"Row "<<i+1<<" => ";
        for(int j=0;j<cols;j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
}

int getMaxRowIndex(vector<vector<float>>& M, int rows, int cols, int currindex) {
    float max = M[currindex][currindex];
    int maxidx = -1;
    for(int i=currindex;i<rows;i++) {
        if(currindex<cols && magnitude(max) < magnitude(M[i][currindex])) {
            max = M[i][currindex];
            maxidx = i;
        }
    }
    return maxidx;
}

void swapRows(vector<vector<float>>& M, int rows, int cols, int currindex, int maxRow) {
    if(debug) cout<<"\tSwapping rows: "<<maxRow<<" and "<<currindex<<endl;
    for(int i=0;i<cols;i++) {
        float temp = M[currindex][i];
        M[currindex][i] = M[maxRow][i];
        M[maxRow][i] = temp;
    }
}

void subtractRows(vector<vector<float>>& M, int rows, int cols, int currindex, int currrow, float factor) {
    if(debug) cout<<"\tSubtracting row "<<currrow<<" from the row "<<currindex<<endl;
    for(int i=0;i<cols;i++)
        M[currrow][i] -= factor*M[currindex][i];
}

void findEchelonForm(vector<vector<float>>& M, int rows, int cols, int currindex) {
    if(currindex >= rows-1) return;
    if(debug) cout<<"Operations for the row "<<currindex<<":"<<endl;
    // get the max row here and swap with the top row.
    int maxRow = getMaxRowIndex(M, rows, cols, currindex);
    swapRows(M, rows, cols, currindex, maxRow);
    // start a for loop and make the below elts zero
    for(int i=currindex+1;i<rows;i++) {
        float factor = (double)M[i][currindex]/(double)M[currindex][currindex];
        if(debug) cout<<"\tfactor for row "<<i<<" is selected as "<<M[i][currindex]<<"/"<<M[currindex][currindex]<<" = "<<factor<<endl;
        subtractRows(M, rows, cols, currindex, i, factor);
    }
    if(debug) cout<<"Printing matrix for row "<<currindex<<endl;
    if(debug) printMatrix(M, rows, cols);
    // call findEchelonForm on the remaining matrix
    findEchelonForm(M, rows, cols, currindex+1);
}

int main(int argc, char const *argv[])
{
    int rows = 0, cols = 0;
    cout<<"enter no of rows: ";
    cin>>rows;
    cout<<"enter no of columns: ";
    cin>>cols;
    cout<<"want to show detailed list of operations? (y/n) "<<endl;
    string debugstring;
    cin>>debugstring;
    debug = (debugstring[0] == 'n' | debugstring[0] == 'N' ? false: true);
    vector<vector<float>> M(rows);
    readMatrix(M, rows, cols);
    printMatrix(M, rows, cols);
    findEchelonForm(M, rows, cols, 0);
    cout<<"\nEchelon Form of the given matrix:"<<endl;
    printMatrix(M, rows, cols);
    return 0;
}
