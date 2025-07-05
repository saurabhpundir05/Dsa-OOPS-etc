//Deleting Element in Array
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cout<<"Enter Range"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter Element"<<endl;
    cin>>x;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            a[i]=a[i+1];
        }
    }
    n--;
    cout<<"After Deletion"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
