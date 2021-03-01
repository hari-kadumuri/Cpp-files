#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[8] = {1, 3, 5, 7, 9, 11, 15};
    bool flag = false;
    for(int i=0;i<8;i++) {
        for(int j=i+1;j<8;j++) {
            for(int k=j+1;k<8;k++) {
                if(a[i]+a[j]+a[k] == 30) {
                    cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                    flag = true;
                }
            }
        }
    }
    if(!flag) cout<<"Not found!"<<endl;
    return 0;
}
