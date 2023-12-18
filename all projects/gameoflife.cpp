#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using namespace std;

const int TEN = 10;
const int TWENTY = 20;
const char ZERO = '0', DOT = '.';

// Alias for the world type
using World = vector<vector<bool>>;

bool aliveNextGen(const World &world, int p, int q);
void copyNextGenToWorld(World &world, const World &nextGen);
void printWorld(const World &world);
int numLiveNeighbors(const World &world, int p, int q);


int main(){
vector<vector<bool> > World world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
}, nextGen(world);
    
    for(int p=0; p < TEN; p++)
        for(int q=0; q < TWENTY; q++)
            nextGen[p][q] = aliveNextGen(world, p, q);
    copyNextGentoWorld(world,nextGen);
    printWorld(world);
    
    return 0;
}

bool aliveNextGen(const World &world, int p, int q) {
    int numNeighbors = numLiveNeighbors(world, p, q);

    if (world[p][q])
        return numNeighbors == 2 || numNeighbors == 3;
    else
        return numNeighbors == 3;
}

void copyNextGenToWorld(World &world, const World &nextGen) {
    for (int p = 0; p < TEN; p++)
        for (int q = 0; q < TWENTY; q++)
            world[p][q] = nextGen[p][q];
}

void printWorld(const World &world) {
    for (int p = 0; p < TEN; p++) {
        for (int q = 0; q < TWENTY; q++)
            cout << (world[p][q] ? ZERO : DOT);
        cout << endl;
    }
}

int numLiveNeighbors(const World &world, int p, int q) {
    int numLive = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            numLive += world[(p + i + TEN) % TEN][(q + j + TWENTY) % TWENTY];
        }
    }
    return numLive - world[p][q];
}
