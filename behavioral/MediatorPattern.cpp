#include <iostream>
#include <string>
#include <vector>


class Colleague ;

class Mediator {

    public : virtual void sendMessage(Colleague* sender , const std::string message ) = 0 ;

};


class Colleague{

    protected: Mediator* mediator ;

    public : Colleague(Mediator* mediator) : mediator(mediator) {}

    virtual void sendMessage(const std::string& message) = 0 ;
    virtual void receiveMessage(const std::string& message) = 0 ;
};


class ConcreteMediator : public Mediator{

    private : std::vector<Colleague*> list ;

    public : void addColleague(Colleague* colleague){
        list.push_back(colleague);

    }

    public : void sendMessage(Colleague* sender , const std::string& message){

        for(int i = 0  ; i <= list.size() ; i++){
                    list[i]->receiveMessage(message);
        }
        /*
        for(Colleague* collegue : list){

            if(collegue != sender){
                collegue->receiveMessage(message);
            }

        }
        */
    }

};



class ConcreteColleague : public Colleague{

    public : ConcreteColleague(Mediator* mediator ) : Colleague(mediator) {}

    void sendMessage(const std::string& message){
        std::cout << "SENDER : " << message << std::endl;
        mediator->sendMessage(this , message);
    }

    void receiveMessage(const std::string& message){

        std::cout << "RECEIVER : " << message << std::endl;

    }

};

int main(){ 

    ConcreteMediator* mediator;

    ConcreteColleague colaborador(mediator);
    ConcreteColleague contratante(mediator);

    mediator->addColleague(&colaborador);
    mediator->addColleague(&contratante);

    contratante.sendMessage("OLA TESTE ");
    contratante.sendMessage("OI ");
    
    return 0 ;
}