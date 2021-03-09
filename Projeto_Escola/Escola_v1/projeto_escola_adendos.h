typedef struct {
	char matricula[50];
	char nome[50];
	char sexo;
	char data[50];
	char cpf[50];
}aluno;

void cadastrarAlunos(int qtdAlunos, aluno estudante[]);
void mostrarAlunos(int qtdAlunos, aluno estudante[]);
int validarNome(char nome[]);
int validarSexo(char sexo);
int validarCPF(char cpf[]);
int validarData(char dataNasc[]);
int menu(int op);