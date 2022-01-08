#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 
#include <list>


class Subject {
	
	public:
		virtual  void Request() const = 0 ;
};


class RealSubject : public Subject{
	
	public :
		void Request() const override{
		std::cout << " REALSUBJECT : HANDLING REQUEST \n" ;
		}
};


class Proxy : public Subject {
	
	private:
		RealSubject *realSubject ;
		
		bool checkAcess() const {
		
		std::cout << "PROXY : CHECKING ACCESS PRIOR TO FIRING A REAL REQUEST : \n" ;
		return true ;
		}
		
		void logAccess() const{
		
		std::cout<< "PROXY : LOGGING THE TIME OF REQUEST \n";
		}
		
		
		public :
			Proxy(RealSubject *realSubject) : realSubject(new RealSubject(*realSubject)){
			}
			
			~Proxy(){
				delete realSubject ;
			}
			
		
		void Request() const override{
		
		if(this->checkAcess()){
			this->realSubject->Request();
			this->logAccess();
		  }
		}
};


      void ClientCode(const Subject &subject){
      	subject.Request();
	  }



int main(){
	
	std::cout << "CLIENT: EXECUTING THE CLIENT CODE WITH A REAL SUBJECT : \n" ;
	RealSubject *realSubject = new RealSubject;
	ClientCode(*realSubject);
	std::cout << "\n";
	std::cout << "CLIENT : EXECUTING THE SAME CLIENT CODE WITH A PROXY \n";
	Proxy *proxy = new Proxy(realSubject);
	ClientCode(*proxy);
	
	delete realSubject ;
	delete proxy ;
	return 0 ;
}
