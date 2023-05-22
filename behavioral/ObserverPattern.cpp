#include<iostream>
#include<vector>


class Observer{

    public : virtual void update(int value) = 0 ;
};


class Subject{

    private : int value ;
    private : std::vector<Observer*> observers ;

    public : void attach(Observer* o){
        observers.push_back(o);
    }

    public : void detach(Observer* o){
        auto it = std::find(observers.begin() , observers.end() , o);
        if(it != observers.end()){
            observers.erase(it);
        }
    }

    private : void notify(){
        for(auto o : observers){
            o->update(value);
        }
    }

    public : void setValue(int newValue){
        value = newValue ;
        notify();

    }
};


class ConcreteObserver : public Observer{

    public : void update(int value){
        std::cout << " RECEIVED UPDADE : " << value  ;
    }
};


int main (){


    Subject subject ;
    ConcreteObserver concreteObserverA;
    ConcreteObserver concreteObserverB;

    subject.attach(&concreteObserverA);
    subject.attach(&concreteObserverB);

    subject.setValue(10);

    subject.detach(&concreteObserverA);

    subject.setValue(13);

    return 0 ;
}