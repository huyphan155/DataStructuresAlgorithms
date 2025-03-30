/*
Cho 1 mang bat ki, tim length lon nhat cua string khong lap lai trong mang do : 

vd : "aa" -> max length = 2
Vd : "abcda" -> max length = 4
*/



#include <stdio.h>

int  main()
{
    int  maxLength = 0U;
    int  Temp = 0U;

    char array[] = {'a','a','b','c','d','a','b','c','d','e'};

    int sizeOfArray = sizeof(array)/sizeof(array[0]);

/**
   so sanh phan tu thu nhat (i) voi cac phan tu con lai trong mang (j). Khi nao repeated thi dung lai.
    -> maxLength = i - j
***/
    for (int i=0 ; i < (sizeOfArray-1); i++)
    {
        for (int j=i+1; j < sizeOfArray; j++)
        {
            if (array[i]==array[j])
            {
                Temp = j - i;
                if (Temp > maxLength)
                {
                    maxLength = Temp;
                }
                break;
            }
        }
    }
    printf("max length of string not repeated in array is : %d ", maxLength );
}