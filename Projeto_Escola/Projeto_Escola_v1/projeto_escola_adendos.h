#define TAM 5

typedef struct {
	int matricula;
	char nome[50];
	char sexo;
	char data[50];
	char cpf[50];
}dados;

typedef struct {
	char codigo[50];
	char nome[50];
	int semestre;
	int numProfessor;
	dados aluno[TAM];
	int qtdAlunoCadastrado;
}disc;

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
void listarAlunoAniversariante(int qtdAluno, dados aluno[]);
void listarAlunoSexo(int qtdAluno, dados aluno[]);
void listarAlunoOrdemAlfabetica(int qtdAluno, dados aluno[]);
int apagarTodosAlunos(int qtdAluno);

// Professor
int mainProfessor(dados professor[], int qtdProfessor);
void cadastrarProfessor(int qtdProfessor, dados professor[]);
void mostrarProfessor(int qtdProfessor, dados professor[]);
void alterarCadastroProfessor(int qtdProfessor, dados professor[]);
int removerProfessor(int qtdProfessor, dados professor[]);
void listarProfessorAniversariante(int qtdProfessor, dados professor[]);
void listarProfessorSexo(int qtdProfessor, dados professor[]);
void listarProfessorOrdemAlfabetica(int qtdProfessor, dados professor[]);
int apagarTodosProfessores(int qtdProfessor);

// Disciplina
int mainDisciplina(disc disciplina[], int qtdDisciplina, int qtdProfessor, dados professor[], int qtdAluno, dados aluno[]);
void cadastrarDisciplina(int qtdDisciplina, disc disciplina[], int qtdProfessor);
void mostrarDisciplina(int qtdDisciplina, disc disciplina[], int qtdProfessor, dados professor[]);
void alterarCadastroDisciplina(int qtdDisciplina, disc disciplina[], int qtdProfessor);
int removerDisciplina(int qtdDisciplina, disc disciplina[]);
int cadastrarAlunoDisciplina(int qtdDisciplina, disc disciplina[], int qtdAluno, dados aluno[]);
void mostrarDisciplinaComAluno(int qtdDisciplina, disc disciplina[], int qtdProfessor, dados professor[]);
void removerAlunoDisciplina(int qtdDisciplina, disc disciplina[]);
void removerTodosAlunosDisciplina(int qtdDisciplina, disc disciplina[]);

// Validações
int validarMatricula(char matricula[]);
int validarNome(char nome[]);
int validarSexo(char sexo);
int validarCPF(char cpf[]);
int validarData(char dataNasc[]);
int validarCodigoDisciplina(char codigo[]);
int validarNomeDisciplina(char nomeDisciplina[]);
int validarSemestreDisciplina(int semestre);

// Funções extras
void descobreNomeMes(int mes, char strMes[]);