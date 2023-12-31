## TASK 0
Напишете рекурсивна функция с прототип `int sumOfDigits(int)` , която връща като резултат сборът от цифрите на цяло положително
число с променлива дължина.

`Пример:` 
``` C++
sumOfDigits(154) => 10
```

## TASK 1
**а)** Напишете рекурсивна функция с прототип int `recStrlen(const char*)` , която връща като резултат дължината на подадения низ.

**b)** Напишете рекурсивна функция с прототип int `countLetters(const char*)` , която връща като резултат броя на буквите в един символен низ.
	
`Пример:`
``` C++
countLetters("Happy new year") => 12
```
  
## TASK 2
Напишете рекурсивна функция с прототип `int reverseNum(int)`, която обръща цяло число (от дадено число получава ново число,
в което цифрите са в обратен ред).

`Пример:`
```C++
reverseNum(1123) => 3211
```

## TASK 3
Да се напише рекурсивна функция, която установява, дали в записа на естественото число n се съдържа цифрата k. 

`Пример:`
``` C++
containsDigitIn(1234,3) => true
```

``` C++
containsDigitIn(1234,5) => false
```

## TASK  4
Напишете рекурсивна функция `int factorial(int)` , която пресмята факториел от дадено цяло число.

`Пример:`
```C++
factorial(5) => 120
```

## TASK 5
Да се напише рекурсивна функция bool `areEqual(char* str1, char* str2)`, която проверява дали двата стринга са равни.(Да се игнорират главни и малки букви)

`Пример:`
```C++
areEqual("", "") -> true
```
```C++
areEqual("", "Hi") -> false
```
```C++
areEqual("Hello","HellO") -> true
```
```C++
areEqual("Hello", "hellu") -> false
```

## TASK 6
Напишете рекурсивна функция с прототип `void evaluate(const char*)`, която намира и изпечатва
   броят на малки и големи букви и броят на цифрите в даденият низ
   
`Пример:`
``` C++
evaluate("3 Doors Down") 
      => Брой малки букви: 7
         Брой големи букви: 2
         Брой цифри: 1
```

## TASK 7
Напишете рекурсивна функция с прототип bool `swapcase(char*)`, която променя всяка голяма
буква на малка и всяка малка на голяма в подадения низ

`Пример:`
``` C++
swapcase("Yellow Submarine") => yELLOW sUBMARINE
```

## TASK 8
 Напишете функция с прототип `void truncate(char* src, int n)`, която скъсява
подадения низ до низ с дължина n. Ако низът вече е по-къс от n, той
не трябва да се модифицира

`Пример:`
``` C++
truncate("The Dark Knight Rises", 15 ) => The Dark Knight
```

## TASK 9

Да се напише рекурсивна функция, която намира n-тото число от редицата на Фибоначи.

``` C++
fib(10) => 55
```

## TASK 10
Да се напише рекурсивна функция, която намира стойността  на  функцията на Акерман Ack(m, n), дефинирана за m >= 0 и n >= 0 по следния начин:  
		Ack(0, n) = n+1  
		Ack(m, 0) = Ack(m-1, 1), m > 0  
		Ack(m, n) = Ack(m-1, Ack(m, n-1)), m > 0, n > 0.

`Пример:`
``` C++	
ack(0,3) = 4
```

``` C++	
ack(0,4) = 5
```

``` C++	
ack(1,0) = 2
```

``` C++	
ack(1,1) = 3
```

``` C++	
ack(2,0) = 3
```

``` C++	
ack(2,1) = 5
```
