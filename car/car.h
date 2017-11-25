typedef struct car {
  char modelo[31];
  char cor[9];
  char ano[5];
  float preco;
  char placa[9];
  char renavam[12];
  char km[7];
  int status;
  int qtd_alugado;
  struct car* proxCar;
} Car;

// Maninupulação do arquivo
void saveDataCar(char *array); // Salvar Dados em Arquivo 'car.dat'
void loadDataCar(); // Carregar Dados do Arquivo 'car.dat'
char searchCar();

// CRUD
void listCar(Car* DataCar);
Car* createListCar(void);
void singUpCar(Car **DataCar); // Cadastrar carro
void editCar();
void deleteCar();

void rentCar(Car *DataCar);

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
