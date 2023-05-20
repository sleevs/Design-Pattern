#include <iostream>
#include <vector>

class Handler{


    public : virtual std::string process(std::string request)  = 0;
    public : virtual Handler *next(Handler *handler)  = 0;

};

class AbstractHandler : public Handler{

    private: Handler *nextHandler ;


    public : AbstractHandler() : nextHandler(nullptr){}

    Handler *next(Handler *handler){
        this->nextHandler = handler ;
        return handler ;
    }
    
    std::string process(std::string request){

        if(this->nextHandler){
            return this->nextHandler->process(request);
        }
        return NULL;

    }

};



class HandlerOrder : public AbstractHandler{

     std::string process(std::string request){

        if(request == "PAYMENT"){
            return " PROCESSING PAYMENT ";
        }else{
            return AbstractHandler::process(request);
        }
    }
};

int main(){

    Handler *order = new HandlerOrder ;

   std::vector<std::string> list ;
    list.push_back("ORDER");
    list.push_back("NOTIFICATION");
    list.push_back("PAYMENT");
    list.push_back("SHIPPING");

   
    for(int i = 0 ; i<= list.size() ; i++){
        std::cout <<  " " << i ;
        const std::string result = list[i];
        std::cout <<  " " << result ;
        order->process(result);
      
    }
    

    return 0 ;
}