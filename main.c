#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

/* Add function that add elements in an array
    for checking if the number has appeared already */
int add(int a[],int data, int pos){
    int i;
    for(i=9999;i>=pos -1;i--)
     a[i+1] = a[i];
    a[pos-1] = data;

}

/* find function that looks for element in an array*/
int find(int a[],int data) {
   int i;
   for (i=0; i<MAX; i++)
   {
     if (a[i] == data)
     {
        return (1);
     }
   }
   return(0);
}

/* Sort function that sorts the function in ascending order*/
/* I have used effective method as I know the number has to */
/* four digit */
int sort_array(int num, int count) {
    int temp, i;
    int val = 0;
    int sorted = 0;

    for (i = 0; i < 10; ++i) {
            for (temp=num;temp>0;temp/=10) {

                if (temp % 10 == i){
                    if (count == 1000) {
                        val = i * count;
                        sorted = val;
                        count = count - 900;
                    }
                    else if (count == 100) {
                        val = i * count;
                        sorted += val;
                         count = count - 90;
                    }
                    else if (count == 10) {
                        val = i * count;
                        sorted += val;
                        count = count - 9;

                    }
                    else if (count == 1) {
                        sorted += i;
                    }
                }
            }
        }
        return sorted;

}

/* Reverse sorted the array to get descending*/
int rev_sort_array(int n, int count2) {
    int temp1;
    int reverse = 0;

    while (n != 0)
       {
            if (count2 == 1000) {
                temp1= n%10 * 1000;
                count2 = count2 - 900;
            }
            else if (count2 == 100) {
                temp1 = n%10 * 100;
                count2 = count2 - 90;
            }
            else if (count2 == 10) {
                temp1 = n%10 * 10;
                count2 = count2 - 9;
            }
            else if (count2 == 1) {
                temp1 = n%10 * 1;
        }
          reverse = reverse + temp1;
            n = n/10;
       }
       return reverse;
}

/* Checking if input is four digit
    so that it is easier to sort later
    even if it less than four digits */
int check_four_digit(int num) {
    if (num >0 && num < 10)
        return (num * 1000);
    else if (num > 9 && num < 100)
        return (num * 100);
    else if (num > 99 && num < 1000)
        return (num * 10);
    else
        return num;
}

int main() {
    int array[10000];
    int num, diff, val, n;
    int sorted;
    int reverse = 0;
    int ret = 0;
    int counter = 0;
    int iterations = 0;

    printf("value: ");
    scanf("%d" , &val);

    num = check_four_digit(val);
    add(array, num, counter);

    while (ret != 1) {
        iterations++;
        sorted = sort_array(num, 1000);
        n = sorted;
        reverse = rev_sort_array(n, 1000);

        printf("n1: %04d\n", reverse);
        printf("n2: %04d\n", sorted);

        diff = reverse - sorted;
        printf("newValue: %04d\n\n", diff);
        printf("value: %d\n", diff );


        counter = counter+1;
        num = check_four_digit(diff);
        ret = find(array, num);
        add(array, num,counter);
    }

    printf("The number of iterations :%d", iterations);
    return 0;

}




