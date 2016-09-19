#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Teste
{
public:
	Teste();
	~Teste();

	void Salvar();
	void Perguntar(string, int, string, string);
	void Mostrar();


private:
	struct PERFIL
	{
		string nomeCliente;
		int idadeCliente;
		string CPFCliente;
		string emailCliente;
	};

	vector<PERFIL> usuario;
};

Teste::Teste()
{
	usuario.resize(0);
}

Teste::~Teste()
{
	usuario.clear();
}

void Teste::Perguntar(string nome, int idade, string CPF, string email)
{
	PERFIL novoPerfil;
	novoPerfil.nomeCliente = nome;
	novoPerfil.idadeCliente = idade;
	novoPerfil.CPFCliente = CPF;
	novoPerfil.emailCliente = email;

	usuario.push_back(novoPerfil);
}

void Teste::Salvar()
{

	for (int i = 0; i < usuario.size(); i++)
	{
		string id = usuario[i].CPFCliente;
		ofstream arq("CPF_" + id + ".txt");
		if (arq.is_open())
		{
			arq << endl << " ---------------FR INFORM햀ICA--------------- " << endl << endl;
			arq << "  NOME: " << usuario[i].nomeCliente << endl;
			arq << " IDADE: " << usuario[i].idadeCliente << endl;
			arq << "   CPF: " << usuario[i].CPFCliente << endl;
			arq << "E-MAIL: " << usuario[i].emailCliente << endl << endl;
			arq << " -------------------------------------------- " << endl;

			arq.flush();
			arq.close();
		}
		else
		{
			cerr << "\n\nERRO!" << endl;
			system("PAUSE");
		}
	}
}

void Teste::Mostrar()
{
	cout << endl << " ---------------FR INFORM햀ICA--------------- " << endl << endl;
	for (int i = 0; i < usuario.size(); i++)
	{
		cout << "  NOME: " << usuario[i].nomeCliente << endl;
		cout << " IDADE: " << usuario[i].idadeCliente << endl;
		cout << "   CPF: " << usuario[i].CPFCliente << endl;
		cout << " EMAIL: " << usuario[i].emailCliente << endl << endl;

		if (usuario.size() > 1)
		{
			cout << " -------------------------------------------- " << endl << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	Teste *t = new Teste();
	string nome, sobrenome, CPF, email;
	int idade, opc = 0;

	while (1)
	{
		try
		{
			system("CLS");
			cout << endl << " ---------------FR INFORM햀ICA--------------- " << endl << endl;
			cout << " 1 - CADASTRAR" << endl;
			cout << " 2 - MOSTRAR" << endl;
			cout << " 3 - SALVAR" << endl;
			cout << " 4 - SAIR" << endl;
			cout << " > ";
			cin >> opc;
			cin.ignore();

			switch (opc)
			{
			case 1:
				try
				{
					system("CLS");
					cout << endl << " ---------------FR INFORM햀ICA--------------- " << endl << endl;
					cout << "   NOME: ";
					getline(cin, nome);
					cout << "  IDADE: ";
					cin >> idade;
					cin.ignore();
					cout << "    CPF: ";
					getline(cin, CPF);
					cout << " E-MAIL: ";
					getline(cin, email);

					t->Perguntar(nome, idade, CPF, email);

				}
				catch (exception)
				{
					system("CLS");
					cerr << " ERRO!" << endl;
					system("PAUSE");
				}
				break;

			case 2:
				system("CLS");
				t->Mostrar();
				system("PAUSE");
				break;

			case 3:
				t->Salvar();
				break;

			case 4:
				exit(0);
				break;

			default:
				system("CLS");
				cout << " Error" << endl;
				system("PAUSE");
			}
		}
		catch (exception)
		{
			system("CLS");
			cerr << " ERRO!" << endl;
			system("PAUSE");
		}
	}

	cout << endl;
	system("PAUSE");
	return 0;
}
