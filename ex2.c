#include <stdio.h>
#include <string.h>

struct Game { // Juegos
    char name[20]; // Nombre del juego
    float price; // Precio del juego
    int stock; // Cantidad de copias en stock del juego (Limitado a 100)

    struct Info { // Detalles del juego
        char developer[20]; // Desarrolladora
        char genre[15]; // Genero del juego
        int launchYear; // Año de lanzamiento
    } info;
};

struct Client { // Clientes
    char name[20]; // Nombre del cliente
    char email[20]; // Email del ciente
    float balance; // Cantidad de dinero en la cuenta del cliente
    struct Game library[100];
};

struct Game games[100]; // Lista de todos los juegos
int gameAmount=0;
struct Client clients[100]; // Lista de todos los clientes
int clientAmount=0;
char *genres[15] = {"Accion", "Aventura", "Puzzle", "Plataformas", "Lucha", "Ritmo", "Disparos", "RPG", "Estrategia", "Deportes", "Carreras"}; // Lista de generos de juegos 

struct Client getClient(char name[], struct Client clients[], int size) {
    for (int i=0; i<size; i++) {
        if (!strcmp(name, clients[i].name)) // Compara el nombre dado con el nombre de la estructura
            return clients[i]; // El nombre es encontrado, retorna la estructura
    }
    struct Client failed = {"NULL"};
    return failed;
}

int getClientIndex(char name[], struct Client clients[], int size) {
    for (int i=0; i<size; i++) {
        if (!strcmp(name, clients[i].name)) // Compara el nombre dado con el nombre de la estructura
            return i; // El nombre es encontrado, retorna la estructura
    }
    return -1;

}

struct Game getGame(char name[], struct Game games[], int size) {
    for (int i=0; i<size; i++) {
        if (!strcmp(name, games[i].name)) // Compara el nombre dado con el nombre de la estructura
            return games[i]; // El nombre es encontrado, retorna la estructura
    }
    struct Game failed = {"NULL"};
    return failed;

}

int getGameIndex(char name[], struct Game games[], int size) {
    for (int i=0; i<size; i++) {
        if (!strcmp(name, games[i].name)) // Compara el nombre dado con el nombre de la estructura
            return i; // El nombre es encontrado, retorna la estructura
    }
    return -1;

}

int search(char key[], char *array[], int size) {
    for (int i=0; i<size; i++) {
        if (!strcmp(key, array[i])) 
            return 1;
    }
    return 0;
}

void line(int size, char character) {
    for (int i=0; i<size; i++)
        printf("%c", character);
    printf("\n");
}

char* space(int price) {
    if (price < 10)
        return "   ";
    else if (price < 100)
        return "  ";
    else if (price < 1000)
        return " ";
    return "";
}

char* rplchr(char string[], int size) {
    for (int c=0;c<size;c++) {
        if (string[c]=='-' || string[c]=='_')
            string[c] = ' ';
    }
    return string;
}

int getLibrarySize(struct Client client) {
    int size = 0;
    for (int i=0; i<100; i++) {
        if (strcmp(client.library[i].name, ""))
            size++;
    }   
    return size;
}

void listGames() {
    int size = sizeof(games)/sizeof(games[0]);
    line(93, '-');

        printf("| %-20s | %-20s | %-15s | %-5s | %-9s | %-6s |\n", "Nombre", "Desarrollador", "Genero", "Año", "Precio", "Stock");
    line(93, '-');
    for (int i=0; i<size; i++) {
        if (strcmp(games[i].name, ""))
            printf("| %-20s | %-20s | %-15s | %04d | $ %-2.2f%s | %-6d |\n", rplchr(games[i].name,20), rplchr(games[i].info.developer,20), games[i].info.genre, games[i].info.launchYear, games[i].price, space(games[i].price), games[i].stock);

    }
    line(93, '-');
}

void showLibrary(struct Game gameList[], int size) {
    line(65,'-');
    printf("| %-20s | %-15s | %-20s |\n", "Nombre", "Genero", "Desarrollador");
    line(65,'-');
    for (int i=0; i<size; i++) {
        printf("| %-20s | %-15s | %-20s |\n", rplchr(gameList[i].name, 20), gameList[i].info.genre, rplchr(gameList[i].info.developer, 20));
    }
    line(65,'-');

}

void listClients() {
    line(60,'-');
    printf("| %-20s | %-20s | %-10s | \n", "Nombre", "Email" , "Balance");
    line(60, '-');
    for (int i=0; i<sizeof(clients)/sizeof(clients[0]); i++) {
        if (strcmp(clients[i].name, ""))
            printf("| %-20s | %-20s | $ %-3.3f%s |\n", rplchr(clients[i].name,20), clients[i].email, clients[i].balance, space(clients[i].balance));
    }
    line(60,'-');
}

void prefabs() { // Datos preseleccionados
    struct Game pg[] = {
        { "Minecraft"           , 24.99, 50, { "Mojang"             , "Aventura"   , 2009 } },
        { "Terraria"            , 9.99 , 70, { "Re-Logic"           , "Aventura"   , 2011 } },
        { "Fallout: New Vegas"  , 9.99 , 20, { "Bethesda Softworks" , "RPG"        , 2010 } },
        { "Celeste"             , 14.99, 80, { "Mattmakesgames"     , "Plataformas", 2018 } },
        { "Enter The Gungeon"   , 14.99, 75, { "Devolver Digital"   , "Disparos"   , 2016 } },
        { "Batman:Arkham City"  , 19.99, 40, { "Rocksteady Studios" , "Aventura"   , 2012 } },
        { "TES: Skyrim"         , 39.99, 80, { "Bethesda Softworks" , "RPG"        , 2011 } },
        { "Forza Horizon 5"     , 59.99, 65, { "Playground Games"   , "Carreras"   , 2021 } },
        { "Left4Dead 2"         , 9.99 , 40, { "Valve"              , "Disparos"   , 2011 } },
        { "Tomb Raider"         , 14.99, 30, { "Square Enix"        , "Accion"     , 2013 } },
    };
    struct Client pc[] = {
        { "Rafael Mata"         , "matarafae@gmail.com" , 9300, {pg[3]} },
        { "Marlon Urdaneta"     , "urdmarlon@gmail.com" , 500 , {pg[2]} },
        { "Jose Carrillo"       , "cariljose@gmail.com" , 630 , {pg[3]} },
        { "Tomas Santana"       , "tommysant@gmail.com" , 3000, {pg[6]} },
        { "Juan Gil"            , "juangil@gmail.com"   , 245 , {pg[9]} },
        { "Eli Mora"            , "elimora@gmail.com"   , 5400, {pg[5]} },
    };
    for (int g=0; g<sizeof(pg)/sizeof(pg[0]); g++)
        games[g] = pg[g];

    for (int c=0; c<sizeof(pc)/sizeof(pc[0]); c++) {
        pc[c].library[0].stock = 1;
        clients[c] = pc[c];
    }
}

void addGame() {
    struct Game test;
    printf("Nota: Colocar los espacios como guiones (-) o pisos (_)\n");
    printf("Nombre: ");              scanf("%s", &test.name);
    printf("Precio: ");              scanf("%f", &test.price);
    printf("Desarrolladora: ");      scanf("%s", &test.info.developer);
    printf("Genero: ");              scanf("%s", &test.info.genre);
    printf("Año de lanzamiento: ");  scanf("%d", &test.info.launchYear);
    printf("Stock: ");               scanf("%d", &test.stock); 

    if (test.price<1 || test.info.launchYear<1 || test.stock<1 ||!search(test.info.genre, genres, sizeof(genres)/sizeof(genres[0]))) {
        printf("Datos invalidos, intente con otros\n");
        addGame();
    }
    else {
        strcpy(test.name, rplchr(test.name,20));
        strcpy(test.info.developer, rplchr(test.info.developer, 20));
        games[gameAmount] = test;
        gameAmount++;
    }
}

void addClient() {
    struct Client test;

    printf("Nota: Colocar los espacios como guiones (-) o pisos (_)\n");
    printf("Nombre: ");            scanf("%s",&test.name);
    printf("Email: ");             scanf("%s",&test.email);
    printf("Balance de cuenta: "); scanf("%f",&test.balance);

    if (test.balance<0) {
        printf("Datos invalidos, intente con otros\n");
        addClient();
    }
    else {
        strcpy(test.name, rplchr(test.name, 20));
        clients[clientAmount] = test;
        clientAmount++;
    }
}

void assignment() { // Asignacion de balance de dinero en la cuenta de un cliente
    char name[20];
    printf("Nota: Colocar los espacios como guiones (-) o pisos (_)\n");
    printf("Ingrese el nombre de la cuenta a asignar: "); scanf("%s", &name);

    struct Client temp = getClient(rplchr(name,20), clients, sizeof(clients)/sizeof(clients[0]));
    if (!strcmp(temp.name, "NULL")) {
        printf("Cuenta no encontrada, intente con otra\n");
        assignment();
    }
    else {
        int index = getClientIndex(rplchr(name,20), clients, sizeof(clients)/sizeof(clients[0]));
        
        float temp;
        printf("Ingese la cantidad a asignar: "); scanf("%f", &temp);
        if (temp > 0 || temp < 10000) 
            clients[index].balance = temp;
        else {
            printf("Valor invalido, intente con otro\n");
            assignment();
        }
    }
}

void listLibrary() {
    char name[20];

    printf("Nota: Colocar los espacios como guiones (-) o pisos (_)\n");
    printf("Ingrese la cuenta a ver: "); 
    scanf("%s", &name);

    struct Client temp = getClient(rplchr(name,20), clients, (sizeof(clients)/sizeof(clients[0])));
    // printf(" %s | %s | %f \n", temp.name, temp.email, temp.balance);
    if (!strcmp(temp.name, "NULL")) {
        printf("Esta cuenta no existe, intente de nuevo\n");
        listLibrary();
    }
    else {
        line(65, '-');
        printf("| Biblioteca de: %-78s|\n", rplchr(temp.name,20));
        showLibrary(temp.library, getLibrarySize(temp));
    }
}

void buy() {
    char accountName[20], gameName[20];
    printf("Nota: Colocar los espacios como guiones (-) o pisos (_)\n");
    printf("Ingrese el nombre de la cuenta a utilizar: "); scanf("%s", &accountName);
    printf("Ingrese el nombre del juego a comprar: ");     scanf("%s", &gameName);
    
    strcpy(accountName, rplchr(accountName, 20));
    strcpy(gameName, rplchr(gameName, 20));
    struct Client tempAccount = getClient(accountName, clients, sizeof(clients)/sizeof(clients[0]));
    struct Game tempGame = getGame(gameName, games, sizeof(games)/sizeof(games[0]));

    if (strcmp(accountName, tempAccount.name) && strcmp(gameName, tempGame.name)) {
        printf("Datos invalidos, intente con otros\n");
        buy();
    }
    else if (tempGame.price > tempAccount.balance) {
        printf("La compra no puede ser procesada, el dinero en la cuenta es insuficiente\n");
    }
    else {
        int clientIndex = getClientIndex(accountName, clients, sizeof(clients)/sizeof(clients[0]));
        int gameIndex = getGameIndex(gameName, games, sizeof(games)/sizeof(games[0]));
        tempGame.stock = 1;

        clients[clientIndex].library[getLibrarySize(tempAccount)] = tempGame;
        printf("La compra ha sido realizada con exito!\n");
    }
}

void menu() {
    printf(
        "\n"
        "##########################################\n"
        "### Elija una opcion:                  ###\n"
        "##########################################\n"
        "### [1] ### Agregar juego              ###\n"
        "### [2] ### Listar juegos              ###\n"
        "### [3] ### Agregar cliente            ###\n"
        "### [4] ### Listar clientes            ###\n"
        "### [5] ### Comprar juegos             ###\n"
        "### [6] ### Asignar balance de cliente ###\n"
        "### [7] ### Ver biblioteca             ###\n"
        "### [8] ### Datos preseleccionados     ###\n"
        "### [9] ### Salir                      ###\n"
        "##########################################\n"
        "### > "
    );
    int opcion;
    scanf("%d", &opcion);
    switch (opcion) {
        case 1: addGame();     menu();  break;
        case 2: listGames();   menu();  break;
        case 3: addClient();   menu();  break;
        case 4: listClients(); menu();  break;
        case 5: buy();         menu();  break;                                            
        case 6: assignment();  menu();  break;
        case 7: listLibrary(); menu();  break;
        case 8: prefabs();     menu();  break;
        case 9: break;
        default:
            printf("Opcion invalida, intente con otra\n");
            menu();
    }
}

int main() {
    menu();
    return 0;
}