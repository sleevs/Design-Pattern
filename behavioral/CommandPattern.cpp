#include <iostream>
#include <vector>



class Command{

    public: virtual ~Command(){

    }
    virtual void execute() const = 0;

};


class Receiver {

    
    public: void action(std::string msg){
        std::cout << " RECEIVER : " << msg <<"\n";
    }
};

class ConcreteCommand : public Command{

    private: Receiver *receiver_ ;
    private: std::string payload_ ;

    public: ConcreteCommand(Receiver *receiver , std::string payload) : receiver_(receiver) ,payload_(payload){

    }

    void execute() const{
        this->receiver_->action(this->payload_);
        std::cout << "CONCRETE COMMAND " <<"\n";
    }

};


class Invoker {

    private: Command *command_ ;
    
    public: void store(Command *cmd){
        this->command_ = cmd ;
    }

    public: void operation(){
        this->command_->execute();
    }
};




int main(){

    std::string message = "PAYMENT";
    Invoker *invoker = new Invoker;
    Receiver *receiver = new Receiver;
    Command *cmd = new ConcreteCommand(receiver, message);
    invoker->store(cmd);
    invoker->operation();
   
   
    return 0 ;
}