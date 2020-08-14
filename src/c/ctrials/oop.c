typedef struct {
  float (*computeArea)(const ShapeClass *shape);
} ShapeClass;

float shape_computeArea(const ShapeClass *shape)
{
  return shape->computeArea(shape);
}


typedef struct {
  ShapeClass shape;
  float width, height;
} RectangleClass;

static float rectangle_computeArea(const ShapeClass *shape)
{
  const RectangleClass *rect = (const RectangleClass *) shape;
  return rect->width * rect->height;
}


void rectangle_new(RectangleClass *rect)
{
  rect->width = rect->height = 0.f;
  rect->shape.computeArea = rectangle_computeArea;
}

void rectangle_new_with_lengths(RectangleClass *rect, float width, float height)
{
  rectangle_new(rect);
  rect->width = width;
  rect->height = height;
}

int main(void)
{
  RectangleClass r1;

  rectangle_new_with_lengths(&r1, 4.f, 5.f);
  printf("rectangle r1's area is %f units square\n", shape_computeArea(&r1));
  return 0;
}

/// Object.h
typedef struct Object {
    uuid_t uuid;
} Object;

int Object_init(Object *self);
uuid_t Object_get_uuid(Object *self);
int Object_clean(Object *self);

/// Person.h
typedef struct Person {
    Object obj;
    char *name;
} Person;

int Person_init(Person *self, char *name);
int Person_greet(Person *self);
int Person_clean(Person *self);

/// Object.c
#include "object.h"

int Object_init(Object *self)
{
    self->uuid = uuid_new();

    return 0;
}
uuid_t Object_get_uuid(Object *self)
{ // Don't actually create getters in C...
    return self->uuid;
}
int Object_clean(Object *self)
{
    uuid_free(self->uuid);

    return 0;
}

/// Person.c
#include "person.h"

int Person_init(Person *self, char *name)
{
    Object_init(&self->obj); // Or just Object_init(&self);
    self->name = strdup(name);

    return 0;
}
int Person_greet(Person *self)
{
    printf("Hello, %s", self->name);

    return 0;
}
int Person_clean(Person *self)
{
    free(self->name);
    Object_clean(self);

    return 0;
}

/// main.c
int main(void)
{
    Person p;

    Person_init(&p, "John");
    Person_greet(&p);
    Object_get_uuid(&p); // Inherited function
    Person_clean(&p);

    return 0;
}

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <uchar.h>

/**
 * Define Shape class
 */
typedef struct Shape Shape;
struct Shape {
    /**
     * Variables header...
     */
    double width, height;

    /**
     * Functions header...
     */
    double (*area)(Shape *shape);
};

/**
 * Functions
 */
double calc(Shape *shape) {
        return shape->width * shape->height;
}

/**
 * Constructor
 */
Shape _Shape() {
    Shape s;

    s.width = 1;
    s.height = 1;

    s.area = calc;

    return s;
}

/********************************************/

int main() {
    Shape s1 = _Shape();
    s1.width = 5.35;
    s1.height = 12.5462;

    printf("Hello World\n\n");

    printf("User.width = %f\n", s1.width);
    printf("User.height = %f\n", s1.height);
    printf("User.area = %f\n\n", s1.area(&s1));

    printf("Made with \xe2\x99\xa5 \n");

    return 0;
};

#include <stdio.h>
#include <string.h>

struct student 
{
    int id1;
    int id2;
    char a;
    char b;
    float percentage;
};

int main() 
{
    int i;
    struct student record1 = {1, 2, 'A', 'B', 90.5};

    printf("size of structure in bytes : %d\n", 
        sizeof(record1));

    printf("\nAddress of id1        = %u", &record1.id1 );
    printf("\nAddress of id2        = %u", &record1.id2 );
    printf("\nAddress of a          = %u", &record1.a );
    printf("\nAddress of b          = %u", &record1.b );
    printf("\nAddress of percentage = %u",&record1.percentage);

    return 0;
}


fractal_t* f = malloc(sizeof *f + sizeof(double[height][width]) );