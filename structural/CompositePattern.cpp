
#include <algorithm>

#include <iostream>
#include <string.h>

#include <list>
using namespace std ;



class Componente {

    protected: Componente *param_ ;
    
    public: virtual ~Componente(){}



    public: void setParent(Componente *parent){
        this->param_ = parent ;
    }

    public: Componente *getParent() const{
        return this->param_ ;
    }


    virtual std::string operation() const = 0 ;

    virtual void add(Componente *componente)  {}

    virtual void rm(Componente *componente)  {}

    virtual bool isComposite() const {
        return false ;
    }

};



class Leaf : public Componente{

    public: std::string operation() const{
        return "LEAF";
    }

};





class Composite : public Componente {

    protected : 
        std::list<Componente *> children_ ;


    public:
        void add (Componente *componente)  {
            this->children_.push_back(componente);
            componente->setParent(this);
        }


    public: void rm(Componente *componente) {

        children_.remove(componente);
        componente->setParent(nullptr);
    }

    public: bool isComposite() const {
        return true ;
    }


    public : std::string operation()  const  {

        std::string result;
        for(const Componente *comp : children_){

            if( comp == children_.back()){

                result += comp->operation();
            }else {
                result += comp->operation() + " ++++ ";
            }

        }
        return " BRANCH : " + result ;
    }
  
};

int main(){


    std::cout <<  "TESTE APP COMPOSITE PATTERN \n" ;


    Componente *simple = new Leaf ;

    std::cout << " LEAF OPERATION  :" << simple->operation() ;

    std::cout<< "\n";

    Componente *tree = new Composite;
   Componente *branch = new Composite;

    branch->add(simple);
    tree->add(branch);

    tree->operation();

    std::cout<< " TREE OPERATION " << tree->operation();

    return 0 ;
}