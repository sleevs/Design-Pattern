#include <iostream>
#include <string.h>

using namespace std;


class Component{

public: virtual  ~Component(){}
public: virtual  std::string operation() const = 0 ;

};


class ConcreteComponent : public Component{

  public :  std::string operation() const{
            return "\n ConcreteComponent : operation() ";
    }
};



class Decorator : public Component{

    protected : Component *component_ ;

    Decorator(Component *compoenent ) : component_ (compoenent){
       
    }

   public : std::string operation() const {
        return  this->component_->operation();;
    }
};



class ConcreteDecoratorA : public Decorator{

    public : ConcreteDecoratorA(Component *component) : Decorator(component){

    }
    
    public :std::string operatio()const {

        cout << "ConcreteDecoratorA " + Decorator::operation() ;
        return "\n ConcreteDecoratorA : Decorator::operation()" ;
    }
};



class ConcreteDecoratorB : public Decorator{

    public : ConcreteDecoratorB(Component *component) : Decorator(component){

    }
    
    std::string operatio() const {
        return "\n ConcreteDecoratorB : " + Decorator::operation() ;
    }
};

int main()
{
    cout <<"JSNSOFTWARE - DECORATOR PATTERN PROGRAM \n";
    Component *comp = new ConcreteComponent ;

    cout << comp->operation() +"\n";

    Component *d1 = new ConcreteDecoratorA(comp) ;
    cout << d1->operation() +"\n" ;
    Component *d2 = new ConcreteDecoratorB(d1);
     cout << d2->operation() +"\n" ;


    return 0 ;
}
