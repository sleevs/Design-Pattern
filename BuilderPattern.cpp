#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 

class Product{
	
	public:
		std::vector<std::string> parts_;
		
		void ListPart() const{
		std::cout << "PRODUCT PARTS: " ;
		for(size_t i=0 ; i < parts_.size() ; i++){
			
			if(parts_[i] == parts_.back()){
			   
			   std::cout << parts_[i];
			}else{
				std::cout << parts_[i] << " , " ;
			}			
		}
		std::cout << "\n\n";
		}


};


class Builder{
	public:
		virtual ~Builder(){}
		virtual void ProducerParteA() const = 0 ;
		virtual void ProducerParteB() const = 0 ;
		virtual void ProducerParteC() const = 0 ;
};


class ConcreteBuilder : public Builder{
	
	private:
		
	Product* product;
	
	public:
	 ConcreteBuilder(){
	 	this-> Reset();
	 }
	 
	 ~ConcreteBuilder(){
	 	delete product;
	 }
	 
	 void Reset(){
	 	this->product = new Product();
	 }
	 
	 void ProducerParteA()const override{
	 	this->product->parts_.push_back("PART A ");
	 }
	 
	 void ProducerParteB()const override{
	 	this->product->parts_.push_back("PART B ");
	 }
	 
	void ProducerParteC()const override{
	 	this->product->parts_.push_back("PART C ");
	 }
	 
	 Product* getProduct(){
	 	Product* result = this->product;
	 	this->Reset();
	 	return result ;
	 }
};


class Director{
	
	private:
		Builder* builder ;
	
	public:
		
		void setBuilder(Builder* builder){
			this->builder= builder;
		}
		
		void BuildMinimalVariableProduct(){
			this->builder->ProducerParteA();
		}
		
		void BuildFullFeactureProduct(){
			this->builder->ProducerParteA();
			this->builder->ProducerParteB();
			this->builder->ProducerParteC();
		}
};

void ClientCode(Director director){
	ConcreteBuilder* builder = new ConcreteBuilder();
	director.setBuilder(builder);
	std::cout << " STANDARD BASIC PRODUCT : \n";
	director.BuildMinimalVariableProduct();
	
	Product* p = builder->getProduct();
	p->ListPart();
	delete p ;
	
	std::cout << " STANDARD FULL FEACTURE PRODUCT :\n";
	director.BuildFullFeactureProduct();
	
	p = builder->getProduct();
	p->ListPart();
	delete p ;
	
	std::cout << " CUSTOM PRODUCT :\n";
	builder->ProducerParteA();
	builder->ProducerParteC();
	p=builder->getProduct();
	p->ListPart();
	delete p ;
	
	delete builder ;
}


int main(){
	Director* director = new Director();
	ClientCode(*director);
	delete director ;
	return 0;
}
