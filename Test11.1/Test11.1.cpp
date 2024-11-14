#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11.1/lab11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test111
{
	TEST_CLASS(Test111)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* testFileName = "test_no_occurrences.txt";

			// ��������� ��������� �����, �� ���� ���� 'a', 'b', 'c'
			ofstream fout(testFileName);
			fout << "def ghi jkl\n"; // ������� ��������� 'a', 'b', 'c'
			fout.close();

			int expectedCount = 0; // ��������� 0
			int actualCount = CountABC(const_cast<char*>(testFileName));

			Assert::AreEqual(expectedCount, actualCount);

			remove(testFileName);
		}
	};
}
