# ft_ssl(hashing)

Understanding how hashing algorithm works and Implement some of hashing algorithm `openssl` has.<br/>
[`MD5`](https://en.wikipedia.org/wiki/MD5), [`SHA2`](https://en.wikipedia.org/wiki/SHA-2) is the hasing algorithm that i implemented.<br/>
wikipedia has detailed instruction how hashing algorithm works and even has pseudo code.

[ft_ssl_md5.en.pdf](/resources/ft_ssl_md5.en.pdf) is the task file to see the detailed instruction.

## Project Structure

This project consists of three parts:

* openssl(ft_ssl)
* md5
* sha

`ft_ssl` should be constructed with **dispatch table** for easily adding other function.

`md5` and `sha` is actual hashing algorithm. understanding each variable type in depth and transforming byte to bit, viceversa is important to implement hashing algorithm.

## Installation

Clone repository and then go into the created directory and run the following command:

```
make
```

## Usage

```
Usage: ft_ssl command [command opts] [command args]
    command      — md5, sha224, sha256, sha384, sha512
    opts         —
                    • -p, echo STDIN to STDOUT and append the checksum to STDOUT
                    • -q, quiet mode
                    • -r, reverse the format of the output.
                    • -s, print the sum of the given string
    args         — file, string need to be hashed

```

## Tester

Has bunch of test case, easily comparable to original `openssl`.
```
Usage: ./resources/tester
```
