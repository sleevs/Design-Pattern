
#include <iostream>
#include <string>
#include <array>

using namespace std;





class ConcreteElementA ;

class ConcreteElementB ;



class Visitor {

    public :
        virtual void VisitorConcreteElementA(const ConcreteElementA *element) const = 0 ;
        virtual void VisitorConcreteElementB(const ConcreteElementB *element) const = 0 ;

};


class Element {
        
        public: 
            virtual ~Element() {}
            virtual void Accept(Visitor *visitor) const = 0 ;    
} ;



class ConcreteElementA : public Element {

    public :
        void Accept(Visitor *visitor ) const override {
            visitor->VisitorConcreteElementA(this); 
        }
        std::string ExclusiveMethodOfConcreteElementA()const{
            return "A" ;
        }

};



class ConcreteElementB : public Element {

    public :
        void Accept(Visitor *visitor ) const override {
            visitor->VisitorConcreteElementB(this); 
        }
        std::string SpecialMethodOfConcreteElementB()const{
            return "B" ;
        }

};





class ConcreteVisitor1 : public Visitor{

    public :
        void VisitorConcreteComponentA(const ConcreteElementA *element) const override {
            std::cout << element->ExclusiveMethodOfConcreteElementA() << " CONCRETE VISITOR 1 " ;
        }
        void VisitorConcreteComponentB( const ConcreteElementB *element) const override{
            std::cout << element->SpecialMethodOfConcreteElementB() << " CONCRETE VISITOR 1 " ;
        }
        
};





class ConcreteVisitor2 : public Visitor{

    public :
        void VisitorConcreteComponentA(const ConcreteElementA *element) const override{
            std::cout << element->ExclusiveMethodOfConcreteElementA() << " CONCRETE VISITOR 2 " ;
        }
        void VisitorConcreteComponentB( const ConcreteElementB *element) const override{
            std::cout << element->SpecialMethodOfConcreteElementB() << " CONCRETE VISITOR 2 " ;
        }
        
};



void ClientCode (std::array<const Element * , 2> elements , Visitor *visitor ){

    for(const Element *element : elements){
            element->Accept(visitor);
    }

}



int main(){


    cout << " MUNIZ SOARES ENGENHARIA DE SOFTWARE \n" ;

    std::array<const Element * , 2> elements = {new ConcreteElementA , new ConcreteElementB};
    std:: cout << " THE CLIENT CODE WORK WITH ALL VISITORS VIA BASE VISITOR INTERFACE \n" ;

    ConcreteVisitor1 *visitor1 = new ConcreteVisitor1;

    ClientCode(elements , visitor1);

    std::cout <<"\n";
    std::cout << " THIS ALLOW THE SAME CLIENT CODE TO WORK WITH DIFFERENT TYPE OF VISITOR \n" ;

    ConcreteVisitor2 *visitor2 = new ConcreteVisitor2 ;
    ClientCode(elements , visitor2);


    for (const Element *element : elements ){
        
            delete element ;

    }

    delete visitor1 ;
    delete visitor2 ;



    return 0;
}