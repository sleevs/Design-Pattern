#include<iostream>
#include<string>
#include<vector>

class Memento {


    private : std::string state ;

    public : Memento( std::string& s) : state(s){}

    std::string getState(){
        return state ;
    }
};


class Originator{

    private : std:: string state ;

    public : void setState(std::string& s){
        state = s ;
    }

    public : std::string getState(){
        return state ;
    }
    Memento createMemento(){
        return Memento(state);
    }

    void restoreFromMemento(Memento m){
        state = m.getState();
    }
};


class CareTaker{

    private : std::vector<Memento> mementos ;

    public : void addMemento(Memento& m){
        mementos.push_back(m);
    }

    Memento getMemento(int index){
        return mementos(index);
    }
};


int main(){


    Originator originator ;
    CareTaker careTaker ;

    originator.setState("INITIAL STATE");
    std::cout << "INITIAL STATE" << originator.getState() << std::endl ;

    careTaker.addMemento(originator.createMemento());

    originator.setState("NEW STATE");
    std::cout << "NEW STATE" << originator.getState() << std::endl ;

    careTaker.addMemento(originator.createMemento());

    originator.restoreFromMemento(careTaker.getMemento(0));
    std::cout<< " RESTORE STATE " << originator.getState << std::endl ;

    return 0 ;
}