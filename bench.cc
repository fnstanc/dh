#include <cstdio>
#include "dh.h"
#include <chrono>

void bench(unsigned int times) {
    for (int i = 0; i < times; ++i) {
        uint64_t alice_private, alice_public;
        dh_gen_keypair(&alice_private, &alice_public);

        uint64_t bob_private, bob_public;
        dh_gen_keypair(&bob_private, &bob_public);

        uint64_t alice_secret = dh_gen_secret(alice_private, bob_public);
        uint64_t bob_secret = dh_gen_secret(bob_private, alice_public);
        (void)alice_secret;
        (void)bob_secret;
    }
}

int main(int argc, char *argv[]) {
    using namespace std;
    const unsigned int times = 10000000;
    auto start = chrono::high_resolution_clock::now();
    bench(times);
    auto end = chrono::high_resolution_clock::now();
    auto total = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    std::printf("cost: %f ms per trial\r\n", (double)total/(double)times);
    return 0;
}
