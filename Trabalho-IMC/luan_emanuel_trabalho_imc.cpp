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
// Vetor onde ficar�o armazenados os usu�rios cadastrados (structs)
vector<Usuario> vetor_usuarios;

// Exibe na tela os dados de um usu�rio
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

// Permite cadastrar um novo usu�rio definindo seus dados (nome, idade, altura e peso)
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
	while (usuario.altura < 0.5 || usuario.altura > 2.5)
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

// Lista todos os usu�rios cadastrados
void listar(const vector<Usuario>& vetor_usuarios) {
	cout << endl << "=================================   Usu�rios cadastrados:   =================================\n\n";
	
	if (vetor_usuarios.empty()){
		cout << "Ainda n�o h� nenhum usu�rio cadastrado...   :(\n" << endl;
	}
	else {
		// Para cada struct usuario em vetor_usuarios exibe o usuario.
		for (const Usuario& usuario : vetor_usuarios) {
			exibir_usuario(usuario.nome, usuario.idade, usuario.peso, usuario.altura, usuario.imc);
		}
	}
	cout << "=============================================================================================" << endl;
}

// Pede ao usu�rio uma entrada para se usada para pesquisar nos dados da lista de usu�rios cadastrados
void pesquisar(const vector<Usuario>& vetor_usuarios) {
	string pesquisa;
	cout << "O que deseja procurar na lista ? : ";
	cin >> pesquisa;
	cout << "\n======================================   Resultados:   ======================================\n\n";
	// Para cada struct usuario no vetor_usuarios executa a fun��o exibir_usuario.
	for (const Usuario& usuario : vetor_usuarios) {
		// Verifica se a pesquisa ocorre no nome de algum dos usu�rios.
		if (usuario.nome.find(pesquisa) != string::npos) {
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
		listar(vetor_usuarios);
		break;
	case 3:
		pesquisar(vetor_usuarios);
		break;
	case 4:
		cout << "\n\n\nEncerrando o programa... Obrigado por usar o SisIMC!" << endl;
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
	} while (id != 4); // Pede ao usu�rio o id para ser utilizado no menu e encerra a fun��o caso o n�mero digitado seja igual a 4.

	return 0;
}