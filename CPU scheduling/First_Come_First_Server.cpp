/*GIT HUP ID : AWM-ENG*/
//implementation of first come first server scheduling algorithm
/*important note: This implementation assumes that processes arrive 
in the ready queue in the order of their arrival times*/
//import libraries
#include<iostream>
#include<vector>
using namespace std;


//The Process
class Process
{
public:
string name;
int Cpu_burst_time;
int Ready_queue_arrive_time;
int Turnaround_time;
int Waiting_time;
//constructor
Process(string name ,int Ready_queue_arrive_time ,int Cpu_burst_time)
{
    this->name = name;
    this->Cpu_burst_time = Cpu_burst_time;
    this->Ready_queue_arrive_time = Ready_queue_arrive_time;
    Turnaround_time = 0;
    Waiting_time = 0;
}



void print_proces()
{
    cout<<"name : " <<name <<"\n"; 
    cout<<"Ready_queue_arrive_time : " <<Ready_queue_arrive_time <<"\n"; 
    cout<<"Cpu_burst_time : " <<Cpu_burst_time <<"\n"; 
    cout<<"Turnaround time : " <<Turnaround_time <<"\n"; 
    cout<<"Waiting time : " <<Waiting_time <<"\n";
    cout<<"-----------------------------\n";
}
};


//Reade Queue
class Ready_queue
{
public:
vector<Process> Ready_Q;
float average_turnaround_time;
float average_waiting_time;
int time;
//constructor
Ready_queue()
{
    average_turnaround_time = 0;
    average_waiting_time = 0;
    time = 0;
}

void add_process(const Process &pro)
{   Process temp = pro;
    if(temp.Ready_queue_arrive_time >= time)
    {
        time = temp.Ready_queue_arrive_time;
    }
    temp.Turnaround_time = temp.Cpu_burst_time + time - temp.Ready_queue_arrive_time;
    average_turnaround_time += temp.Turnaround_time;
    if(temp.Ready_queue_arrive_time < time)
    {
        temp.Waiting_time = time - temp.Ready_queue_arrive_time;
        average_waiting_time += temp.Waiting_time;
    }
    else
    {
        temp.Waiting_time = 0;
    }
    time += temp.Cpu_burst_time;
    Ready_Q.push_back(temp);
}


//printing
void print_Process()
{
    for(int i = 0;i<Ready_Q.size();i++)
    {
        cout << i<<" ::_______ \n";
        Ready_Q[i].print_proces();
        cout << "\n";
    }
}

void print_data()
{
    cout << "average turnaround time : " << average_turnaround_time/Ready_Q.size()<<"\n";
    cout << "average waiting time : " << average_waiting_time/Ready_Q.size()<<"\n";
}

void print()
{
    print_Process();
    print_data();
}
};



//Main function
int main()
{
//testing

Ready_queue rr;
int t = 3;
while (t--)
{
    cout << t+1 <<" : Enter process name , arrival time and cpu burst time : \n";
    string n;
    int a1;
    int b1;
    cin >> n;
    cin >> a1;
    cin >> b1;
    Process a(n,a1,b1);
    rr.add_process(a);
}

rr.print();


return 0;

}
