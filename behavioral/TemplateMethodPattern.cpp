#include <iostream>
#include <string>

using namespace std;

/*
o template method pattern e uma tecnica fundamental para o reuso de codigo
ele e particularmente importante em bibliotecas e frameworks

o template method pattern possui uma estrutura de inversao de controle 
referenciado tambem como principio Hollywood : "nao nos ligue , nos ligamos para voce" 
*/
class AbstractClass {

  virtual void primitiveOperation1() const = 0 ;
  virtual void primitiveOperation2() const = 0 ;
  virtual void hook1() const {}
  virtual void hook2() const {} 


/*
o template method define o esqueleto d um algoritimo
    
*/
  public : void TemplateMethod()const{

    this->baseOperation1();
    this->primitiveOperation1();
    this->baseOperation2();
    this->hook1();
    this->primitiveOperation2();
    this->baseOperation3();
    this->hook2();

  }

  protected : 
  void baseOperation1() const {
    std:: cout << " OPERATION 1 \n" ;
  }

   void baseOperation2() const {
    std:: cout << " OPERATION 2 \n" ;
  }

    void baseOperation3() const {
    std:: cout << " OPERATION 3 \n" ;
  }



};


class ConcreteClass1 : public AbstractClass {


      protected : 
      
      void primitiveOperation1() const {
        std:: cout << "CONCRETE CLASS IMPLEMENTS PRIMITIVE OPERATION 1 \n" ; 
      }
       void primitiveOperation2() const {
        std:: cout << " CONCRETE CLASS IMPLEMENTS PRIMITIVE OPERATION 2 \n" ; 
      }

      void hook1() const {
        std:: cout << " CONCRETE CLASS IMPLEMENTS OEPRATION HOOCK 1 \n" ;
      }

    

};


void ClientCode(AbstractClass *abstractClass){
  abstractClass -> TemplateMethod();
}

int main(){

  ConcreteClass1 *concreteClass1 = new ConcreteClass1;
  ClientCode(concreteClass1);

  return 0 ;
}