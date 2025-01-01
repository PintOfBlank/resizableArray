**an implmentation of Java ArrayList in the c programming language (only ints)**

to define an arrayList
```c

ArrayList* nameOfArray = new();

```

append an int to it

```c
append(nameOfArray, valuePush);
```

removing something from a certain index

```c
pop(nameOfArray, index);
```

destroying array

```c
destroy(nameOfArray);
```

improvements needed:
- insert method
- remove element in list taken the value (like pop but for a value)
- encapsulate needing a pointer to make a new arraylist / encapsulate methods into a class
- different types other then int
- inital size declaration or capacity declaration
