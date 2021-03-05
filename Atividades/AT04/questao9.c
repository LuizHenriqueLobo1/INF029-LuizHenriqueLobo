#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*9) Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada
validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente
deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado
com sucesso ou se houve erro, informando onde foi o erro:
• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
masculino; f e F para feminino, o e O para outro).
• função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
• função validarNacimento: recebe o data digitada, e valida é uma data válida.*/

typedef struct {
	char nome[50];
	char dataNascimento[50];
	char cpf[50];
	char sexo;
}cliente;

cliente cadastrarCliente();
int validarNome(cliente valores);
int validarSexo(cliente valores);
int validarCPF(cliente valores);

int main() {

	cliente valor;
	
	valor = cadastrarCliente();

	printf("------------------------------------");
	printf("\nDADOS DO CLIENTE\n");
	printf("Nome: %s", valor.nome);
	printf("Data de nascimento: %s", valor.dataNascimento);
	printf("CPF: %s", valor.cpf);
	printf("Sexo: %c", valor.sexo);
	printf("\n------------------------------------\n");

	return 0;
}

cliente cadastrarCliente() {

	cliente valores;
	int validacaoNome = 0;
	int validacaoSexo = 0;
	int validacaoCPF = 0;

	printf("\nDigite o nome do cliente: ");
	fgets(valores.nome, 25, stdin);
	setbuf(stdin, NULL);

	printf("Digite a data de nascimento do cliente: ");
	fgets(valores.dataNascimento, 11, stdin);
	setbuf(stdin, NULL);

	printf("Digite o cpf do cliente: ");
	fgets(valores.cpf, 20, stdin);

	printf("Digite o sexo do cliente: ");
	scanf("%c", &valores.sexo);
	setbuf(stdin, NULL);

	printf("\n------------------------------------");
	printf("\nVALIDACOES DO CADASTRO");
	validacaoNome = validarNome(valores);
	if(validacaoNome == 1) {
		printf("\nValidacao do nome feita com sucesso!");
	} else {
		printf("\nErro na validacao do nome!");
	}

	validacaoSexo = validarSexo(valores);
	if(validacaoSexo == 1) {
		printf("\nValidacao do sexo feita com sucesso!");
	} else {
		printf("\nErro na validacao do sexo!");
	}
	
	validacaoCPF = validarCPF(valores);
	if(validacaoCPF == 1) {
		printf("\nValidacao do CPF feita com sucesso!");
	} else {
		printf("\nErro na validacao do CPF!");
	}
	printf("\n------------------------------------\n\n");


	return valores;
}

int validarNome(cliente valores) {

	int tamanho = 0;

	tamanho = strlen(valores.nome);

	if(tamanho <= 1 || tamanho > 21) {
		return -1;
	} else {
		return 1;
	}
}

int validarSexo(cliente valores) {

	valores.sexo = toupper(valores.sexo);

	if(valores.sexo=='M' || valores.sexo=='F' || valores.sexo=='O') {
		return 1;
	} else {
		return -1;
	}
}

int validarCPF(cliente valores) {

	double cpfInt = atof(valores.cpf);

	double primeiroDigitoF = 0;
	int primeiroDigito = 0;
	int segundoDigito = 0;
	int terceiroDigito = 0;
	int quartoDigito = 0;
	int quintoDigito = 0;
	int sextoDigito = 0;
	int setimoDigito = 0;
	int oitavoDigito = 0;
	int nonoDigito = 0;

	// Validando primeiro digito vericador

	int multiDigito1 = 0;
	int multiDigito2 = 0;
	int multiDigito3 = 0;
	int multiDigito4 = 0;
	int multiDigito5 = 0;
	int multiDigito6 = 0;
	int multiDigito7 = 0;
	int multiDigito8 = 0;
	int multiDigito9 = 0;

	int somaDigitos = 0;
	int restoDigitos = 0;
	int subDigitos = 0;

	int primeiroDigitoVerificador = 0;

	primeiroDigitoF = cpfInt / 10000000000;
	primeiroDigito = primeiroDigitoF;
	segundoDigito = cpfInt / 1000000000;
	segundoDigito = segundoDigito % 10;
	terceiroDigito = cpfInt / 100000000;
	terceiroDigito = terceiroDigito % 10;
	quartoDigito = cpfInt / 10000000;
	quartoDigito = quartoDigito % 10;
	quintoDigito = cpfInt / 1000000;
	quintoDigito = quintoDigito % 10;
	sextoDigito = cpfInt / 100000;
	sextoDigito = sextoDigito % 10;
	setimoDigito = cpfInt / 10000;
	setimoDigito = setimoDigito % 10;
	oitavoDigito = cpfInt / 1000;
	oitavoDigito = oitavoDigito % 10;
	nonoDigito = cpfInt / 100;
	nonoDigito = nonoDigito % 10;

	//	Pegando últimos digitos informados

	long long int decimoDigito  =0;
	long long int decimo1Digito = 0;

	decimoDigito = cpfInt / 10;
	decimoDigito = decimoDigito % 10;
	decimo1Digito = cpfInt;
	decimo1Digito = decimo1Digito % 10;
	//decimo1Digito = decimoDigito % 10;

	//decimo1Digito = decimo1Digito % 10;

	multiDigito1 = primeiroDigito * 10;
	multiDigito2 = segundoDigito  * 9;
	multiDigito3 = terceiroDigito * 8;
	multiDigito4 = quartoDigito   * 7;
	multiDigito5 = quintoDigito   * 6;
	multiDigito6 = sextoDigito    * 5;
	multiDigito7 = setimoDigito   * 4;
	multiDigito8 = oitavoDigito   * 3;
	multiDigito9 = nonoDigito     * 2;

	somaDigitos = (multiDigito1 + multiDigito2 + multiDigito3 + multiDigito4
				    + multiDigito5 + multiDigito6 + multiDigito7 + multiDigito8 + multiDigito9);

	restoDigitos = somaDigitos % 11;

	subDigitos = 11 - restoDigitos;

	if(subDigitos >= 10) {
		primeiroDigitoVerificador = 0;
	} else {
		primeiroDigitoVerificador = subDigitos;
	}

	// Validando segundo digito verifcador

	int multi2Digito1 = 0;
	int multi2Digito2 = 0;
	int multi2Digito3 = 0;
	int multi2Digito4 = 0;
	int multi2Digito5 = 0;
	int multi2Digito6 = 0;
	int multi2Digito7 = 0;
	int multi2Digito8 = 0;
	int multi2Digito9 = 0;
	int multi2Digito10 = 0;

	int soma2Digitos = 0;
	int resto2Digitos = 0;
	int sub2Digitos = 0;

	int segundoDigitoVerificador = 0;

	multi2Digito1 = primeiroDigito * 11;
	multi2Digito2 = segundoDigito  * 10;
	multi2Digito3 = terceiroDigito * 9;
	multi2Digito4 = quartoDigito   * 8;
	multi2Digito5 = quintoDigito   * 7;
	multi2Digito6 = sextoDigito    * 6;
	multi2Digito7 = setimoDigito   * 5;
	multi2Digito8 = oitavoDigito   * 4;
	multi2Digito9 = nonoDigito     * 3;
	multi2Digito10 = primeiroDigitoVerificador * 2;

	soma2Digitos = (multi2Digito1 + multi2Digito2 + multi2Digito3 + multi2Digito4 + multi2Digito5
				    + multi2Digito6 + multi2Digito7 + multi2Digito8 + multi2Digito9 + multi2Digito10);

	resto2Digitos = soma2Digitos % 11;

	sub2Digitos = 11 - resto2Digitos;
	
	if(sub2Digitos >= 10) {
		segundoDigitoVerificador = 0;
	} else {
		segundoDigitoVerificador = sub2Digitos;
	}

	if(decimoDigito == primeiroDigitoVerificador && decimo1Digito == segundoDigitoVerificador) {
		return 1;
	} else {
		return -1;
	}

	/*printf("\n\n\nCPF Inteiro: %.0lf\n", cpfInt);
	printf("Digito 1  do CPF: %d\n", primeiroDigito);
	printf("Digito 2  do CPF: %d\n", segundoDigito);
	printf("Digito 3  do CPF: %d\n", terceiroDigito);
	printf("Digito 4  do CPF: %d\n", quartoDigito);
	printf("Digito 5  do CPF: %d\n", quintoDigito);
	printf("Digito 6  do CPF: %d\n", sextoDigito);
	printf("Digito 7  do CPF: %d\n", setimoDigito);
	printf("Digito 8  do CPF: %d\n", oitavoDigito);
	printf("Digito 9  do CPF: %d\n", nonoDigito);
	printf("Digito 10 do CPF: %d\n", decimoDigito);
	printf("Digito 11 do CPF: %d\n\n\n", decimo1Digito);
	printf("Digito 10 correto do CPF: %d\n", primeiroDigitoVerificador);
	printf("Digito 11 correto do CPF: %d\n\n\n", segundoDigitoVerificador);*/
	
	return 0;
}