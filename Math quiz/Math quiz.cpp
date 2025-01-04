
#include <iostream>
#include <string> 
#include <Windows.h>
using namespace std; 

enum enLevels{ Easy = 1, Medium = 2, Hard = 3, Mix = 4};
enum enQuestionsType { Add = 1, Sub = 2, Mul = 3, Div = 4, OpMix = 5 };

struct QuizInfos
{
   short  NumberOfQuestions; 
   enLevels level;
   enQuestionsType type;
   short rightAnswers  ; 
   short wrongAnswers  ; 
   QuizInfos() : NumberOfQuestions(0), rightAnswers(0), wrongAnswers(0) {} 
};

int randomNum(int from, int to) { return rand() % (to - from + 1) + from;}

//function to ask the user of his answer
int readAnswer()
{
    int answer; 
    cout << "Your answer : "; cin >> answer;
    return answer;
}

//This function will give us a random level if the user chose mix
enQuestionsType randomType()
{
    int randNum = randomNum(1, 4);
    return (enQuestionsType)randNum; 
}
//in case the level was mix we will generate some random levels 
enLevels randomLevel()
{
    int randNum = randomNum(1, 3);
    return (enLevels)randNum; 
}


string stLevels(enLevels level)
{
    switch (level)
    {
    case Easy:
        return "Easy";
        break;
    case Medium:
        return "Medium";
        break;
    case Hard:
        return "Hard";
        break;
    case Mix:
        return "Mix";
        break;
    default:
        break;
    }
}
string stTypes(enQuestionsType type)
{
    switch (type)
    {
    case Add:
        return "Addition"; 
        break;
    case Sub:
        return "Subtraction"; 
        break; 
    case Mul:
        return "Multiplication";
        break;
    case Div:
        return "Division";
        break;
    case OpMix:
        return "Mix"; 
        break;
    default:
        break;
    }
}

// this function will convert the enum type of the question type to string
string stOperators(enQuestionsType ty)
{
    switch (ty)
    {
    case Add:
        return "+"; 
    case Sub:
        return "-";
    case Mul:
        return "*"; 
    case Div:
        return "/"; 
    default:
        break;
    }
}


// this function will generate numbers based on the level
int generateNums(enLevels levels) 
{
    
    if (levels == Easy) return randomNum(1, 9);
    if (levels == Medium) return randomNum(10, 50);
    if (levels == Hard) return randomNum(50, 100);

}

enLevels readLevel()
{
    int lvl;
    do
    {
      cout << "Choose the questions lvl : [1] Easy, [2] Medium, [3] Hard, [4] Mix ? ->  "; cin >> lvl;
    } while (lvl < 1 || lvl > 4);


    return (enLevels) lvl; 
}
enQuestionsType readType()
{
    int type;
    do {
        cout << "Choose the questions type : [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ->  "; cin >> type;
    } while (type < 1 || type > 5);
    return (enQuestionsType)type; 
 }

void Newlines()
{
    cout << "\n\n\n"; 
}
void tabs()
{
    cout << "\t\t"; 
}
void lines()
{
    cout << "______________________________________________\n" << endl; 
}


//This function will give us the result of an operation based on the type of the operation
double operationResult(enQuestionsType type, double a, double b)
{
    if (type == Add) return a + b; 
    if (type == Sub) return a - b; 
    if (type == Mul) return a * b; 
    if (type == Div) return double(a / b);
   
}

// this function will display operation based on the question type
void displayOperations(int a, int b, enQuestionsType ty)
{
    cout << a << endl; 
    cout << b << " " << stOperators(ty) << endl; 
    cout << "___________________" << endl; 
}

//this function will display the answer based on the result 
void displayAnswer(int correct, QuizInfos& quiz)
{
    int playerAnswer =  readAnswer();
    if (playerAnswer == correct)
    {
        quiz.rightAnswers++;
        system("color 2F"); 
        cout << "Right answer :-)" << endl; 
    }
    else
    {
        quiz.wrongAnswers++;
        system("color 4F"); 
        Beep(500, 500);
        cout << "Wrong Answer :-(" << endl; 
        cout << "The right answer is : " << correct << endl; 
    }
}

//this functions will work with all operations so we just need to pass the type operation and we need to pass this function to the operation function
void generateQuestionsAndAnswers(enQuestionsType type, enLevels level, QuizInfos& quiz, int questions)
{
    Newlines();
    if (type == OpMix) type = randomType();
    if (level == Mix) level = randomLevel();
    cout << "Question [" << questions << "/" << quiz.NumberOfQuestions << "] : " << endl; 
    int num1 = generateNums(level);
    int num2 = generateNums(level);
    displayOperations(num1, num2, type);
    displayAnswer(operationResult(type, num1, num2), quiz);
}

void setInfo(QuizInfos& quiz)
{
    cout << "How many Questions do you want to answer ? : "; cin >> quiz.NumberOfQuestions;
    cout << "\n"; 


    quiz.level = readLevel();
    quiz.type = readType();
}

void passOrfail(QuizInfos& quiz)
{
    if (quiz.rightAnswers >= quiz.wrongAnswers)
    {
        tabs();  cout << "  Final Exam pass !!!!\n" << endl;
    }
    else
    {
        tabs();
        cout << "  Final Exam Failed !!!" << endl;
    }
}
void result(QuizInfos& quiz)
{
    lines();
    passOrfail(quiz); lines(); 

    cout << "Number of questions       : " << quiz.NumberOfQuestions << endl; 
    cout << "Qustions level            : " << stLevels(quiz.level) << endl; 
    cout << "Questions type            : " << stTypes(quiz.type) << endl; 
    cout << "Number of right answers   : " << quiz.rightAnswers << endl; 
    cout << "Number of wrong answers   : " << quiz.wrongAnswers << endl; 
    lines(); 

}

void resetScreen()
{
    system("cls"); 
    system("color 0F"); 
}
void finalQuiz()
{

    QuizInfos quiz;
    resetScreen();
    setInfo(quiz);
    int questions = quiz.NumberOfQuestions; 
    while (questions > 0)
    {
        generateQuestionsAndAnswers(quiz.type, quiz.level, quiz, questions);
        questions--;
    }
    result(quiz); 
}





int main()
{
    srand((unsigned)time(NULL));
    string repeating = "yes"; 
    do
    {
        finalQuiz();
        Newlines();
        cout << "Do you want to play again ? : "; cin >> repeating; 
    } while (repeating != "no");
}

