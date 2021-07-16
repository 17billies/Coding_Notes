
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "11728.h"
Point * ones_vec_1(int length);
float compute_distance(Point* a, int first_id, int second_id);
int main(void)
{
   Point *point_array;
   int i, length, N;
   float ans;

   scanf("%d", &length);
   // give point_array memory and get first element address
   point_array = ones_vec_1(length);

   scanf("%d", &N);
   for (i = 0; i < N; i++){
      int first, second;
      scanf("%d %d", &first, &second);
      // compute distance of two points
      ans = compute_distance(point_array, first, second);
      printf("%.3f\n", ans);
   }

   return 0;
}

Point * ones_vec_1(int length){
   Point *p = malloc(length * sizeof(*p));//same as an array
   for(int i = 0; i < length; ++i){
      scanf("%d %d", &p[i].x, &p[i].y);
   }
   return &p[0];
}

float compute_distance(Point* a, int first_id, int second_id){
   float ans;
   Point first_p, second_p;
   first_p = a[first_id];
   second_p = a[second_id];
   float x1 = (float) first_p.x;//switch to float
   float x2 = (float) second_p.x;
   float y1 = (float) first_p.y;
   float y2 = (float) second_p.y;
   ans = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) ;

   return ans;
}
