#include "pch.h"
#include "CppUnitTest.h"
#include "../CHINCZYK_LUDO/Kostka.h"
#include "../CHINCZYK_LUDO/Pionek.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using std::string;

namespace ChinczykTest
{
	TEST_CLASS(ChinczykTest)
	{
	public:
		
		TEST_METHOD(TestKostki)
		{
			
			int wynikRzutu = Kostka::Rzut();
			if (wynikRzutu < 1 || wynikRzutu>6)Assert::Fail();
		}

		TEST_METHOD(TestPionka)
		{

			Pionek pionek1(KolorGracza::zielony, 3);
			Pionek pionek2(KolorGracza::zielony, 3);
			Pionek pionek3(KolorGracza::czerwony, 3);
			if (!(pionek1==pionek2))Assert::Fail();
			if (pionek2 == pionek3)Assert::Fail();
		}
	};
}
