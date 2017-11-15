typedef struct car Car;

// Maninupulação do arquivo
void saveDataCar(char *array); // Salvar Dados em Arquivo 'car.dat'
void loadDataCar(); // Carregar Dados do Arquivo 'car.dat'
char searchCar();

// Validações
int valModel(); // Modelo
int valColor(char color[8]); // Cor
int valYear(char year[5]); // Ano
int valPrice(); // Preço
int valPlate(); // Placa
int valRenavan(); // Renavan
int valKm(); // km's rodados
int valDate(); // Data

int checkExist();
