#include <stdio.h>

typedef struct {
    /* rational type with numerator and
     * denumerator */
    int num;
    int denum;
} rational;


rational getRat();
rational makeRat(int num, int denum);
rational addRat(rational x, rational y);
rational productRat(rational x, rational y);
float deciRat(rational x);
rational reciRat(rational x);
void disp(rational x);
int gcd(int x, int y);
void dispHelp();

int main() { 
    rational x, y, z;
    char o;
    dispHelp();

    x = getRat();
    while(1){
        y = getRat();
        printf("o: ");
        o = getchar(); 
        switch (o){
            case '+':
                z = addRat(x, y);
                break;
            case '*':
                z = productRat(x, y);
                break;
            case '/':
                z = productRat(x, reciRat(y));
                break;
            case 'd':
                printf("%.4f", deciRat(x));
                z = x;
                break;
            case 'i':
                z = reciRat(x);
                break;
            case 'e':
                printf("\nExiting!\n");
                return(0);
            default:
                dispHelp();
        }
        disp(z);
        x = z;
    }
}

rational getRat(){
    int num, denum;
    printf("n: ");
    scanf("%d/%d", &num, &denum);
    getchar();  /* to flush out the <return> key pressed above */
    return(makeRat(num, denum));
}

rational makeRat(int num, int denum){
    int cfactor;
    rational x;
    cfactor = gcd(num, denum);
    x.num = num/cfactor;
    x.denum = denum/cfactor;
    return(x);
}

void disp(rational x){
    printf("A: %d/%d\n", x.num, x.denum);
}

rational addRat(rational x, rational y){
    rational z;
    z = makeRat((x.num*y.denum + y.num*x.denum), x.denum*y.denum);
    return(z);
}

rational productRat(rational x, rational y){
    return(makeRat(x.num * y.num, x.denum * y.denum));
}


float deciRat(rational x){
    return((float) x.num/x.denum);
}

rational reciRat(rational x){
    int temp;
    if (x.num == 0){
        printf("Division by 0 Error. Aborting! ");
        return(x);
    }
    temp = x.num;
    x.num = x.denum;
    x.denum = temp;
    return(x);
}

int gcd(int x, int y){
    int i, min, max;
    if (x<y){
        min = x;
        max = y;
    }
    else{
        min = y;
        max = x;
    }

    for (i=min; i>=2; i--){
        if (x%i == 0 && y%i == 0)
            return i;
    }
    return(1);
}

void dispHelp(){
    printf("\nFirst input two rational numbers (p/q).\nThen input the operation you want to perform on them.\n");
    printf("The resut will be stored in memory for next calculation.\n");
    printf("=========Operations============\n");
    printf("+  :  Addition\n");
    printf("*  :  Multiplication\n");
    printf("/  :  Division\n");
    printf("i  :  Inverse/Reciporcal\n");
    printf("d  :  Show value in Decimal\n");
    printf("h  :  Show this help message\n");
    printf("e  :  exit\n");
    printf("\n");
}
