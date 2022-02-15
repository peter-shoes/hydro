// C program to find diameter, circumference and area of a circle using functions

#include <stdio.h>
#include <math.h>
#define PI 3.1415

// Your Function prototypes should be listed first*/
float diameter(float r);
float circumference(float r);
float area(float r);


int main() {
    float radius, dia, circ, ar;
    /* Reads radius of the circle from user */

    printf("Enter radius of the circle: ");
    scanf("%f", &radius);

    dia = diameter(radius);                //Call diameter function
    circ = circumference(radius);               //Call circumference function
    ar = area(radius);                        //Call area function

    printf("Diameter of the circle = %.2f units\n", dia);
    printf("Circumference of the circle = %.2f units\n", circ);
    printf("Area of the circle = %.2f sq. units\n", ar);

    return 0;
}

// Your Function implementations should be listed last*/

// diameter function: Find the diameter of a circle whose radius is given. Remember diameter = 2 * Radius
float diameter(float r) {
    float d = 2*r;
    return d;
}
// circumference function: Find circumference of the circle whose radius is given. Remember circumference = 2 * PI * Radius
float circumference(float r) {
    float c = 2 * PI * r;
    return c;
}
// area function: Find area of the circle whose radius is given. Remember Area = PI * Radius2
float area(float r){
    float a = PI * pow(r, 2);
    return a;
}