#include <stdio.h>

int main(){
  int score[5][3];
  int i, j, sum;
  float avg;

  for(i=0; i<5; i++){
    printf("%d¹ø : ",i+1);
    for(j=0; j<3; j++){
      scanf("%d",&score[i][j]);
      }
  }

  //Æò±Õ°ú ÃÑÁ¡ ±¸ÇÏ±â
  for(i=0; i<5; i++){
    sum = 0;
    for(j=0; j<3; j++){
      sum += score[i][j];
    }
    avg = (float)sum/3;
    
    printf("%d¹ø ÃÑÁ¡Àº %d, Æò±ÕÀº %.1f(µî±Þ )", i+1, sum, avg);
  }
  return 0;
}