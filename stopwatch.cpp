#include<iostream>
#include<ctime>
#include<windows.h>
using namespace std;
int h,m,s,gg;bool bo;
void ord(int *t,int f)
{
    do{bo=0;
            for(int i=0;i<f-1;i++)
        if(t[i]>t[i+1]){gg=t[i];t[i]=t[i+1];t[i+1]=gg;bo=1;}
    }while(bo);
}
void af(int a)
{
    cout<<"     "<<a/3600<<" h  "<<(a%3600)/60<<" mm  "<<a%60<<" s   "<<endl;
}
int ver(int a,time_t i,time_t j)
{
    return (a>(i-j));
}
void re(int*t,int l,int&f)
{
    for(int i=l;i<f-1;i++) t[i]=t[i+1];
        f--;
}
void rep(int*t,int f)
{for(int i=0;i<f;i++){system("cls");cout<<"crono: "<<i+1<<endl;
cout<<"  heure: "; cin>>h; cout<<"  munites: "; cin>>m;cout<<"  secondes: "; cin>>s; t[i]=(h*3600)+(m*60)+s;}

}
main()
{int t[50];
int f,vv,w;
cout<<" entrez le nombre de cronos ";cin>>f;
rep(t,f);ord(t,f);w=f;system("cls");
time_t i,j;time(&j);
do{time(&i);
do{time(&i);vv=1;system("cls");for(int u=0;u<w-f;u++) cout<<"     0 h  0 mm  0 s   fin" <<endl;
for(int q=0;q<f;q++){if(ver(t[q],i,j)) af(t[q]-(i-j));
else {Beep(3000,600); re(t,q,f);vv=0;}

}}while(!vv);


Sleep(999);
}while(f>0);Beep(5000,500);Beep(5000,500);



}
