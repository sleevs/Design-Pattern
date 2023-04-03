#include <iostream>
#include <string.h>


using namespace std ;
//using std::string ;



class Implementation {

    public : virtual ~Implementation(){}
    public : virtual std::string method1() const = 0 ;
    public : virtual std::string method2() const = 0 ;

};


class ConcreteImplementationA : public Implementation{

    public: std::string method1() const {
        return "ConcreteImplementationA - method1() " ;
    }

    public: std::string method2() const{
        return "ConcreteImplementationA - method2() " ;
    }
};




class ConcreteImplementationB : public Implementation{


  public: std::string method1() const{
        return "ConcreteImplementationB - method1() " ;
    }

    public: std::string method2() const{
        return "ConcreteImplementationB - method2() " ;
    }
};


class Abstraction {

        protected: Implementation *implementation_ ;
        public: Abstraction(Implementation *implementation) : implementation_(implementation){}

        virtual ~Abstraction(){}

        virtual std::string feactureA() const{
            return "ABSTRACTION WITH BASE FEACTURE " + this->implementation_->method1();
        }

        virtual std::string feactureB() const{
            return "ABSTRACTION WITH BASE FEACTURE " + this->implementation_->method2();
        }


};


class RefinedAbstraction : public Abstraction{

    public : RefinedAbstraction(Implementation *implementation):Abstraction(implementation){}

    std::string feactureA() const {
        return "RefinedAbstraction feactureA()" + this->implementation_->method2();
    }

    std::string feactureB() const {
        return "RefinedAbstraction feactureB()" + this->implementation_->method2();
    }
};

int main(){

        Implementation *impl = new ConcreteImplementationA;
        Abstraction *abstraction = new Abstraction(impl);
        cout << abstraction->feactureA();
        cout << "\n-----------------------------------------\n" ;

        cout << abstraction->feactureB();

        delete impl ;
        delete abstraction ;
        cout << "\n-----------------------------------------\n" ;

        impl = new ConcreteImplementationB;
        abstraction = new RefinedAbstraction(impl);

        cout << abstraction->feactureA();

        delete impl ;
        delete abstraction ;
        cout << "\n-----------------------------------------\n" ;

        std::cout<< "JSNSOFTWARE - TESTE APP BRIDGE";
    return 0 ;
}