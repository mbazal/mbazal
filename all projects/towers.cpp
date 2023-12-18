

/*
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <getopt.h> // to parse long arguments.
#include <cstdlib> // for atoi function

void towersOfHanoi(int x, int a, int c, int b){
        if (x == 0) return;
        towersOfHanoi(x - 1, a, b, c);
        cout << a << " to " << c << endl;
        towersOfHanoi(x - 1, b, c, a);
    }
/* Here's a skeleton main function for processing the arguments. /
int main(int argc, char *argv[]) {
    // define long options
    static struct option long_opts[] = {
        {"start",        required_argument, 0, 's'},
        {"end",          required_argument, 0, 'e'},
        {"num-disks",    required_argument, 0, 'n'},
        {0,0,0,0} // this denotes the end of our options.
    }
;
    // now process the options:
    char c; // to hold the option
    int opt_index = 0;
    short n=0,start=1,end=2; /* to store inputs to the towers function. /
    while ((c = getopt_long(argc, argv, "s:e:n:", long_opts, &opt_index)) != -1) {
        switch (c) {
            case 's': // process option s
                start = atoi(optarg);
                break;
            case 'e': // process option e
                end = atoi(optarg);
                break;
            case 'n': // process option n
                n = atoi(optarg);
                break;
            case '?': // this will catch unknown options.
                // here is where you would yell at the user.
                // although, getopt will already print an error message.
                return 1;
        }
    }

    /* TODO: now that you have the options and arguments,
     * solve the puzzle. /
    
    int z;
    int a = 1;
    int b = 1;
    int c = 1;
    
    int out[2] = {start, end};
    for (int i = 0; i < 2; i++){
        if(out[i] == 1)
        a = a - 1;
        if(out[i] == 2)
        b = b - 1;
        if(out[i] == 3)
        c = c - 1;
        }

    if(a) z = 1;
    if(b) z = 2;
    if(c) z = 3;
        
    towersOfHanoi(n, start, end, z);
        
    return 0;
    }
*/
#include <iostream>
#include <getopt.h>

// Function to solve the Towers of Hanoi puzzle
void hanoi(int n, int start, int end, int aux) {
    if (n == 1) {
        std::cout << start << '\t' << end << std::endl;
        return;
    }

    hanoi(n - 1, start, aux, end);
    std::cout << start << '\t' << end << std::endl;
    hanoi(n - 1, aux, end, start);
}

int main(int argc, char* argv[]) {
    int numDisks = 0;
    int startPeg = 1;
    int endPeg = 3;

    // Define long options
    static struct option longOpts[] = {
        {"num-disks", required_argument, nullptr, 'n'},
        {"start", required_argument, nullptr, 's'},
        {"end", required_argument, nullptr, 'e'},
        {nullptr, 0, nullptr, 0}
    };

    int c;
    int optionIndex = 0;

    // Process command line options
    while ((c = getopt_long(argc, argv, "n:s:e:", longOpts, &optionIndex)) != -1) {
        switch (c) {
            case 'n':
                numDisks = atoi(optarg);
                break;
            case 's':
                startPeg = atoi(optarg);
                break;
            case 'e':
                endPeg = atoi(optarg);
                break;
            default:
                std::cerr << "Invalid option" << std::endl;
                return 1;
        }
    }

    // Check if the number of disks is valid
    if (numDisks <= 0) {
        std::cerr << "Invalid number of disks" << std::endl;
        return 1;
    }

    // Solve the Towers of Hanoi puzzle
    hanoi(numDisks, startPeg, endPeg, 6 - startPeg - endPeg);

    return 0;
}
