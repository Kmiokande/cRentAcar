typedef struct car Car;

// Maninupulação do arquivo
void saveDataCar(char *array); // Salvar Dados em Arquivo 'car.dat'
void loadDataCar(); // Carregar Dados do Arquivo 'car.dat'
char searchCar();

// CRUD
void listCar(Car* DataCar);
Car* createListCar(void);
Car* singUpCar(Car* DataCar); // Cadastrar usuário
void editCar();
void deleteCar();

// Validações
int valModel(char model[31]); // Modelo
int valColor(char color[9]); // Cor
int valYear(char year[5]); // Ano
int valPrice(); // Preço
int valPlate(char plate[9]); // Placa
int valRenavam(char ano[5], char renavam[12]); // Renavam
int valKm(char km[7]); // km's rodados
int valDate(); // Data

int checkExist();
