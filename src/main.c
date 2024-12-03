#include <stdio.h>
#include <string.h>
#include "combat.c"

//Global variables
int gameRunning = 1;
//int combat = 0;
int time;
int goalsComplete[5] = {0};

typedef struct {
    char name [20];
    char colour [15];
    int damage;
} Weapon;

typedef struct {
    char description [300];
    int hasEnemy;
    int exits [4]; // ([0] = up, [1] = right, [2] = down, [3] = left)
    Weapon roomWeapon;
} Room;

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

Room map[3][3];

//Initialize player
Player player = {50, "Santa", {}, 0, 0};

// Function declarations
void initGame();
void movePlayer(int direction);
void describeRoom();
void pickUpWeapon();
void readSwitches();

int main()
{
    initGame();
    //FÖR ATT TESTA I TERMINAL
    char key;

    //Game loop
    while (gameRunning) {

        //FÖR ATT TESTA I TERMINAL
        key = getchar();
        switch (key) {
        case '0': movePlayer(0); break;
        case '1': movePlayer(1); break;
        case '2': movePlayer(2); break;
        case '3': movePlayer(3); break;
        
        default:
            break;
        }

        /*
        //temporär
        if (get_btn()){
            read_switches();   
        }
        */
    }
    
    return 0;
}


void initGame() {
    //Initalize rooms
    strcpy(map[0][0].description, "start");
    map[0][0].exits [0] = 0; map[0][0].exits [1] = 1; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;

    strcpy(map[0][1].description, "description");
    map[0][1].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;
    map[0][1].hasEnemy = 1;

    strcpy(map[0][2].description, "description");
    map[0][2].exits [0] = 0; map[0][0].exits [1] = 0; map[0][0].exits [2] = 0; map[0][0].exits [3] = 0;
    map[0][2].roomWeapon = (Weapon){"Candy Cane", "Red", 5};

    strcpy(map[1][0].description, "second");
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
        //startCombat(&player);
    }
}


void describeRoom() {
    // Get the current room description and print it
    Room currentRoom = map[player.posX][player.posY];
    printf("Room description: %s\n", currentRoom.description);
}

void pickUpWeapon() {
    Room *currentRoom = &map[player.posX][player.posY];
    if (strlen(currentRoom->roomWeapon.name) == 0){
        
    }
}

int get_sw (void){
  volatile int* ptr = (volatile int*)0x04000010;
  return *ptr & 0x3FF;
}

int get_btn(void){
  volatile int* ptr = (volatile int*)0x040000d0;
  return *ptr & 0x01;
}

void read_switches() {
    int switches = get_sw();
    
    //INSPIRATION FRÅN TIDIGARE DTEK UPPGIFT
    //switches >> 8 gets the value of the two leftmost switches
    //switches & 0x03 masks out the six leftmost switches
    /*
    if (switches >> 8 == 1) {
        seconds = (switches & 0x03f)%60;
    } else if (switches >> 8 == 2){
        minutes = (switches & 0x03f)%60;
    } else if (switches >> 8 == 3){
        hours = (switches & 0x03f)%24;
    }*/

    movePlayer(switches);
}

/*
//BARA KOPIERAT FRÅN TIDIGARE DTEK UPPGIFT
void set_display(int display_number, int value){
  //Addition before int casting to prevent massive leap
  volatile int *ptr = (volatile int*)(0x04000050 + 0x10*display_number);
  int display = 0;

  //Set display to display correct value on 7 segment display
  switch (value) {
    case 0:
      display = 0x40;
      break;
    case 1:
      display = 0x79;
      break;
    case 2:
      display = 0x24;
      break;
    case 3:
      display = 0x30;
      break;
    case 4:
      display = 0x19;
      break;
    case 5:
      display = 0x12;
      break;
    case 6:
      display = 0x02;
      break;
    case 7:
      display = 0x78;
      break;
    case 8:
      display = 0x00;
      break;
    case 9:
      display = 0x18;
      break;
  }
  
//Pointer unchanged except last 2 digits
  *ptr = *ptr & 0xffffff00;
  //Insert display at last 2
  *ptr = *ptr | display;
}
*/
