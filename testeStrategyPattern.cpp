#include<iostream>

using namespace std ;


class ComportamentoOrganizar {

	public:
		virtual void sort() const = 0 ;
};

class Merge: public ComportamentoOrganizar {

		public:
		virtual void sort() const  {

	std::cout << "\n" ;
			cout << " MERGE CONSTANTE()" ;
				std::cout << "\n" ;
		}
};

class Rapido: public ComportamentoOrganizar {

	public:
		virtual void sort() const  {

			cout << "RAPIDO sort()";
		}

};


class ComportamentoBuscar {

	public:
		virtual void buscar() const  = 0 ;
};


class Heap: public ComportamentoOrganizar {

	public:
		virtual void sort() const  {

			cout << " HEAP SORT()" ;
		}
};

class Sequencial: public ComportamentoBuscar {

	public:

		virtual void buscar() const  {



			cout << " Sequencial buscar()";
				std::cout << "\n" ;
		}
};


class ArvoreBinaria: public ComportamentoBuscar {

	public:
		virtual void buscar() const  {

	std::cout << "\n" ;
			cout << " ArvoreBinaria buscar()" ;
				std::cout << "\n" ;
		}
};


class HashTable: public ComportamentoBuscar {


	public:
		virtual void buscar() const  {

			cout << " hashtable buscar()";
		}

};


class Colecao {


	private:
		ComportamentoOrganizar * ponteiroOrganizar ;
		ComportamentoBuscar * ponteiroBuscar ;


	public:
		Colecao() {
		}

		void setOrganizar(ComportamentoOrganizar* co) {
			ponteiroOrganizar = co ;
		}

		void setBuscar(ComportamentoBuscar* cb) {

			ponteiroBuscar =  cb ;

		}


		void sort() const  {

			ponteiroOrganizar->sort();
		}

		void buscar() const  {

			ponteiroBuscar->buscar();
		}

};


int main(void) {

	std::cout << "\n" ;
	std::cout << "\n" ;
	std::cout << "\n" ;

	std::cout << " JSN - ENGENHARIA DE SOFTWARE C++ - DESIGN PATTERN STRATEGY \n" ;

	std::cout << "\n" ;
	std::cout << "\n" ;
	std::cout << "\n" ;
	std::cout << "\n" ;


	Merge merge ;
	Rapido rapido ;
	Heap heap ;

	Sequencial sequencial ;
	ArvoreBinaria arvoreBinaria ;
	HashTable hashTable ;

	Colecao colecaoA ;

	colecaoA.setOrganizar(&merge);
	colecaoA.sort();


	Colecao colecaoB;
	colecaoB.setBuscar(&arvoreBinaria);
	colecaoB.buscar();


	std::cout << "\n" ;
	std::cout << "\n" ;
	std::cout << "\n" ;
	std::cout << "\n" ;

	return 0 ;
}
