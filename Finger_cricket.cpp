#include <iostream>
#include<string.h>
#include<time.h>
using namespace std;
int toss_of_match(){
    srand(time(0));
    int toss=rand()%2 , c;
    char user_toss[6];
    cout<<"Time for testing your luck --------TOSS"<<endl<<"HEAD or TAILS---? ";
    cin>>user_toss;
    if(strcmpi(user_toss,"head")==0){
        c=0;
    }
    else if(strcmpi(user_toss,"tail")==0 || strcmpi(user_toss,"tails")==0){
        c=1;
    }
    else{
        cout<<"wrong input"<<endl;
        exit(0);
    }
    if(toss==0){
        cout<<"It's Head "<<endl;
    }
    else{
        cout<<"It's Tails "<<endl;
    }
    if(toss==c){
        cout<<"Wow hoo, you won the toss"<<endl<<"what would you like to chosse--------- Batting or Fielding "<<endl;
        return 1;
    }
    else{
        cout<<"ohh hoo, you lost the toss "<<endl;
        return 0;
    }

    return 0;
}


int user_batting(){
    srand(time(0));
    int run=rand()%7, user_run;
    cout<<"Show your fingers....... ";
    cin>>user_run;
    if(user_run>6 || user_run<0){
        cout<<"How can you score "<<user_run<<" in single bowl....stupid!!"<<endl;
        exit(0);
    }
    cout<<"Computer's fingers: "<<run<<endl;
    if(user_run==run){
        cout<<"Opps that's OUT!!"<<endl;
        return -1;
    }
    else return user_run;
}


int comp_batting(){
    srand(time(0));
    int run=rand()%7, user_run;
    cout<<"Show your fingers....... ";
    cin>>user_run;
    if(user_run>6 || user_run<0){
        cout<<"How can you score "<<user_run<<" in single bowl....stupid!!"<<endl;
        exit(0);
    }
    cout<<"Computer's fingers: "<<run<<endl;
    if(user_run==run){
        cout<<"Good bowling buddy, you took the wicket"<<endl;
        return -1;
    }
    else return run;
}





int main(){
    char name[20];
    cout<<"enter your name"<<endl;
    cin.getline(name,20);
    cout<<"Hello "<<name<<endl;
    cout<<"Ready for the match ?"<<endl;
    int toss=toss_of_match(), user_run=0, comp_run=0;
    if(toss==0){
        srand(time(0));
        int p=rand()%3, v=0;
        if(p==0 || p==2){
            cout<<"You have to bat first"<<endl;
            for(int i=0; i<6; i++)
            {
                if(v==-1){
                    break;
                }
                v=user_batting();
                user_run+=v;
            }
            cout<<"Your Total Score= "<<user_run<<endl;
            cout<<endl;
            cout<<"Now, fielding time"<<endl;
            for(int i=0; i<6; i++)
            {
                
                if(v==-1 || comp_run>user_run){
                    break;
                }
                v=comp_batting();
                comp_run+=v;
            }
        }
        else{
            cout<<"You have to field first"<<endl;
            for(int i=0; i<6; i++)
            {
                
                if(v==-1){
                    break;
                }
                v=comp_batting();
                comp_run+=v;
            }
            cout<<"Computer Total Score= "<<comp_run<<endl;
            cout<<endl;
            cout<<"Now, batting time"<<endl;
            for(int i=0; i<6; i++)
            {
                
                if(v==-1 || user_run>comp_run){
                    break;
                }
                v=user_batting();
                user_run+=v;
            }
        }
    }
    else{
        char user_choice[10];
        int v=0;
        cin>>user_choice;
        if(strcmpi(user_choice,"batting")==0 || strcmpi(user_choice,"bat")==0){
            for(int i=0; i<6; i++)
            {
                
                if(v==-1){
                    break;
                }
                v=user_batting();
                user_run+=v;
            }
            cout<<"Your Total Score= "<<user_run<<endl;
            cout<<endl;
            cout<<"Now, fielding time"<<endl;
            for(int i=0; i<6; i++)
            {
                
                if(v==-1 || comp_run>user_run){
                    break;
                }
                v=comp_batting();
                comp_run+=v;
            }
            
        }
        if(strcmpi(user_choice,"fielding")==0 || strcmpi(user_choice,"field")==0 || strcmpi(user_choice,"bowling")==0 || strcmpi(user_choice,"bowl")==0){
            for(int i=0; i<6; i++)
            {
                
                if(v==-1){
                    break;
                }
                v=comp_batting();
                comp_run+=v;
            }
            cout<<"Computer Total Score= "<<comp_run<<endl;
            cout<<endl;
            cout<<"Now, batting time"<<endl;
            for(int i=0; i<6; i++)
            {
                
                if(v==-1 || user_run>comp_run){
                    break;
                }
                v=user_batting();
                user_run+=v;
            }
            
        }    
    }
    cout<<endl;
    cout<<"Your Total Score= "<<user_run<<endl;
    cout<<"Computer Total Score= "<<comp_run<<endl;
    if(user_run > comp_run){
        cout<<"Congratulations "<<name<<", you won the match";
    }
    else{
        cout<<"you lost the match "<<name<<", better luck next time";
    }
}