#include <iostream>
#include <string>
#include <stdio.h>



class ProductException {

    public:
        virtual ~ProductException(){}
        virtual std::string operation() const = 0 ;
        
};


class ConcreteProductExceptionSQL : public ProductException {

    public:
        std::string operation() const {
            return "{PRODUCE MYSQL EXCEPTION }";
        }
};




class ConcreteProductExceptionAlloc : public ProductException {

    public:
        std::string operation() const {
            return "{PRODUCE BAD ALLOC EXCEPTION }";
        }
};



class Creator{

    public:
        virtual ~Creator(){};
        virtual ProductException *factoryMethod() const = 0 ;

    
    std::string action() const {

        ProductException* product = this->factoryMethod();
        std::string result = " CREATOR : " + product->operation() ;
        delete product ;
        return result ;
    }
};



class ConcreteCreatorSQLException : public Creator{

    public:
        ProductException *factoryMethod() const{
            return new ConcreteProductExceptionSQL();
        }
};



class ConcreteCreatorAllocExcaption : public Creator{

    public:
        ProductException *factoryMethod() const{
            return new ConcreteProductExceptionAlloc();
        }
};




int main(){


    std::cout << " JSNSOFTWARE \n" ;

    Creator* creator1 = new ConcreteCreatorSQLException();
    std::cout <<   creator1->action();

    std::cout << "\n";
     Creator* creator2 = new ConcreteCreatorAllocExcaption();
    std::cout <<   creator2->action();

    return 0 ;
}