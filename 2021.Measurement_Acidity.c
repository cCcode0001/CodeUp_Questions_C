#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	// Codeup Question number. 2021
	
	int Sensor_Num = 0; 
	scanf("%d", &Sensor_Num);
	
	// 동적 할당 (dynamic allocate)
	int * Acid_Data = (int *)malloc(sizeof(int) * Sensor_Num);
	int Frequency_Data[1000] = {0,}; 
	
	// 입력과 빈도 저장 (input and Storage frequency) 
	int i;
	for (i = 0; i < Sensor_Num; i++)
	{
		scanf("%d", &Acid_Data[i]);
		Frequency_Data[Acid_Data[i]] += 1;
	}	
	
	int Absolute_Subtract = 0;
	int High_Frequency = 0;
	int Less_High_Frequency = 0;
	
	// 최대 빈도와 그 다음으로 높은 빈도 찾기 (finding most high-frequency and less high-frequency)
	for (i = 0; i < 1000; i++)
	{
		if (i == 0)
			High_Frequency = i;
		else
		{
			if (Frequency_Data[High_Frequency] < Frequency_Data[i])
			{
				Less_High_Frequency = High_Frequency;
				High_Frequency = i;
			}
			
			if (Frequency_Data[Less_High_Frequency] <= Frequency_Data[i] && i != High_Frequency)
			{
				if(Frequency_Data[Less_High_Frequency] < Frequency_Data[i])
					Less_High_Frequency = i; 
				else
				{
					if (abs(High_Frequency - Less_High_Frequency) < abs(High_Frequency - i))
						Less_High_Frequency = i;
				}
			}	
		}
	}
	
	// 결과 출력 (print result) 
	printf("%d\n", abs(High_Frequency - Less_High_Frequency));
	
	// 동적 할당 해제 (release dynamic allocate)
	free(Acid_Data);
	
	return 0;
}
