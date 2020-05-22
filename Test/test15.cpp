#include <stdexcept>
#include <iostream>
#include <vector>

class TrainComposition
{
private:
    // int capacity;
    // int current;
    // int *arr;
    //std::vector <int> m_cars(int);

public:
    // TrainComposition() { }
    // TrainComposition(){
    //     arr = new int[1];
    //     capacity = 1;
    //     current = 0;
    // }
    // ~TrainComposition(){
    //     delete[] arr;
    // }
    // void push_front (int data){
    //     if(current==capacity){
    //         int *temp = new int[2*capacity];
    //         for (int i=0; i<capacity;i++){
    //             temp[i] = arr[i];
    //         }
    //     delete[] arr;
    //     capacity *= 2;
    //     arr = temp;
    //     }
    //     arr[current] = data;
    //     current++;
    // }
    std::vector <int> m_cars;

    void attachWagonFromRight(int wagonId)
    {
       m_cars.push_back(wagonId); // adds element to end of vector
    }

    void attachWagonFromLeft(int wagonId)
    {
        m_cars.insert(m_cars.begin(),wagonId);  // adds element to begining of vector
    }

    int detachWagonFromLeft()
    {   
        int wagonId = m_cars.front();
        m_cars.erase(m_cars.begin());
        return wagonId;
    }

    int detachWagonFromRight()
    {   
        int wagonId = m_cars.back();
        m_cars.pop_back();
        return wagonId;
    }

    void showTrain(){
        std::cout << "Train: ";
        for(auto it : m_cars)
            std::cout << it << " ";
        std::cout << std::endl;
    }


};

#ifndef RunTests
int main()
{
    TrainComposition train;
    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    train.showTrain();
    std::cout << train.detachWagonFromRight() << "\n"; // 7 
    std::cout << train.detachWagonFromLeft() << "\n";; // 13

    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    train.attachWagonFromLeft(1);
    train.attachWagonFromLeft(2);
    train.showTrain();

    std::cout << train.detachWagonFromRight() << "\n"; // 7 
    std::cout << train.detachWagonFromLeft() << "\n";; // 2

}
#endif