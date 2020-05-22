#include <iostream>
#include <string>

class MultipleChoiceTest
{
public:
    MultipleChoiceTest(int questionsCount)
    {
        this->questionsCount = questionsCount;
        answers = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            answers[i] = -1;
        }
    }

    void setAnswer(int questionIndex, int answer)
    {
        answers[questionIndex] = answer;
    }

    int getAnswer(int questionIndex) const
    {
        return answers[questionIndex];
    }
    ~MultipleChoiceTest(){
        std::cout<<"Destroying MultiChoiceTests\n";
        delete[] answers;
    }
protected:
    int questionsCount;

private:
    int* answers;
};
/* Solution exceeded memory limt when timed multiple choice test as
    multiple choice test
*/
class TimedMultipleChoiceTest : public MultipleChoiceTest
{
public:
    TimedMultipleChoiceTest(int questionsCount)
        : MultipleChoiceTest(questionsCount)
    {
        times = new int[questionsCount];
        for (int i = 0; i < questionsCount; i++)
        {
            times[i] = 0;
        }
    }
    ~TimedMultipleChoiceTest(){
        std::cout<<"Destroying timed\n";
        delete[] times;
    }

    void setTime(int questionIndex, int time)
    {
        times[questionIndex] = time;
    }

    int getTime(int questionIndex) const
    {
        return times[questionIndex];
    }

private:
    int* times;
};

#ifndef RunTests
void executeTest()
{
    MultipleChoiceTest test(5);
    for (int i = 0; i < 5; i++)
    {
        test.setAnswer(i, rand()%5+1);
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i) << "\n";
    }
}

void executeTestTimed(){
    TimedMultipleChoiceTest test(5);
    for(int i =0; i< 5; i++){
        test.setAnswer(i,i);
        test.setTime(i, rand()%30+1);
    }

    for(int i=0; i< 5; i++)
        std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i)
                 << " Time: "<< test.getTime(i) << "\n";
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Test: " << i + 1 << "\n";
        executeTest();
    }
    int i = 3;
    std::cout << "Test: " << i + 1 << "\n";
    executeTestTimed();
    return 0;
}
#endif