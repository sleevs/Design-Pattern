#include<iostream>


// desenho da interface alvo
class Retangulo {
	
	public :
		virtual void desenho() = 0 ;
};


// componente adapter
 class LegadoRetangulo {
 	
 	public:
 		
 		LegadoRetangulo (int tamanho,  int altura ){
		 
		 t = tamanho ;
	     a = altura ;
		 std::cout << " LegadoRetangulo(tamanho , altura) \n" ;
	
		 }
		 
		 
		 
		 
		 void antigoDesenho(){
		 	
		 	std::cout << " LegadoRetangulo : antigoDesenho(). \n" ;
		 }
		 
		 private:
		 	int t ;
			int a ;


 };
 
 
 
  class RetanguloAdapter: public Retangulo , private LegadoRetangulo{
  
  public:
  	RetanguloAdapter(int tamanho , int altura):
  		LegadoRetangulo(tamanho , altura){
  			
  			std::cout << "RetanguloAdapter(tamanho , altura) \n "; 
		  }
		  
  	void desenho(){
  		std::cout << " RetanguloAdapter : desenho(). \n ";
	  }
	  
	 
  
   };
 
 
  int main(){
	  	
	  	int tamanho = 80 ;
	  	int altura = 40 ;
	  	Retangulo *retangulo = new RetanguloAdapter(tamanho, tamanho);
	  	retangulo->desenho();
	  	
	  }
 
  
