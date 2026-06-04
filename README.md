# Text-Encrypter-Decrypter
https://i.imgur.com/0EIT4Ia.gif

## Archive status

This is an archived C++ text encryption/decryption demo. The repository includes source plus older Windows build artifacts for historical context.

## Local build notes

Build from source when testing locally instead of relying on committed executables:

```sh
c++ -std=c++11 -Wall -Wextra main.cpp -o text-lock
```

Keep newly generated binaries and local test files out of git.

## CLI demo

```sh
printf 'hello portfolio\n' > /tmp/text-lock-input.txt
./text-lock --encrypt --key 42 --input /tmp/text-lock-input.txt --output /tmp/text-lock-enc.bin
./text-lock --decrypt --key 42 --input /tmp/text-lock-enc.bin --output /tmp/text-lock-dec.txt
cat /tmp/text-lock-dec.txt
```

The program uses the same XOR operation for encryption and decryption. The key
must be an integer from `0` to `255`.
