#pragma once
#include "iostream"
#include "Windows.h"
#include <TlHelp32.h>


DWORD FindProcessId(const std::wstring& processName);
bool IsProcessRunning(const wchar_t *processName);

namespace Touhou_ScoreOrEncrypt {
	


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const wchar_t *nameOfProcess = L"th06e.exe";
	//Process Name

	LPCVOID MemoryAddress = (LPCVOID)0x0069BCA0;
	//Memory Address of Score
	

	/// <summary>
	/// MainThread에 대한 요약입니다.
	/// </summary>
	public ref class MainThread : public System::Windows::Forms::Form
	{
	public:
		MainThread(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			
		}

	public:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MainThread()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::GroupBox^  DecryptionBox;
	private: System::Windows::Forms::GroupBox^  ScoreBox;
	private: System::Windows::Forms::ProgressBar^  ScoreProgress;
	private: System::Windows::Forms::Label^  ScoreLabel;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::GroupBox^  PCMCbox;
	private: System::Windows::Forms::Label^  MemCheckLabel;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ProgressBar^  MemCheckProgress;
	private: System::Windows::Forms::Button^  button1;


	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainThread::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->DecryptionBox = (gcnew System::Windows::Forms::GroupBox());
			this->ScoreBox = (gcnew System::Windows::Forms::GroupBox());
			this->ScoreProgress = (gcnew System::Windows::Forms::ProgressBar());
			this->ScoreLabel = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->PCMCbox = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->MemCheckLabel = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->MemCheckProgress = (gcnew System::Windows::Forms::ProgressBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->DecryptionBox->SuspendLayout();
			this->ScoreBox->SuspendLayout();
			this->PCMCbox->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(253, 534);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"궁서", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(250, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(268, 40);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Your Precious Files are\r\nEncrypted by BakaWare";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(254, 65);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(257, 60);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Cirno was walking around your computer\r\nand saw a precious ransomware called\r\nWan"
				L"naCry. Cirno accidently double-clicked\r\nthe program and your precious files are "
				L"now\r\nencrypted";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"궁서", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(249, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(265, 38);
			this->label3->TabIndex = 3;
			this->label3->Text = L"What you need to do to\r\nrecover your FILES";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(259, 192);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(248, 60);
			this->label4->TabIndex = 4;
			this->label4->Text = L"That\'s easy, You just need to persuade\r\nCirno by playing TH06 - The Embodiment \r\n"
				L"of Scarlet Devil and score more than 1M\r\nin the game! Cirno will give you the ke"
				L"y to \r\ndecrypt your precious FILES!";
			// 
			// DecryptionBox
			// 
			this->DecryptionBox->Controls->Add(this->button1);
			this->DecryptionBox->Controls->Add(this->ScoreBox);
			this->DecryptionBox->Controls->Add(this->PCMCbox);
			this->DecryptionBox->Font = (gcnew System::Drawing::Font(L"돋움", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->DecryptionBox->Location = System::Drawing::Point(256, 273);
			this->DecryptionBox->Name = L"DecryptionBox";
			this->DecryptionBox->Size = System::Drawing::Size(253, 261);
			this->DecryptionBox->TabIndex = 5;
			this->DecryptionBox->TabStop = false;
			this->DecryptionBox->Text = L"Decryption Status";
			// 
			// ScoreBox
			// 
			this->ScoreBox->Controls->Add(this->ScoreProgress);
			this->ScoreBox->Controls->Add(this->ScoreLabel);
			this->ScoreBox->Controls->Add(this->label6);
			this->ScoreBox->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->ScoreBox->Location = System::Drawing::Point(5, 80);
			this->ScoreBox->Name = L"ScoreBox";
			this->ScoreBox->Size = System::Drawing::Size(243, 74);
			this->ScoreBox->TabIndex = 2;
			this->ScoreBox->TabStop = false;
			this->ScoreBox->Text = L"TH06 Score Status";
			// 
			// ScoreProgress
			// 
			this->ScoreProgress->Location = System::Drawing::Point(10, 56);
			this->ScoreProgress->Name = L"ScoreProgress";
			this->ScoreProgress->Size = System::Drawing::Size(223, 12);
			this->ScoreProgress->TabIndex = 2;
			// 
			// ScoreLabel
			// 
			this->ScoreLabel->AutoSize = true;
			this->ScoreLabel->Font = (gcnew System::Drawing::Font(L"돋움", 22));
			this->ScoreLabel->Location = System::Drawing::Point(102, 21);
			this->ScoreLabel->Name = L"ScoreLabel";
			this->ScoreLabel->Size = System::Drawing::Size(132, 30);
			this->ScoreLabel->TabIndex = 1;
			this->ScoreLabel->Text = L"1000000";
			this->ScoreLabel->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 39);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(95, 12);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Current Score : ";
			// 
			// PCMCbox
			// 
			this->PCMCbox->Controls->Add(this->MemCheckLabel);
			this->PCMCbox->Controls->Add(this->label5);
			this->PCMCbox->Controls->Add(this->MemCheckProgress);
			this->PCMCbox->Font = (gcnew System::Drawing::Font(L"굴림", 9));
			this->PCMCbox->Location = System::Drawing::Point(4, 21);
			this->PCMCbox->Name = L"PCMCbox";
			this->PCMCbox->Size = System::Drawing::Size(245, 54);
			this->PCMCbox->TabIndex = 1;
			this->PCMCbox->TabStop = false;
			this->PCMCbox->Text = L"Process Check and MemCheck";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"굴림", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->Location = System::Drawing::Point(11, 160);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(238, 29);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Start Memory Checking";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainThread::button1_Click);
			// 
			// MemCheckLabel
			// 
			this->MemCheckLabel->AutoSize = true;
			this->MemCheckLabel->Font = (gcnew System::Drawing::Font(L"굴림", 8));
			this->MemCheckLabel->Location = System::Drawing::Point(9, 36);
			this->MemCheckLabel->Name = L"MemCheckLabel";
			this->MemCheckLabel->Size = System::Drawing::Size(95, 11);
			this->MemCheckLabel->TabIndex = 2;
			this->MemCheckLabel->Text = L"MemCheckLabel";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"굴림", 8));
			this->label5->Location = System::Drawing::Point(11, 36);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 11);
			this->label5->TabIndex = 1;
			// 
			// MemCheckProgress
			// 
			this->MemCheckProgress->Location = System::Drawing::Point(7, 16);
			this->MemCheckProgress->Name = L"MemCheckProgress";
			this->MemCheckProgress->Size = System::Drawing::Size(228, 14);
			this->MemCheckProgress->TabIndex = 0;
			this->MemCheckProgress->Click += gcnew System::EventHandler(this, &MainThread::MemCheckProgress_Click);
			// 
			// MainThread
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(514, 546);
			this->Controls->Add(this->DecryptionBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MainThread";
			this->Text = L"BAKAware";
			this->Load += gcnew System::EventHandler(this, &MainThread::MainThread_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->DecryptionBox->ResumeLayout(false);
			this->ScoreBox->ResumeLayout(false);
			this->ScoreBox->PerformLayout();
			this->PCMCbox->ResumeLayout(false);
			this->PCMCbox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		
#pragma endregion
		
		void checkonline()
		{


		}


	private: System::Void MainThread_Load(System::Object^  sender, System::EventArgs^  e) {
		
		
		
	}

	
			 

			 


private: System::Void MemCheckProgress_Click(System::Object^  sender, System::EventArgs^  e) {
	

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	if (IsProcessRunning)
	{
		this->MemCheckLabel->Text = L"th06e.exe found!!";
		this->MemCheckProgress->Value = 100;
		DWORD ProcessID = FindProcessId(nameOfProcess);

	}else{
		this->MemCheckLabel->Text = L"th06e.exe not found";
		this->MemCheckProgress->Value = 100;
	}
}
};

DWORD FindProcessId(const std::wstring& processName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE processesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (processesSnapshot == INVALID_HANDLE_VALUE) {
		return 0;
	}

	Process32First(processesSnapshot, &processInfo);
	if (!processName.compare(processInfo.szExeFile))
	{
		CloseHandle(processesSnapshot);
		return processInfo.th32ProcessID;

	}

	while (Process32Next(processesSnapshot, &processInfo))
	{
		if (!processName.compare(processInfo.szExeFile))
		{
			CloseHandle(processesSnapshot);
			return processInfo.th32ProcessID;
		}

	}

	CloseHandle(processesSnapshot);
	return 0;

} //this function
  //ProcessId Finder End

}

