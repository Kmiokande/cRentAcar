void saveDataUser(char *array); // Salvar Dados em Arquivo 'user.dat'
void loadDataUser(); // Carregar Dados do Arquivo 'user.dat'
char searchCar();

// CRUD

void createUser();
void editUser();
void deleteUser();

// Validações

void valCPF(char cpf[11], int icpf[11]); // CPF
int valAddress(); // Endereço
int valFone(); // Telefone
int valEmail(); // Email
int valName(); // Nome
int valDate(); // Data Nascimento

// Others
int checkExist();

int bestClients();
