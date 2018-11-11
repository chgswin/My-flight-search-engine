#include "stdafx.h"


Time::Time(int hour, int min)
{
	aHour = hour;
	aMin = min;
}

Time::Time(const Time& t)
{
	aHour = t.aHour;
	aMin = t.aMin;
}

int Time::GetHour()
{
	return aHour;
}

int Time::GetMin()
{
	return aMin;
}

Time Time::FindDuration(Time time)
{
	int resultMin;
	int resultHour;
	resultMin = GetMin() - time.GetMin();

	if (resultMin < 0)
	{
		resultMin += 60;
		resultHour = -1;
	}
	else
	{
		resultHour = 0;
	}

	resultHour += GetHour() - time.GetHour();
	if (resultHour < 0) resultHour += 24;

	Time result(resultHour, resultMin);
	return result;
}

string Time::Display()
{
	char result[10];
	sprintf_s(result, "%02d:%02d", GetHour(), GetMin());
	return result;
}

void Time::AddTime(Time time)
{
	int resultMin, resultHour;
	resultMin = time.GetMin() + GetMin();
	if (resultMin >= 60)
	{
		resultHour = resultMin / 60;
		resultMin = resultMin % 60;
	}
	else
	{
		resultHour = 0;
	}
	resultHour += GetHour() + time.GetHour();
	aHour = resultHour;
	aMin = resultMin;
}
int Time::CompareTime(const Time time)
{
	if (GetHour() < time.aHour) return -1;
	if (GetHour() > time.aHour) return 1;
	if (GetMin() < time.aMin) return -1;
	if (GetMin() > time.aMin) return 1;
	return 0;
}
