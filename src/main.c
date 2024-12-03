#include "combat.c"

//Global variables
int gameRunning = 1;
int combat = 0;
int time;
int goalsComplete[5] = {0};
Room map[3][3];

//Initialize player
Player player = {50, "Santa", {}, 0, 0};

typedef struct {
    char description [300];
    int hasEnemy;
    int exits [4]; // (up, right, down, left)
} Room;

typedef struct {
    char name [20];
    char colour [15];
    int damage;
} Weapon;

typedef struct {
    int hp;
    char name [15];
    Weapon backpack [5];
    int posX, posY;
} Player;

typedef struct {
    int hp;
    char name [15];
} Enemy;

int main()
{
    initGame();

    //Game loop
    while (gameRunning) {

        //temporär
        if (get_btn()){
            read_switches();   
        }
    }
    
    return 0;
}

void initGame() {
    //Initalize rooms
    strcpy(map[0][0].description, "description");
    map[0][0].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;

    strcpy(map[0][1].description, "description");
    map[0][1].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;
    map[0][1].hasEnemy = 1;

    strcpy(map[0][2].description, "description");
    map[0][2].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;

    strcpy(map[1][0].description, "description");
    map[1][0].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;

    strcpy(map[1][1].description, "description");
    map[1][1].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;

    strcpy(map[1][2].description, "description");
    map[1][2].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;

    strcpy(map[2][0].description, "description");
    map[2][0].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;

    strcpy(map[2][1].description, "description");
    map[2][1].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;

    strcpy(map[2][2].description, "description");
    map[2][2].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;

    describeRoom();
}

void read_switches() {
    int switches = get_sw();
    movePlayer(switches);
}

void movePlayer (int direction) {
    //Check if the current room has exit
    if (!map[player.posX][player.posY].exits[direction]) {
        printf("There is no exit in that direction! \n");
        return;
    }

    //Store new direction
    int newX = player.posX;
    int newY = player.posY;

    switch(direction) {
        case 0: newX--; break; //Up
        case 1: newY++; break; //Right
        case 2: newX++; break; //Down
        case 3: newY--; break; //Down
        default:
            printf("Invalid dir");
            return;
    }

    //Update pos
    player.posX = newX;
    player.posY = newY; 

    if (map[player.posX][player.posY].hasEnemy) {
        startCombat(&player);
    }
}

void describeRoom() {
    // Get the current room description and print it
    Room currentRoom = map[player.posX][player.posY];
    printf("Room description: %s\n", currentRoom.description);
}
