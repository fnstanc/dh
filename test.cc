#include <cassert>
#include <cstdio>
#include "dh.h"

int main(int argc, char *argv[]) {
    for (int i = 0; i < 10; ++i) {
        uint64_t alice_private, alice_public;
        dh_gen_keypair(&alice_private, &alice_public);

        uint64_t bob_private, bob_public;
        dh_gen_keypair(&bob_private, &bob_public);

        uint64_t alice_secret = dh_gen_secret(alice_private, bob_public);
        uint64_t bob_secret = dh_gen_secret(bob_private, alice_public);

        std::printf("alice: private = %llu, public = %llu, secret = %llu\r\n",
                    alice_private, alice_public, alice_secret);
        std::printf("bob: private = %llu, public = %llu, secret = %llu\r\n",
                    bob_private, bob_public, bob_secret);
        assert(alice_secret == bob_secret);
    }
    return 0;
}
