#define ID_TYPE_CARTAO_SUS 0
#define ID_TYPE_CPF 1

#define STATUS_OK 0
#define STATUS_ID_NAO_ENCONTRADO 1
#define STATUS_NAO_HA_VACINAS 2
#define STATUS_BAD_REQUEST 3
#define STATUS_INTERNAL_ERROR 4

#define QTT_SERVERS 4

char estados_addrs[27][15] = {
    "localhost",
    "192.168.4.3",
    "192.168.4.700",
    "192.168.27.48"
};