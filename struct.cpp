#include <iostream>
#include <cstring>

using namespace std;
void list(struct Team team);
struct Team{
    int age;
    char name[20];
    char sport[20];
};

int main(){
    struct Team TeamA;
    struct Team TeamB;
    
    TeamA.age=24;
    strcpy(TeamA.name, "Rita");
    strcpy(TeamA.sport, "Volley-Ball");
    
    TeamB.age=21;
    strcpy(TeamB.name, "Tina");
    strcpy(TeamB.sport, "Badminton");
    
    list(TeamA);
    list(TeamB);
    
    return 0;
}
void list(struct Team team){
    cout<<"name : "<<team.name<<endl;
    cout<<"age : "<<team.age<<endl;
    cout<<"sport : "<<team.sport<<endl;
    
}
