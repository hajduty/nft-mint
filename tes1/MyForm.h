#pragma once
#pragma comment(lib, "user32.lib")
#include <iostream>
#include <windows.h>
#include <msclr/marshal_cppstd.h>

namespace tes2 {
	bool timerApplied = false;

	std::string currentTime() {
		std::string t;
		time_t currentTime;
		struct tm* localTime;

		time(&currentTime);
		localTime = localtime(&currentTime);

		int Hour = localTime->tm_hour;
		int Min = localTime->tm_min;
		int Sec = localTime->tm_sec;

		t = std::to_string(Hour) + ":" + std::to_string(Min) + ":" + std::to_string(Sec);
		return t;
	}

	void fastDupe() {
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = 0;
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;

		ip.ki.wVk = VK_CONTROL;
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT));

		ip.ki.wVk = VK_SHIFT;
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT));
		//	System::Threading::Thread::Sleep(20);
		ip.ki.wVk = 'K';
		ip.ki.dwFlags = 0;
		SendInput(1, &ip, sizeof(INPUT));

		ip.ki.wVk = VK_CONTROL;
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));

		ip.ki.wVk = VK_SHIFT;
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));

		ip.ki.wVk = 'K';
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));
		//System::Threading::Thread::Sleep(20);
		std::cout << "Clicked\n";
	}

	void getTime(int h, int m, int s) {
		while (true) {
			time_t currentTime;
			struct tm* localTime;

			time(&currentTime);
			localTime = localtime(&currentTime);

			int Hour = localTime->tm_hour;
			int Min = localTime->tm_min;
			int Sec = localTime->tm_sec;

			if (GetAsyncKeyState('U')) {
				break;
			}

			if (Hour == h && Min == m && Sec == s) {
				break;
			}
			Sleep(50);
		}
	}
	void tabChange() {
		INPUT ip;
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = 0;
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;

		ip.ki.wVk = VK_CONTROL;
		ip.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));

		ip.ki.wVk = VK_TAB;
		ip.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));

		ip.ki.wVk = VK_TAB;
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));

		ip.ki.wVk = VK_CONTROL;
		ip.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &ip, sizeof(INPUT));
	}
	void click(int x, int y) {
		PostMessage(GetForegroundWindow(), WM_LBUTTONDOWN, MK_RBUTTON, MAKELPARAM(x, y));
		PostMessage(GetForegroundWindow(), WM_LBUTTONUP, MK_RBUTTON, MAKELPARAM(x, y));
		PostMessage(GetForegroundWindow(), WM_LBUTTONDOWN, MK_RBUTTON, MAKELPARAM(x, y));
		PostMessage(GetForegroundWindow(), WM_LBUTTONUP, MK_RBUTTON, MAKELPARAM(x, y));
		PostMessage(GetForegroundWindow(), WM_LBUTTONDOWN, MK_RBUTTON, MAKELPARAM(x, y));
		PostMessage(GetForegroundWindow(), WM_LBUTTONUP, MK_RBUTTON, MAKELPARAM(x, y));
	}
}

namespace tes1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			timer1->Enabled;
			timer2->Enabled;

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ urlBox;
	protected:

	protected:

	private: System::Windows::Forms::Label^ urlText;

	private: System::Windows::Forms::Button^ applyButton;
	private: System::Windows::Forms::Label^ urlAppliedLabel;

	private: System::Windows::Forms::CheckBox^ recButton;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ recText;

	private:

	private: System::Windows::Forms::Label^ ylabel;
	private: System::Windows::Forms::Label^ xlabel;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Button^ tabsButton;
	private: System::Windows::Forms::Label^ tabsLabel;
	private: System::Windows::Forms::Label^ tabsAppliedLabel;

	private: System::Windows::Forms::Label^ timerText;

	private: System::Windows::Forms::Button^ timeApply;
	private: System::Windows::Forms::Label^ timerLabel;
	private: System::Windows::Forms::Button^ startButton;

	private: System::Windows::Forms::NumericUpDown^ tabsUp;
	private: System::Windows::Forms::NumericUpDown^ secUp;

	private: System::Windows::Forms::NumericUpDown^ minUp;

	private: System::Windows::Forms::NumericUpDown^ hourUp;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker2;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker3;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker4;
	public: System::Windows::Forms::NumericUpDown^ multiplier;
	private: System::Windows::Forms::Label^ hintBox;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label3;
	public:

	public:
	private:

	private:

	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->urlBox = (gcnew System::Windows::Forms::TextBox());
			this->urlText = (gcnew System::Windows::Forms::Label());
			this->applyButton = (gcnew System::Windows::Forms::Button());
			this->urlAppliedLabel = (gcnew System::Windows::Forms::Label());
			this->recButton = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->recText = (gcnew System::Windows::Forms::Label());
			this->ylabel = (gcnew System::Windows::Forms::Label());
			this->xlabel = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabsButton = (gcnew System::Windows::Forms::Button());
			this->tabsLabel = (gcnew System::Windows::Forms::Label());
			this->tabsAppliedLabel = (gcnew System::Windows::Forms::Label());
			this->timerText = (gcnew System::Windows::Forms::Label());
			this->timeApply = (gcnew System::Windows::Forms::Button());
			this->timerLabel = (gcnew System::Windows::Forms::Label());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->tabsUp = (gcnew System::Windows::Forms::NumericUpDown());
			this->secUp = (gcnew System::Windows::Forms::NumericUpDown());
			this->minUp = (gcnew System::Windows::Forms::NumericUpDown());
			this->hourUp = (gcnew System::Windows::Forms::NumericUpDown());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker3 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker4 = (gcnew System::ComponentModel::BackgroundWorker());
			this->multiplier = (gcnew System::Windows::Forms::NumericUpDown());
			this->hintBox = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tabsUp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->secUp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minUp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hourUp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->multiplier))->BeginInit();
			this->SuspendLayout();
			// 
			// urlBox
			// 
			this->urlBox->BackColor = System::Drawing::Color::White;
			this->urlBox->ForeColor = System::Drawing::Color::Black;
			this->urlBox->Location = System::Drawing::Point(36, 62);
			this->urlBox->Name = L"urlBox";
			this->urlBox->Size = System::Drawing::Size(225, 27);
			this->urlBox->TabIndex = 1;
			this->urlBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// urlText
			// 
			this->urlText->AutoSize = true;
			this->urlText->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->urlText->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->urlText->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"urlText.Image")));
			this->urlText->Location = System::Drawing::Point(31, 33);
			this->urlText->Name = L"urlText";
			this->urlText->Size = System::Drawing::Size(47, 26);
			this->urlText->TabIndex = 2;
			this->urlText->Text = L"URL";
			// 
			// applyButton
			// 
			this->applyButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"applyButton.BackgroundImage")));
			this->applyButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->applyButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->applyButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->applyButton->FlatAppearance->BorderSize = 0;
			this->applyButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Aqua;
			this->applyButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Blue;
			this->applyButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->applyButton->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->applyButton->ForeColor = System::Drawing::Color::Transparent;
			this->applyButton->Location = System::Drawing::Point(266, 62);
			this->applyButton->Name = L"applyButton";
			this->applyButton->Size = System::Drawing::Size(56, 27);
			this->applyButton->TabIndex = 3;
			this->applyButton->Text = L"Open";
			this->applyButton->UseVisualStyleBackColor = true;
			this->applyButton->Click += gcnew System::EventHandler(this, &MyForm::applyButton_Click_1);
			// 
			// urlAppliedLabel
			// 
			this->urlAppliedLabel->AutoSize = true;
			this->urlAppliedLabel->Font = (gcnew System::Drawing::Font(L"Calibri Light", 11, System::Drawing::FontStyle::Italic));
			this->urlAppliedLabel->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->urlAppliedLabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"urlAppliedLabel.Image")));
			this->urlAppliedLabel->Location = System::Drawing::Point(33, 92);
			this->urlAppliedLabel->Name = L"urlAppliedLabel";
			this->urlAppliedLabel->Size = System::Drawing::Size(193, 18);
			this->urlAppliedLabel->TabIndex = 4;
			this->urlAppliedLabel->Text = L"Enter page url you wish to use.";
			// 
			// recButton
			// 
			this->recButton->Appearance = System::Windows::Forms::Appearance::Button;
			this->recButton->AutoSize = true;
			this->recButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"recButton.BackgroundImage")));
			this->recButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->recButton->CheckAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->recButton->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->recButton->FlatAppearance->BorderSize = 0;
			this->recButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->recButton->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->recButton->ForeColor = System::Drawing::Color::White;
			this->recButton->Location = System::Drawing::Point(267, 163);
			this->recButton->Name = L"recButton";
			this->recButton->Size = System::Drawing::Size(55, 25);
			this->recButton->TabIndex = 5;
			this->recButton->Text = L"Record";
			this->recButton->UseVisualStyleBackColor = false;
			this->recButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::recButton_CheckedChanged);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(31, 110);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 81);
			this->label1->TabIndex = 6;
			this->label1->Text = L"MOUSE LOCATION";
			// 
			// recText
			// 
			this->recText->Font = (gcnew System::Drawing::Font(L"Calibri Light", 10, System::Drawing::FontStyle::Italic));
			this->recText->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->recText->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"recText.Image")));
			this->recText->Location = System::Drawing::Point(31, 191);
			this->recText->Name = L"recText";
			this->recText->Size = System::Drawing::Size(291, 22);
			this->recText->TabIndex = 9;
			this->recText->Text = L"Press record, then point at location and press \'K\'.  ";
			// 
			// ylabel
			// 
			this->ylabel->AutoSize = true;
			this->ylabel->Font = (gcnew System::Drawing::Font(L"Calibri Light", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ylabel->ForeColor = System::Drawing::Color::SteelBlue;
			this->ylabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ylabel.Image")));
			this->ylabel->Location = System::Drawing::Point(143, 165);
			this->ylabel->Name = L"ylabel";
			this->ylabel->Size = System::Drawing::Size(20, 19);
			this->ylabel->TabIndex = 11;
			this->ylabel->Text = L"Y:";
			// 
			// xlabel
			// 
			this->xlabel->AutoSize = true;
			this->xlabel->Font = (gcnew System::Drawing::Font(L"Calibri Light", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->xlabel->ForeColor = System::Drawing::Color::SteelBlue;
			this->xlabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"xlabel.Image")));
			this->xlabel->Location = System::Drawing::Point(31, 165);
			this->xlabel->Name = L"xlabel";
			this->xlabel->Size = System::Drawing::Size(21, 19);
			this->xlabel->TabIndex = 12;
			this->xlabel->Text = L"X:";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri Light", 9.5F, System::Drawing::FontStyle::Italic));
			this->label2->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label2.Image")));
			this->label2->Location = System::Drawing::Point(33, 414);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 15);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Time is currently: ";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(343, 544);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// tabsButton
			// 
			this->tabsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabsButton.BackgroundImage")));
			this->tabsButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->tabsButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->tabsButton->FlatAppearance->BorderSize = 0;
			this->tabsButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Aqua;
			this->tabsButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Blue;
			this->tabsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->tabsButton->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabsButton->ForeColor = System::Drawing::Color::Transparent;
			this->tabsButton->Location = System::Drawing::Point(267, 260);
			this->tabsButton->Name = L"tabsButton";
			this->tabsButton->Size = System::Drawing::Size(56, 27);
			this->tabsButton->TabIndex = 16;
			this->tabsButton->Text = L"Apply";
			this->tabsButton->UseVisualStyleBackColor = true;
			this->tabsButton->Click += gcnew System::EventHandler(this, &MyForm::tabsButton_Click);
			// 
			// tabsLabel
			// 
			this->tabsLabel->AutoSize = true;
			this->tabsLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabsLabel->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->tabsLabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabsLabel.Image")));
			this->tabsLabel->Location = System::Drawing::Point(29, 231);
			this->tabsLabel->Name = L"tabsLabel";
			this->tabsLabel->Size = System::Drawing::Size(55, 26);
			this->tabsLabel->TabIndex = 17;
			this->tabsLabel->Text = L"TABS";
			// 
			// tabsAppliedLabel
			// 
			this->tabsAppliedLabel->AutoSize = true;
			this->tabsAppliedLabel->Font = (gcnew System::Drawing::Font(L"Calibri Light", 11, System::Drawing::FontStyle::Italic));
			this->tabsAppliedLabel->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->tabsAppliedLabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tabsAppliedLabel.Image")));
			this->tabsAppliedLabel->Location = System::Drawing::Point(32, 290);
			this->tabsAppliedLabel->Name = L"tabsAppliedLabel";
			this->tabsAppliedLabel->Size = System::Drawing::Size(234, 18);
			this->tabsAppliedLabel->TabIndex = 18;
			this->tabsAppliedLabel->Text = L"Enter how many tabs you\'d like open.";
			// 
			// timerText
			// 
			this->timerText->AutoSize = true;
			this->timerText->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timerText->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->timerText->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"timerText.Image")));
			this->timerText->Location = System::Drawing::Point(31, 337);
			this->timerText->Name = L"timerText";
			this->timerText->Size = System::Drawing::Size(68, 26);
			this->timerText->TabIndex = 20;
			this->timerText->Text = L"CLOCK";
			// 
			// timeApply
			// 
			this->timeApply->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"timeApply.BackgroundImage")));
			this->timeApply->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->timeApply->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->timeApply->FlatAppearance->BorderSize = 0;
			this->timeApply->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Aqua;
			this->timeApply->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Blue;
			this->timeApply->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->timeApply->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeApply->ForeColor = System::Drawing::Color::Transparent;
			this->timeApply->Location = System::Drawing::Point(266, 366);
			this->timeApply->Name = L"timeApply";
			this->timeApply->Size = System::Drawing::Size(56, 27);
			this->timeApply->TabIndex = 21;
			this->timeApply->Text = L"Apply";
			this->timeApply->UseVisualStyleBackColor = true;
			this->timeApply->Click += gcnew System::EventHandler(this, &MyForm::timeApply_Click);
			// 
			// timerLabel
			// 
			this->timerLabel->AutoSize = true;
			this->timerLabel->Font = (gcnew System::Drawing::Font(L"Calibri Light", 10, System::Drawing::FontStyle::Italic));
			this->timerLabel->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->timerLabel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"timerLabel.Image")));
			this->timerLabel->Location = System::Drawing::Point(33, 396);
			this->timerLabel->Name = L"timerLabel";
			this->timerLabel->Size = System::Drawing::Size(232, 17);
			this->timerLabel->TabIndex = 22;
			this->timerLabel->Text = L"Enter which time you\'d like to autostart.";
			// 
			// startButton
			// 
			this->startButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->startButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"startButton.BackgroundImage")));
			this->startButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->startButton->FlatAppearance->BorderSize = 0;
			this->startButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->startButton->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startButton->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->startButton->Location = System::Drawing::Point(0, 444);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(343, 100);
			this->startButton->TabIndex = 25;
			this->startButton->Text = L"START";
			this->startButton->UseVisualStyleBackColor = false;
			this->startButton->Click += gcnew System::EventHandler(this, &MyForm::startButton_Click);
			// 
			// tabsUp
			// 
			this->tabsUp->BackColor = System::Drawing::Color::White;
			this->tabsUp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tabsUp->ForeColor = System::Drawing::Color::Black;
			this->tabsUp->Location = System::Drawing::Point(35, 260);
			this->tabsUp->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->tabsUp->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->tabsUp->Name = L"tabsUp";
			this->tabsUp->Size = System::Drawing::Size(108, 27);
			this->tabsUp->TabIndex = 26;
			this->tabsUp->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->tabsUp->ValueChanged += gcnew System::EventHandler(this, &MyForm::tabsUp_ValueChanged);
			// 
			// secUp
			// 
			this->secUp->BackColor = System::Drawing::Color::White;
			this->secUp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->secUp->ForeColor = System::Drawing::Color::Black;
			this->secUp->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->secUp->Location = System::Drawing::Point(119, 366);
			this->secUp->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->secUp->Name = L"secUp";
			this->secUp->Size = System::Drawing::Size(73, 27);
			this->secUp->TabIndex = 27;
			this->secUp->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// minUp
			// 
			this->minUp->BackColor = System::Drawing::Color::White;
			this->minUp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->minUp->ForeColor = System::Drawing::Color::Black;
			this->minUp->Location = System::Drawing::Point(198, 366);
			this->minUp->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->minUp->Name = L"minUp";
			this->minUp->Size = System::Drawing::Size(63, 27);
			this->minUp->TabIndex = 28;
			this->minUp->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// hourUp
			// 
			this->hourUp->BackColor = System::Drawing::Color::White;
			this->hourUp->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->hourUp->ForeColor = System::Drawing::Color::Black;
			this->hourUp->Location = System::Drawing::Point(36, 366);
			this->hourUp->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 24, 0, 0, 0 });
			this->hourUp->Name = L"hourUp";
			this->hourUp->Size = System::Drawing::Size(77, 27);
			this->hourUp->TabIndex = 29;
			this->hourUp->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			// 
			// backgroundWorker3
			// 
			this->backgroundWorker3->WorkerReportsProgress = true;
			this->backgroundWorker3->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker3_DoWork);
			this->backgroundWorker3->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker3_RunWorkerCompleted);
			// 
			// backgroundWorker4
			// 
			this->backgroundWorker4->WorkerReportsProgress = true;
			this->backgroundWorker4->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker4_DoWork);
			this->backgroundWorker4->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker4_RunWorkerCompleted);
			// 
			// multiplier
			// 
			this->multiplier->BackColor = System::Drawing::Color::White;
			this->multiplier->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->multiplier->ForeColor = System::Drawing::Color::Black;
			this->multiplier->Location = System::Drawing::Point(153, 260);
			this->multiplier->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->multiplier->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->multiplier->Name = L"multiplier";
			this->multiplier->Size = System::Drawing::Size(108, 27);
			this->multiplier->TabIndex = 30;
			this->multiplier->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->multiplier->ValueChanged += gcnew System::EventHandler(this, &MyForm::multiplier_ValueChanged);
			// 
			// hintBox
			// 
			this->hintBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->hintBox->AutoSize = true;
			this->hintBox->Font = (gcnew System::Drawing::Font(L"Calibri", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hintBox->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->hintBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hintBox.Image")));
			this->hintBox->Location = System::Drawing::Point(105, 517);
			this->hintBox->Name = L"hintBox";
			this->hintBox->Size = System::Drawing::Size(0, 16);
			this->hintBox->TabIndex = 31;
			this->hintBox->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->hintBox->UseCompatibleTextRendering = true;
			this->hintBox->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 5000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label3.Image")));
			this->label3->Location = System::Drawing::Point(148, 231);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 26);
			this->label3->TabIndex = 32;
			this->label3->Text = L"MULTIPLIER";
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
			this->BackColor = System::Drawing::Color::DarkCyan;
			this->ClientSize = System::Drawing::Size(343, 544);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->hintBox);
			this->Controls->Add(this->multiplier);
			this->Controls->Add(this->hourUp);
			this->Controls->Add(this->minUp);
			this->Controls->Add(this->secUp);
			this->Controls->Add(this->tabsUp);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->timerLabel);
			this->Controls->Add(this->timeApply);
			this->Controls->Add(this->timerText);
			this->Controls->Add(this->tabsAppliedLabel);
			this->Controls->Add(this->tabsLabel);
			this->Controls->Add(this->tabsButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->xlabel);
			this->Controls->Add(this->ylabel);
			this->Controls->Add(this->recText);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->recButton);
			this->Controls->Add(this->urlAppliedLabel);
			this->Controls->Add(this->applyButton);
			this->Controls->Add(this->urlText);
			this->Controls->Add(this->urlBox);
			this->Controls->Add(this->pictureBox1);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->HelpButton = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"MintSpammer";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tabsUp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->secUp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minUp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hourUp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->multiplier))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void applyButton_Click_1(System::Object^ sender, System::EventArgs^ e) {
		urlAppliedLabel->Text = "Applied as " + urlBox->Text;

		System::String^ url2 = urlBox->Text;
		std::string converted_url2 = msclr::interop::marshal_as< std::string >(url2);
		//url2 = std::c_str(urlBox->Text);
		system(("start msedge.exe " + converted_url2).c_str());
	}
	private: System::Void recButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		//recText->Text = "Mouse location successfully set.";

		//if (backgroundWorker3->IsBusy) {
		//	recText->Text = "Stopped";
		//	backgroundWorker3->CancelAsync();
		//	backgroundWorker4->CancelAsync();
		//}
		if (!backgroundWorker3->IsBusy) {
			backgroundWorker3->RunWorkerAsync();
			backgroundWorker4->RunWorkerAsync();
			recText->Text = "RECORDING.";
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		String^ crTime = msclr::interop::marshal_as < String^ >(tes2::currentTime());

		String^ time = "Time is currently: " + crTime;

		label2->Text = time;
	}
	private: System::Void tabsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		tabsAppliedLabel->Text = "Tabs have been set to " + tabsUp->Text;
	}
	private: System::Void tabsUp_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timeApply_Click(System::Object^ sender, System::EventArgs^ e) {
		tes2::timerApplied = true;
	}
	private: System::Void backgroundWorker2_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		e->Cancel = false;
		if (xlabel->Text == "X:" & ylabel->Text == "Y:") {
			return;
		}
		else {
			std::string hourS = msclr::interop::marshal_as< std::string >(hourUp->Text);
			std::string minuteS = msclr::interop::marshal_as< std::string >(secUp->Text);
			std::string secondS = msclr::interop::marshal_as< std::string >(minUp->Text);
			std::string tabsU = msclr::interop::marshal_as< std::string >(tabsUp->Text);
			std::string multiU = msclr::interop::marshal_as< std::string >(multiplier->Text);

			int hour = std::stoi(hourS);
			int minute = std::stoi(minuteS);
			int second = std::stoi(secondS);
			int tabs = std::stoi(tabsU);
			int multi = std::stoi(multiU);

			System::String^ url2 = urlBox->Text;
			std::string converted_url2 = msclr::interop::marshal_as< std::string >(url2);

			system(("start msedge.exe " + converted_url2).c_str());
			System::Threading::Thread::Sleep(2000);
			for (int i = 0; i < tabs; i++) {
				if (GetAsyncKeyState('U')) {
					e->Cancel = true;
					return;
					Beep(100, 60);
				}
				if (backgroundWorker2->CancellationPending == true) {
					e->Cancel = true;
					return;
				}
				tes2::fastDupe();
				System::Threading::Thread::Sleep(30);
			}
			System::Threading::Thread::Sleep(1000);
			if (tes2::timerApplied == true) {
				tes2::getTime(hour, minute, second);
			}

			std::string xe = msclr::interop::marshal_as< std::string >(xlabel->Text);
			std::string ye = msclr::interop::marshal_as< std::string >(ylabel->Text);

			int x = std::stoi(xe);
			int y = std::stoi(ye);

			for (int i = 0; i < tabs * multi; i++) {
				if (GetAsyncKeyState('U')) {
					e->Cancel = true;
					return;
					Beep(100, 60);
				}
				if (backgroundWorker2->CancellationPending == true) {
					e->Cancel = true;
					return;
				}
				tes2::tabChange();
				System::Threading::Thread::Sleep(50);
				tes2::click(x, y);
				System::Threading::Thread::Sleep(50);
			}
		}
		if (backgroundWorker2->CancellationPending == true) {
			e->Cancel = true;
			return;
		}
	}
	private: System::Void backgroundWorker2_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
		if (e->Cancelled) {
			startButton->Text = "Cancelled";
		}
		else if (e->Error != nullptr) {
			startButton->Text = "Error";
		}
		else {
			startButton->Text = "COMPLETED.";
		}
	}
	private: System::Void backgroundWorker3_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		e->Cancel = false;
		System::String^ xe = "";
		while (true) {
			if (GetAsyncKeyState(0x4B) & 0x8000) {
				Beep(200, 60);

				POINT point;
				if (GetCursorPos(&point)) {
					int px = 0;
					px = point.x;
					std::string hejx = std::to_string(px);
					String^ xbString = msclr::interop::marshal_as < String^ >(hejx);
					xe = xbString;
				}
				break;
			}
		}
		System::String^ resx = xe;
		e->Result = resx;
		System::Threading::Thread::Sleep(50);
	}
	private: System::Void backgroundWorker3_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
		if (e->Cancelled) {
			recText->Text = "Press record, then point at location and press 'K'.";
		}
		else if (e->Error != nullptr) {
			recText->Text = "Error";
		}
		else {
			recText->Text = "Press record, then point at location and press 'K'.";
			xlabel->Text = System::Convert::ToString(e->Result);
			//ylabel->Text = //System::Convert::ToString(py);
		}
	}
	private: System::Void backgroundWorker4_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
		e->Cancel = false;
		System::String^ xe = "";
		System::String^ ye = "";
		while (true) {
			if (GetAsyncKeyState(0x4B) & 0x8000) {
				int py = 0;
				Beep(100, 60);

				POINT point;
				if (GetCursorPos(&point)) {
					int py;
					py = point.y;
					std::string hejy = std::to_string(py);
					String^ ybString = msclr::interop::marshal_as < String^ >(hejy);
					ye = ybString;
				}
				break;
			}
		}
		System::String^ resy = ye;
		e->Result = resy;
		System::Threading::Thread::Sleep(50);
	}
	private: System::Void backgroundWorker4_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
		if (e->Cancelled) {
			recText->Text = "Press record, then point at location and press 'K'.";
		}
		else if (e->Error != nullptr) {
			recText->Text = "Error";
		}
		else {
			ylabel->Text = System::Convert::ToString(e->Result);
			//ylabel->Text = //System::Convert::ToString(py);
		}
	}
	private: System::Void multiplier_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	}
	private: System::Void timer2_Tick_1(System::Object^ sender, System::EventArgs^ e) {
		hintBox->Text = "";
	}
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (backgroundWorker2->IsBusy) {
			backgroundWorker2->CancelAsync();
			startButton->Text = "START";
		}
		if (!backgroundWorker2->IsBusy) {
			backgroundWorker2->RunWorkerAsync();
			startButton->Text = "RUNNING";
		}
		if (backgroundWorker2->CancellationPending == true) {
			startButton->Text = "STOPPED";
		}
		if (xlabel->Text == "X:" && ylabel->Text == "Y:") {
			hintBox->Text = "ERR: SET MOUSE LOCATION";
			startButton->Text = "START";
		}
	}
	};
}
//String^ result;
//result = msclr::interop::marshal_as < String ^ >(tes2::currentTime());
//recX->Text = result;