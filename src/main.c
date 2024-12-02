//Global variables
int gameRunning = 1;
int time;
int goalsComplete[5] = {0};
Room map[3][3];

typedef struct {
    char description [300];
    Enemy roomEnemy;
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
    //Initialize player
    Player player = {50, "Santa"};
}

void read_switches() {
    int switches = get_sw();
}
