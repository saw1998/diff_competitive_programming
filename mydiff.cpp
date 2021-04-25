#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;
int main(int argc,char* argv[]){
    if(argc < 2){
        cout<<"invalid arguement!!\n";
        return 0;
    }
    fstream file1,file2;
    file1.open(argv[1],ios::in); //open a file to perform read operation using file object
    file2.open(argv[2],ios::in);

    vector<pair<int,pair<string,string>>> v;

    bool df=false;
    int i=1;
    if (file1.is_open() && file2.is_open()){   //checking whether the file is open
        string s1,s2;
        int i=1;
        bool r1=true;
        bool r2=true;
        while(1){

            if(r1 && getline(file1,s1)){
            } 
            else{
                r1=false;
            }
            if(r2 && getline(file2,s2)){
            }
            else{
                r2=false;
            }
            if(r1 && r2){
                if(s1!=s2){
                    v.push_back({i,{s1,s2}});
                }
            }
            else if(r1 && (!r2)){
                v.push_back({i,{s1,""}});
                if(s1!="") df=true;
            }
            else if((!r1) && r2){
                v.push_back({i,{"",s2}});
                if(s2!="") df=true;
            }
            else{
                break;
            }
            i++;
        }

        file1.close();
        file2.close();

    }

    bool matched = true;
    cout<<"\n"<<argv[1]<<"\n****************************************************\n";
    for(int i=0;i<v.size();i++){
        if(!df){
            if((v[i].second.first!=v[i].second.second)){
                printf("%2d | %s\n",v[i].first,v[i].second.first.c_str());
                matched=false;
            } 
        }
        else{
            printf("%2d | %s\n",v[i].first,v[i].second.first.c_str());
        }
    }

    cout<<"\n"<<argv[2]<<"\n****************************************************\n";
    for(int i=0;i<v.size();i++){
        if(!df){
            if(v[i].second.first!=v[i].second.second){
                printf("%2d | %s\n",v[i].first,v[i].second.second.c_str());
                matched=false;
            }
        } 
        else{
            printf("%2d | %s\n",v[i].first,v[i].second.second.c_str());
        }
    }

    if(matched && (!df)){
        cout<<"\n*****     No difference found!!!!       ******\n";
    }
}
