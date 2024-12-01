//Global variables
int gameRunning = 1;
int time;
int goalsComplete[5] = {0};
int map[3][3];

typedef struct {
    char name[20];
    char colour [15];
    int damage;
} Weapon;

typedef struct {
    int hp;
    char name [15];
    Weapon backpack [5];
} Player;

int main()
{
    initGame();

    //Game loop
    while (gameRunning) {
        
    }
    
    return 0;
}

void initGame() {
    //Initialize player
    Player player = {50, "Santa"};
}
