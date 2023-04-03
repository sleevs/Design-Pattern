
#include <iostream>
#include <string.h>
#include <stdio.h>

using std::string;

enum Type{
    PROTPTYPE_1 = 0 ,
    PROTOTYPE_2 
};



class Prototype{

    protected:
        string prototype_name_;
        float prototype_field_ ;

    public:
        Prototype(){}
        Prototype(string prototype_name) 
                : prototype_name_ (prototype_name){

    }
    virtual ~Prototype(){}
    virtual Prototype *Clone() const = 0 ;
    virtual void method(float prototype_field){
        this->prototype_field_ = prototype_field ;
        std::cout << " CALL METHOD FROM " << prototype_name_ << " WITH FIELD " << prototype_field << std::endl;
    }  

      
};



class ConcretePrototype1 : public Prototype {

    private:
        float concretePrototypeField1 ;

    public:
        ConcretePrototype1(string prototype_name , float concrete_prototypeField)
            : Prototype(prototype_name), concretePrototypeField1(concrete_prototypeField){

        }

    Prototype *Clone() const {
        return new ConcretePrototype1(*this);
    }
};







class ConcretePrototype2 : public Prototype {

    private:
        float concretePrototypeField2 ;

    public:
        ConcretePrototype2(string prototype_name , float concrete_prototypeField)
            : Prototype(prototype_name), concretePrototypeField2(concrete_prototypeField){

        }

    Prototype *Clone() const {
        return new ConcretePrototype2(*this);
    }
};






int main(){

    std::cout << " JSNSOFTWARE - MPROTOTYPE PATTERN \n" ;
    return 0 ;
}