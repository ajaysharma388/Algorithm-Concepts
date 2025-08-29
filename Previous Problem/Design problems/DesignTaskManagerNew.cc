#include<bits/stdc++.h>
using namespace std;

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        #endif  
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

class Task
{
public:
    int userId, taskId, priority;
    Task(int uid, int tid, int pri)
    {
        this->userId = uid;
        this->taskId = tid;
        this->priority = pri;
    }
};

class TaskManager {
    set<int> priorityList;
    unordered_map<int, set<int>> priorityToTaskMapper;
    unordered_map<int, Task*> taskInfo;
public:
    TaskManager(vector<vector<int>>& tasks) {
        priorityList.clear();
        priorityToTaskMapper.clear();
        taskInfo.clear();
        for(auto task : tasks)
        {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskInfo[taskId] = new Task(userId, taskId, priority);
        priorityList.insert(priority);
        priorityToTaskMapper[priority].insert(taskId);
    }

    void cleanTaskRecord(int priority, int taskId, int newPriority = -1)
    {
        if(newPriority == -1) taskInfo.erase(taskId);
        else taskInfo[taskId]->priority = newPriority;
        if(priorityToTaskMapper[priority].size() == 1)
        {
            priorityToTaskMapper.erase(priority);
            priorityList.erase(priorityList.find(priority));
        }
        else
        {
            priorityToTaskMapper[priority].erase(priorityToTaskMapper[priority].find(taskId));
        }
    }
    
    void edit(int taskId, int newPriority) {
        // fetching the old priority
        int oldPri = taskInfo[taskId]->priority;
        if(oldPri == newPriority) return;
        // now we have some updates to do.
        cleanTaskRecord(oldPri, taskId, newPriority);
        priorityToTaskMapper[newPriority].insert(taskId);
        priorityList.insert(newPriority);
        // print();
    }
    
    void rmv(int taskId) {// 3
        int curPri = taskInfo[taskId]->priority;
        // now we have some updates to do.
        delete taskInfo[taskId];
        cleanTaskRecord(curPri, taskId);
        // print();
    }
    
    int execTop() {// 4
        if(priorityList.size() == 0) return -1;
        int topPri = *priorityList.rbegin();
        int taskId = *priorityToTaskMapper[topPri].rbegin();
        int usr = taskInfo[taskId]->userId;
        cleanTaskRecord(topPri, taskId);
        // print();
        return usr;
    }

    void print()
    {
        cout << "Task In Queue\n";
        for(auto data: priorityToTaskMapper)
        {
            cout << data.first << " => [ ";
            for(auto tid: data.second)
            {
                cout << tid << ", ";
            }
            cout << "]\n";
        }
    }
};


int main() 
{
    fastio(true);
    int cnt;
    cin >> cnt;
    int uid, tid, pri, option;
    vector<vector<int>> initialdata;
    while (cnt--) 
    {
        vector<int> data(3, 0);
        for(int i = 0; i < 3; ++i)
            cin >> data[i];
        initialdata.push_back(data);
    }    
    TaskManager *taskManager = new TaskManager(initialdata);
    int operation;
    cin >> operation;
    while(operation--)
    {
        cin >> option;
        switch(option)
        {
            case 1:
                // cout << "Adding task \n";
                cin >> uid >> tid >> pri;
                taskManager->add(uid, tid, pri);
                break;
            case 2:
                // cout << "Editing task \n";
                cin >> tid >> pri;
                taskManager->edit(tid, pri);
                break;
            case 3:
                // cout << "Removing task \n";
                cin >> tid;
                taskManager->rmv(tid);
                break;
            case 4:
                cout << "Executing top task \n";
                cout << taskManager->execTop() << endl;
                break;
            default:
                cout << "Invalid Input\n";
                break;
        }
    }
    return 0;
}