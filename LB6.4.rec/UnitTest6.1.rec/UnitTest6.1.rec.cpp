#include "pch.h"
#include "CppUnitTest.h"
#include "../LB6.4.rec/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61rec
{
	TEST_CLASS(UnitTest61rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int SIZE = 20;
			int arr[SIZE]{};
			int MIN = -20;
			int MAX = 20;
			create(arr, SIZE, MIN, MAX, 0);
			int expectedMaxModIndex = 0;
			int result = findMaxModIndex(arr, SIZE, 0, abs(arr[0]), 1);

			Assert::AreEqual(expectedMaxModIndex, result, 0.00001);
		}
	};
}
