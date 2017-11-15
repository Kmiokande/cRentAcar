struct end;
typedef struct user User;

User* creatList();

// Maninupulação do arquivo
void saveDataUser(char *array); // Salvar Dados em Arquivo 'user.dat'
void loadDataUser(); // Carregar Dados do Arquivo 'user.dat'
char searchCar();

// CRUD
void listUser(User* DataUser);
User* singUp(User* DataUser); // Cadastrar usuário
void editUser();
void deleteUser();

// Validações
int valCPF(char cpf[11]); // CPF
int valAddress(); // Endereço
int valFone(); // Telefone
int valEmail(); // Email
int valName(); // Nome
int valDate(); // Data Nascimento

// Others
int checkExist();

int bestClients();

void freeMemory();
