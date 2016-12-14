#include <iostream>
#include <cstring>

using namespace std;

void referenceStuff()
{
    // някаква променлива, може да е всякакъв тип
    int x = 10;

    // когато създаваме копие, копираме стойността и после променяме копието
    int xCopy = x;
    xCopy = 15;
    // после x == 10, само xCopy == 15;

    // за да създадем псевдоним (референция), задължително трябва
    // да го "обвържем" с някоя съществуваща променлива
    // int& xRef; -> грешка!

    // след това всички промени над псевдонима директно се отразяват на същата променлива (!)
    int& xRef = x; // xRef искам да е псевдоним на x, а x е тип int => xRef е тип int&
    xRef = 20;
    // вече x == 20 и xRef == 20; xCopy все така е 15

    // можем да създаваме много псевдоними на една променлива
    int& xRef2 = x;
    xRef2 += 10;
    // ефектът е същият: x == 30, xRef == 30 и xRef2 == 30.

    // позволено е и създаването на псевдоним ОТ друг псевдоним - това ще "обвърже"
    // новия псевдоним със същата променлива, с която е "обвързан" и старият.
    // няма такова нещо като псевдоним КЪМ псевдоним.
    int& xRef3 = xRef;
    xRef3 *= 2;
    // сега x == 60, xRef == 60, xRef2 == 60 и xRef3 == 60
    // а в паметта числото 60 се съдържа само на едно място - на оригиналния x (!)

    // важно - при псевдонимите нямаме превръщане на типовете!
    // double xCopy2 = x; -> позволено, ще създаде нова стойност
    // double& xRef5 = x; -> грешка!
}

void wrong_swap(int x, int y)
{
    // тъй като x и y са копия на подадените променливи,
    // то това разменя само копията и не върши нищо повече :(
    int tmp = x;
    x = y;
    y = tmp;
}

// кръщаваме я така, за да няма конфликт с вградената функция
void swap1(int& x, int& y)
{
    cout << "swap(int)" << endl;
    int tmp = x;
    x = y;
    y = tmp;
}

// позволено е да имаме същото име на функция,
// стига параметрите й да се различават по типове
void swap1(double& x, double& y)
{
    cout << "swap(double)" << endl;
    double tmp = x;
    x = y;
    y = tmp;
}

void testSwaps()
{
    int a = 5, b = 7;
    double c = 2.3, d = 3.5;
    float e = 1.2f, f = 3.4f;
    swap1(a, b); // извиква функцията, работеща с int& (int моментално се превръща в int&, няма проблем)
    swap1(c, d); // извиква функцията, работеща с double&
    // swap1(e, f); -> грешка - няма как да превърне float в int& или double&

    int& aRef = a;
    int& bRef = b;
    // функцията приема псевдоними, ние подаваме псевдоними
    // това отново разменя истинските стойности a и b!
    swap1(aRef, bRef);
    cout << a << " " << b << endl << endl;
}

void findMinMax(int arr[5], int& min, int& max)
{
    // всяка операция над масива, който сме подали, е страничен ефект!
    // arr[0] += 5;
    // масиви от псевдоними няма (!)

    // изчисляваме по някакъв начин минимума и максимума
    // и ги записваме в параметрите min и max.
    // Понеже те представляват псевдоними, то това е желаният ефект -
    // една функция да изчисли две неща и да ги "върне" на извикващата я.
    min = 0;
    max = 42;
    // и не връщаме нищо - our job here is done
}

void testMinMax()
{
    int myArr[5] = { 1,2,3,4,5 };
    int myMin, myMax;
    // тъй като findMinMax приема аргументите си като псевдоними, то
    // промените в тях ще променят именно тези myMin и myMax
    findMinMax(myArr, myMin, myMax);
    cout << "min = " << myMin << endl;
    cout << "max = " << myMax << endl;
    cout << endl;
}

void printArray(int *a, int n) {
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

void shiftArray(int a[], int n) {
    for(int i = 0; i < n - 1; i++)
        a[i] = a[i+1];
}

void printMatrix(int (*a)[10], int m, int n) {
    // cout << sizeof(a) << ' ' << sizeof(*a) << endl;
    // n = sizeof(*a) / sizeof(int);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
}

const int MAX = 100;

int readStrings(char strings[][MAX]) {
    cout << "Въведете брой низове: ";
    int n;
    cin >> n;
    // !!! изчистваме новия ред
    cin.getline(strings[0], MAX);
    for(int i = 0; i < n; i++) {
        cout << "Въведете низ " << (i + 1) << ": ";
        cin.getline(strings[i], MAX);
    }
    return n;
}

bool searchString(char strings[][MAX], int n, char s[]) {
    int i = 0;
    while (i < n && strcmp(strings[i], s) != 0)
        i++;
    // !!! НЕ: i == n
    // !!! ДА: strcmp(strings[i], s) == 0
    return i < n;
    // !!! return strcmp(strings[i], s) == 0;
}

void printStrings(char strings[][MAX], int n) {
    for(int i = 0; i < n; i++)
        cout << strings[i] << endl;
}

void testArrays() {
    int b[10] = { 1, 5, 7, 8, 10 };
    printArray(b, 5);
    printArray(b + 1, 4);
    shiftArray(b, 5);
    printArray(b, 4);
    int c[10][10] = { { 1, 2, 3 }, {4, 5, 6}, {7, 8, 9}};
    printMatrix(c, 3, 3);
    char s[10][MAX] = { "abc", "def", "ghi" };
    int n = readStrings(s);
    printStrings(s, n);
    cout << searchString(s, n, "test");

}

int z = 5;

int* f(int y, int* a) {
    int x = y;
    // !!! return &x;
    // !!! return &y;
    // return &z;
    return a + 2;
}

void testPointers() {
    int a[10] = { 1, 3, 55, 7, 10};
    int* p = f(3, a);
    cout << *p << endl;
}

int main()
{
    // testSwaps();
    // testMinMax();
    // testArrays();
    testPointers();
}
