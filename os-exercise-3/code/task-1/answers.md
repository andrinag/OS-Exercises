# Task 1
**i)**
The output with 5 producers and 0 consumers is:
```
Producer produced: 1534507321, buffer position: 1 
Producer produced: 1171885191, buffer position: 0 
Producer produced: 93906833, buffer position: 2 
Producer produced: 1880913188, buffer position: 3 
Producer produced: 1626918669, buffer position: 4 
Producer produced: 813268848, buffer position: 0 
Producer produced: 1111910226, buffer position: 1 
Producer produced: 1174213401, buffer position: 2 
Producer produced: 1898119435, buffer position: 3 
Producer produced: 1445350030, buffer position: 4 
Producer produced: 1080500579, buffer position: 0 
Producer produced: 1205686382, buffer position: 1 
Producer produced: 867974659, buffer position: 2 
Producer produced: 1033013534, buffer position: 3 
Producer produced: 481134014, buffer position: 4 
Producer produced: 1920510410, buffer position: 0 
Producer produced: 728059674, buffer position: 1 
Producer produced: 1476770413, buffer position: 2 
Producer produced: 2135844037, buffer position: 3 
Producer produced: 199523957, buffer position: 4 
```
The problem is that the buffer will be overwritten; the producers don't stop producing when the buffer is full!

---

The output with 0 producers and 5 consumers is:
```
Consumer consumed: 0, buffer position: 0 
Consumer consumed: 0, buffer position: 1 
Consumer consumed: 0, buffer position: 2 
Consumer consumed: 0, buffer position: 3 
Consumer consumed: 0, buffer position: 4 
Consumer consumed: -1, buffer position: 0 
Consumer consumed: -1, buffer position: 1 
Consumer consumed: -1, buffer position: 2 
Consumer consumed: -1, buffer position: 3 
Consumer consumed: -1, buffer position: 4 
Consumer consumed: -1, buffer position: 0 
Consumer consumed: -1, buffer position: 1 
Consumer consumed: -1, buffer position: 2 
Consumer consumed: -1, buffer position: 3 
Consumer consumed: -1, buffer position: 4 
Consumer consumed: -1, buffer position: 0 
Consumer consumed: -1, buffer position: 2 
Consumer consumed: -1, buffer position: 1 
Consumer consumed: -1, buffer position: 3 
Consumer consumed: -1, buffer position: 4 
Consumer consumed: -1, buffer position: 0 
Consumer consumed: -1, buffer position: 1 
Consumer consumed: -1, buffer position: 2 
Consumer consumed: -1, buffer position: 3 
Consumer consumed: -1, buffer position: 4 
Consumer consumed: -1, buffer position: 0 
Consumer consumed: -1, buffer position: 1 
Consumer consumed: -1, buffer position: 2 
```
The problem is that the consumers consumes even if the buffer is empty!

---

**ii)**

