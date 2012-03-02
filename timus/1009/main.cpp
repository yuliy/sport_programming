#include <stdio.h>
//#include <vector>
//#include <stdlib.h>
//#include <math.h>
//using namespace std;

int main()
{
   // Рекуррентная формула получилась вот такая:
   // Mn+1 = (K - 1) * (Mn + Mn-1);
   // Начальное условие: M2 = K * (K - 1)
   //                    M3 = (K - 1) * (K - 1) * (K + 1)

   int N, K;
   scanf( "%d%d", &N, &K );

   long long M2 = K * (K - 1);
   long long M3 = (K - 1) * (K - 1) * (K + 1);

   int res;
   if( N == 2 )
      res = M2;
   else if( N == 3 )
      res = M3;
   else
   {
      for( int i = 3; i < N; ++i )
      {
         res = (K - 1) * (M3 + M2);
         M2 = M3;
         M3 = res;
      }
   }

   printf( "%d\n", res );

   return 0;
}
