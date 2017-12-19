#include <iostream>

using namespace std;

class DynamicArray {
private:
    int length = 0;
    int *arr;
public:
    DynamicArray() {
        arr = new int[1];
    }
    ~DynamicArray() {
        delete[] arr;
    }

    void push(int x) {
        int bufferArray[this->length];
        for (int i = 0; i < this->length; i++) {
            bufferArray[i] = arr[i];
        }

        this->length++;
        delete[] arr;

        arr = new int[this->length];
        for (int i = 0; i < this->length - 1; i++) {
            arr[i] = bufferArray[i];
        }
        arr[this->length - 1] = x;
    }

    void removeAtIndex(int index) {
        for (int i = index; i < this->length - 1; i++) {
            arr[index] = arr[index + 1];
        }

        int bufferArray[this->length];
        for (int i = 0; i < this->length; i++) {
            bufferArray[i] = arr[i];
        }

        this->length--;
        delete[] arr;

        arr = new int[this->length];
        for (int i = 0; i < this->length; i++) {
            arr[i] = bufferArray[i];
        }
    }

    void sort() {
        for (int i = 0; i < this->length-1; i++) {
            for (int j = 0; j < this->length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    int find(int x) {
        for (int i = 0; i < this->length; i++) {
            if (arr[i] == x) {
                return i;
            }
        }
        return -1;
    }

    void insert(int index, int x) {
        int bufferArray[this->length];
        for (int i = 0; i < this->length; i++) {
            bufferArray[i] = arr[i];
        }

        delete[] arr;
        this->length++;
        arr = new int[this->length];

        for (int i = 0; i < this->length - 1; i++) {
            arr[i] = bufferArray[i];
        }

        for (int i = this->length - 1; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = x;
    }

    void pop() {
        this->removeAtIndex(this->getLength() - 1);
    }

    int& operator[](int index) {
        return arr[index];
    }

    int getLength() {
        return this->length;
    }
};

int main() {

    DynamicArray arr;

    arr.push(13);
    arr.push(4);

    arr.pop();

    arr[0] = 5;

    arr.push(31);
    arr.push(1);

    arr.insert(3, 7);
    arr.insert(3, 14);

    for (int i = 0; i < arr.getLength(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << arr.getLength() << endl;

    return 0;
}
