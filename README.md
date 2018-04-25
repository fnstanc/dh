# A simple Diffie–Hellman key exchange algorithm
Diffie–Hellman key exchange (DH) is a method of securely exchanging cryptographic keys over a public channel.

## How to use

1.Alice generates private&public key pair
```
    uint64_t alice_private, alice_public;
    dh_gen_keypair(&alice_private, &alice_public);
```
2.Bob generates private&public key pair
```
    uint64_t bob_private, bob_public;
    dh_gen_keypair(&bob_private, &bob_public);
```

3.Alice and Bob exchange their public key

4.Generate their own secret key by public key from the other

for Alice:
```
    uint64_t alice_secret = dh_gen_secret(alice_private, bob_public);
```
for Bob:
```
    uint64_t bob_secret = dh_gen_secret(bob_private, alice_public);
```

## Build Demo
```
    mkdir build
    cd build
    cmake .. && make
    ./dh
```

you may get results looked like:
```
alice: private = 10353895189544087180, public = 15967819997615043245, secret = 1566751761039696448
bob: private = 361696073736433773, public = 2974711112666403235, secret = 1566751761039696448
alice: private = 15235742425396638534, public = 16538995203828016914, secret = 3655848871078093045
bob: private = 6105329636375434176, public = 17011817957860221321, secret = 3655848871078093045
alice: private = 12669490949904178265, public = 4717763450672132842, secret = 9199944547275171067
bob: private = 6368022594617898455, public = 1945475483120537793, secret = 9199944547275171067
...
```
