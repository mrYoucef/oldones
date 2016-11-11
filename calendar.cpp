
#include<iostream>
using namespace std;
double A(int a,int m,int d)
{double q;

int mm[11];
int n(6);
while(n)
{
    mm[n]=31;mm[n+1]=30;n=n-2;
}mm[1]=28;mm[0]=31;
mm[7]=31;
mm[8]=30;
mm[9]=31;mm[10]=30;

q=((a-1)*365)+((a-((a-1)%4)-1)/4)+d-1;
if((a%4==0)&&(m>3)) q++;
for(int i=0;i<m-1;i++){q=q+mm[i];}
return q;


}
main(){int mm[12];
int n(6);
while(n)
{
    mm[n]=31;mm[n+1]=30;n=n-2;
}mm[1]=28;mm[0]=31;
mm[7]=31;
mm[8]=30;
mm[9]=31;mm[10]=30;mm[11]=31;int a,b;while(1){
while(1){cout<<endl<<"year:";cin>>a;cout<<"month:";
cin>>b;if(b<=12&&b>=1&&a>=1)break;cout<<endl<<"   'error'"<<endl;}
int f,r;
f=(A(a,b,1)-A(2014,1,4));
    if(f<0){ r=-f;r=7-(r%7);}
    else {r=f;r=r%7;}
    if(b>9)cout<<b<<"/"<<a<<"   ";
if(r==7)r=0;
    if(b<=9)cout<<"0"<<b<<"/"<<a<<"   ";


cout<<endl;cout<<endl<<"   Sat  Sun  Mon  Tue  Wed  Thu  Fri  "<<endl;
for(int i=0;i<=r*5+2;i++)cout<<" ";cout<<"01";
for(int i=2;i<10;i++){r++;if(r%7==0)cout<<endl;cout<<"   0"<<i;}
for(int i=10;i<=mm[b-1];i++){r++;if(r%7==0)cout<<endl;cout<<"   "<<i;}
if(b==2&&a%4==0&&r%7==6)cout<<endl;
if(b==2&&a%4==0)cout<<"   29";cout<<endl;}}
