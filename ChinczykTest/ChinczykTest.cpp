#include "pch.h"
#include "CppUnitTest.h"
#include "../CHINCZYK_LUDO/Kostka.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChinczykTest
{
	TEST_CLASS(ChinczykTest)
	{
	public:
		
		TEST_METHOD(TestKostki)
		{
			//Kostka::Rzut();
			Kostka kostka;
			kostka.Rzut();

			Assert::Fail();



		}
	};
}
