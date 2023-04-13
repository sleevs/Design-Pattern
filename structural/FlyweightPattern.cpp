#include <string>
#include <iostream>
#include <unordered_map>

using namespace std ;



class Flyweight {

    private:
     string name ;
     string id ;


    public:
        Flyweight(string name , string id) : name(name) , id(id) {}

    
    public: void operation(){

        cout<< "MODELO: " << name << id << "\n";
    }

};



class FlyweightFactory {

        private: unordered_map<string  , Flyweight*> modelosMap ;


        public : Flyweight* getModels(string name , string id){

                if(modelosMap.find(name) == modelosMap.end()){
                  modelosMap[name] = new Flyweight(name , id); 
                  
                   cout<< "NOVO OBJETO FLYWEIGHT\n" ;
                   return  modelosMap[name]; 
                }else{
                      cout<<  "OBJETO FLYWEIGHT EXISTENTE\n" ;
                      return  modelosMap[name];
                }
               
        }

};



int main(){

    FlyweightFactory factory ;
    Flyweight* carro = factory.getModels("COROLA","1313");
    Flyweight* carro2 = factory.getModels("COROLA","1313");
    Flyweight* carro3 = factory.getModels("BMW","1313");

   

        
    return 0 ;
}