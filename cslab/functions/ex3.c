#include <stdio.h>
#include <math.h>

struct Point
 {
    char name;
    int x;
    int y;
};

void READ(struct Point points[])
 {
    for (int i = 0; i < 4; i++) {
        printf("Enter information for point %d:\n", i + 1);
        printf("Name: ");
        scanf(" %c", &points[i].name);
        printf("X-coordinate: ");
        scanf("%d", &points[i].x);
        printf("Y-coordinate: ");
        scanf("%d", &points[i].y);
    }
}

double DISTANCE(struct Point p1, struct Point p2)
 {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

struct Point MIDPOINT(struct Point p1, struct Point p2)
 {
    struct Point midpoint;
    midpoint.x = (p1.x + p2.x) / 2;
    midpoint.y = (p1.y + p2.y) / 2;
    return midpoint;
}

void main() {

    struct Point points[4];

    READ(points);

    printf("Distance between points 1 and 2: %f\n", DISTANCE(points[0], points[1]));

    struct Point midpoint = MIDPOINT(points[2], points[3]);
    printf("Midpoint of points 3 and 4: (%d, %d)\n", midpoint.x, midpoint.y);

}
