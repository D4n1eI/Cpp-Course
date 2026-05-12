#include <iostream>



using namespace std;



void print(int array[],size_t size);

int* apply_all(int*arr1,size_t size1,int*arr2,size_t size2);


int* apply_all(int*arr1,size_t size1,int*arr2,size_t size2){
    int*result = new int[size1*size2];
    int* current = result;
    int* a1_start = arr1;
    for (int i {0};i<size2;i++){
        arr1 = a1_start;
        for(int j{0};j<size1;j++){
            *current = (*arr1)*(*arr2);
            arr1++;
            current++;
        }
        &arr1[0];
        arr2++;
    }

    return result;
}





void print(int array[],size_t size){
    cout << "{";
    for (int i{0};i<size;i++){
        i==size-1? cout<<array[i] : cout << array[i] <<",";
    }
    cout << "}";
    cout <<endl;
}



int main(){
    const size_t array1_size {5};
    const size_t array2_size {3};


    int array1[]={1,2,3,4,5};
    int array2[]={10,20,30};

    cout << "Array 1: ";
    print(array1,array1_size);


    cout << "Array 2: ";
    print(array2,array2_size);


    int * results = apply_all(array1,array1_size,array2,array2_size);
    constexpr size_t result_size {array1_size*array2_size};


    cout << "Result: ";
    print(results,result_size);

    delete[] results;


    cout << endl;
}