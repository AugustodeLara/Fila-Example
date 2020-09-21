
#include <iostream>
#include <cstddef>
using namespace std;

class No
{
	friend class Lista;

private:
	int valor;
	No *Pproximo;

public:
	No(int val)
		: valor(val), Pproximo(NULL)
	{

	}

};

class Lista
{
private:
	No *PCabeca;
	No *PCalda;

	No *PegaNo(int v);

public:
	Lista(void);
	//Lista(int val);

	//adiciona um no
	void AdicionaNoBack(int val);

	//remove No
	bool RemoveNoFront();

	//bool ListaVazia();
	void Imprimir();
};

Lista::Lista() :PCabeca(NULL), PCalda(NULL)
{

}

void Lista::AdicionaNoBack(int val)
{
	No *AuxP = PegaNo(val);

	if (PCabeca == NULL)
	{
		PCabeca = PCalda = AuxP;
	}
	else
	{
		PCalda->Pproximo = AuxP;
		PCalda = AuxP;
	}
}

bool Lista::RemoveNoFront()
{
	if (PCabeca == NULL)
	{
		return false;
	}
	else
	{
		No * Ptemp = PCabeca;

		if (PCabeca == PCalda)
		{
			PCabeca = PCalda = NULL;
		}
		else
		{
			PCabeca = PCabeca->Pproximo;
		}

		delete Ptemp;
		return true;
	}
}


No *Lista::PegaNo(int valor)
{
	No *aux = new No(valor);
	return aux;
}

void Lista::Imprimir()
{
	No *p = PCabeca;

	if (PCabeca == NULL)
	{
		cout << "Fila vazia" << endl;

	}

	cout << "Fila: ";
	while (p != NULL) {
		cout << p->valor;
		p = p->Pproximo;
	}
	cout << endl;
}

class Filas :private Lista
{
public:
	void entra(int val)
	{
		AdicionaNoBack(val);
	}

	bool sai()
	{
		return RemoveNoFront();
	}

	void imprimeF()
	{
		Imprimir();
	}
};

int main()
{
	Filas fila;

	fila.entra(1);
	fila.entra(2);
	fila.entra(3);
	fila.entra(4);

	fila.imprimeF();

	fila.sai();
	fila.sai();

	fila.imprimeF();

	system("pause");
	return 0;
}
