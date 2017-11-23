struct end {
  char sigla_estado[3];
  char cidade[51];
  char rua[51];
  int numero;
  char bairro[31];
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
User* createListUser(void);
void singUpUser(User **DataUser); // Cadastrar usuário
void listUser(User *DataUser); // Ver todos os usuarios cadastrados
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
