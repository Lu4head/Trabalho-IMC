#include <iostream>
#include <string>
#include <locale.h>
#include <vector>

using namespace std;

// Define o struct Usu�rio que armazenar� os dados de um usu�rio cadastrado;
struct Usuario {
	string nome;
	int idade;
	float peso;
	float altura;
	float imc;
};
vector<Usuario> vetor_usuarios;

void exibir_usuario(string nome, int idade, float peso, float altura, float imc) {
	cout << "Nome = " << nome << endl;
	cout << "Idade = " << idade << " anos" << endl;
	cout << "Peso = " << peso << "kg" << endl;
	cout << "Altura = " << altura << "m" << endl;
	cout << "IMC = " << imc << "kg/m^2" << endl;

	if (imc < 18.5) {
		cout << "O usu�rio est� abaixo do peso!" << endl;
	}
	else if (imc < 25) {
		cout << "O usu�rio est� na faixa de IMC ideal." << endl;
	}
	else if (imc < 30) {
		cout << "O usu�rio est� com excesso de peso!" << endl;
	}
	else if (imc < 35) {
		cout << "O usu�rio est� com Obesidade Grau 1!" << endl;
	}
	else if (imc < 40) {
		cout << "O usu�rio est� com Obesidade Grau 2!!" << endl;
	}
	else if (imc >= 40) {
		cout << "O usu�rio est� com Obesidade Grau 3!!!" << endl;
	}
	else {
		cout << "IMC inv�lido!" << endl;
	}
	cout << endl;
	
	return;
}

// Fun��es do menu;
void cadastrar() {

	// Cria uma nova vari�vel do tipo struct Usuario para armazenas os dados
	Usuario usuario;

	cout << "\n\n=================================== Cadastro de Usu�rio =====================================\n";

	cout << "Digite o nome do usu�rio: ";
	cin.ignore();
	getline(cin, usuario.nome);

	cout << "Digite a idade: ";
	cin >> usuario.idade;
	while (usuario.idade < 1 || usuario.idade > 120)
	{
		cout << "Idade inv�lida ! Digite novamente... \n";
		cout << "Digite a idade: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> usuario.idade;
	}

	cout << "Digite o peso (em quilos) : ";
	cin >> usuario.peso;
	while (usuario.peso < 1 || usuario.peso > 500)
	{
		cout << "Peso inv�lido ! Digite novamente... \n";
		cout << "Digite o peso (em quilos) : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> usuario.peso;
	}

	cout << "Digite a altura (em metros) : ";
	cin >> usuario.altura;
	while (usuario.altura < 0.5 || usuario.altura > 3)
	{
		cout << "Altura inv�lida ! Digite novamente... \n";
		cout << "Digite a altura (em metros) : ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> usuario.altura;
	}

	usuario.imc = usuario.peso / (usuario.altura * usuario.altura);

	//Insere os dados cadastrados do usuario no vetor_usuarios.
	vetor_usuarios.push_back(usuario);

	cout << "=============================================================================================" << endl << "       Usu�rio cadastrado :       " << endl;
	exibir_usuario(usuario.nome, usuario.idade, usuario.peso, usuario.altura, usuario.imc);
	cout << "=============================================================================================" << endl;
}

void listar() {
	cout << endl << "=================================   Usu�rios cadastrados:   =================================\n\n";
	
	if (vetor_usuarios.empty()){
		cout << "Ainda n�o h� nenhum usu�rio cadastrado...   :(\n" << endl;
	}
	else {
		// Verifica as ocorrencias da struct Aluno & o objeto aluno no vetor vetor_alunos.
		for (const Usuario& usuario : vetor_usuarios) {
			exibir_usuario(usuario.nome, usuario.idade, usuario.peso, usuario.altura, usuario.imc);
		}
	}
	cout << "=============================================================================================" << endl;
}

void pesquisar() {
	string pesquisa;
	cout << "O que deseja procurar na lista ? : ";
	cin >> pesquisa;
	cout << "\n======================================   Resultados:   ======================================\n\n";
	// Verifica se ocorre a struct Aluno & o objeto aluno no vetor vetor_alunos.
	for (const Usuario& usuario : vetor_usuarios) {
		if (usuario.nome.find(pesquisa) != string::npos ||
			to_string(usuario.idade) == pesquisa ||
			to_string(usuario.peso) == pesquisa ||
			to_string(usuario.altura) == pesquisa ||
			to_string(usuario.imc) == pesquisa) {
			exibir_usuario(usuario.nome, usuario.idade, usuario.peso, usuario.altura, usuario.imc);
		}
	}
	cout << "=============================================================================================" << endl;
}

// Seleciona a a��o a ser executada;
void menu(const int& id) {
	switch (id)
	{
	case 1:
		cadastrar();
		break;
	case 2:
		listar();
		break;
	case 3:
		pesquisar();
		break;
	case 4:
		cout << "\n\n\nSaindo..." << endl;
		break;
	default:
		cout << "\nOp��o inv�lida! Digite novamente... \n" << endl;
		break;
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int id = 0;

	cout << "Bem-vindo ao SisIMC - Um sistema de cadastramento e calculo de IMC" << endl;
	do
	{
		cout << endl << "O que deseja fazer? " << endl;
		cout << "As fun��es dispon�veis sao: \n1-) Cadastrar\n2-) Listar\n3-) Pesquisar\n4-) Sair" << endl << "\nDigite o que deseja fazer : ";
		cin >> id;
		if (cin.fail()) {
			cout << "\nOp��o inv�lida! Digite novamente... \n" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			menu(id);
		}
	} while (id != 4);

	return 0;
}