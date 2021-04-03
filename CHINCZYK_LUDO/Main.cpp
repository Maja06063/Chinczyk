#include "pch.h"
#include"Kontrolowa_widoku.h"

using namespace System;
using namespace System::Windows::Forms;

int main()
{
    Application::EnableVisualStyles();
    CHINCZYKLUDO::Kontrolowa_widoku kontrola_widoku;
    Application::Run(% kontrola_widoku);



    return 0;
}
