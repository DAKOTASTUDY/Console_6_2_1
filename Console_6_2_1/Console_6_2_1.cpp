#include <iostream>
class smartArray
{
private:
    int asize;
    int* array;
    int index = 0;
public:

    smartArray(int size)
    {
        asize = 2 * size;
        array = new int[asize];

    };
    ~smartArray()
    {
        delete[] array;

    }


    smartArray(const smartArray&) = delete;
    smartArray& operator=(const smartArray&) = delete;
    void elementValue(int value)
    {


       // std::cout << "\n / Element index" << index << " / " << " asize" << asize << std::endl;
        if ((index >= asize) || (index < 0))

        {
            // std::cout << "throw" << std::endl;
            throw std::runtime_error("\n Error. Index is out of range.");
        }
        else {
          //  std::cout << "\n / " << index << " / " << std::endl;
           
            array[index] = value;
        }
        std::cout << "\n used index: " << index << std::endl;
        index++;
        std::cout << " realtime index: " << index << std::endl;
    }
    int getElement(int position)
    {
        if ((position < 0) || (position >= index))

        {

            throw std::exception("\n Error. No valuable element.");
        }
        //std::cout << "\n /  index " << index << " / " << std::endl;
       // std::cout << "\n / position" << position << " / " << std::endl;
        return array[position];
    }
};

int main()
{
    smartArray a(5);
    for (int i = 0; i < 10; i++)
    {
        try {
            a.elementValue(i + 100 * i);
        }

        catch (const std::exception& e) {
            std::cout << e.what();
        }

    }
    for (int i = 0; i < 10; i++)
    {
        try {
            std::cout << "Array element (index): " << "(" << i << ") " << a.getElement(i) << std::endl;
        }

        catch (const std::exception& e) {
            std::cout << e.what();

        };
    }
    /*try
    {
        a.elementValue(20);
        std::cout << a.getElement(20) << std::endl;
    }
    catch (const std::exception& e) { std::cout << e.what(); };*/

    return 0;
}
