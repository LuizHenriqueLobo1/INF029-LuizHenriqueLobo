#define TAM 5

typedef struct {
	char matricula[50];
	char nome[50];
	char sexo;
	char data[50];
	char cpf[50];
}dados;

int menu_principal();
int menuAlunos();
int mainAlunos(dados estud[], int quantidadeAlunos);
void cadastrarAlunos(int qtdAlunos, dados estudante[]);
void mostrarAlunos(int qtdAlunos, dados estudante[]);
void alterarCadastroAlunos(int qtdAlunos, dados estudante[]);
int removerAluno(int qtdAlunos, dados estudante[]);
int validarMatricula(char matricula[]);
int validarNome(char nome[]);
int validarSexo(char sexo);
int validarCPF(char cpf[]);
int validarData(char dataNasc[]);