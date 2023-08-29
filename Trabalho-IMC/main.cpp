#include <iostream>
#include <string>
#include <locale.h>
#include <vector>

//teste de commit

using namespace std;

// Define o struct Usuário que armazenará os dados de um usuário cadastrado;
struct Usuario {
	string nome;
	int idade;
	float peso;
	float altura;
	float imc;
};
vector<Usuario> vetor_usuarios;

float calcula_imc(float peso, float altura) {
	float imc = peso / (altura * altura);
	return imc;
}

void exibir_usuario(string nome, int idade, float peso, float altura, float imc) {
	cout << "Nome = " << nome << endl;
	cout << "Idade = " << idade << endl;
	cout << "Peso = " << peso << endl;
	cout << "Altura = " << altura << endl;
	cout << "IMC = " << imc << endl;

	if (imc > 20) {
		cout << "O usuário está acima da faixa de IMC ideal" << endl;
	}
	else if (imc < 15) {
		cout << "O usuário está abaixo da faixa de IMC ideal" << endl;
	}
	else {
		cout << "O usuário está dentro da faixa de IMC ideal" << endl;
	}
	cout << endl;
	return;
}

// Funções do menu;
int cadastrar() {

	// Cria uma nova variável do tipo struct Usuario para armazenas os dados
	Usuario usuario;

	cout << "\n\n=================================== Cadastro de Usuário =====================================\n";

	cout << "Digite o nome do usuário: ";
	cin.ignore();
	getline(cin, usuario.nome);

	cout << "Digite a idade: ";
	cin >> usuario.idade;
	while (usuario.idade < 1 || usuario.idade > 120)
	{
		cout << "Idade inválida ! Digite novamente... \n";
		cout << "Digite a idade: ";
		cin >> usuario.idade;
	}

	cout << "Digite o peso (em quilos) : ";
	cin >> usuario.peso;
	while (usuario.peso < 1 || usuario.peso > 500)
	{
		cout << "Peso inválido ! Digite novamente... \n";
		cout << "Digite o peso (em quilos) : ";
		cin >> usuario.peso;
	}

	cout << "Digite a altura (em metros) : ";
	cin >> usuario.altura;
	while (usuario.altura < 0.5 || usuario.altura > 3)
	{
		cout << "Altura inválida ! Digite novamente... \n";
		cout << "Digite a altura (em metros) : ";
		cin >> usuario.altura;
	}

	usuario.imc = calcula_imc(usuario.peso, usuario.altura);

	//Insere os dados cadastrados do usuario no vetor_usuarios.
	vetor_usuarios.push_back(usuario);

	cout << "=============================================================================================" << endl << "       Usuário cadastrado :       " << endl;
	exibir_usuario(usuario.nome, usuario.idade, usuario.peso, usuario.altura, usuario.imc);
	cout << "=============================================================================================" << endl;
	return 0;
}
int listar() {
	cout << endl << "=================================   Usuários cadastrados:   =================================\n\n";
	// Verifica as ocorrencias da struct Aluno & o objeto aluno no vetor vetor_alunos.
	for (const Usuario& usuario : vetor_usuarios) {
		exibir_usuario(usuario.nome, usuario.idade, usuario.peso, usuario.altura, usuario.imc);
	}
	cout << "=============================================================================================" << endl;
	return 0;
}
int pesquisar() {
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
	return 0;
}
int sair() {
	cout << "\n\n\n\n\nsaindo...";
	return 0;
}

// Seleciona a ação a ser executada;
int menu(int id) {
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
		sair();
		break;
	default:
		cout << "\nOpção inválida! Digite novamente... \n" << endl;
		break;
	}
	return id;
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	int id = 0;

	cout << "Bem-vindo ao SisIMC - Um sistema de cadastramento e calculo de IMC" << endl;
	do
	{
		cout << endl << "O que deseja fazer? " << endl;
		cout << "As funções disponíveis sao: \n1-) Cadastrar\n2-) Listar\n3-) Pesquisar\n4-) Sair" << endl << "\nDigite o que deseja fazer : ";
		cin >> id;
		menu(id);
	} while (id != 4);

	return 0;
}