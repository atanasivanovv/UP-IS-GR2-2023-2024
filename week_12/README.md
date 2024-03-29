# Пракикум #12

## Какво научихме предния път?
* Низове + Указатели + Референции

## Какво ще научим днес?
* Рекурсия

## Рекурсия (Recursion)
### Рекурсия в математиката
#### Какво е рекурсивна функция?
Ако в **дефиницията** на някаква функция се използва **самата функция**, дефиницията на функцията се нарича **рекурсивна**.  
				
Пример:
Ако n е произволно естествено число, следната дефиниция на функцията факториел 

	   n! = 1 , при n = 0
	   n! = n(n-1)!, при n > 0  
	
е рекурсивна. Условието при n = 0 не съдържа обръщение към функцията факториел и се нарича гранично условие(граничен/основен случай).

### Случаи в рекурсията:
#### основен случай(base case) - случаят, за който резултата се получава директно 
#### общ случай(general case) - случаят, при който резултата се получава рекурсивно чрез опростяване при всяко повикване
#### Правила за рекурсивни случаи:
* Всяка рекурсивнa дефиниция трябва да има един (или повече) **основни случая.**
* **Общият случай** трябва евентуално да се сведе до **основния случай.**
* **Оосновният случай** спира рекурсията.

Нека видим какво представлява рекурсията отблизо. Ще пробваме да изпълним горната дефиниция за естественото число 4.
		
		4! = 4.3!               // 4 > 0 => 4! = 4.3!
		4.3! = 4.3.2!           // 3 > 0 => 3! = 3.2! 
		4.3.2! = 4.3.2.1!       // 2 > 0 => 2! = 2.1!
		4.3.2.1! = 4.3.2.1.0!   // 1 > 0 => 1! = 1.0!
		4.3.2.1.0! = 4.3.2.1.1  // 0 = 0 => 0! = 1(гранично)
		4.3.2.1.1 = 4.3.2.1
		4.3.2.1 = 4.3.2
		4.3.2 = 4.6
		4.6 = 24		

  
### Рекурсия в С++
Известно е, че в тялото на всяка функция може да бъде извикана друга функция, която е дефинирана или е декларирана до момента на извикването й. Освен това, в C++ е разрешено функция да вика в тялото си самата себе си. **Функция, която се обръща пряко или косвено към себе си, се нарича** ***рекурсивна.*** Програма, съдържаща рекурсивна функция е рекурсивна. Чрез пример ще илюстрираме *описанието, обръщението и изпълнението* на функцията Факториел. 
```c++
#include <iostream.h> 
int fact(int); 
int main() 
{
	cout << "x= ";  
	int x;  
	cin >> x;  
	
	cout << x << "!= " << fact(x) << '\n';  
	return 0; 
} 
int fact(int n) 
{
	if (n == 0) 
		return 1;  
	else 
		return n * fact(n-1); 
} 
```	
#### Изпълнение на програмата 
Изпълнението започва с изпълнение на главната функция - въвежда стойност на променливата x. Нека за стойност на x е въведено 4. След това се изпълнява операторът  
```c++
    cout << x << "!= " << fact(x) << '\n';
```
 
За целта трябва да се пресметне стойността на функцията **fact(x)** за **x равно на 4**, след което получената стойност да се изведе. 

![](https://github.com/stoyanov624/IS_2020_2021_GR4/blob/master/Week11/images/stekova-ramka.png)

Генерира се стекова рамка за това обръщение към функцията **fact(4)**. В нея започва изпълнението на тялото на функцията за подадения параметър, тоест **n = x = 4**. 

Тъй като **n е различно от 0**, изпълнява се операторът 
```c++
	return n * fact(n-1);
```
при което трябва да се намери **fact(n-1), т.е. fact(3)**. По такъв начин преди завършването на първото обръщение към fact се прави второ обръщение към тази функция. За целта се генерира нова стекова рамка на функцията fact(3), в която **n = 3**. Тялото на функцията fact започва да се изпълнява за втори път. По аналогичен начин възникват още обръщения към функцията fact. При **последното от тях**, стойността на **n е равна на 0**.  
 
При **петото обръщение към fact стойността на n е равна на 0**. В резултат, изпълнението на това обръщение завършва и за стойност на **fact се получава 1**. 

След това последователно завършват изпълненията на останалите обръщения към тялото на функцията. При всяко изпълнение на тялото на функцията се определя съответната стойност на функцията fact. След завършването на всяко изпълнение на функцията fact, отделената за fact стекова рамка се освобождава. В крайна сметка в главната програма се връща 24 - стойността на 4!, която се извежда върху екрана. 

#### *Забележка:*
В този случай, рекурсивното дефиниране на функцията факториел не е подходящо, тъй като съществува лесно итеративно решение.(Кажете го! :) )  

#### Препоръка: Ако за решаването на някаква задача може да се използва итеративен алгоритъм(цикъл), реализирайте го. Не се препоръчва винаги използването на рекурсия, тъй като това води до загуба на памет и време. 

### Рекурсивен срещу итеративен подход

Един от често задаваните въпроси за рекурсивни функции, е "Защо да използваме рекурсивна функция, ако можеш да вършиш много от същите задачи итеративно(използвайки цикъл или цикличен алгоритъм)?". Оказва се, че винаги можете да решите проблема, както рекурсивно, така и итеративно, за нетривиални проблеми, рекурсивната версия често е много по-лесна за писане (и четене). Например, за да напишем функцията Fibonacci итеративно, ще се мъчим доста, докато рекурсивното й решение е много интуитивно. Итерационните функции (тези, които използват цикъл) са почти винаги **по-ефективни** от рекурсивните им версии. Това е така, заради стековите рамки. Итерационните функции избягват тази разходи на памет. Това не означава, че итеративните функции винаги са по-добрия избор. Понякога рекурсивната версия на функция е по-чиста и по-лесна. Като цяло, рекурсията е добър избор, когато повечето от следните неща са верни:

* Рекурсивният код е много по-лесен за изпълнение.
* Дълбочината на рекурсията може да бъде ограничена (например няма начин да се осигури вход, който да доведе до самоизвикване на 100   000 нива).
* Итеративната версия на алгоритъма изисква управление на стек от данни.
* Не е критична за ефективността на кода.

Въпреки това, ако рекурсивният алгоритъм е по-прост за изпънение, може да има смисъл да започнете рекурсивно и след това да се оптимизира до итеративен алгоритъм.

#### *За любознателните*:
**Стекът** е област за временно съхранение на информация. Той е кратковременна памет. C++ използва стека основно за реализиране на **обръщения към функции.** ***Всяко обръщение към функция*** предизвиква конструиране на **нова стекова рамка**, която се установява на върха на стека. По такъв начин когато функция A извика функция B, която от своя страна вика функция C, **стекът нараства.** Когато пък всяка от тези функции завършва, стековите рамки на тези функции автоматично се разрушават. Така **стекът се свива.** 

### Видове рекурсия
1. Линейна рекурсия (Linear recursion)
2. Двоична рекурсия (Binary recursion)
3. Oпашата рекурсия (Tail recursion)
4. Взаимна рекурсия (Mutual recursion)
5. Вложена рекурсия (Nested recursion)

#### 1. Линейна рекурсия: 
Тази рекурсия е най-често използваната. При тази рекурсия една функция извиква себе се по прост начин и при изпълнение на основния случай, тя завършва. 
Пример: Изчисление на Факториел

```c++
int Fact(long n)
{
	if(0>n)
		return -1;
	if(0 == n)
		return 1;
	else
	{
		return (n * Fact(n-1));
	}
}
```

#### 2. Двоична рекурсия: 
Двоичната рекурсия е рекурсия, при която функцията извиква себе си два пъти едновременно. Обикновено това се използва в структури, чиито операции са свързани с дървета претърсване, намиране на височина, сливане и т.н.
Пример: числа на Фибоначи

```c++
int FibNum(int n)
{
	// Основни условия
	if (n < 1)
		return -1;
	if (1 == n || 2 == n)
		return 1; 
	else	
	return FibNum(n - 1) + FibNum(n - 2);
	// По едно и също време две рекурсивни извикваня
}
```

#### 3. Опашата рекурсия: 
При този метод, рекурсивната функция извиква себе си само веднъж в края, но променя 2 параметъра едновременно. Така този метод е по-ефективен от метода на линейна или двойчна рекурсия. Това означава също, че условието на прекратяване(основния случай) ще настъпи 100%, само че, трябва да поставите това условие.

Пример: номер на Фибоначи

```c++
int FibNum(int n, int x, int y)
{
	if (1 == n) 
		return y;
	else 
		return FibNum(n-1, y, x+y);
}
```

#### 4. Взаимна рекурсия: 
Функциите се извикват взаимно. Да кажем, че A извиква B и B извиква A "рекурсивно". Това всъщност не е рекурсивно, но прави същото като рекурсията. Така че, може да се каже, че при програмните езици, които не поддържат рекурсивни извикваня, може да бъде използвано взаимно рекурсиране, за да се изпълни изискването за рекурсия. Базовия случай може да бъде включено в една, или повече от една, или всички функции.
Пример: Намиране на четно или нечетно число

```c++
bool IsOddNumber(int n)
{
	if (0 == n)
		return 0;
	else
		return IsEvenNumber(n - 1);
}

bool IsEvenNumber(int n)
{
	if (0 == n)
		return 1;
	else
		return IsOddNumber(n - 1);
}
```

#### 5. Вложена рекурсия: 
Това е много по-различна рекурсия от всички рекурсии. Външната рекурсия може да бъде преобразувана в итеративен алгоритъм(цикъл), обаче не и вложената рекурсия. Можете да се опитате да разберете тази рекурсия, чрез примера за функцията Акерман.
Пример: Функцията Акерман
В теорията на изчислителната способност, функцията Акерман, наречена на Вилхелм Акерман, е един от най-простите и най-ранно откритите примери за изчислима функция, която не е примитивена рекурсия(проста). Една обща версия на функцията: Финкция на два аргумента и е определена както следва за неотрицателни цели числа m и n:

Стойността на А нараства бързо, дори и при малки аргументи. Например, А(4,2) е число с 19 729 десетични цифри.

```c++
int Ackermann(int x, int y)
{
	// Основен случай
	if(x==0)
		return y+1;
	// Условие за обработка на грешки
	if(x > 0 && y==0)
		return Аckermann(x-1,1);
	// Рекурсивно извикване чрез вложен метод
	else
		return Аckermann(x-1, Аckermann(x,y-1));
}
```