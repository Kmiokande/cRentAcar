typedef struct historic {
    char data[12];
    char placa[9];
    char cpfUser[12];
    int status;
    float priceTotal;
    struct historic* proxHistoric;
} Historic;

void addInHistoric();
