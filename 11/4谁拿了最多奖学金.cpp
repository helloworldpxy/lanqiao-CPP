#include<bits/stdc++.h>
using namespace std;
class person{
public:
    int id;
    string name;
    int endavg;
    int gscore;
    char hstudent;
    char estudent;
    int es;
    int scmoney=0;
    person(){
    }
    person(int id,string name,int endavg,int gscore,char hstudent,char estudent,int es){
        this->id=id;
        this->name=name;
        this->endavg=endavg;
        this->gscore=gscore;
        this->hstudent=hstudent;
        this->estudent=estudent;
        this->es=es;
    }
};
bool My_compare(const person &p1,const person &p2){
    if(p1.scmoney!=p2.scmoney){
        return p1.scmoney>p2.scmoney;
    }
    return p1.id<p2.id;
}


int main(){
    int n;
    cin>>n;
    person *p=new person[n];
    for(int i=0;i<n;i++){
        string name;int endavg;int gscore;char hstudent;char estudent;int es;
        
        cin>>name>>endavg>>gscore>>hstudent>>estudent>>es;
        p[i]=person(i+1,name,endavg,gscore,hstudent,estudent,es);
//        cin>>p[i].name>>p[i].endavg>>p[i].gscore>>p[i].hstudent>>p[i].estudent>>p[i].es;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(p[i].endavg>80&&p[i].es>=1)p[i].scmoney+=8000;
        if(p[i].endavg>85&&p[i].gscore>80)p[i].scmoney+=4000;
        if(p[i].endavg>90)p[i].scmoney+=2000;
        if(p[i].endavg>85&&p[i].estudent=='Y')p[i].scmoney+=1000;
        if(p[i].gscore>80&&p[i].hstudent=='Y')p[i].scmoney+=850;
        sum+=p[i].scmoney;
    }
    sort(p,p+n,My_compare);
    cout<<p[0].name<<endl<<p[0].scmoney<<endl<<sum;
    return 0;
}
