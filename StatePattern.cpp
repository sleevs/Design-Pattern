#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 
#include <list>
#include <typeinfo>



class Context ;


class State{
	
	protected :
		Context *context_;
		
		
	public :
	    virtual ~State(){
	    	
		}
		
	void setContext(Context *context){
		this->context_ = context ;
	}
	
	
	virtual void handler1()= 0 ;
	virtual void handler2() = 0;
	
	
};


  class Context {
  	
  	private:
  		State *state_ ;
  		
  	public :
  	   Context(State *state) : state_(nullptr){
  	   	this->TrasnsmitionTo(state);
		 }
		 
	~Context(){
		delete state_ ;
	}		
	
	
	
	void TransmitionTo(State *state){
		
		std::cout << "CONTEXT : TRANSMITION TO " << typeid(*state).name() << " \n" ;
	   if(this->state_ != nullptr){
	   	
	   	delete this->state_;
	   	this->state_ = state ;
	   	this->state_->setContext(this);
	   }
	   
	}
	
		   void Request1(){
	   	this->state_->handler1();
	   }
	   
	   
	   void Request2(){
	   	this->state_->handler2();
	   }
	
  };
  
  
  
  class ConcreteStateA : public State{
  	
  	public:
  		void handler1() override;
  		
  		void handler2() override{
		  
		std::cout << "CONCRETE STATE A HANDLES REQUEST 2 \n" ;
		}
  };
  
  
  
  class ConcreteStateB : public State{
  	
  	public:
  		void handler1() override{
		
		std::cout << " CONCRETE STATE B HANDLES REQUEST 1 \n" ;  
		}
		
		void handler2() override{
			
			std::cout << "CONCRETE STATE B HANDLES REQUEST2 \n";
			
			std::cout << "CONCRETE STATE B WANTS TO CHANGE THE STATE OF THE CONTEXT \n";
			
			this->context_->TransmitionTo(new ConcreteStateA);
		}
  };
  
  
  ConcreteStateA::handler1(){
  	
		{
				std::cout << "CONCRETE STATE A HANDLES REQUEST1 \n";
			
			std::cout << "CONCRETE STATE A WANTS TO CHANGE THE STATE OF THE CONTEXT \n";
			
			this->context_->TransmitionTo(new ConcreteStateB);
		}
		
  }
  
  
  void ClientCode(){
  	
  	Context *context = new Context(new ConcreteStateA);
  	context->Request1();
  	context->Request2();
  	delete context();
  }
  
  int main(){
  	ClientCode();
  	return 0 ;
  }
  
  
