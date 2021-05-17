#include "pch.h"
#include"KontrolaWidoku.h"

using namespace System;
using namespace System::Windows::Forms;

int main()
{
    Application::EnableVisualStyles();
    CHINCZYKLUDO::KontrolaWidoku kontrolaWidoku;
    Application::Run(% kontrolaWidoku);

    return 0;
}
