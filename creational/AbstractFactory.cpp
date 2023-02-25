
#include <iostream>
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 

class AbstractProduct {

    public:
        virtual ~AbstractProduct(){};
        virtual std::string action() const =0 ;
};





class AbstractProductButton {

    public:
        virtual ~AbstractProductButton(){};
        virtual std::string action() const =0 ;
};



class AbstractProductWindow {

    public:
        virtual ~AbstractProductWindow(){};
        virtual std::string action() const =0 ;
};


class AbstractProductIcon {

    public:
        virtual ~AbstractProductIcon(){};
        virtual std::string action() const =0 ;
};


class AbstractProductMenu {

    public:
        virtual ~AbstractProductMenu(){};
        virtual std::string action() const =0 ;
};

class AbstractProductSelector {

    public:
        virtual ~AbstractProductSelector(){};
        virtual std::string action() const =0 ;
};





class ConcreteProductButton : public AbstractProductButton{

    public:
        std::string action() const {
            return "====== GRAPHICAL USER INTERFACE WITH BUTTON \n";
        }
    
};


class ConcreteProductMenu : public AbstractProductMenu{

    public:
        std::string action() const {
            return "====== GRAPHICAL USER INTERFACE WITH MENU \n";
        }
    
};




class ConcreteProductIcon : public AbstractProductIcon{

    public:
        std::string action() const {
            return "====== GRAPHICAL USER INTERFACE WITH ICON \n";
        }
    
};


class ConcreteProductSelector : public AbstractProductSelector{

    public:
        std::string action() const {
            return "====== GRAPHICAL USER INTERFACE WITH SELECTOR \n";
        }
    
};



class ConcreteProductWindow : public AbstractProductWindow{

    public:
        std::string action() const {
            return "====== GRAPHICAL USER INTERFACE WITH WINDOW \n";
        }
    
};


class AbstractFactory{


    public:
        virtual AbstractProductSelector *createSelector() const = 0 ;
        virtual AbstractProductIcon *createIcon() const = 0 ;
        virtual AbstractProductWindow *createWindow() const = 0 ;
        virtual AbstractProductMenu *createMenu() const = 0 ;
        virtual AbstractProductButton *createButton() const = 0 ;
};



class ConcreteFactoryLinux : public AbstractFactory{

    public:
        AbstractProductSelector *createSelector() const {
            return new ConcreteProductSelector();
        }

    public:
        AbstractProductIcon *createIcon() const {
            return new ConcreteProductIcon();
        }

     public:
        AbstractProductWindow *createWindow() const {
            return new ConcreteProductWindow();
        }
    
    public:
        AbstractProductMenu *createMenu() const {
            return new ConcreteProductMenu();
        }
    
    public:
        AbstractProductButton *createButton() const {
            return new ConcreteProductButton();
        }

};




class ConcreteFactoryMac: public AbstractFactory{

    public:
        AbstractProductSelector *createSelector() const {
            return new ConcreteProductSelector();
        }

    public:
        AbstractProductIcon *createIcon() const {
            return new ConcreteProductIcon();
        }

     public:
        AbstractProductWindow *createWindow() const {
            return new ConcreteProductWindow();
        }
    
    public:
        AbstractProductMenu *createMenu() const {
            return new ConcreteProductMenu();
        }
    
    public:
        AbstractProductButton *createButton() const {
            return new ConcreteProductButton();
        }

};





class ConcreteFactoryWindows: public AbstractFactory{

    public:
        AbstractProductSelector *createSelector() const {
            return new ConcreteProductSelector();
        }

    public:
        AbstractProductIcon *createIcon() const {
            return new ConcreteProductIcon();
        }

     public:
        AbstractProductWindow *createWindow() const {
            return new ConcreteProductWindow();
        }
    
    public:
        AbstractProductMenu *createMenu() const {
            return new ConcreteProductMenu();
        }
    
    public:
        AbstractProductButton *createButton() const {
            return new ConcreteProductButton();
        }

};




void ClienteCode (const AbstractFactory &abstractFactory){

    const AbstractProductSelector *abstractProductSelector = abstractFactory.createSelector();
    std::cout << abstractProductSelector->action()  ;

    const AbstractProductIcon *abstractProductIcon = abstractFactory.createIcon();
     std::cout << abstractProductIcon->action()  ;

     const AbstractProductWindow *abstractProductWindow = abstractFactory.createWindow();
     std::cout << abstractProductWindow->action()  ;

     const AbstractProductMenu *abstractProductMenu = abstractFactory.createMenu();
     std::cout << abstractProductMenu->action()  ;

    const AbstractProductButton *abstractProductButton = abstractFactory.createButton();
     std::cout << abstractProductButton->action()  ;
     
    delete abstractProductMenu ;
    delete abstractProductWindow;
    delete abstractProductIcon ;
    delete abstractProductSelector ;
}


int main(){

    
    std::cout << " GRAPHICAL FRAMEWORK WORK ON LINUX OS \n" ;
    ConcreteFactoryLinux *concreteFactoryLinux = new ConcreteFactoryLinux();
    ClienteCode(*concreteFactoryLinux);
    delete concreteFactoryLinux ;

    std::cout << "\n" ;
     std::cout << " GRAPHICAL FRAMEWORK WORK ON MAC OS \n" ;
    ConcreteFactoryMac *concreteFactoryMac = new ConcreteFactoryMac();
    ClienteCode(*concreteFactoryMac);
    delete concreteFactoryMac ;

     std::cout << "\n" ;
     std::cout << " GRAPHICAL FRAMEWORK WORK ON WINDOWS OS \n" ;
    ConcreteFactoryWindows *concreteFactoryWindows = new ConcreteFactoryWindows();
    ClienteCode(*concreteFactoryWindows);
    delete concreteFactoryWindows ;

    return 0 ;
}