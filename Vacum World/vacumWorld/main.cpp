#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Perception{
    bool location;
    bool isDirty;

public:
    Perception(bool _location = true, bool _isDirty = true){
        this->location = _location;
        this->isDirty = _isDirty;
    }

    bool getLocation(){
        return location;
    }
    void setLocation(bool value){
        location = value;
    }
    bool getIsDirty(){
        return isDirty;
    }
    void setIsDirty(bool value){
        isDirty = value;
    }
};

class Enviromment{
    bool isDirtyA;
    bool isDirtyB;
    bool agentLocation;

public:
    Enviromment(bool _isDirtyA = true, bool _isDirtyB = true, bool _agentLocation = true) {
        this->isDirtyA = _isDirtyA;
        this->isDirtyB = _isDirtyB;
        this->agentLocation = _agentLocation;
    }

    bool getIsDirtyA(){
        return isDirtyA;
    }
    void setisDirtyA(bool value){
        isDirtyA = value;
    }
    bool getIsDirtyB(){
        return isDirtyB;
    }
    void setisDirtyB(bool value){
        isDirtyB = value;
    }
    bool getAgentLocation(){
        return agentLocation;
    }
    void setAgentLocation(bool value){
        agentLocation = value;
    }

    Perception getPerception(){
         return Perception(agentLocation, agentLocation ? isDirtyA : isDirtyB);
    }

    void updateEnvironment(Perception p){
        p.getLocation() ? isDirtyA = p.getIsDirty() : isDirtyB = p.getIsDirty();
        this->agentLocation = p.getLocation();
    }
};

class Action{
    string name;
public:
    Action(string _name = ""){
        this->name = _name;
    }

    string getName(){
        return name;
    }


};

class Agent{
protected:
    Perception perception;
    vector<Action> actions;

public:
    Agent() {}

    void setPerception(Perception perception){
            this->perception = perception;
    }

    Perception getPerception(){
            return this->perception;
    }

};



class TableDriveAgent : Agent{
    vector<Perception> perceptions;
    map<Perception*,Action*> table;
public:
    TableDriveAgent(){}

    void setTable(){
        this->table.insert(make_pair(new Perception(true,false), new Action("Right")));
        this->table.insert(make_pair(new Perception(true,true), new Action("Aspire")));
        this->table.insert(make_pair(new Perception(false,false), new Action("Left")));
        this->table.insert(make_pair(new Perception(false,true), new Action("Aspire")));
    }

    Action SelectAction(Perception _perception){
        perceptions.push_back(_perception);

        map<Perception*,Action*>::iterator it;
        for (it = table.begin(); it != table.end(); it++) {
            if((it->first->getLocation()== _perception.getLocation()) && (it->first->getIsDirty() == _perception.getIsDirty())){
                return *(it->second);
            }

        }
        return Action("Erro");

    }
};


class SimpleReflexAgent : Agent{
private:

public:

    Action SelectAction(Perception _perception){
        this->perception = _perception;

        if(perception.getIsDirty()){
            this->actions.push_back(Action("Aspire"));
            this->perception.setIsDirty(false);
            return Action("Aspire");
        }
        else if(perception.getLocation()){
            this->actions.push_back(Action("Right"));
            this->perception.setLocation(false);
            return Action("Right");
        }
        else if(!perception.getLocation()){
            this->actions.push_back(Action("Left"));
            this->perception.setLocation(true);
                return Action("Left");
        }
        return Action("ERRO!");

    }

    void setPerception(Perception perception){
            this->perception = perception;
        }

    Perception getPerception(){
        return this->perception;
    }


};


void mainTable(TableDriveAgent& agent){
    Action action;

    Enviromment enviromment(false, true, true);
    agent.setTable();

    cout << "\n------------------------------\nGetting Started:\n";
    cout << "Loc: ";
            enviromment.getAgentLocation() ? cout << "A" : cout << "B";
    cout<< " isDirtyA: " << enviromment.getIsDirtyA()
         << " isDirtyB: " << enviromment.getIsDirtyB() << endl;
    cout << "------------------------------\n\n";

    int x;
    cout << "Number of steps: ";
    cin >> x;

    for(int i = 0; i < x; i++){
        cout << "Loc: ";
        enviromment.getAgentLocation() ? cout << "A" : cout << "B";
        cout << " isDirtyA: ";
        enviromment.getIsDirtyA() ? cout << "True" : cout << "False";
        cout << " | isDirtyB: ";
        enviromment.getIsDirtyB() ? cout << "True" : cout << "False";

        bool isDirty;
        if(enviromment.getAgentLocation()){
            isDirty = enviromment.getIsDirtyA();
        }else{
            isDirty = enviromment.getIsDirtyB();
        }

        action = agent.SelectAction(Perception(enviromment.getAgentLocation(), isDirty));

        cout << "\nAction: " << action.getName() << endl << endl;

        if(action.getName() == "Aspire"){
            enviromment.getAgentLocation() ? enviromment.setisDirtyA(false) : enviromment.setisDirtyB(false);
        }
        if(action.getName() == "Left"){
            enviromment.setAgentLocation(1);
        }
        if(action.getName() == "Right"){
            enviromment.setAgentLocation(0);
        }

    }
}

void mainReflex(SimpleReflexAgent& _reflex){

    Enviromment enviromment(true,true,true);
    SimpleReflexAgent reflex = _reflex;

    cout << "\n------------------------------\nGetting Started:\n";
    cout << "Loc: ";
            enviromment.getAgentLocation() ? cout << "A" : cout << "B";
    cout<< " isDirtyA: " << enviromment.getIsDirtyA()
         << " isDirtyB: " << enviromment.getIsDirtyB() << endl;
    cout << "------------------------------\n\n";

    int x;
    cout << "Number of steps: ";
    cin >> x;
    for(int i = 0; i < x; i++){
        reflex.setPerception(enviromment.getPerception());

        cout << "Loc: ";
        cout << (enviromment.getAgentLocation() ? "A" : "B");

        cout << " | Is Dirty: ";
        cout << (enviromment.getAgentLocation() ? (enviromment.getIsDirtyA() ? "Y" : "N") : (enviromment.getIsDirtyB() ? "S" : "N")) << endl;
        cout << "Action: ";
        cout << reflex.SelectAction(reflex.getPerception()).getName() << endl << endl;

        enviromment.updateEnvironment(reflex.getPerception());
    }
}

int main(){
    TableDriveAgent agent;

    SimpleReflexAgent reflex;
    //mainTable(agent);


    int x;
    cout << "0 to Agent Table, 1 to Agent Reflex: ";
    cin >> x;
    if(x == 0){
        mainTable(agent);
    }else if (x == 1) {
        mainReflex(reflex);
    }else{
        cout << "\n\n ERROR \n\n";
    }

    return 0;
}




















