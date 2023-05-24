#include<iostream>
#include<string>
#include<vector>

class Memento {


    private : std::string state ;

    public : Memento(const std::string& s) : state(s){}

    public : std::string getState()const{
        return state ;
    }
};


class Originator{

    private : std::string state ;

    public : void setState(const std::string& s){
        state = s ;
    }

    public : std::string getState()const{
        return state ;
    }

    public: Memento createMemento()const{
        return Memento(state);
    }

    public: void restoreFromMemento(const Memento& m){
        state = m.getState();
    }
};


class CareTaker{

    private : std::vector<Memento> mementos ;

    public : void addMemento(const Memento& m){
        mementos.push_back(m);
    }

    public : Memento getMemento(int index)const {
        return mementos[index];
    }
};


int main(){


    Originator originator ;
    CareTaker careTaker ;

    originator.setState("INITIAL STATE N");
    std::cout << originator.getState() << std::endl ;

    careTaker.addMemento(originator.createMemento());

    originator.setState("NEW STATE N2");
    std::cout << originator.getState() << std::endl ;

    careTaker.addMemento(originator.createMemento());

    originator.restoreFromMemento(careTaker.getMemento(0));
    std::cout<< "RESTORE STATE : " << originator.getState() << std::endl ;

    return 0 ;
}