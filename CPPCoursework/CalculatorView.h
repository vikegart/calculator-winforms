#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>

namespace CPPCalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	using namespace std;
	using namespace CPPCalculator;


	/// <summary>
	/// Summary for CalculatorView
	/// </summary>
	public ref class CalculatorView : public System::Windows::Forms::Form
	{
	public:
		CalculatorView(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CalculatorView()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region My variables and methods

		// My bits

	private:
		String^ operatorFailMessage = "Please enter valid numbers and operators in a correct sequence";
		String^ nanMessage = "Not A Number. Please enter valid numbers and operators";
		double lhsNum, rhsNum;
		bool lhsOperator, midOperator, rhsOperator;
		String^ chosenOperator = "";
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  Backspace;
	private: System::Windows::Forms::Button^  ClearInput;

			 char* charsToRemove = "+-/X^%!qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM()";

			 String^ Calculate();
			 String^ InstantOperators(String^ enteredStr);
			 void midOperatorsSetup(String^ operatorStr);
			 void ResetAfterCalculation();
			 void UpdateText(String^ text);
			 void MoveTextToListBox(String^ desiredText);
			 string StringHatToString(String^ originalStrHat);
			 String^ StringToStringHat(string originalString);
			 char* StringHatToCharArray(String^ originalStrHat);
			 int StringHatToInt(String^ originalStrHat);
			 double StringHatToDouble(String^ originalStrHat);

#pragma region Auto generated button and panel declarations.
	private: System::Windows::Forms::TableLayoutPanel^  RootTablePanel;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  LeftRightPanel;
	private: System::Windows::Forms::TableLayoutPanel^  LeftTablePanel;
	private: System::Windows::Forms::TableLayoutPanel^  RightTablePanel;
	private: System::Windows::Forms::Button^  Nine;
	private: System::Windows::Forms::Button^  Eight;
	private: System::Windows::Forms::Button^  Seven;
	private: System::Windows::Forms::Button^  Multiply;
	private: System::Windows::Forms::Button^  Six;
	private: System::Windows::Forms::Button^  Five;
	private: System::Windows::Forms::Button^  Four;
	private: System::Windows::Forms::Button^  Divide;
	private: System::Windows::Forms::Button^  Three;
	private: System::Windows::Forms::Button^  Two;
	private: System::Windows::Forms::Button^  One;
	private: System::Windows::Forms::Button^  Subtract;
	private: System::Windows::Forms::Button^  Equals;
	private: System::Windows::Forms::Button^  Zero;
	private: System::Windows::Forms::Button^  DecimalPoint;
	private: System::Windows::Forms::Button^  Add;
	private: System::Windows::Forms::Button^  Pi;
	private: System::Windows::Forms::Button^  Tan;
	private: System::Windows::Forms::Button^  Cos;
	private: System::Windows::Forms::Button^  Sin;














	private: System::Windows::Forms::Button^  ClearHistory;
	private: System::Windows::Forms::TextBox^  InputTextBox;
	private: System::Windows::Forms::ListBox^  PreviousEntryListBox;

#pragma endregion




#pragma endregion

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

	private:
		/// <summary>
		/// Required designer variable.ыва
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->LeftRightPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->RightTablePanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Nine = (gcnew System::Windows::Forms::Button());
			this->Eight = (gcnew System::Windows::Forms::Button());
			this->Seven = (gcnew System::Windows::Forms::Button());
			this->Multiply = (gcnew System::Windows::Forms::Button());
			this->Six = (gcnew System::Windows::Forms::Button());
			this->Five = (gcnew System::Windows::Forms::Button());
			this->Four = (gcnew System::Windows::Forms::Button());
			this->Divide = (gcnew System::Windows::Forms::Button());
			this->Three = (gcnew System::Windows::Forms::Button());
			this->Two = (gcnew System::Windows::Forms::Button());
			this->One = (gcnew System::Windows::Forms::Button());
			this->Subtract = (gcnew System::Windows::Forms::Button());
			this->Equals = (gcnew System::Windows::Forms::Button());
			this->Zero = (gcnew System::Windows::Forms::Button());
			this->DecimalPoint = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->LeftTablePanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Pi = (gcnew System::Windows::Forms::Button());
			this->Tan = (gcnew System::Windows::Forms::Button());
			this->Cos = (gcnew System::Windows::Forms::Button());
			this->Sin = (gcnew System::Windows::Forms::Button());
			this->RootTablePanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ClearHistory = (gcnew System::Windows::Forms::Button());
			this->PreviousEntryListBox = (gcnew System::Windows::Forms::ListBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->InputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Backspace = (gcnew System::Windows::Forms::Button());
			this->ClearInput = (gcnew System::Windows::Forms::Button());
			this->LeftRightPanel->SuspendLayout();
			this->RightTablePanel->SuspendLayout();
			this->LeftTablePanel->SuspendLayout();
			this->RootTablePanel->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// LeftRightPanel
			// 
			this->LeftRightPanel->ColumnCount = 2;
			this->LeftRightPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->LeftRightPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->LeftRightPanel->Controls->Add(this->RightTablePanel, 1, 0);
			this->LeftRightPanel->Controls->Add(this->LeftTablePanel, 0, 0);
			this->LeftRightPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LeftRightPanel->Location = System::Drawing::Point(2, 94);
			this->LeftRightPanel->Margin = System::Windows::Forms::Padding(2);
			this->LeftRightPanel->Name = L"LeftRightPanel";
			this->LeftRightPanel->RowCount = 1;
			this->LeftRightPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->LeftRightPanel->Size = System::Drawing::Size(874, 364);
			this->LeftRightPanel->TabIndex = 2;
			// 
			// RightTablePanel
			// 
			this->RightTablePanel->ColumnCount = 4;
			this->RightTablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->RightTablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->RightTablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->RightTablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->RightTablePanel->Controls->Add(this->Nine, 3, 3);
			this->RightTablePanel->Controls->Add(this->Eight, 2, 3);
			this->RightTablePanel->Controls->Add(this->Seven, 1, 3);
			this->RightTablePanel->Controls->Add(this->Multiply, 0, 3);
			this->RightTablePanel->Controls->Add(this->Six, 3, 2);
			this->RightTablePanel->Controls->Add(this->Five, 2, 2);
			this->RightTablePanel->Controls->Add(this->Four, 1, 2);
			this->RightTablePanel->Controls->Add(this->Divide, 0, 2);
			this->RightTablePanel->Controls->Add(this->Three, 3, 1);
			this->RightTablePanel->Controls->Add(this->Two, 2, 1);
			this->RightTablePanel->Controls->Add(this->One, 1, 1);
			this->RightTablePanel->Controls->Add(this->Subtract, 0, 1);
			this->RightTablePanel->Controls->Add(this->Equals, 3, 0);
			this->RightTablePanel->Controls->Add(this->Zero, 2, 0);
			this->RightTablePanel->Controls->Add(this->DecimalPoint, 1, 0);
			this->RightTablePanel->Controls->Add(this->Add, 0, 0);
			this->RightTablePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->RightTablePanel->Location = System::Drawing::Point(439, 2);
			this->RightTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->RightTablePanel->Name = L"RightTablePanel";
			this->RightTablePanel->RowCount = 4;
			this->RightTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->RightTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->RightTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->RightTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->RightTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 16)));
			this->RightTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 16)));
			this->RightTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 16)));
			this->RightTablePanel->Size = System::Drawing::Size(433, 360);
			this->RightTablePanel->TabIndex = 0;
			// 
			// Nine
			// 
			this->Nine->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Nine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Nine->Location = System::Drawing::Point(326, 272);
			this->Nine->Margin = System::Windows::Forms::Padding(2);
			this->Nine->Name = L"Nine";
			this->Nine->Size = System::Drawing::Size(105, 86);
			this->Nine->TabIndex = 15;
			this->Nine->Text = L"9";
			this->Nine->UseVisualStyleBackColor = true;
			this->Nine->Click += gcnew System::EventHandler(this, &CalculatorView::Nine_Click);
			// 
			// Eight
			// 
			this->Eight->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Eight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Eight->Location = System::Drawing::Point(218, 272);
			this->Eight->Margin = System::Windows::Forms::Padding(2);
			this->Eight->Name = L"Eight";
			this->Eight->Size = System::Drawing::Size(104, 86);
			this->Eight->TabIndex = 14;
			this->Eight->Text = L"8";
			this->Eight->UseVisualStyleBackColor = true;
			this->Eight->Click += gcnew System::EventHandler(this, &CalculatorView::Eight_Click);
			// 
			// Seven
			// 
			this->Seven->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Seven->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Seven->Location = System::Drawing::Point(110, 272);
			this->Seven->Margin = System::Windows::Forms::Padding(2);
			this->Seven->Name = L"Seven";
			this->Seven->Size = System::Drawing::Size(104, 86);
			this->Seven->TabIndex = 13;
			this->Seven->Text = L"7";
			this->Seven->UseVisualStyleBackColor = true;
			this->Seven->Click += gcnew System::EventHandler(this, &CalculatorView::Seven_Click);
			// 
			// Multiply
			// 
			this->Multiply->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Multiply->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Multiply->Location = System::Drawing::Point(2, 272);
			this->Multiply->Margin = System::Windows::Forms::Padding(2);
			this->Multiply->Name = L"Multiply";
			this->Multiply->Size = System::Drawing::Size(104, 86);
			this->Multiply->TabIndex = 12;
			this->Multiply->Text = L"X";
			this->Multiply->UseVisualStyleBackColor = true;
			this->Multiply->Click += gcnew System::EventHandler(this, &CalculatorView::Multiply_Click);
			// 
			// Six
			// 
			this->Six->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Six->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Six->Location = System::Drawing::Point(326, 182);
			this->Six->Margin = System::Windows::Forms::Padding(2);
			this->Six->Name = L"Six";
			this->Six->Size = System::Drawing::Size(105, 86);
			this->Six->TabIndex = 11;
			this->Six->Text = L"6";
			this->Six->UseVisualStyleBackColor = true;
			this->Six->Click += gcnew System::EventHandler(this, &CalculatorView::Six_Click);
			// 
			// Five
			// 
			this->Five->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Five->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Five->Location = System::Drawing::Point(218, 182);
			this->Five->Margin = System::Windows::Forms::Padding(2);
			this->Five->Name = L"Five";
			this->Five->Size = System::Drawing::Size(104, 86);
			this->Five->TabIndex = 10;
			this->Five->Text = L"5";
			this->Five->UseVisualStyleBackColor = true;
			this->Five->Click += gcnew System::EventHandler(this, &CalculatorView::Five_Click);
			// 
			// Four
			// 
			this->Four->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Four->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Four->Location = System::Drawing::Point(110, 182);
			this->Four->Margin = System::Windows::Forms::Padding(2);
			this->Four->Name = L"Four";
			this->Four->Size = System::Drawing::Size(104, 86);
			this->Four->TabIndex = 9;
			this->Four->Text = L"4";
			this->Four->UseVisualStyleBackColor = true;
			this->Four->Click += gcnew System::EventHandler(this, &CalculatorView::Four_Click);
			// 
			// Divide
			// 
			this->Divide->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Divide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Divide->Location = System::Drawing::Point(2, 182);
			this->Divide->Margin = System::Windows::Forms::Padding(2);
			this->Divide->Name = L"Divide";
			this->Divide->Size = System::Drawing::Size(104, 86);
			this->Divide->TabIndex = 8;
			this->Divide->Text = L"/";
			this->Divide->UseVisualStyleBackColor = true;
			this->Divide->Click += gcnew System::EventHandler(this, &CalculatorView::Divide_Click);
			// 
			// Three
			// 
			this->Three->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Three->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Three->Location = System::Drawing::Point(326, 92);
			this->Three->Margin = System::Windows::Forms::Padding(2);
			this->Three->Name = L"Three";
			this->Three->Size = System::Drawing::Size(105, 86);
			this->Three->TabIndex = 7;
			this->Three->Text = L"3";
			this->Three->UseVisualStyleBackColor = true;
			this->Three->Click += gcnew System::EventHandler(this, &CalculatorView::Three_Click);
			// 
			// Two
			// 
			this->Two->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Two->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Two->Location = System::Drawing::Point(218, 92);
			this->Two->Margin = System::Windows::Forms::Padding(2);
			this->Two->Name = L"Two";
			this->Two->Size = System::Drawing::Size(104, 86);
			this->Two->TabIndex = 6;
			this->Two->Text = L"2";
			this->Two->UseVisualStyleBackColor = true;
			this->Two->Click += gcnew System::EventHandler(this, &CalculatorView::Two_Click);
			// 
			// One
			// 
			this->One->Dock = System::Windows::Forms::DockStyle::Fill;
			this->One->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->One->Location = System::Drawing::Point(110, 92);
			this->One->Margin = System::Windows::Forms::Padding(2);
			this->One->Name = L"One";
			this->One->Size = System::Drawing::Size(104, 86);
			this->One->TabIndex = 5;
			this->One->Text = L"1";
			this->One->UseVisualStyleBackColor = true;
			this->One->Click += gcnew System::EventHandler(this, &CalculatorView::One_Click);
			// 
			// Subtract
			// 
			this->Subtract->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Subtract->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Subtract->Location = System::Drawing::Point(2, 92);
			this->Subtract->Margin = System::Windows::Forms::Padding(2);
			this->Subtract->Name = L"Subtract";
			this->Subtract->Size = System::Drawing::Size(104, 86);
			this->Subtract->TabIndex = 4;
			this->Subtract->Text = L"-";
			this->Subtract->UseVisualStyleBackColor = true;
			this->Subtract->Click += gcnew System::EventHandler(this, &CalculatorView::Subtract_Click);
			// 
			// Equals
			// 
			this->Equals->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Equals->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Equals->Location = System::Drawing::Point(326, 2);
			this->Equals->Margin = System::Windows::Forms::Padding(2);
			this->Equals->Name = L"Equals";
			this->Equals->Size = System::Drawing::Size(105, 86);
			this->Equals->TabIndex = 3;
			this->Equals->Text = L"=";
			this->Equals->UseVisualStyleBackColor = true;
			this->Equals->Click += gcnew System::EventHandler(this, &CalculatorView::Equals_Click);
			// 
			// Zero
			// 
			this->Zero->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Zero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Zero->Location = System::Drawing::Point(218, 2);
			this->Zero->Margin = System::Windows::Forms::Padding(2);
			this->Zero->Name = L"Zero";
			this->Zero->Size = System::Drawing::Size(104, 86);
			this->Zero->TabIndex = 2;
			this->Zero->Text = L"0";
			this->Zero->UseVisualStyleBackColor = true;
			this->Zero->Click += gcnew System::EventHandler(this, &CalculatorView::Zero_Click);
			// 
			// DecimalPoint
			// 
			this->DecimalPoint->Dock = System::Windows::Forms::DockStyle::Fill;
			this->DecimalPoint->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DecimalPoint->Location = System::Drawing::Point(110, 2);
			this->DecimalPoint->Margin = System::Windows::Forms::Padding(2);
			this->DecimalPoint->Name = L"DecimalPoint";
			this->DecimalPoint->Size = System::Drawing::Size(104, 86);
			this->DecimalPoint->TabIndex = 1;
			this->DecimalPoint->Text = L".";
			this->DecimalPoint->UseVisualStyleBackColor = true;
			this->DecimalPoint->Click += gcnew System::EventHandler(this, &CalculatorView::DecimalPoint_Click);
			// 
			// Add
			// 
			this->Add->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Add->Location = System::Drawing::Point(2, 2);
			this->Add->Margin = System::Windows::Forms::Padding(2);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(104, 86);
			this->Add->TabIndex = 0;
			this->Add->Text = L"+";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &CalculatorView::Add_Click);
			// 
			// LeftTablePanel
			// 
			this->LeftTablePanel->ColumnCount = 4;
			this->LeftTablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->LeftTablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->LeftTablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->LeftTablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->LeftTablePanel->Controls->Add(this->Pi, 3, 0);
			this->LeftTablePanel->Controls->Add(this->Tan, 2, 0);
			this->LeftTablePanel->Controls->Add(this->Cos, 1, 0);
			this->LeftTablePanel->Controls->Add(this->Sin, 0, 0);
			this->LeftTablePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LeftTablePanel->Location = System::Drawing::Point(2, 2);
			this->LeftTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->LeftTablePanel->Name = L"LeftTablePanel";
			this->LeftTablePanel->RowCount = 1;
			this->LeftTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->LeftTablePanel->Size = System::Drawing::Size(433, 360);
			this->LeftTablePanel->TabIndex = 1;
			this->LeftTablePanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CalculatorView::LeftTablePanel_Paint);
			// 
			// Pi
			// 
			this->Pi->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Pi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Pi->Location = System::Drawing::Point(326, 2);
			this->Pi->Margin = System::Windows::Forms::Padding(2);
			this->Pi->Name = L"Pi";
			this->Pi->Size = System::Drawing::Size(105, 356);
			this->Pi->TabIndex = 16;
			this->Pi->Text = L"Pi";
			this->Pi->UseVisualStyleBackColor = true;
			this->Pi->Click += gcnew System::EventHandler(this, &CalculatorView::Pi_Click);
			// 
			// Tan
			// 
			this->Tan->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Tan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Tan->Location = System::Drawing::Point(218, 2);
			this->Tan->Margin = System::Windows::Forms::Padding(2);
			this->Tan->Name = L"Tan";
			this->Tan->Size = System::Drawing::Size(104, 356);
			this->Tan->TabIndex = 15;
			this->Tan->Text = L"Tan()";
			this->Tan->UseVisualStyleBackColor = true;
			this->Tan->Click += gcnew System::EventHandler(this, &CalculatorView::Tan_Click);
			// 
			// Cos
			// 
			this->Cos->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Cos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cos->Location = System::Drawing::Point(110, 2);
			this->Cos->Margin = System::Windows::Forms::Padding(2);
			this->Cos->Name = L"Cos";
			this->Cos->Size = System::Drawing::Size(104, 356);
			this->Cos->TabIndex = 14;
			this->Cos->Text = L"Cos()";
			this->Cos->UseVisualStyleBackColor = true;
			this->Cos->Click += gcnew System::EventHandler(this, &CalculatorView::Cos_Click);
			// 
			// Sin
			// 
			this->Sin->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Sin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Sin->Location = System::Drawing::Point(2, 2);
			this->Sin->Margin = System::Windows::Forms::Padding(2);
			this->Sin->Name = L"Sin";
			this->Sin->Size = System::Drawing::Size(104, 356);
			this->Sin->TabIndex = 13;
			this->Sin->Text = L"Sin()";
			this->Sin->UseVisualStyleBackColor = true;
			this->Sin->Click += gcnew System::EventHandler(this, &CalculatorView::Sin_Click);
			// 
			// RootTablePanel
			// 
			this->RootTablePanel->ColumnCount = 1;
			this->RootTablePanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->RootTablePanel->Controls->Add(this->LeftRightPanel, 0, 2);
			this->RootTablePanel->Controls->Add(this->tableLayoutPanel1, 0, 0);
			this->RootTablePanel->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->RootTablePanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->RootTablePanel->Location = System::Drawing::Point(0, 0);
			this->RootTablePanel->Margin = System::Windows::Forms::Padding(2);
			this->RootTablePanel->Name = L"RootTablePanel";
			this->RootTablePanel->RowCount = 3;
			this->RootTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->RootTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 10)));
			this->RootTablePanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 80)));
			this->RootTablePanel->Size = System::Drawing::Size(878, 460);
			this->RootTablePanel->TabIndex = 0;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				85)));
			this->tableLayoutPanel1->Controls->Add(this->ClearHistory, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->PreviousEntryListBox, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(2, 2);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(874, 42);
			this->tableLayoutPanel1->TabIndex = 3;
			// 
			// ClearHistory
			// 
			this->ClearHistory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ClearHistory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClearHistory->Location = System::Drawing::Point(2, 2);
			this->ClearHistory->Margin = System::Windows::Forms::Padding(2);
			this->ClearHistory->Name = L"ClearHistory";
			this->ClearHistory->Size = System::Drawing::Size(127, 38);
			this->ClearHistory->TabIndex = 5;
			this->ClearHistory->Text = L"Очистить историю";
			this->ClearHistory->UseVisualStyleBackColor = true;
			this->ClearHistory->Click += gcnew System::EventHandler(this, &CalculatorView::ClearHistory_Click);
			// 
			// PreviousEntryListBox
			// 
			this->PreviousEntryListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PreviousEntryListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PreviousEntryListBox->FormattingEnabled = true;
			this->PreviousEntryListBox->ItemHeight = 24;
			this->PreviousEntryListBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"0" });
			this->PreviousEntryListBox->Location = System::Drawing::Point(133, 2);
			this->PreviousEntryListBox->Margin = System::Windows::Forms::Padding(2);
			this->PreviousEntryListBox->Name = L"PreviousEntryListBox";
			this->PreviousEntryListBox->Size = System::Drawing::Size(739, 38);
			this->PreviousEntryListBox->TabIndex = 6;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				85)));
			this->tableLayoutPanel2->Controls->Add(this->InputTextBox, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(2, 48);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(2);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(874, 42);
			this->tableLayoutPanel2->TabIndex = 4;
			// 
			// InputTextBox
			// 
			this->InputTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->InputTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->InputTextBox->Location = System::Drawing::Point(133, 2);
			this->InputTextBox->Margin = System::Windows::Forms::Padding(2);
			this->InputTextBox->Name = L"InputTextBox";
			this->InputTextBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->InputTextBox->Size = System::Drawing::Size(739, 29);
			this->InputTextBox->TabIndex = 2;
			this->InputTextBox->Text = L"0";
			this->InputTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->Backspace, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->ClearInput, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(125, 36);
			this->tableLayoutPanel3->TabIndex = 3;
			// 
			// Backspace
			// 
			this->Backspace->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Backspace->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Backspace->Location = System::Drawing::Point(64, 2);
			this->Backspace->Margin = System::Windows::Forms::Padding(2);
			this->Backspace->Name = L"Backspace";
			this->Backspace->Size = System::Drawing::Size(59, 32);
			this->Backspace->TabIndex = 4;
			this->Backspace->Text = L"<-";
			this->Backspace->UseVisualStyleBackColor = true;
			this->Backspace->Click += gcnew System::EventHandler(this, &CalculatorView::Backspace_Click);
			// 
			// ClearInput
			// 
			this->ClearInput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ClearInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ClearInput->Location = System::Drawing::Point(2, 2);
			this->ClearInput->Margin = System::Windows::Forms::Padding(2);
			this->ClearInput->Name = L"ClearInput";
			this->ClearInput->Size = System::Drawing::Size(58, 32);
			this->ClearInput->TabIndex = 5;
			this->ClearInput->Text = L"C";
			this->ClearInput->UseVisualStyleBackColor = true;
			this->ClearInput->Click += gcnew System::EventHandler(this, &CalculatorView::ClearInput_Click);
			// 
			// CalculatorView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(878, 460);
			this->Controls->Add(this->RootTablePanel);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"CalculatorView";
			this->Text = L"CalculatorView";
			this->LeftRightPanel->ResumeLayout(false);
			this->RightTablePanel->ResumeLayout(false);
			this->LeftTablePanel->ResumeLayout(false);
			this->RootTablePanel->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion



#pragma region Auto generated button declarations
	private: void Equals_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Zero_Click(System::Object^  sender, System::EventArgs^  e);
	private: void One_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Two_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Three_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Four_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Five_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Six_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Seven_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Eight_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Nine_Click(System::Object^  sender, System::EventArgs^  e);
	private: void DecimalPoint_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Add_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Subtract_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Divide_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Multiply_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Pi_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Sin_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Cos_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Tan_Click(System::Object^  sender, System::EventArgs^  e);
	private: void InverseSin_Click(System::Object^  sender, System::EventArgs^  e);
	private: void InverseCos_Click(System::Object^  sender, System::EventArgs^  e);
	private: void InverseTan_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Atan2_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Factorial_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Log10_Click(System::Object^  sender, System::EventArgs^  e);
	private: void LogE_Click(System::Object^  sender, System::EventArgs^  e);
	private: void RaiseToPower_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Modulus_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Sqrt_Click(System::Object^  sender, System::EventArgs^  e);
	private: void RadDeg_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Exponent_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Percent_Click(System::Object^  sender, System::EventArgs^  e);
	private: void ClearHistory_Click(System::Object^  sender, System::EventArgs^  e);
	private: void Backspace_Click(System::Object^  sender, System::EventArgs^  e);
	private: void ClearInput_Click(System::Object^  sender, System::EventArgs^  e);
#pragma endregion
	private: System::Void LeftTablePanel_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
};
}
