#include<iostream>
 
using namespace std;
void move(int n,char *s,char *i,char *d)
// s stands for source tower
// d stands for destination tower
// i stands for intermediate tower
{
 if(n>0)
 {
  move(n-1,s,d,i);
  // move n-1 disks from source to intermediate tower
  cout<<"disk "<<n<<" is moved from "<<s<<" to "<<d<<endl;
  // move the disk from to source to destination
  move(n-1,i,s,d);
  // move n-1 disks from intermediate to destination
 }
}
 
int main()
{
 cout<<"\n**********************************************************\n";
 cout<<"This C++ program is to solve the towers of hanoi problem";
 cout<<"\n**********************************************************\n";
 cout<<"Enter the no. of disks ";
 int n;
 cin>>n;
 move(n,"source tower","intermediate tower","destination tower");
 return 0;
}
