struct end {
  char sigla_estado[2];
  char cidade[50];
  char rua[50];
  int numero;
  char bairro[30];
}

typedef struct User {
	char nome[50];
	char sobrenome[50];
	char data_nascimento[20];
	char cpf[20];
	char nome_mae[80];
	char rg[20];
	char email[80];
	char cnh[20];
	char end endereco;
	char fone[15];
	struct user* proxUser;
};

// Maninupulação do arquivo
void saveDataUser(char *array); // Salvar Dados em Arquivo 'user.dat'
void loadDataUser(); // Carregar Dados do Arquivo 'user.dat'
char searchCar();

// CRUD
User singUp(User* DataUser);
void editUser();
void deleteUser();

// Validações
int valCPF(char cpf[11], int icpf[11]); // CPF
int valAddress(); // Endereço
int valFone(); // Telefone
int valEmail(); // Email
int valName(); // Nome
int valDate(); // Data Nascimento

// Others
int checkExist();

int bestClients();
