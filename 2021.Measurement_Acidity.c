#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	// Codeup Question number. 2021
	
	int Sensor_Num = 0; 
	scanf("%d", &Sensor_Num);
	
	// ���� �Ҵ� (dynamic allocate)
	int * Acid_Data = (int *)malloc(sizeof(int) * Sensor_Num);
	int Frequency_Data[1000] = {0,}; 
	
	// �Է°� �� ���� (input and Storage frequency) 
	int i;
	for (i = 0; i < Sensor_Num; i++)
	{
		scanf("%d", &Acid_Data[i]);
		Frequency_Data[Acid_Data[i]] += 1;
	}	
	
	int Absolute_Subtract = 0;
	int High_Frequency = 0;
	int Less_High_Frequency = 0;
	
	// �ִ� �󵵿� �� �������� ���� �� ã�� (finding most high-frequency and less high-frequency)
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
	
	// ��� ��� (print result) 
	printf("%d\n", abs(High_Frequency - Less_High_Frequency));
	
	// ���� �Ҵ� ���� (release dynamic allocate)
	free(Acid_Data);
	
	return 0;
}
