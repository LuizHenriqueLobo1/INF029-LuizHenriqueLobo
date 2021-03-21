#define TAM 5

typedef struct {
	char codigo[50];
	char nome[50];
	int semestre;
	int numProfessor;
	int numAluno;
}disc;

typedef struct {
	char matricula[50];
	char nome[50];
	char sexo;
	char data[50];
	char cpf[50];
}dados;

// Menus
int menu_principal();
int menuAluno();
int menuProfessor();
int menuDisciplina();
int menu_alterarCadastroA(int num);
int menu_alterarCadastroP(int num);
int menu_alterarCadastroD(int num);

// Aluno
int mainAluno(dados aluno[], int qtdAluno);
void cadastrarAluno(int qtdAluno, dados aluno[]);
void mostrarAluno(int qtdAluno, dados aluno[]);
void alterarCadastroAluno(int qtdAluno, dados aluno[]);
int removerAluno(int qtdAluno, dados aluno[]);

// Professor
int mainProfessor(dados professor[], int qtdProfessor);
void cadastrarProfessor(int qtdProfessor, dados professor[]);
void mostrarProfessor(int qtdProfessor, dados professor[]);
void alterarCadastroProfessor(int qtdProfessor, dados professor[]);
int removerProfessor(int qtdProfessor, dados professor[]);

// Disciplina
int mainDisciplina(disc disciplina[], int qtdDisciplina, int qtdProfessor, int qtdAluno, dados professor[], dados aluno[]);
int cadastrarDisciplina(int qtdDisciplina, disc disciplina[], int qtdProfessor, int qtdAluno);
void mostrarDisciplina(int qtdDisciplina, disc disciplina[], int qtdProfessor, int qtdAluno, dados professor[], dados aluno[]);
void alterarCadastroDisciplina(int qtdDisciplina, disc disciplina[], int qtdProfessor, int qtdAluno);
int removerDisciplina(int qtdDisciplina, disc disciplina[]);

// Validações
int validarMatricula(char matricula[]);
int validarNome(char nome[]);
int validarSexo(char sexo);
int validarCPF(char cpf[]);
int validarData(char dataNasc[]);
int validarNomeDisciplina(char nomeDisciplina[]);
int validarSemestre(int semestre);