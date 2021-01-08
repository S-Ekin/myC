#pragma once
int fact(int val);

template <typename T>
T abs(T i)
{
	return i >= 0 ? i : -i;
}
