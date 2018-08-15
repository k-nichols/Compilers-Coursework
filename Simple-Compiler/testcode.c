int i;
int x[100];

int add(int n, int m) {
    return  n + m;
}
int subtract(int n, int m) {
    return  n - m;
}
int multiply(int n, int m) {
    return  n * m;
}
int divide(int n, int m) {
    return  n / m;
}

void f(void) {
    write "Void function works";
}

void main(void) {
    int j;
    int k;
    
    write "Enter three integers on their own lines";
    read i;
    read j;
    read k;
    
    write "You entered for variables i, j and k:";
    write i;
    write j;
    write k;

    write "(i + j) * k =";
    write multiply(k, add(i, j));
    write "(k - j) / 2 =";
    write divide(subtract(k, j), 2);

    if (i != j)
	write "i is not the same as j";

    if(i <= k) {
	if (i == k)
	    write "i equals k";
	else
	    write "i is less than k";
    }
    else
	write "i is greater than k";

    write "This loop should print 1-4";
    i = 1;
    while(i < 5) {
	x[i] = i;
	write x[i];
	i = i + 1;
    }

    f();
}
