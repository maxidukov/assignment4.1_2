#include <iostream>

int numgt(int,int*,int);

int main() {

  int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
  int size = sizeof(arr)/sizeof(int);
  int num{};
  std::cout << "Введите точку отсчёта: ";
  std::cin>>num;
  std::cout<<"Количество элементов в массиве больших, чем "<<num<<": "<<numgt(num, arr, size)<<"\n";
}

int numgt(int num, int* arr, int size){
   if(num>=arr[size-1]){
     return 0;
   }else if(num<arr[0]){
     return size;
   }else{
   int right = size - 1;
   int mid{};
   int left{};
   while(right-left>0){
      mid = (left + right)/2;
      //std::cout<<"Left: "<<left<<", mid:  "<<mid<<" right: "<<right<<"\n";
      if(arr[mid]<=num){
        left = ++mid;
      }else if(arr[mid]>num){
        right = mid;
      }
    }
   //std::cout<<"Final. Left: "<<left<<" ("<<arr[left]<<"), mid: "<<mid<<" ("<<arr[mid]<<") right: "<<right<<" ("<<arr[right]<<")\n";
   return size-mid;
   }
}
