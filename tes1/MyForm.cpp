#include "MyForm.h"
#include <iostream>
#include <ctime>
#include <thread>
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace System;
using namespace System::Windows::Forms;

	[STAThread] 


void main(array<String^>^ args) {
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		tes1::MyForm form;
		Application::Run(% form);
}