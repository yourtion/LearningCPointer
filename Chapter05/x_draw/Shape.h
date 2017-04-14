#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

typedef enum {
  COLOR_BLACK,     /* 黑 */
  COLOR_BLUE,      /* 蓝 */
  COLOR_RED,       /* 红 */
  COLOR_MAGENTA,   /* 品红 */
  COLOR_GREEN,     /* 绿 */
  COLOR_CYAN,      /* 青 */
  COLOR_YELLOW,    /* 黄 */
  COLOR_WHITE      /* 白 */
} Color;

typedef enum {
  FILL_NONE,       /* 不填充 */
  FILL_SOLID,      /* 实心填充 */
  FILL_HATCH,      /* 填充斜线图案 */
  FILL_CROSSHATCH  /* 填充交叉阴影线 */
} FillPattern;

typedef enum {
  POLYLINE_PRIMITIVE,
  RECTANGLE_PRIMITIVE,
  CIRCLE_PRIMITIVE
} PrimitiveType;

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  int npoints;
  Point *point;
} Polyline;

typedef struct {
  Point minPoint;  /* 左下的坐标 */
  Point maxPoint;  /* 右上的坐标 */
} Rectangle;

typedef struct {
  Point center;    /* 圆心 */
  double radius;   /* 半径 */
} Circle;

typedef struct {
  /* 画笔（轮廓）的颜色 */
  Color pen_color;
  /* 填充样式，FILL_NONE的时候不填充 */
  FillPattern fill_pattern;
  /* 填充的颜色 */
  Color fill_color;
  /* 图形的种类 */
  PrimitiveType type;
  union {
    Polyline polyline;
    Rectangle rectangle;
    Circle circle;
  } u;
} Primitive;

typedef struct Shape_tag Shape;

typedef struct {
  Shape *head;
  Shape *tail;
} Group;

typedef enum {
  PRIMITIVE_SHAPE,
  GROUP_SHAPE
} ShapeType;

struct Shape_tag {
  ShapeType type;
  union {
    Primitive primitive;
    Group group;
  } u;
  struct Shape_tag *prev;
  struct Shape_tag *next;
};

#endif /* SHAPE_H_INCLUDED */