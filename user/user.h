struct end {
  char sigla_estado[2];
  char cidade[50];
  char rua[50];
  int numero;
  char bairro[30];
};

typedef struct user {
  char nome[50];
  char sobrenome[50];
  char data_nascimento[10];
  char cpf[12];
  char nome_mae[80];
  char rg[20];
  char cnh[20];
  struct end endereco;
  char email[80];
  char fone[15];
  struct user* proxUser;
} User;

// Maninupulação do arquivo
void saveDataUser(char *array); // Salvar Dados em Arquivo 'user.dat'
void loadDataUser(); // Carregar Dados do Arquivo 'user.dat'
char searchCar();

// CRUD
void listUser(User* DataUser);
User* createListUser(void);
void singUpUser(User **DataUser); // Cadastrar usuário
void editUser();
void deleteUser();

// Validações
int valCPF(char cpf[12]); // CPF
int valAddress(); // Endereço
int valFone(); // Telefone
int valEmail(); // Email
int valName(char name[50]); // Nome
int valDate(); // Data Nascimento

// Others
int checkExist();

int bestClients();

void freeMemory();
