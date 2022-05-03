# Task 2

## Linking error

Executing `make all` we get the following ld error (linking error):

```
gcc -o diningphilosophers main.o dining.o philosopher.o -lpthread
/usr/bin/ld: dining.o:(.bss+0x0): multiple definition of `state'; main.o:(.bss+0x0): first defined here
/usr/bin/ld: dining.o:(.bss+0x20): multiple definition of `thread_id'; main.o:(.bss+0x20): first defined here
/usr/bin/ld: dining.o:(.bss+0x40): multiple definition of `cond_vars'; main.o:(.bss+0x40): first defined here
/usr/bin/ld: dining.o:(.bss+0x140): multiple definition of `mutex_lock'; main.o:(.bss+0x140): first defined here
/usr/bin/ld: philosopher.o:(.bss+0x0): multiple definition of `state'; main.o:(.bss+0x0): first defined here
/usr/bin/ld: philosopher.o:(.bss+0x20): multiple definition of `thread_id'; main.o:(.bss+0x20): first defined here
/usr/bin/ld: philosopher.o:(.bss+0x40): multiple definition of `cond_vars'; main.o:(.bss+0x40): first defined here
/usr/bin/ld: philosopher.o:(.bss+0x140): multiple definition of `mutex_lock'; main.o:(.bss+0x140): first defined here
collect2: error: ld returned 1 exit status
make: *** [Makefile:6: diningphilosophers] Error 1
```

