# Learn C The Hard Way

## Exercise 26: Write a First Real Program

### Dependencies

Debian:

```
sudo apt-get install libapr1-dev libaprutil1-dev

# In the Makefile:
CFLAGS=-Wall -g -I/usr/include/apr-1.0
LDFLAGS=-L/usr/lib/apr-util-1 -lapr-1 -pthread -laprutil-1
```

Mac (homebrew):

```
brew install apr apr-util

# In the Makefile:
CFLAGS=-Wall -g -I/usr/local/opt/apr/include/apr-1 -I/usr/local/opt/apr-util/include/apr-1
LDFLAGS=-L/usr/local/opt/apr/lib -L/usr/local/opt/apr-util/lib -lapr-1 -pthread -laprutil-1
```
