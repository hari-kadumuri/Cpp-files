#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  string line = "5 2 10 1 2 5 5 12";
  int index = 1;
  long long int N, K, M;
//   while (!cin.eof()) {
    // getline(cin, line);
    // cout << "line[" << index++ << "]:" << line << "\n";
    N = 0;
    int i=0;
    while(line[i]!=' ') {
        N = N*10+line[i]-'0';
        i++;
    }
    cout<<N<<endl;
    i++;
    K = 0;
    while(line[i]!=' ') {
        K = K*10+line[i]-'0';
        i++;
    }
    cout<<K<<endl;
    long long int A[N];
    i++;
    M = 0;
    while(line[i]!=' ') {
        M = M*10+line[i]-'0';
        i++;
    }
    cout<<M<<endl;

    for(int j=0;j<N;j++) {
        i++;
        A[j] = 0;
        while(i<line.size() && line[i]!=' ') {
            A[j] = A[j]*10+line[i]-'0';
            i++;
        }
        cout<<A[j]<<endl;
    }
    //processing
    int j=K-1;
    for(j=K-1;j<N;j++) {
        if(A[i]<=M) {
            M = M-A[i];
        }
        else {
            cout<<j+2<<endl;
            break;
        }
    }
    if(j==N) cout<<N+1<<endl;
//   }
  return 0;
}
