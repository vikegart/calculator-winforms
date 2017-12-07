#include "CalculatorView.h"
#include "CalculatorMaths.h"
#include <string>
#include <algorithm>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;
using namespace CPPCalculator;


int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CalculatorView form;
	form.Text = "C++ Calculator matt123miller";

	Application::Run(%form);


		int n;
		cin >> n;

		if (n < 1) {
			return 0;
		}
		string output = "";

		for (int i = n; i > 0; i--) {

			// empty spaces
			for (int j = 0; j > n; j++) {

				string mod = j < (n - i) ? " " : "#";
				output += mod;
			}
			output += "\n";
		}
		cout << output;
	
	return 0;
}

// I need to include and work out the string conversion things and where to use them.
// Split the string? Remove any non numeric characters?
String^ CPPCalculator::CalculatorView::Calculate()
{
	double result;
	String^ output;

	// If this doesn't work then just get Items[0] each time
	//int selectedIndex = PreviousEntryListBox->SelectedIndex;
	//String^ lastInputSelected = PreviousEntryListBox->Items[selectedIndex]->ToString();

	// Work out what's going on and parse the text into the right format.
	//if(midOperator) // The only one that cares about past and current input? I think.
	//{
		//lhsNum = StringHatToDouble(lastInputSelected);
	rhsNum = StringHatToDouble(InputTextBox->Text);
	//}
	//else // Throw an error?
	//{
	//	return operatorFailMessage;
	//}

	CalculatorMaths maths = CalculatorMaths();
	// Try catch this shit? If it throws just ask the user to input numbers properly as expected

	// I'd prefer to switch over all this but whatever
	if (chosenOperator == "+")
	{
		result = maths.Add(lhsNum, rhsNum);
	}
	else if (chosenOperator == "-")
	{
		result = maths.Subtract(lhsNum, rhsNum);
	}
	else if (chosenOperator == "/")
	{
		result = maths.Divide(lhsNum, rhsNum);
	}
	else if (chosenOperator == "X")
	{
		result = maths.Multiply(lhsNum, rhsNum);
	}
	else if (chosenOperator == "^")
	{
		result = maths.RaiseToPower(lhsNum, rhsNum);
	}
	else if (chosenOperator == "Mod")
	{
		result = maths.Modulous(lhsNum, rhsNum);
		chosenOperator = " Modulo ";
	}
	else if (chosenOperator == "Atan2")
	{
		result = maths.Atan2(lhsNum, rhsNum);
	}
	else if (chosenOperator == "%")
	{
		result = maths.Percent(lhsNum, rhsNum);
		chosenOperator = " % of ";
	}

	// Error checking
	if (isnan(result)) {
		output = nanMessage;
	}
	else // Assing a formatted output string. Atan2 looks nicer when the arguments are displayed in brackets, hence this line.
	{
		output = chosenOperator == "Atan2" ? "Atan2(" + lhsNum + ", " + rhsNum + ")" : lhsNum + chosenOperator + rhsNum;
	}


	PreviousEntryListBox->Items->Insert(0, output);

	InputTextBox->Text = StringToStringHat(to_string(result)); // double to string, then String^
	// Probably. 
	//lhsNum = result;
	// Reset ALL THE THINGS
	ResetAfterCalculation();

	return "";
}


String ^ CPPCalculator::CalculatorView::InstantOperators(String^ enteredStr)
{
	double inputNumber = StringHatToDouble(enteredStr);
	double result;
	String^ output;

	CalculatorMaths maths = CalculatorMaths();

	// What's the operator?
	if (chosenOperator == "Sin")
	{
		result = maths.Sin(inputNumber);
	}
	else if (chosenOperator == "Cos")
	{
		result = maths.Cos(inputNumber);
	}
	else if (chosenOperator == "Tan")
	{
		result = maths.Tan(inputNumber);
	}
	else if (chosenOperator == "ASin")
	{
		result = maths.ASin(inputNumber);
	}
	else if (chosenOperator == "ACos")
	{
		result = maths.ACos(inputNumber);
	}
	else if (chosenOperator == "ATan")
	{
		result = maths.ATan(inputNumber);
	}
	else if (chosenOperator == "!")
	{
		result = maths.Factorial(inputNumber);
	}
	else if (chosenOperator == "Log10")
	{
		result = maths.CommonLog(inputNumber); // log 10
	}
	else if (chosenOperator == "LogE")
	{
		result = maths.NatLog(inputNumber); // log e
	}
	else if (chosenOperator == "Sqrt")
	{
		result = maths.SquareRoot(inputNumber);
	}
	else if (chosenOperator == "EXP")
	{
		result = maths.Exponential(inputNumber);
	}

	/*output = result.ToString();

	if (isnan(result))
	{
		output = nanMessage;
	}*/
	output = isnan(result) ? nanMessage : result.ToString();

	String^ operationStr = chosenOperator == "!" ? inputNumber + "!" : chosenOperator + "(" + inputNumber + ")";

	PreviousEntryListBox->Items->Insert(0, operationStr);
	InputTextBox->Text = output;

	return output;
}

void CPPCalculator::CalculatorView::midOperatorsSetup(String ^ operatorStr)
{
	// Cache the number entered
	lhsNum = StringHatToDouble(InputTextBox->Text);
	// Assign my operator straight away before doing some formatting for display
	chosenOperator = operatorStr; 
	if (operatorStr == "Mod")
		operatorStr = "Modulo ";
	else if (operatorStr == "%")
		operatorStr = "% of ";
	// Update my text boxes
	UpdateText(" " + operatorStr + " ");
	MoveTextToListBox(InputTextBox->Text);

	midOperator = true;
}


void CPPCalculator::CalculatorView::ResetAfterCalculation()
{
	// What do I need to reset?
	lhsOperator = false;
	rhsOperator = false;
	midOperator = false;
}

// I'd really like to have this do all the formatting and things as well
void CPPCalculator::CalculatorView::UpdateText(String^ inputText)
{
	// Check for known reasons to apply inputText, if not then append inputText
	if (InputTextBox->Text == "0")
	{
		InputTextBox->Text = inputText;
	}
	else if (InputTextBox->Text == operatorFailMessage)
	{
		InputTextBox->Text = inputText;
	}
	else if (InputTextBox->Text == nanMessage)
	{
		InputTextBox->Text = inputText;
	}
	else if (InputTextBox->Text == "-")
	{
		InputTextBox->Text += inputText;
	}
	else
	{
		InputTextBox->Text += inputText;
	}

}


void CPPCalculator::CalculatorView::MoveTextToListBox(String^ desiredText)
{
	PreviousEntryListBox->Items->Insert(0, desiredText);
	PreviousEntryListBox->SelectedIndex = 0; // Make sure the new inserted value is selected
	InputTextBox->Text = "0"; // Maybe just use ""?
}


#pragma region conversion methods

// I'm using these 4 conversion methods instead of the Microsoft Convert:: methods as these are cross platform.
string CPPCalculator::CalculatorView::StringHatToString(String ^ originalStrHat)
{
	return msclr::interop::marshal_as<std::string>(originalStrHat);
}

String ^ CPPCalculator::CalculatorView::StringToStringHat(string originalStr)
{
	return gcnew String(originalStr.c_str());
}

char * CPPCalculator::CalculatorView::StringHatToCharArray(String ^ originalStrHat)
{
	IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(originalStrHat);
	return static_cast<char*>(ptrToNativeString.ToPointer());
}

int CPPCalculator::CalculatorView::StringHatToInt(String ^ originalStrHat)
{
	return atoi(StringHatToCharArray(originalStrHat));
}

double CPPCalculator::CalculatorView::StringHatToDouble(String ^ originalStrHat)
{
	return atof(StringHatToCharArray(originalStrHat));
}

#pragma endregion


void CPPCalculator::CalculatorView::ClearHistory_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	PreviousEntryListBox->Items->Clear();
	// Do I also need to reset other things?
	ResetAfterCalculation();
}

void CPPCalculator::CalculatorView::Backspace_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	String^ text = InputTextBox->Text;

	if (text == "" /*|| text == "0"*/)
	{
		return;
	}
	else if (text == nanMessage)
	{
		InputTextBox->Text = "";
		return;
	}
	else if (text == operatorFailMessage)
	{
		InputTextBox->Text = "";
		return;
	}

	string textStr = StringHatToString(text);
	// Remove the final item, erase() is cool!;
	// http://www.cplusplus.com/reference/string/string/erase/
	// "Erases the portion of the string value that begins at the character position pos 
	// and spans len characters (or until the end of the string, if either the content is too short or if len is string::npos.)"
	textStr.erase(textStr.end() - 1);

	InputTextBox->Text = StringToStringHat(textStr);
}

void CPPCalculator::CalculatorView::ClearInput_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	InputTextBox->Text = "";
	ResetAfterCalculation();
}


void CPPCalculator::CalculatorView::Equals_Click(System::Object ^ sender, System::EventArgs ^ e)
{

	String^ result = Calculate(); // Calculate is where the magic happens!
	//Probably
	//ResetAfterCalculation()
}

void CPPCalculator::CalculatorView::Zero_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText("0");
}

void CPPCalculator::CalculatorView::One_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText("1");
}

void CPPCalculator::CalculatorView::Two_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText("2");
}

void CPPCalculator::CalculatorView::Three_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText("3");
}

void CPPCalculator::CalculatorView::Four_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText("4");
}

void CPPCalculator::CalculatorView::Five_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText("5");
}

void CPPCalculator::CalculatorView::Six_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText("6");
}

void CPPCalculator::CalculatorView::Seven_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText("7");
}

void CPPCalculator::CalculatorView::Eight_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText("8");
}

void CPPCalculator::CalculatorView::Nine_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText("9");
}

void CPPCalculator::CalculatorView::DecimalPoint_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	UpdateText(".");
}

void CPPCalculator::CalculatorView::Add_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	midOperatorsSetup("+");
}

void CPPCalculator::CalculatorView::Subtract_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	midOperatorsSetup("-");

}

void CPPCalculator::CalculatorView::Divide_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	midOperatorsSetup("/");

}

void CPPCalculator::CalculatorView::Multiply_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	midOperatorsSetup("X");
}

void CPPCalculator::CalculatorView::Pi_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Cheat and fetch Pi.
	double pi = CalculatorMaths().Pi();
	lhsNum = pi; // This will get overwritten...probably

	UpdateText(pi.ToString());
}

void CPPCalculator::CalculatorView::Sin_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "Sin";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}

void CPPCalculator::CalculatorView::Cos_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "Cos";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}

void CPPCalculator::CalculatorView::Tan_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "Tan";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}

void CPPCalculator::CalculatorView::InverseSin_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "ASin";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}

void CPPCalculator::CalculatorView::InverseCos_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "ACos";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}

void CPPCalculator::CalculatorView::InverseTan_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "ATan";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}

void CPPCalculator::CalculatorView::Atan2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	midOperatorsSetup("Atan2");
}

void CPPCalculator::CalculatorView::Factorial_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "!";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}

void CPPCalculator::CalculatorView::Log10_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "Log10";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}

void CPPCalculator::CalculatorView::LogE_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "LogE";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}


void CPPCalculator::CalculatorView::RaiseToPower_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	midOperatorsSetup("^");
}

void CPPCalculator::CalculatorView::Exponent_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "EXP";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}

void CPPCalculator::CalculatorView::Percent_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	midOperatorsSetup("%");
}

void CPPCalculator::CalculatorView::Modulus_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	midOperatorsSetup("Mod");
}

void CPPCalculator::CalculatorView::Sqrt_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	chosenOperator = "Sqrt";
	String^ result = InstantOperators(InputTextBox->Text);
	 
}


void CPPCalculator::CalculatorView::RadDeg_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	// Set some bools that are used after getting a calculation back, then convert that result to the desired format.
}
