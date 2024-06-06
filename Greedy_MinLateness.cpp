#include<bits/stdc++.h>
using namespace std;

struct task{
    int id;
    int duration;
    int deadline;
    
    task(int id,int duration,int deadline):id(id),duration(duration),deadline(deadline){}
};

bool compareDeadline(task a,task b){
    return a.deadline<b.deadline;
}

void minimizeLateness(vector<task> tasks){
    sort(tasks.begin(),tasks.end(),compareDeadline);

    int currTime = 0;
    int maxLateness = 0;

    cout<<"task Schedule"<<endl;

    for(const auto& task:tasks){
        cout<<"task"<<task.id<<":";
        cout<<"Start Time ="<<currTime<<",";
        cout<<"End Time = "<<currTime+task.duration<<",";
        int lateness = max(0,currTime+task.duration-task.deadline);
        cout<<"Lateness = "<<lateness<<endl;
        currTime+=task.duration;
        maxLateness = max(maxLateness,lateness);
    }   

    cout<<"Maximum Lateness = "<<maxLateness<<endl;
}

int main(){
    vector<task> tasks={
        {1,4,5},
        {2,2,2},
        {3,1,4},
        {4,3,3}
    };

    minimizeLateness(tasks);
    return 0;
}

