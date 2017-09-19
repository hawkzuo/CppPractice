#include <iostream>


/*
 * Internet checksum function
 */
u_short cksum(u_short *buf, int count) {
    register u_long sum = 0;
    while(count --) {
        sum += *buf++;
        if(sum & 0xFFFF0000 ) {
            // Carry occurs
            // Discard the carry
            sum &= 0xFFFF;
            // Then add 1
            sum += 1;
        }
    }
    return static_cast<u_short>(~(sum & 0xFFFF));
}



using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}