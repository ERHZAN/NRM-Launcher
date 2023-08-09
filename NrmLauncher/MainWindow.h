#pragma once
#include <windows.h>
#include <stdlib.h>
#include <filesystem>
#include <iostream>

namespace NrmLauncher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		String^ m_wName;
		std::vector<std::wstring>& m_submodsNames;
		std::vector<std::wstring>& m_submodsPaths;
		std::vector<std::wstring>& m_submodsSelected;
		std::wstring& m_fullCmdArgs;
		MainWindow(String^ wName, std::vector<std::wstring>& submodsNames, std::vector<std::wstring>& submodsPaths,
			std::vector<std::wstring>& submodsSelected, std::wstring& cmdFullArgs)
			: m_wName(wName), m_submodsNames(submodsNames), m_submodsPaths(submodsPaths), m_fullCmdArgs(cmdFullArgs),
			m_submodsSelected(submodsSelected)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		String^ getName() {
			return m_wName;
		}
		const std::vector<std::wstring>& getVector() {
			return m_submodsNames;
		}
		cli::array<Object^>^ getSubmodsNames();
		const std::vector<std::wstring>& getSubmodsPathsVector() {
			return m_submodsPaths;
		}
		std::vector<std::wstring>& getSubmodsSelectedVector() {
			return m_submodsSelected;
		}
		void pushSelectedSubmod(std::wstring str);
		std::wstring& getCmdArgsStr() {
			return m_fullCmdArgs;
		}
		void calcCmdArgs();
		void startGame(LPCTSTR lpApplicationName);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ playGame;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent()
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->playGame = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// playGame
			// 
			this->playGame->BackColor = System::Drawing::Color::Transparent;
			this->playGame->Cursor = System::Windows::Forms::Cursors::Hand;
			this->playGame->FlatAppearance->BorderColor = System::Drawing::Color::Olive;
			this->playGame->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->playGame->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->playGame->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->playGame->Font = (gcnew System::Drawing::Font(L"a_OldTyper", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->playGame->ForeColor = System::Drawing::Color::White;
			this->playGame->Location = System::Drawing::Point(483, 408);
			this->playGame->Name = L"playGame";
			this->playGame->Size = System::Drawing::Size(205, 63);
			this->playGame->TabIndex = 0;
			this->playGame->Text = L"Ќачать игру";
			this->playGame->UseVisualStyleBackColor = false;
			this->playGame->Click += gcnew System::EventHandler(this, &MainWindow::playGame_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(700, 394);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->BackColor = System::Drawing::Color::Moccasin;
			this->checkedListBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Cambria", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkedListBox1->ForeColor = System::Drawing::Color::Indigo;
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(12, 410);
			this->checkedListBox1->Margin = System::Windows::Forms::Padding(5);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(235, 60);
			this->checkedListBox1->TabIndex = 1;
			this->checkedListBox1->Items->AddRange(getSubmodsNames());
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(700, 490);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->playGame);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->Text = getName();
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void playGame_Click(System::Object^ sender, System::EventArgs^ e) {
		startGame(L"vic2.exe");
	}
};
}