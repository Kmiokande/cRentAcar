 #include "../historic/historic.h"

typedef struct car {
  char modelo[31];
  char cor[9];
  int ano;
  float preco;
  char placa[9];
  char renavam[12];
  char km[7];
  char cpf[12];
  int status;
  int qtd_alugado;
  struct car* proxCar;
} Car;

// CRUD
void listCar(Car* DataCar);
void singUpCar(Car **DataCar); // Cadastrar carro
int searchCar(Car *DataCar); // Busca cadastro do carro pela placa
void editCar(Car *DataCar);
Car *deleteCar(Car *DataCar); // Deleta cadastro do carro pela placa

void rentCar(Car *DataCar, Historic **DataHistoric);
void CarRented(Car *DataCar);

// Validações
int valModel(char model[31]); // Modelo
int valColor(char color[9]); // Cor
int valYear(int year); // Ano
int valPrice(); // Preço
int valPlate(char plate[9]); // Placa
int valRenavam(int ano, char renavam[12]); // Renavam
int valKm(char km[7]); // km's rodados
int valDate(); // Data

// Maninupulação do arquivo
void saveCar(Car *DataCar); // Salvar Dados em Arquivo 'car.dat'
Car *loadCar(Car *DataCar); // Carregar Dados do Arquivo 'car.dat'

// Others
int checkExist();