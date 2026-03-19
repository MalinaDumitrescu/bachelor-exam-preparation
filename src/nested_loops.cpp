#include <bits/stdc++.h>
using namespace std;
#include <iostream>
// Develop a C++ program that prints all numbers from 1 up to and including N using a for loop.
void ex_1(int n){
    for(int i = 1; i <= n; i++){
        cout << i << " ";
    }

    cout<< endl;
}

void ex_2(){
    for(int i = 1; i <= 20; i++){
        if(i % 2 == 0){
            cout << i << " ";     
        }
    }

    cout<< endl;
}


void ex_3(){
    int i = 0;
    int m ;
    cout << "m = "; cin >> m;
    cout << m << endl;
    int sum = 0;
    while(i <= m){
        sum += i;
        i++;
    }
    cout << "sum = " << sum;
    cout << endl;
}

void ex_4(int n) {
    int sum_par = 0;
    int sum_impar = 0;
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            sum_par += i;
        } else {
            sum_impar += i;
        }
    }
    cout << "sum par = " << sum_par << ", " << "sum impar = " << sum_impar << endl;
}

// factorial -> doua cazuri

void ex_5(int n) {
    long long factorial = 1;
    if (n == 0) {
    } else {
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
    }
    cout << "factorial = " << factorial << endl;

}

void ex_6(int n) {
    int i = 0;
    while (i <= n) {
       int product = i * 2;
        cout << "2 x " << i << " = " << product << endl;
        i++;
    }
}
// 0 ca input, 1 sau mai mult (trebuie tratate si numerele negatize)

void ex_7() {
    long long number;
    int count = 0;
    cout << "add a number: " << endl;
    cin >>number;
    int i = 1;
    long long temp_number = abs(number);
    if (number == 0) {
        count = 1;
    }else { while (temp_number > 0) {
        temp_number /= 10;              // Remove the last digit!!!!!!!!!!!!!!!!!!!!!!!!
        count++;
      }
    }
    cout<< "count = " << count << endl;
}

void ex_8() {
    int original_number;
    cout << "give me a number: " << endl; cin >> original_number;
    long long reverse_number = 0;
    int temp_number = original_number;
    while (temp_number != 0){
        int digit = temp_number % 10;
        reverse_number = reverse_number * 10 + digit;
        temp_number /= 10;
    }
    cout << "reverse number = " << reverse_number << endl;
}

void ex_9() {
    int palindrom_number;
    cout << "give me a number: " << endl; cin >> palindrom_number;
    int reverse_number = 0;
    int original_number;
    int temp_number;
    if(palindrom_number < 0){
        temp_number = -palindrom_number;
        original_number = -palindrom_number;
    } else {
        temp_number = palindrom_number;
        original_number = palindrom_number;
    }
    while (temp_number != 0) {
        int digit = temp_number % 10;
        reverse_number = reverse_number * 10 + digit;
        temp_number /= 10;
        cout << "iteration " << temp_number << endl;
        cout<< "digit iteration " << digit << endl;
        cout<< "reverse number iteration " << reverse_number << endl;
    }

    cout << "org num "<< original_number << endl;
    cout << "rev numb " << reverse_number << endl;
    if(reverse_number == original_number){
        cout << original_number << " is a plaindrom!" << endl;
    } else {
        cout << original_number << " is not a palindrom!" << endl;
    }
}

void ex_10() {
    int number;
    cout << "give me a number: "; cin >> number;
    int sum = 0;
    int current_number = abs(number);
    while (current_number != 0) {
        int digit = current_number % 10;
        current_number /= 10;
        sum += digit;
    }
    cout << "sum = " << sum << endl;
}

void ex_11() {
    int base;
    int exponent;
    int result = 1;
    cout << "give me a base: "; cin >> base;
    cout << "give me an exponent: "; cin >> exponent;
    if (exponent == 0) {
    }else {
        for (int i = 1; i <= exponent; i++) {
            result = result * base;
        }
    }
    cout << "result = " << result << endl;
}

int factorial(int exponent, int base) {
    int result = 1;
    if (exponent == 0) {
    } else {
        for (int i = 1; i <= exponent; i++) {
            result *= base;
        }
    }
    return result;
}
// using recursive function
void ex_12() {
    int number;
    cout << "give me a number to check if it's an Armstrong number: "; cin >> number ;
    int original_number = abs(number);
    int temp_number = abs(number);
    int sum = 0;
    int number_of_digits = 0;
    while (temp_number != 0) {
        temp_number /= 10;
        number_of_digits ++;
    }
    temp_number = original_number;
    cout << "the number has: " << number_of_digits << "of digits" << endl;
    for (int i = 1; i <= number_of_digits; i++) {
        int current_digit = temp_number % 10;
        sum += factorial(number_of_digits, current_digit);
        temp_number /= 10;
    }
    if (sum == original_number) {
        cout << original_number << " is an Armstrong number!" << endl;
    } else {
        cout << original_number << " is not an Armstrong number!" << endl;
    }
}

void ex_13() {
    int n_fibonaci;
    int number_1 = 0; int number_2 = 1;
    cout << "give me an n: "; cin >> n_fibonaci;
    if (n_fibonaci == 1) {
        cout << number_1 << " ";
    }
    if (n_fibonaci == 2) {
        cout << number_1 << " " << number_2 << " ";
    }
    cout << number_1 << " " << number_2 << " ";
    for (int i = 3; i <= n_fibonaci; i++){
        int next_number = number_1 + number_2;
        cout << next_number << " ";
        number_1 = number_2;
        number_2 = next_number;
    }
}

void ex_14(int a, int b) {
    int lowest = min(a, b);
    int gdc = 1;
    for (int i = 1; i <= lowest; i++) {
        if (a % i == 0 && b % i == 0){
            gdc = i;
        }
    }
    cout << "cel mai mare divizor comun: " << gdc << endl;
}

void ex_15(int a, int b) {
    int largest = max(a,b);
    int i = largest;
    while (true) {
        if (i % a == 0 && i % b == 0) {
            cout << "cel mai mic multiplu comun: " << i << endl;
            break;
        }
        i++;

    }

}

void ex_16(string word) {
    int length = word.length();
    int counter_vocale = 0;
    int counter_consoane = 0;
    list <char> vocale = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i <= length; i ++) {
        char current_letter = word[i];
        char lower_current_letter = tolower(current_letter);
        bool true_vocale = false;
        if (isalpha(lower_current_letter)){
        for (char v : vocale) {
            if (lower_current_letter == v) {
                true_vocale = true;
                counter_vocale++;
                break;
            }
        }
            if (!true_vocale) {
                counter_consoane++;
            }
        }
    }
    cout << "number of vocale = " << counter_vocale << endl;
    cout << "number of consoane = " << counter_consoane << endl;
}

void ex_17() {
    int arr[10] = { 1, 2 , 6, 7 , 2 , 7, 9, 10, 16, 20};
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    cout << "sum = " << sum << endl;
}

void ex_18() {
    vector<int> vec = {2, 46, 8, 29, 20, 30};
    int min, max;
    for (int i = 0; i < vec.size(); i++) {
        if (i == 0) {
            min = vec[i];
            max = vec[i];
        } else {
            if (vec[i] < min) {
                min = vec[i];
            }
            if (vec[i] > max) {
                max = vec[i];
            }
        }

        }
        cout << "min = " << min << endl;
        cout << "max = " << max << endl;
    }

bool ex_19(int number) {
    int counter = 0;
    bool prime = false;
    if (number <= 1) {
    } else {
        for (int i = 2; i <= sqrt(number); i ++) {
            if (number % i == 0) {
                counter++;
            }
        }
        if (counter == 0) {
            prime = true;
    }
        }
    return prime;
}

void ex_20() {
    vector <int> vec = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < vec.size(); i ++) {
        if (ex_19(vec[i]) == true) {
            cout << vec[i] << " ";
        }
    }
}

void ex_21() {
    int n;
    cout << "n = " << endl; cin >> n;
    int m;
    cout << "m = " << endl; cin >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << " * ";
        }
        cout << endl;
    }
}

void ex_22() {
    int n;
    int counter = 1;
    cout << "n: " << endl; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < counter; j++) {
            cout << " * ";
        }
        cout << endl;
        counter++;
    }
}

void ex_23() {
    int n;
    cout << "n: " << endl; cin >> n;
    int counter = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < counter; j++) {
            cout << " * ";
        }
        cout << endl;
        counter--;
    }
}

void ex_24() {
    int n;
    cout << "n: " << endl; cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j ++) {
            cout << " ";
        }

        for (int k = 1 ; k <= 2 * i - 1; k++) {
            cout << "*";
        }

        cout << endl;
    }


    }


void ex_25() {
    int n;
    cout << "n: " << endl; cin >> n;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j ++) {
            cout << " ";
        }

        for (int k = 1 ; k <= 2 * i - 1; k++) {
            cout << "*";
        }

        cout << endl;
    }
}
int main(){
    int n = 10;
    /*ex_1(n);
    ex_2();
    ex_3();
    ex_4(n);
    ex_5(n);
    ex_6(n);
    ex_7();
    ex_8();
    ex_9();
    ex_10();
    ex_11();
    ex_12();
    ex_13();
    ex_14(5, 10);
    ex_15(45, 10);
    ex_16("an+bsana");
    ex_17();
    ex_18();
    ex_19(4);
    ex_20();
    ex_21();
    ex_22();
    ex_23();
    ex_24();*/
    ex_25();
    return 0;
}

