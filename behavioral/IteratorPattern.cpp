#include <iostream>
#include <vector>
#include <algorithm>



template <typename T>

class Iterator{

    public : virtual bool hasNext() const = 0 ;
    public : virtual T next() = 0 ;
};



template <typename T>

class ConcreteIterator : public Iterator<T>{


    private : const std::vector<T>& mVector ;
    private : size_t index ;

    public : ConcreteIterator(const std::vector<T>& vec) : mVector(vec) , index(0){

    }

    public: bool hasNext() const {
        return index < mVector.size();
    }

    public: T next(){
        return mVector[index++];
    }

};



template <typename T>

class ConcreteCollection{

    private : std::vector<T> vector ;

    public : void add(const T& value){

        vector.push_back(value);

    }

    public : Iterator<T>* createIterator() const {

        return new ConcreteIterator<T>(vector);
    }
    
};



int main(){

ConcreteCollection<int> concreteCollection ;

concreteCollection.add(7);
concreteCollection.add(18);
concreteCollection.add(51);
concreteCollection.add(13);


Iterator<int>* iter = concreteCollection.createIterator();

while(iter->hasNext()){

    std::cout << iter->next() << " ";
}

std::cout << std::endl ;

    return 0 ;
}