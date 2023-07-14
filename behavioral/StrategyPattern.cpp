#include<iostream>
#include <memory>

using namespace std ;



class Strategy {

 public : virtual void algorithm() = 0 ;

};


class ConcreteStrategyA: public  Strategy {

	public : void algorithm() override {
		std::cout << " ESTRATEGIA 1 " <<std::endl;
	}
};



class ConcreteStrategyB	: public  Strategy {

	public : void algorithm() override {
		std::cout << " ESTRATEGIA 2 " <<std::endl;
	}
};



class Context {

	private : std::unique_ptr<Strategy> strategy_ ;

	public: void  setStrategy(std::unique_ptr<Strategy> strategy){
		strategy_ = std::move(strategy);
	}

	public: void executeStrategy(){
		strategy_->algorithm();
	}
};



int main(){

	Context context ;
	std::unique_ptr<ConcreteStrategyA> strategyA = std::make_unique<ConcreteStrategyA>();

	 context.setStrategy(std::move(strategyA));
	 context.executeStrategy();

	return 0 ;
}

