#include <iostream>
#include <stdexcept>

template <typename T>
class GenericArray {
private:
    T* data;
    int length;

public:
    // Constructor
    GenericArray() : data(nullptr), length(0) {}

    // Destructor
    ~GenericArray() {
        delete[] data;
    }

    // Add element to the end of the array
    void addElement(T element) {
        T* newData = new T[length + 1];
        for (int i = 0; i < length; i++) {
            newData[i] = data[i];
        }
        newData[length] = element;

        delete[] data;
        data = newData;
        length++;
    }

    // Access element at a specific index
    T at(int index) const {
        if (index < 0 || index >= length) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    // Return the size of the array
    int size() const {
        return length;
    }

    // Calculate the sum of the array
    T sum() const {
        T total = 0;
        for (int i = 0; i < length; i++) {
            total += data[i];
        }
        return total;
    }

    // Find the maximum value in the array
    T max() const {
        if (length == 0) {
            throw std::logic_error("Array is empty");
        }
        T maxVal = data[0];
        for (int i = 1; i < length; i++) {
            if (data[i] > maxVal) {
                maxVal = data[i];
            }
        }
        return maxVal;
    }

    // Find the minimum value in the array
    T min() const {
        if (length == 0) {
            throw std::logic_error("Array is empty");
        }
        T minVal = data[0];
        for (int i = 1; i < length; i++) {
            if (data[i] < minVal) {
                minVal = data[i];
            }
        }
        return minVal;
    }

    // Slice the array between begin and end (inclusive)
    T* slice(int begin, int end) const {
        if (begin < 0 || end >= length || begin > end) {
            throw std::out_of_range("Slice indices out of bounds");
        }

        int sliceLength = end - begin + 1;
        T* slicedArray = new T[sliceLength];
        for (int i = 0; i < sliceLength; i++) {
            slicedArray[i] = data[begin + i];
        }
        return slicedArray;
    }
};

// Example usage
int main() {
    GenericArray<int> intArray;
    intArray.addElement(10);
    intArray.addElement(20);
    intArray.addElement(30);
    intArray.addElement(40);

    std::cout << "Size of array: " << intArray.size() << std::endl;
    std::cout << "Sum of array: " << intArray.sum() << std::endl;
    std::cout << "Max value: " << intArray.max() << std::endl;
    std::cout << "Min value: " << intArray.min() << std::endl;

    try {
        int* slicedArray = intArray.slice(1, 2);
        std::cout << "Sliced array: ";
        for (int i = 0; i < 2; i++) { // Size of slice (2 - 1 + 1)
            std::cout << slicedArray[i] << " ";
        }
        std::cout << std::endl;
        delete[] slicedArray; // Remember to free memory
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

