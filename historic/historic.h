typedef struct historic {
    char data[12];
    char placa[9];
    char cpfUser[12];
    int status;
    float priceTotal;
    struct historic *proxHistoric;
} Historic;

void addInHistoric(char cpf[12], char placa[9], char data[12], float price, int status, Historic **DataHistoric);

void saveHistoric(Historic *DataHistoric);

Historic *loadHistoric(Historic *DataHistoric);
