#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 

class ProductNotification{
	
	public:
		std::vector<std::string> itens;
		
		void listItens() const{
		std::cout << " NOTIFICATION PARTS : " ;
		for(size_t i=0 ; i < itens.size() ; i++){
			
			if(itens[i] == itens.back()){
			   
			   std::cout << itens[i];
			}else{
				std::cout << itens[i] << " , " ;
			}			
		}
		std::cout << "\n\n";
		}


};


class Builder{
	public:
		virtual ~Builder(){}
		virtual void getAlert() const = 0 ;
		virtual void getMessage() const = 0 ;
		virtual void getDialog() const = 0 ;
		virtual void getEmail() const = 0 ;
		virtual void getSms() const = 0 ;
};


class ConcreteBuilder : public Builder{
	
	private:
		
	ProductNotification* productNotification;
	
	public:
	 ConcreteBuilder(){
	 	this-> Reset();
	 }
	 
	 ~ConcreteBuilder(){
	 	delete productNotification;
	 }
	 
	 void Reset(){
	 	this->productNotification = new ProductNotification();
	 }
	 
	 void getAlert()const {
	 	this->productNotification->itens.push_back("ALERT");
	 }
	 
	 void getMessage()const {
	 	this->productNotification->itens.push_back("MESSAGE");
	 }
	 
	void getDialog()const {
	 	this->productNotification->itens.push_back("DIALOG");
	 }

	void getEmail()const {
	 	this->productNotification->itens.push_back("EMAIL");
	 }

	void getSms()const {
	 	this->productNotification->itens.push_back("SMS");
	 }
	 
	 ProductNotification* getProduct(){
	 	ProductNotification* result = this->productNotification;
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
		
		void BuildBasic(){
			this->builder->getAlert();
			this->builder->getEmail();
		}
		
		void BuildFull(){
			this->builder->getAlert();
			this->builder->getMessage();
			this->builder->getDialog();
			this->builder->getEmail();
			this->builder->getSms();
		}
};

void ClientCode(Director director){
	ConcreteBuilder* builder = new ConcreteBuilder();
	director.setBuilder(builder);
	std::cout << "\n";

	std::cout << " BASIC NOTIFICATION : \n";
	director.BuildBasic();
	
	ProductNotification* p = builder->getProduct();
	p->listItens();
	delete p ;
	
	std::cout << " FULL NOTIFICATION :\n";
	director.BuildFull();
	
	p = builder->getProduct();
	p->listItens();
	delete p ;
	
	std::cout << " CUSTOM NOTIFICATION :\n";
	builder->getAlert();
	builder->getSms();
	p=builder->getProduct();
	p->listItens();
	delete p ;
	
	delete builder ;
}


int main(){
	Director* director = new Director();
	ClientCode(*director);
	delete director ;
	return 0;
}
