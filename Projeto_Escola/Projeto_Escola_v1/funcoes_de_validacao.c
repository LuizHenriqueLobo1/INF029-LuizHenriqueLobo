#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarNome(char nome[]) {

	int retorno;

	if(strlen(nome) - 1 > 20 || strlen(nome) - 1 <= 0) {
		retorno = -1;
	} else {
		retorno = 1;
	}

	return retorno;
}

int validarSexo(char sexo) {

	int retorno;
	sexo = toupper(sexo);

	if(sexo == 'M' || sexo == 'F' || sexo == 'O') {
		retorno = 1;
	} else {
		retorno = -1;
	}

	return retorno;
}

int validarCPF(char cpf[]) {

	int retorno;

	if(strlen(cpf) - 1 != 11) {
		retorno = -1;
	} else {
		double cpfInt = atof(cpf);

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
			retorno = 1;
		} else {
			retorno = -1;
		}
	}

	return retorno;
}

int validarData_tamanho(char data[]) {

	int retorno;

	if(strlen(data) - 1 < 11 && strlen(data) - 1 > 5) {
		retorno = 1;
	} else {
		retorno = -1;
	}

	return retorno;
}

int validarData_digitos(char data[]) {

	int retorno;
	int contador = 0;
	int i;

	for(i = 0; data[i] != '\0'; i++) {
		if(data[i] == '/') {
			contador++;
		}
	}

	if(contador == 2) {
		retorno = 1;
	} else {
		retorno = -1;
	}

	return retorno;
}

int validarData_main(char data[]) {

	int retorno;
	char *dia;
	char *mes;
	char *ano;
	int diaI;
	int mesI;
	int anoI;
	int contador = 0;
	int tamAno;

	dia = strtok(data, "/");
	mes = strtok(NULL, "/");
	ano = strtok(NULL, "/");

	ano[strlen(ano)-1] = '\0';

	diaI = atoi(dia);
	mesI = atoi(mes);
	anoI = atoi(ano);

	if(strlen(ano) == 2) {
		anoI += 2000;
		tamAno = 4;
	}
	if(strlen(ano) == 4 || tamAno == 4) {

		if(mesI == 1 || mesI == 3 || mesI == 5 || mesI == 7 || mesI == 8 || mesI == 10 || mesI == 12) {
			if(diaI <= 0 || diaI > 31) {
				// Dia inválido
				retorno = 0;
			} else {
				// Dia válido
				retorno = 1;
			}
		} else if(mesI == 2) {
			// Descobre se o ano é bissexto
			if(anoI % 4 == 0)
				contador++;
			if(anoI % 100 == 0) 
				contador--;
			if(anoI % 400 == 0) 
				contador++;
			// Contador > 0 = Ano bissexto
			if(contador > 0) {
				// Ano bissexto
				if(mesI == 2) {
					if(diaI <= 0 || diaI > 29) {
						// Dia inválido
						retorno = 0;
					} else {
						// Dia válido
						retorno = 1;
					}	
				}
			}
			// Contador <= 0 = Ano nao bissexto
			else {
				// Ano naõ bissexto
				if(mesI == 2) {
					if(diaI <= 0 || diaI > 28) {
						// Dia inválido
						retorno = 0;
					} else {
						// Dia válido
						retorno = 1;
					}
				}
			}
		}
		else if(mesI == 4 || mesI == 6 || mesI == 9 || mesI == 11) {
			if(diaI <= 0 || diaI > 30) {
				// Dia inválido
				retorno = 0;
			} else {
				// Dia válido
				retorno = 1;
			}
		}
		else {
			// Mês inválido
			retorno = 0;
		}
	} else {
		// Ano inválido
		retorno = 0;
	}

	return retorno;
}

int validarData(char data[]) {

	int retorno;
	char dataAux[15];
	strcpy(dataAux, data);

	if(validarData_tamanho(data) != 1) {
		retorno = -1;
	} else if(validarData_digitos(data) != 1) {
		retorno = -1;
	} else if(validarData_main(data) != 1) {
		retorno -1;
	} else {
		retorno = 1;
	}

	strcpy(data, dataAux);

	return retorno;
}

int validarCodigoDisciplina(char codigo[]) {

	int retorno;

	if(strlen(codigo) - 1 <= 0 || strlen(codigo) - 1 > 10) {
		retorno = -1;
	} else {
		retorno = 1;
	}


	return retorno;
}

int validarNomeDisciplina(char nomeDisciplina[]) {

	int retorno;

	if(strlen(nomeDisciplina) - 1 < 1 || strlen(nomeDisciplina) - 1 > 30) {
		retorno = -1;
	} else {
		retorno = 1;
	}

	return retorno;
}

int validarSemestreDisciplina(int semestre) {

	int retorno;

	if(semestre <= 0 || semestre > 12) {
		retorno = -1;
	} else {
		retorno = 1;
	}

	return retorno;
}