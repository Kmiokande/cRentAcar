typedef struct car {
	char modelo[10];
	char cor[10];
	char ano[4];
	char preco[10];
	char placa[7];
	int renavam;
	char km[80];
	char status;
	char qtd_alugado[120];
  struct *car proxCar;
};

// Maninupulação do arquivo
void saveDataCar(char *array); // Salvar Dados em Arquivo 'car.dat'
void loadDataCar(); // Carregar Dados do Arquivo 'car.dat'
char searchCar();

// Validações

int valModel(); // Modelo
int valColor(); // Cor
int valYear(); // Ano
int valPrice(); // Preço
int valPlate(); // Placa
int valRenaban(); // Renavan
int valKm(); // km's rodados
int valDate(); // Data

int checkExist();
