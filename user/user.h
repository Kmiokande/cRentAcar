struct end;
typedef struct user User;

// Maninupulação do arquivo
void saveDataUser(char *array); // Salvar Dados em Arquivo 'user.dat'
void loadDataUser(); // Carregar Dados do Arquivo 'user.dat'
char searchCar();

// CRUD
void listUser(User* DataUser);
User* createListUser(void);
User* singUpUser(User* DataUser); // Cadastrar usuário
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
