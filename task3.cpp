#include <iostream>

using namespace std;
template<typename T>
bool p(const T& elem){
    if(elem = true) return true;
    else return false;
}



template<typename T>
bool all_of(T* arr, size_t length, bool(*p)(const T& elem)){
    for(size_t i = 0; i < length; i++){
        if(*p(arr[i]) == true){
        }
        else{
            return false;
        }
    }
    return true;
}

template<typename T>
bool any_of(T* arr, size_t length, bool(*p)(const T& elem)){
    for(size_t i = 0; i < length; i++){
        if(*p(arr[i]) == true) {
            return true;
        }
    }
    return false;
}


int main(int argc, char *argv[])
{

    return 0;
}
