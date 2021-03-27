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

int validarData(char dataNasc[]) {

	int retorno;

	long int data = atoi(dataNasc);

	if(strlen(dataNasc) - 1 == 6) {
		int digito1 = 0;
		int digito2 = 0;
		int digito3 = 0;
		int digito4 = 0;
		int digito5 = 0;
		int digito6 = 0;
		digito1 = (data / 100000) % 10;
		digito2 = (data / 10000) % 10;
		digito3 = (data / 1000) % 10;
		digito4 = (data / 100) % 10;
		digito5 = (data / 10) % 10;
		digito6 = data % 10;

		// Dividindo os números em três partes (Dias, Meses, Anos);
		
		// Dias
		int digito1Dia = digito1 * 10;
		int digito2Dia = digito2;
		int digitosDias = digito1Dia + digito2Dia;
		if(digitosDias <= 0 || digitosDias > 31) {
			retorno = -1;
		} else {
			// Meses
			int digito1Mes = digito3 * 10;
			int digito2Mes = digito4;
			int digitosMes = digito1Mes + digito2Mes;
			if(digitosMes <= 0 || digitosMes > 12) {
				retorno = -1;
			} else {
				int digito1Ano = digito5 * 10;
				int digito2Ano = digito6;
				int digitosAno = digito1Ano + digito2Ano;
				if(digitosAno < 0 || digitosAno > 21) {
					retorno = -1;
				} else {
					retorno = 1;
				}
			}
		}
	} else if(strlen(dataNasc) -1 == 8) {
		int digito1 = 0;
		int digito2 = 0;
		int digito3 = 0;
		int digito4 = 0;
		int digito5 = 0;
		int digito6 = 0;
		int digito7 = 0;
		int digito8 = 0;
		digito1 = (data / 10000000) % 10;
		digito2 = (data / 1000000) % 10;
		digito3 = (data / 100000) % 10;
		digito4 = (data / 10000) % 10;
		digito5 = (data / 1000) % 10;
		digito6 = (data / 100) % 10;
		digito7 = (data / 10) % 10;
		digito8 = data % 10;		

		// Dias
		int digito1Dia = digito1 * 10;
		int digito2Dia = digito2;
		int digitosDia = digito1Dia + digito2Dia;
		if(digitosDia <= 0 || digitosDia > 31) {
			retorno = -1;
		} else {
			// Meses
			int digito1Mes = digito3 * 10;
			int digito2Mes = digito4;
			int digitosMes = digito1Mes + digito2Mes;
			if(digitosMes <= 0 || digitosMes > 12) {
				retorno = -1;
			} else {
				// Anos
				int digito1Ano = digito5 * 1000;
				int digito2Ano = digito6 * 100;
				int digito3Ano = digito7 * 10;
				int digito4Ano = digito8;
				int digitosAno = digito1Ano + digito2Ano + digito3Ano + digito4Ano;
				if(digitosAno <= 0 || digitosAno > 2021) {
					retorno = -1;
				} else {
					retorno = 1;
				}
			}
		}
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

int validarSemestre(int semestre) {

	int retorno;

	if(semestre <= 0 || semestre > 12) {
		retorno = -1;
	} else {
		retorno = 1;
	}

	return retorno;
}